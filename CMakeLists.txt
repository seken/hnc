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
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11 -pedantic -fopenmp")

	
# Boost MPI

	find_package(Boost COMPONENTS mpi serialization)
	if (Boost_FOUND)
		# Boost.MPI and Boost.Serialization
		set(boost_mpi_serialization "${Boost_LIBRARIES}")
		message(STATUS "Boost.MPI and Boost.Serialization found :) ${boost_mpi_serialization}")
		# MPI compiler
		find_program(MPICXX_COMPILER NAMES mpic++ mpicxx mpiCC mpicc)
		if (MPICXX_COMPILER)
			# Change the compiler
			message(STATUS "MPI C++ compiler found = ${MPICXX_COMPILER}")
			set(CMAKE_CXX_COMPILER ${MPICXX_COMPILER})
		else()
			message(STATUS "MPI C++ compiler not found :(")
		endif()
		# MPI run
		find_program(MPIRUN_EXE NAMES mpirun)
		if (MPIRUN_EXE)
			message(STATUS "mpirun executable found = ${MPIRUN_EXE}")
		else()
			message(STATUS "mpirun executable not found :(")
		endif()
	else()
		message(STATUS "Boost.MPI and Boost.Serialization not found :(")
	endif()


# Include directories (to use #include <> instead of #include "")

	# hnc
	set(hnc_INCLUDE "./include")
	message(STATUS "Include hnc = ${hnc_INCLUDE}")
	include_directories("${hnc_INCLUDE}")


# Build hnc doxygen

	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		add_custom_target(
			doc
			${DOXYGEN_EXECUTABLE}
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${hnc_INCLUDE}/hnc"
			COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
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

	foreach(test ${tests})
		string(REPLACE ".cpp" "" test ${test})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/tests/" "" test ${test})
		message(STATUS "Add test tests/${test}")
		# Executable MPI
		if ("${test}" MATCHES ".*test__.*mpi.*")
			# with Boost.MPI
			if (boost_mpi_serialization AND MPICXX_COMPILER)
				add_executable(${test} "tests/${test}.cpp")
				target_link_libraries(${test} ${boost_mpi_serialization})
				add_test(${test} "${test}")
			endif()
			if (MPIRUN_EXE)
				add_test("${test}_with_mpirun_np_4" "${MPIRUN_EXE}" "-np" "4" "${test}")
			endif()
			# without
			add_executable("${test}_without_mpi" "tests/${test}.cpp")
			set_target_properties("${test}_without_mpi" PROPERTIES COMPILE_FLAGS "-DNO_HNC_Boost_Serialization -DNO_HNC_Boost_MPI")
			message(STATUS "Add test tests/${test}_without_mpi")
			add_test("${test}_without_mpi" "${test}_without_mpi")
		# Executable
		else()
			# Executable
			add_executable(${test} "tests/${test}.cpp")
			# Test with args
			if ("${test}" STREQUAL "test__args")
				add_test(${test} "${test}" "--opt" "--int" "42" "--float" "3.14" "--ints" "21" "42" "73" "--types" "this is a" "tuple" "with" "5" "elements")
			elseif (${test} STREQUAL "test__args_without_argument")
				add_test(${test} "${test}" "--opt0" "--option1" "--opt3")
			elseif (${test} STREQUAL "test__args_with_one_argument")
				add_test(${test} "${test}" "--n" "21" "--M" "42" "--u" "--V" "--c" "c" "--W" "word" "--s" "A few words is a sentence")
			elseif (${test} STREQUAL "test__args_with_same_type_arguments")
				add_test(${test} "${test}" "--n" "21" "42" "73" "--x_y" "800" "600" "--U" "21" "--v" "--C" "d" "e" "f")
			elseif (${test} STREQUAL "test__args_with_different_type_arguments")
				add_test(${test} "${test}" "--n" "21" "42" "73" "--x_y" "800" "600" "--U" "21" "--v" "--C" "d" "e" "f" "--t" "42" "One word" "c" "1" "--i" "21" "--A" "b")
			# Test
			else()
				add_test(${test} "${test}")
			endif()
		endif()
	endforeach()

	# Visual tests

	file(
		GLOB_RECURSE
		tests
		tests_visual/*.cpp
	)

	foreach(test ${tests})
		string(REPLACE ".cpp" "" test ${test})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/tests_visual/" "" test ${test})
		message(STATUS "Add visual test tests_visual/${test}")
		add_executable(${test} "tests_visual/${test}.cpp")
		add_test(${test} "${test}")
	endforeach()

	# Human tests

	file(
		GLOB_RECURSE
		tests
		tests_human/*.cpp
	)

	foreach(test ${tests})
		string(REPLACE ".cpp" "" test ${test})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/tests_human/" "" test ${test})
		message(STATUS "Add human test tests_human/${test}")
		add_executable(${test} "tests_human/${test}.cpp")
	endforeach()


# Install

	install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
	install(FILES hnc-config.cmake DESTINATION lib/hnc)


# Little help

	message(STATUS "---")
	message(STATUS "You can execute:")
	message(STATUS "    make         # To compile hnc tests")
	message(STATUS "    make test    # To execute tests")
	message(STATUS "    make install # To install library, include and CMake module")
	message(STATUS "                 # If you need root access:")
	message(STATUS "                 #     sudo make install")
	message(STATUS "                 #     su -c \"make install\"")
	message(STATUS "    make doc     # To generate the Doxygen")

	message(STATUS "---")
