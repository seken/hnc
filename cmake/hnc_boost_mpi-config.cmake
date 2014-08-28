# Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

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


# Try to find the Boost.MPI library

# HNC_BOOST_MPI_FOUND       - System has Boost.MPI library
# HNC_BOOST_MPI_INCLUDE_DIR - The Boost.MPI include directory
# HNC_BOOST_MPI_LIBRARY     - Library needed to use Boost.MPI

# HNC_NO_BOOST_MPI_MACRO    - System has not Boost.MPI library


find_package(Boost COMPONENTS mpi)

set(HNC_NO_BOOST_MPI_MACRO "hnc_no_boost_mpi")

if (Boost_FOUND AND NOT CMAKE_HNC_NO_MPI STREQUAL "FALSE")
	
	set(HNC_BOOST_MPI_FOUND "TRUE")
	set(HNC_BOOST_MPI_INCLUDE_DIR "${Boost_INCLUDE_DIR}")
	set(HNC_BOOST_MPI_LIBRARY "${Boost_LIBRARIES}")
	
	include_directories(${HNC_BOOST_MPI_INCLUDE_DIR})
	
	message(STATUS "Library Boost.MPI found =) ${HNC_BOOST_MPI_INCLUDE_DIR} | ${HNC_BOOST_MPI_LIBRARY}")
	
else()
	
	set(HNC_BOOST_MPI_FOUND "FALSE")
	
	add_definitions("-D${HNC_NO_BOOST_MPI_MACRO}")
	
	if (NOT CMAKE_HNC_NO_MPI STREQUAL "FALSE")
	
		message(STATUS "Library Boost.MPI not found :(")
	
	else()
	
		message(STATUS "MPI is disable by CMAKE_HNC_NO_MPI=FALSE")
	
	endif()
	
endif()
