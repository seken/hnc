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


# Try to find the Boost.Sytem library

# HNC_BOOST_SYSTEM_FOUND       - System has Boost.Sytem library
# HNC_BOOST_SYSTEM_INCLUDE_DIR - The Boost.Sytem include directory
# HNC_BOOST_SYSTEM_LIBRARY     - Library needed to use Boost.Sytem

# HNC_NO_BOOST_SYSTEM_MACRO    - System has not Boost.System library


find_package(Boost COMPONENTS system)

set(HNC_NO_BOOST_SYSTEM_MACRO "hnc_no_boost_system")

if (Boost_FOUND)
	
	set(HNC_BOOST_SYSTEM_FOUND "TRUE")
	set(HNC_BOOST_SYSTEM_INCLUDE_DIR "${Boost_INCLUDE_DIR}")
	set(HNC_BOOST_SYSTEM_LIBRARY "${Boost_LIBRARIES}")
	
	include_directories(${HNC_BOOST_SYSTEM_INCLUDE_DIR})
	
	message(STATUS "Library Boost.Sytem found =) ${HNC_BOOST_SYSTEM_INCLUDE_DIR} | ${HNC_BOOST_SYSTEM_LIBRARY}")
	
else()
	
	set(HNC_BOOST_SYSTEM_FOUND "FALSE")
	
	add_definitions("-D${HNC_NO_BOOST_SYSTEM_MACRO}")
	
	message(STATUS "Library Boost.Sytem not found :(")
	
endif()
