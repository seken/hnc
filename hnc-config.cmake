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


if (HNC_INCLUDE_DIR)
	# Already in cache, be silent
	set(HNC_FIND_QUIETLY TRUE)
endif()

find_path(HNC_INCLUDE_DIR NAMES hnc/hnc.hpp)

if (HNC_INCLUDE_DIR)
	message(STATUS "Library hnc found =) ${HNC_INCLUDE_DIR}")
else()
	message(STATUS "Library hnc not found =(")
endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(HNC DEFAULT_MSG HNC_INCLUDE_DIR)

mark_as_advanced(HNC_INCLUDE_DIR)
