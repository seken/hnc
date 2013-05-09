// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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


/*! @mainpage A C++11 header only library
 *
 * @section section_introduction Introduction
 *
 * hnc is a C++11 header only library.
 *
 * TODO why hnc ?
 *
 * To use hnc, you only need a C++11 compiler like GCC 4.7
 *
 * @n
 *
 *
 * @section section_decription Description
 *
 * hnc contains ... TODO
 *
 * @n
 *
 *
 * @section section_get_hnc Get hnc
 *
 * @section section_download Download
 *
 * You can get the last development version: @n
 * TODO
 *
 * Release: @n
 * TODO
 *
 * Old release: @n
 * TODO
 *
 * @section section_building_and_installation Building & Installation
 *
 * hnc is a header only library, you have nothing to build to use hnc !
 *
 * hnc contains many tests and a doxygen documentation, use CMake in a terminal:
 * @code
 * mkdir build
 * cd build
 * make
 * make test
 * make doc
 * make install
 * @endcode
 *
 * @section section_manual_installation Manual installation
 *
 * TODO
 *
 * @section section_local_installation Local installation
 *
 * TODO
 *
 * @n
 *
 *
 * @section section_getting_use_hnc Use hnc
 *
 * TODO
 *
 * @section section_getting_started Getting started
 *
 * TODO
 *
 * @n
 *
 *
 * @section section_bug Bug
 *
 * TODO
 *
 * @n
 *
 *
 * @section section_licence Licence
 *
 * TODO
 *
 * @n
 *
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
