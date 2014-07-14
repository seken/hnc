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


# Try to find the OpenSSL library

# HNC_OPENSSL_FOUND       - System hasOpenSSL library
# HNC_OPENSSL_INCLUDE_DIR - The OpenSSL include directory
# HNC_OPENSSL_LIBRARY     - Library needed to use OpenSSL

# HNC_NO_OPENSSL_MACRO    - System has not OpenSSL library


find_package(OpenSSL)

set(HNC_NO_OPENSSL_MACRO "hnc_no_openssl")

if (OPENSSL_FOUND)
	
	set(HNC_OPENSSL_FOUND "TRUE")
	set(HNC_OPENSSL_INCLUDE_DIR "${OPENSSL_INCLUDE_DIR}")
	set(HNC_OPENSSL_LIBRARY "${OPENSSL_LIBRARIES}")
	
	include_directories(${HNC_OPENSSL_INCLUDE_DIR})
	
	message(STATUS "Library OpenSSL found =) ${HNC_OPENSSL_INCLUDE_DIR} | ${HNC_OPENSSL_LIBRARY}")
	
else()
	
	set(HNC_OPENSSL_FOUND "FALSE")
	
	add_definitions("-D${HNC_NO_OPENSSL_MACRO}")
	
	message(STATUS "Library OpenSSL not found :(")
	
endif()
