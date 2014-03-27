# Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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


# User's settings - C++ Flags
	
# 	set(release "TRUE")
	set(release "FALSE")

	# Release
	if (release)
		set(CMAKE_CXX_FLAGS "-O3 -DNDEBUG -march=native -fomit-frame-pointer -ffast-math")
	# Debug # valgrind --show-reachable=yes --leak-check=full -v exe
	else()
		set(CMAKE_CXX_FLAGS "-O0 -g3")
	endif()

# User's settings - General C++ Flags
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -std=c++11 -pedantic -fopenmp")

# Unix
if (UNIX)
	add_definitions("-DUNIX")
endif()


# Boost MPI
	message(STATUS "---")
	find_package(Boost COMPONENTS mpi serialization)
	if (Boost_FOUND)
		# Boost.MPI and Boost.Serialization
		set(boost_mpi_serialization "${Boost_LIBRARIES}")
		message(STATUS "Boost.MPI and Boost.Serialization found =) ${boost_mpi_serialization}")
		# MPI compiler
		find_program(MPICXX_COMPILER NAMES mpic++ mpicxx mpiCC mpicc)
		if (MPICXX_COMPILER)
			# Change the compiler
			message(STATUS "MPI C++ compiler found =) ${MPICXX_COMPILER}")
			set(CMAKE_CXX_COMPILER ${MPICXX_COMPILER})
		else()
			message(STATUS "MPI C++ compiler not found :(")
		endif()
		# mpirun
		find_program(mpirun_exe NAMES mpirun)
		if (mpirun_exe)
			message(STATUS "mpirun executable found =) ${mpirun_exe}")
		else()
			message(STATUS "mpirun executable not found :(")
		endif()
	else()
		message(STATUS "Boost.MPI and Boost.Serialization not found :(")
	endif()


# Boost System
	message(STATUS "---")
	find_package(Boost COMPONENTS system)
	if (Boost_FOUND)
		set(boost_system "${Boost_LIBRARIES}")
		foreach(lib ${boost_mpi_serialization})
			string(REPLACE "${lib}" "" boost_system ${boost_system})
		endforeach()
		message(STATUS "Boost.System found =) ${boost_system}")
	else()
		message(STATUS "Boost.System not found :(")
	endif()


# Boost Asio
	message(STATUS "---")
	if (boost_system)
		find_file(boost_asio "boost/asio.hpp")
		if (boost_asio)
			message (STATUS "Boost.Asio found =) ${boost_asio}")
		else()
			message(STATUS "Boost.Asio not found :( (header boost/asio.hpp not found)")
		endif()
	else()
		message(STATUS "Boost.Asio needs Boost.System :(")
	endif()


# OpenSSL
	message(STATUS "---")
	find_package(OpenSSL)
	if (OPENSSL_FOUND)
		message(STATUS "OpenSSL found =) ${OPENSSL_LIBRARIES}")
	else()
		message(STATUS "OpenSSL not found :(")
	endif()


# Gnuplot
	message(STATUS "---")
	find_program(Gnuplot_exe NAMES gnuplot)
	if (Gnuplot_exe)
		message(STATUS "gnuplot executable found =) ${Gnuplot_exe}")
	else()
		message(STATUS "gnuplot executable not found :(")
	endif()


# LaTeX
	message(STATUS "---")
	find_program(pdflatex_exe NAMES pdflatex)
	if (pdflatex_exe)
		message(STATUS "pdflatex executable found =) ${pdflatex_exe}")
	else()
		message(STATUS "pdflatex executable not found :(")
	endif()


# Include directories (to use #include <> instead of #include "")

	# hnc
	message(STATUS "---")
	set(hnc_INCLUDE "./include")
	message(STATUS "Include hnc = ${hnc_INCLUDE}")
	include_directories("${hnc_INCLUDE}")


# Build hnc doxygen

	message(STATUS "---")
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		message(STATUS "Doxygen found =)")
		add_custom_target(
			doc
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
	if (release)
		message(STATUS "Mode Release")
	else()
		message(STATUS "Mode Debug")
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
			if (boost_mpi_serialization AND MPICXX_COMPILER)
				add_executable(${test_name} "${test_source}")
				target_link_libraries(${test_name} ${boost_mpi_serialization})
				add_test(${test_name} ${test_name})
			endif()
			if (mpirun_exe)
				add_test("${test_name}_with_mpirun_np_4" "${mpirun_exe}" "-np" "4" "${test_name}")
			endif()
			
			# without
			add_executable("${test_name}_without_mpi" "${test_source}")
			set_target_properties("${test_name}_without_mpi" PROPERTIES COMPILE_FLAGS "-DNO_HNC_Boost_Serialization -DNO_HNC_Boost_MPI")
			message(STATUS "Add test ${test_name}_without_mpi")
			add_test("${test_name}_without_mpi" "${test_name}_without_mpi")
			
		# Compilation with OpenSSL
		elseif ("${test_name}" MATCHES ".*test__ssl.*")
		
			# With OpenSSL
			if (OPENSSL_FOUND)
				add_executable(${test_name} "${test_source}")
				target_link_libraries(${test_name} ${OPENSSL_LIBRARIES})
				add_test(${test_name} "${test_name}")
			endif()
			
			# Without OpenSSL
			add_executable("${test_name}_without_ssl" "${test_source}")
			set_target_properties("${test_name}_without_ssl" PROPERTIES COMPILE_FLAGS "-DNO_HNC_SSL")
			message(STATUS "Add test ${test_name}_without_ssl")
			add_test("${test_name}_without_ssl" "${test_name}_without_ssl")
			
		# Compilation with Boost.Asio
		elseif (("${test_name}" STREQUAL "test__http") OR ("${test_name}" STREQUAL "test__http_get") OR ("${test_name}" STREQUAL "test__http_w3c_validator") OR ("${test_name}" STREQUAL "test__html_head") OR ("${test_name}" STREQUAL "test__html_webpage") OR ("${test_name}" MATCHES "test__tabular.*"))
		
			# With Boost.Asio
			if (boost_asio)
				add_executable(${test_name} "${test_source}")
				target_link_libraries(${test_name} ${boost_system})
				add_test(${test_name} "${test_name}")
			endif()
			
			# Without Boost.Asio
			add_executable("${test_name}_without_boost_asio" "${test_source}")
			set_target_properties("${test_name}_without_boost_asio" PROPERTIES COMPILE_FLAGS "-DNO_HNC_Boost_Asio")
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
			if (Gnuplot_exe)
				string(REPLACE "test__" "hnc_" gnuplot_script ${test_name})
				string(REPLACE "${gnuplot_script}" "${gnuplot_script}.png.gnuplot" gnuplot_script ${gnuplot_script})
				message(STATUS "Add test gnuplot ${gnuplot_script}")
				add_test("${test_name}_gnuplot" "${Gnuplot_exe}" "${gnuplot_script}")
			endif()
		endif()
		
		# Add a LaTeX check
		if (("${test_name}" MATCHES ".*test__latex_.*") OR ("${test_name}" MATCHES "test__tabular.*"))
			if (pdflatex_exe)
				string(REPLACE "test__" "hnc_" latex_document ${test_name})
				string(REPLACE "${latex_document}" "${latex_document}.tex" latex_document ${latex_document})
				message(STATUS "Add test pdflatex ${latex_document}")
				add_test("${test_name}_pdflatex" "${pdflatex_exe}" "-interaction=nonstopmode" "${latex_document}")
			endif()
		endif()
		
	endforeach()


# Install

	install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
	install(FILES hnc-config.cmake DESTINATION lib/hnc)
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
		message(STATUS "    make doc     # To generate the Doxygen")
	endif()

	message(STATUS "---")
