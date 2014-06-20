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


# Determine if platform is OS X or not

# HNC_OS_X_FOUND - Platform is OS X
# HNC_OS_X_MACRO - Macro to define


set(HNC_OS_X_MACRO "hnc_os_x")

if (APPLE AND ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	
	set(HNC_OS_X_FOUND "TRUE")
	
	add_definitions("-D${HNC_OS_X_MACRO}")
	
	message(STATUS "Platform is OS X :(")
	
else()
	
	set(HNC_UNIX_FOUND "FALSE")
	
	message(STATUS "Platform is not OS X =)")
	
endif()
