// Copyright © 2012,2013 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_TO_STRING_HPP
#define HNC_TO_STRING_HPP

#include <string>
#include <sstream>
#include <limits>


namespace hnc
{
	/**
	 * @brief Convert the input into a std::string
	 *
	 * @code
	 * #include <hnc/to_string.hpp>
	 * @endcode
	 * 
	 * We use a std::ostringstream to do the conversion @n
	 * We use full precision of the input @n
	 *
	 * @param[in] in The input
	 *
	 * @return the converted input into a std::string
	 */
	template <class T>
	std::string to_string(T const & in)
	{
		// Declare a stream
		std::ostringstream o;
		o.precision(std::numeric_limits<T>::digits10 + 1);
		// Fill the stream
		o << in;
		// Output the stream in string
		return (o.str());
	}

	std::string to_string(std::string const & in)
	{
		return in;
	}

	std::string to_string(char const * const in)
	{
		return std::string(in);
	}
}

#endif
