// Copyright © 2012, 2013 Lénaïc Bagnères, hnc@singularity.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef HNC_HPP
#define HNC_HPP

#include <string>


/*! @mainpage hnc https://gitorious.org/hnc
 *
 * @section section_introduction Introduction
 *
 * Basic (but useful) C++11 header-only library
 * 
 * Files can be under different licenses, see the header of a file to know its license and copyright.
 * List of the licenses actually used:
 * - Apache License, Version 2.0
 * - GNU Affero General Public License 3+
 * 
 * @section section_system_requirement System requirement for hnc
 * 
 * hnc uses CMake build system.
 * 
 * The required packages are:
 * build-essential cmake git doxygen
 * 
 * The optional packages (but recommended) are:
 * libssl-dev gnuplot libboost-all-dev libboost-mpi-dev
 * 
 * @section section_installation Installation of hnc
 * 
 * @subsection subsection_installation_with_cmake With CMake
 * 
 * Your C++ compiler must support common features of C++11
 * GCC 4.7 works (GCC 4.7.2 is in Debian Wheezy)
 * 
 * Use CMake to build hnc:
 * mkdir build
 * cd build
 * cmake .. #-DCMAKE_INSTALL_PREFIX=/path/to/install/hnc
 * make
 * # make doc
 * # make test
 * make install # su -c "make install" # sudo make install
 * 
 * @subsection subsection_installation_without_cmake Without CMake
 * 
 * hnc is an header-only library, you can copy the include directory in /usr/local or in your project.
 * 
 */


/// @brief hnc is a little (but useful) C++11 header-only
namespace hnc
{
	/// Version of hnc
	std::string version() { return "0.0.0"; }

	/// Codename of hnc
	std::string codename() { return "hope ;)"; }
}

#endif
