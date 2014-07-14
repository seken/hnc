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


# Try to find the Boost.Serialization library

# HNC_BOOST_SERIALIZATION_FOUND       - System has Boost.Serialization library
# HNC_BOOST_SERIALIZATION_INCLUDE_DIR - The Boost.Serialization include directory
# HNC_BOOST_SERIALIZATION_LIBRARY     - Library needed to use Boost.Serialization

# HNC_NO_BOOST_SERIALIZATION_MACRO    - System has not Boost.Serialization library


find_package(Boost COMPONENTS serialization)

set(HNC_NO_BOOST_SERIALIZATION_MACRO "hnc_no_boost_serialization")

if (Boost_FOUND)
	
	set(HNC_BOOST_SERIALIZATION_FOUND "TRUE")
	set(HNC_BOOST_SERIALIZATION_INCLUDE_DIR "${Boost_INCLUDE_DIR}")
	set(HNC_BOOST_SERIALIZATION_LIBRARY "${Boost_LIBRARIES}")
	
	include_directories(${HNC_BOOST_SERIALIZATION_INCLUDE_DIR})
	
	message(STATUS "Library Boost.Serialization found =) ${HNC_BOOST_SERIALIZATION_INCLUDE_DIR} | ${HNC_BOOST_SERIALIZATION_LIBRARY}")
	
else()
	
	set(HNC_BOOST_SERIALIZATION_FOUND "FALSE")
	
	add_definitions("-D${HNC_NO_BOOST_SERIALIZATION_MACRO}")
	
	message(STATUS "Library Boost.Serialization not found :(")
	
endif()
