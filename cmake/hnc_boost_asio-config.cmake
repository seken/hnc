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


# Try to find the Boost.Asio library

# HNC_BOOST_ASIO_FOUND       - System has Boost.Asio library
# HNC_BOOST_ASIO_INCLUDE_DIR - The Boost.Asio include directory

# HNC_NO_BOOST_ASIO_MACRO    - System has not Boost.Asio library


find_file(HNC_BOOST_ASIO_HPP "boost/asio.hpp")

set(HNC_NO_BOOST_ASIO_MACRO "hnc_no_boost_asio")

if (HNC_BOOST_ASIO_HPP)
	
	string(REPLACE "/asio.hpp" "" HNC_BOOST_ASIO_INCLUDE_DIR ${HNC_BOOST_ASIO_HPP})
	
	set(HNC_BOOST_ASIO_FOUND "TRUE")
	
	include_directories(${HNC_BOOST_ASIO_INCLUDE_DIR})
	
	message(STATUS "Library Boost.Asio found =) ${HNC_BOOST_ASIO_INCLUDE_DIR}")
	
else()
	
	set(HNC_BOOST_ASIO_FOUND "FALSE")
	
	add_definitions("-D${HNC_NO_BOOST_ASIO_MACRO}")
	
	message(STATUS "Library Boost.Asio not found :(")
	
endif()
