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


#ifndef HNC_TO_INT_HPP
#define HNC_TO_INT_HPP

#include <hnc/to_type.hpp>


namespace hnc
{
	/**
	 * @brief Convert the input into a int
	 *
	 * @code
	 * #include <hnc/to_int.hpp>
	 * @endcode
	 * 
	 * @param[in] in The input
	 * 
	 * @return the converted input into a int
	 */
	template <class T>
	int to_int(T const & in)
	{ return hnc::to_<int>(in); }
}

#endif
