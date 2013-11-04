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


# Try to find the hnc library

# HNC_FOUND       - System has hnc lib
# HNC_INCLUDE_DIR - The hnc include directory

# HNC_LIB_BOOST_SERIALIZATION
# HNC_LIB_BOOST_MPI
# HNC_MPICXX_COMPILER
# HNC_MPI_RUN
# HNC_LIB_BOOST_SYSTEM
# HNC_LIB_BOOST_ASIO
# HNC_LIB_SSL


if (HNC_INCLUDE_DIR AND HNC_LIB_BOOST_SERIALIZATION AND HNC_LIB_BOOST_MPI AND HNC_MPICXX_COMPILER AND HNC_LIB_BOOST_SYSTEM AND HNC_LIB_BOOST_ASIO AND HNC_LIB_SSL)
	# Already in cache, be silent
	set(HNC_FIND_QUIETLY TRUE)
endif()

find_path(HNC_INCLUDE_DIR NAMES hnc/hnc.hpp)
if (HNC_INCLUDE_DIR)
	message(STATUS "Library hnc found =) ${HNC_INCLUDE_DIR}")
else()
	message(STATUS "Library hnc not found :(")
endif()

find_package(Boost COMPONENTS serialization)
if (Boost_FOUND)
	set(HNC_LIB_BOOST_SERIALIZATION "${Boost_LIBRARIES}")
	message(STATUS "Library Boost.Serialization found =) ${HNC_LIB_BOOST_SERIALIZATION}")
else()
	message(STATUS "Library Boost.Serialization not found :(")
endif()

find_package(Boost COMPONENTS mpi serialization)
if (Boost_FOUND)
	# Boost.MPI and Boost.Serialization
	set(HNC_LIB_BOOST_MPI "${Boost_LIBRARIES}")
	message(STATUS "Libraries Boost.MPI and Boost.Serialization found =) ${HNC_LIB_BOOST_MPI}")
	# MPI compiler
	find_program(HNC_MPICXX_COMPILER NAMES mpic++ mpicxx mpiCC mpicc)
	if (HNC_MPICXX_COMPILER)
		message(STATUS "MPI C++ compiler found =) ${HNC_MPICXX_COMPILER}")
	else()
		message(STATUS "MPI C++ compiler not found :(")
	endif()
	# mpirun
	find_program(HNC_MPI_RUN NAMES mpirun)
	if (HNC_MPI_RUN)
		message(STATUS "mpirun executable found =) ${HNC_MPI_RUN}")
	else()
		message(STATUS "mpirun executable not found :(")
	endif()
else()
	message(STATUS "Libraries Boost.MPI and Boost.Serialization not found :(")
endif()

find_package(Boost COMPONENTS system)
if (Boost_FOUND)
	set(HNC_LIB_BOOST_SYSTEM "${Boost_LIBRARIES}")
	foreach(lib ${HNC_LIB_BOOST_MPI})
		string(REPLACE "${lib}" "" HNC_LIB_BOOST_SYSTEM ${HNC_LIB_BOOST_SYSTEM})
	endforeach()
	message(STATUS "Library Boost.System found =) ${HNC_LIB_BOOST_SYSTEM}")
else()
	message(STATUS "Library Boost.System not found :(")
endif()

if (HNC_LIB_BOOST_SYSTEM)
	find_file(HNC_LIB_BOOST_ASIO "boost/asio.hpp")
	if (HNC_LIB_BOOST_ASIO)
		message (STATUS "Library Boost.Asio found =) ${HNC_LIB_BOOST_ASIO}")
	else()
		message(STATUS "Library Boost.Asio not found :( (header boost/asio.hpp not found)")
	endif()
else()
	message(STATUS "Library Boost.Asio needs Boost.System :(")
endif()

find_package(OpenSSL)
if (OPENSSL_FOUND)
	set(HNC_LIB_SSL "${OPENSSL_LIBRARIES}")
	message(STATUS "Library OpenSSL found =) ${HNC_LIB_SSL}")
else()
	message(STATUS "Library OpenSSL not found :(")
endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(HNC DEFAULT_MSG HNC_INCLUDE_DIR HNC_LIB_BOOST_SERIALIZATION HNC_LIB_BOOST_MPI HNC_MPICXX_COMPILER HNC_MPI_RUN HNC_LIB_BOOST_SYSTEM HNC_LIB_BOOST_ASIO HNC_LIB_SSL)

mark_as_advanced(HNC_INCLUDE_DIR HNC_LIB_BOOST_SERIALIZATION HNC_LIB_BOOST_MPI HNC_MPICXX_COMPILER HNC_MPI_RUN HNC_LIB_BOOST_SYSTEM HNC_LIB_BOOST_ASIO HNC_LIB_SSL)
