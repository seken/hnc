// Copyright © 2013, 2014 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_STRING_HPP
#define HNC_STRING_HPP

#include <string>


/**
 * @brief std::string literal
 * 
 * @code
   "Hello world!"_s // string, not "zero-terminated array of char"
   @endcode
 *
 * http://www.stroustrup.com/C++11FAQ.html#UD-literals
 */
std::string operator"" _s(char const * p, std::size_t const n)
{
	return std::string(p, n);
}


namespace hnc
{
	/**
	 * @brief Functions on string
	 *
	 * @code
	   #include <hnc/string.hpp>
	   @endcode
	 */
	namespace string
	{
		// For Doxygen only
	}
}

#endif
