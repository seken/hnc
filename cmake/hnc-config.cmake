# Copyright © 2012-2014 Lénaïc Bagnères, hnc@singularity.fr

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

# HNC_FOUND       - System has hnc library
# HNC_INCLUDE_DIR - The hnc include directory

# See other lib/hnc_*/*.cmake files for other variables


find_file(HNC_INCLUDE_DIR "hnc/hnc.hpp")

if (HNC_INCLUDE_DIR)
	
	set(HNC_FOUND "TRUE")
	
	message(STATUS "Library hnc found =) ${HNC_INCLUDE_DIR}")
	
else()
	
	set(HNC_FOUND "FALSE")
	
	message(STATUS "Library hnc not found :(")
	
endif()


find_package(hnc_unix)

find_package(hnc_linux)

find_package(hnc_os_x)

find_package(hnc_windows)

find_package(hnc_boost_serialization)

find_package(hnc_boost_system)

find_package(hnc_boost_mpi)

find_package(hnc_compiler_mpi_cpp)

find_package(hnc_boost_asio)

find_package(hnc_openssl)

find_package(hnc_gnuplot_exe)

find_package(hnc_pdflatex_exe)
