# Copyright © 2012-2014 Lénaïc Bagnères, hnc@singularity.fr

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


cmake_minimum_required(VERSION 2.6)


# Release / Debug flags

	if (RELEASE STREQUAL "FALSE" OR RELEASE STREQUAL "DEBUG")
		set(RELEASE "FALSE")
	else()
		set(RELEASE "TRUE")
	endif()

	if (RELEASE)
		set(CMAKE_CXX_FLAGS "-O3 -DNDEBUG -march=native -ffast-math")
	else()
		set(CMAKE_CXX_FLAGS "-O0 -g3")
	endif()

# User's settings - General C++ Flags
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -std=c++11 -pedantic -fopenmp")


# Get local directory where .cmake are
	set(FIND_PACKAGE_LOCAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# UNIX
	message(STATUS "---")
	find_package(hnc_unix PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Linux
	message(STATUS "---")
	find_package(hnc_linux PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Windows
	message(STATUS "---")
	find_package(hnc_windows PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Boost.Serialization
	message(STATUS "---")
	find_package(hnc_boost_serialization PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Boost.System
	message(STATUS "---")
	find_package(hnc_boost_system PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Boost.MPI
	message(STATUS "---")
	find_package(hnc_boost_mpi PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# MPI C++ Compiler
	message(STATUS "---")
	find_package(hnc_compiler_mpi_cpp PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Boost.Asio
	message(STATUS "---")
	find_package(hnc_boost_asio PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# OpenSSL
	message(STATUS "---")
	find_package(hnc_openssl PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Gnuplot executable
	message(STATUS "---")
	find_package(hnc_gnuplot_exe PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# pdflatex executable
	message(STATUS "---")
	find_package(hnc_pdflatex_exe PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# hnc
	message(STATUS "---")
	set(hnc_INCLUDE "./include")
	message(STATUS "Include hnc = ${hnc_INCLUDE}")
	include_directories("${hnc_INCLUDE}")


# Build hnc doxygen
	message(STATUS "---")
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		message(STATUS "Doxygen found =) ${DOXYGEN_EXECUTABLE}")
		add_custom_target(
			doxygen
			${DOXYGEN_EXECUTABLE}
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
			COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
	else()
		message(STATUS "Doxygen not found :(")
	endif()


# Compiler log
	message(STATUS "---")
	message(STATUS "C++ compiler = ${CMAKE_CXX_COMPILER}")
	if (RELEASE)
		message(STATUS "Release mode")
	else()
		message(STATUS "Debug mode")
	endif()
	message(STATUS "C++ flags    = ${CMAKE_CXX_FLAGS}")


# Executables & tests
	enable_testing()
	message(STATUS "---")

	# Tests
	file(
		GLOB_RECURSE
		tests
		tests/*.cpp
	)
	foreach(test_source ${tests})
	
		# Get test name and source
		string(REPLACE ".cpp" "" test_name ${test_source})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/tests/" "test__" test_name ${test_name})
		
		message(STATUS "Add test ${test_name}")
		
		# Executable MPI, Compilation with Boost.MPI
		if ("${test_name}" MATCHES ".*test__.*mpi.*")
		
			# with Boost.MPI
			if (HNC_BOOST_SERIALIZATION_FOUND AND HNC_BOOST_MPI_FOUND AND HNC_COMPILER_MPI_CPP)
				add_executable(${test_name} "${test_source}")
				target_link_libraries(${test_name} ${HNC_BOOST_MPI_LIBRARY} ${HNC_BOOST_SERIALIZATION_LIBRARY})
				add_test(${test_name} ${test_name})
			endif()
			if (HNC_COMPILER_MPI_CPP)
				add_test("${test_name}_with_mpirun_np_4" "${HNC_MPIRUN_EXE}" "-np" "4" "${test_name}")
			endif()
			
			# without
			add_executable("${test_name}_without_mpi" "${test_source}")
			set_target_properties("${test_name}_without_mpi" PROPERTIES COMPILE_FLAGS "-D${HNC_NO_BOOST_SERIALIZATION_MACRO} -D${HNC_NO_BOOST_MPI_MACRO}")
			message(STATUS "Add test ${test_name}_without_mpi")
			add_test("${test_name}_without_mpi" "${test_name}_without_mpi")
			
		# Compilation with OpenSSL
		elseif ("${test_name}" MATCHES ".*test__ssl.*")
		
			# With OpenSSL
			if (HNC_OPENSSL_FOUND)
				add_executable(${test_name} "${test_source}")
				target_link_libraries(${test_name} ${HNC_OPENSSL_LIBRARY})
				add_test(${test_name} "${test_name}")
			endif()
			
			# Without OpenSSL
			add_executable("${test_name}_without_ssl" "${test_source}")
			set_target_properties("${test_name}_without_ssl" PROPERTIES COMPILE_FLAGS "-D${HNC_NO_OPENSSL_MACRO}")
			message(STATUS "Add test ${test_name}_without_ssl")
			add_test("${test_name}_without_ssl" "${test_name}_without_ssl")
			
		# Compilation with Boost.Asio
		elseif (("${test_name}" STREQUAL "test__http") OR ("${test_name}" STREQUAL "test__http_get") OR ("${test_name}" STREQUAL "test__http_w3c_validator") OR ("${test_name}" STREQUAL "test__html_head") OR ("${test_name}" STREQUAL "test__html_webpage") OR ("${test_name}" MATCHES "test__tabular.*"))
		
			# With Boost.Asio
			if (HNC_BOOST_ASIO_FOUND)
				add_executable(${test_name} "${test_source}")
				target_link_libraries(${test_name} ${HNC_BOOST_SYSTEM_LIBRARY})
				add_test(${test_name} "${test_name}")
			endif()
			
			# Without Boost.Asio
			add_executable("${test_name}_without_boost_asio" "${test_source}")
			set_target_properties("${test_name}_without_boost_asio" PROPERTIES COMPILE_FLAGS "-D${HNC_NO_BOOST_ASIO_MACRO}")
			message(STATUS "Add test ${test_name}_without_boost_asio")
			add_test("${test_name}_without_boost_asio" "${test_name}_without_boost_asio")
			
		# Executable
		else()
		
			# Executable
			add_executable(${test_name} "${test_source}")
			
			# Test with args
			if ("${test_name}" STREQUAL "test__args")
				add_test(${test_name} "${test_name}" "--opt" "--int" "42" "--float" "3.14" "--ints" "21" "42" "73" "--types" "this is a" "tuple" "with" "5" "elements")
			elseif (${test_name} STREQUAL "test__args_without_argument")
				add_test(${test_name} "${test_name}" "--opt0" "--option1" "--opt3")
			elseif (${test_name} STREQUAL "test__args_with_one_argument")
				add_test(${test_name} "${test_name}" "--n" "21" "--M" "42" "--u" "--V" "--c" "c" "--W" "word" "--s" "A few words is a sentence")
			elseif (${test_name} STREQUAL "test__args_with_same_type_arguments")
				add_test(${test_name} "${test_name}" "--n" "21" "42" "73" "--x_y" "800" "600" "--U" "21" "--v" "--C" "d" "e" "f")
			elseif (${test_name} STREQUAL "test__args_with_different_type_arguments")
				add_test(${test_name} "${test_name}" "--n" "21" "42" "73" "--x_y" "800" "600" "--U" "21" "--v" "--C" "d" "e" "f" "--t" "42" "One word" "c" "1" "--i" "21" "--A" "b")
				
			# Test
			else()
				add_test(${test_name} "${test_name}")
			endif()
			
		endif()
		
		# Add a Gnuplot check
		if ("${test_name}" MATCHES ".*test__gnuplot_gnuplot_.*")
			if (HNC_GNUPLOT_EXE)
				string(REPLACE "test__" "hnc_" gnuplot_script ${test_name})
				string(REPLACE "${gnuplot_script}" "${gnuplot_script}.png.gnuplot" gnuplot_script ${gnuplot_script})
				message(STATUS "Add test gnuplot ${gnuplot_script}")
				add_test("${test_name}_gnuplot" "${HNC_GNUPLOT_EXE}" "${gnuplot_script}")
			endif()
		endif()
		
		# Add a LaTeX check
		if (("${test_name}" MATCHES ".*test__latex_.*") OR ("${test_name}" MATCHES "test__tabular.*"))
			if (HNC_PDFLATEX_EXE)
				string(REPLACE "test__" "hnc_" latex_document ${test_name})
				string(REPLACE "${latex_document}" "${latex_document}.tex" latex_document ${latex_document})
				message(STATUS "Add test pdflatex ${latex_document}")
				add_test("${test_name}_pdflatex" "${HNC_PDFLATEX_EXE}" "-interaction=nonstopmode" "${latex_document}")
			endif()
		endif()
		
	endforeach()


# Install
	# .hpp
	install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
	# .cmake
	install(FILES cmake/hnc-config.cmake DESTINATION lib/hnc)
	install(FILES cmake/hnc_boost_asio-config.cmake DESTINATION lib/hnc_boost_asio)
	install(FILES cmake/hnc_boost_mpi-config.cmake DESTINATION lib/hnc_boost_mpi)
	install(FILES cmake/hnc_boost_serialization-config.cmake DESTINATION lib/hnc_boost_serialization)
	install(FILES cmake/hnc_boost_system-config.cmake DESTINATION lib/hnc_boost_system)
	install(FILES cmake/hnc_compiler_mpi_cpp-config.cmake DESTINATION lib/hnc_compiler_mpi_cpp)
	install(FILES cmake/hnc_gnuplot_exe-config.cmake DESTINATION lib/hnc_gnuplot_exe)
	install(FILES cmake/hnc_linux-config.cmake DESTINATION lib/hnc_linux)
	install(FILES cmake/hnc_openssl-config.cmake DESTINATION lib/hnc_openssl)
	install(FILES cmake/hnc_pdflatex_exe-config.cmake DESTINATION lib/hnc_pdflatex_exe)
	install(FILES cmake/hnc_unix-config.cmake DESTINATION lib/hnc_unix)
	install(FILES cmake/hnc_windows-config.cmake DESTINATION lib/hnc_windows)
	# Doxygen
	if (IS_DIRECTORY doc/doxygen)
		install(DIRECTORY doc/doxygen DESTINATION share/hnc)
	endif()


# Little help
	message(STATUS "---")
	message(STATUS "You can execute:")
	message(STATUS "    make         # To compile hnc tests")
	message(STATUS "    make test    # To execute tests")
	message(STATUS "    make install # To install library, include and CMake module")
	message(STATUS "                 # If you need root access:")
	message(STATUS "                 #     sudo make install")
	message(STATUS "                 #     su -c \"make install\"")
	if (DOXYGEN_FOUND)
		message(STATUS "    make doxygen # To generate the Doxygen")
	endif()

	message(STATUS "---")
