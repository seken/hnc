// Copyright © 2012-2014 Lénaïc Bagnères, hnc@singularity.fr

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
#include <iomanip>
#include <ios>


namespace hnc
{
	/**
	 * @brief Convert the input into a std::string with a std::ostringstream
	 *
	 * @code
	   #include <hnc/to_string.hpp>
	   @endcode
	 *
	 * @param[in] in The input
	 * @param[in] o  A std::ostringstream
	 *
	 * @return the converted input into a std::string
	 */
	template <class T, class ... iomanip_list_t>
	std::string to_string(T const & in, std::ostringstream & o)
	{
		// Fill the stream
		o << in;
		
		// Output the stream in string
		return (o.str());
	}
	
	/**
	 * @brief Convert the input into a std::string with a std::ostringstream and iomanip
	 *
	 * @code
	   #include <hnc/to_string.hpp>
	   @endcode
	 *
	 * @param[in] in       The input
	 * @param[in] o        A std::ostringstream
	 * @param[in] iomanip  A iomanip (like std::boolalpha, std::hex)
	 * @param[in] iomanips Others iomanip
	 *
	 * @return the converted input into a std::string
	 */
	template <class T, class iomanip_t, class ... iomanips_t>
	std::string to_string(T const & in, std::ostringstream & o, iomanip_t const & iomanip, iomanips_t const & ... iomanips)
	{
		o << iomanip;
		return hnc::to_string(in, o, iomanips...);
	}
	
	/**
	 * @brief Convert the input into a std::string with iomanip
	 *
	 * @code
	   #include <hnc/to_string.hpp>
	   @endcode
	 *
	 * @param[in] in       The input
	 * @param[in] iomanips Some iomanip (like std::boolalpha, std::hex)
	 *
	 * @return the converted input into a std::string
	 */
	template <class T, class ... iomanips_t>
	std::string to_string(T const & in, iomanips_t const & ... iomanips)
	{
		// Declare a stream
		std::ostringstream o;
		o << std::setprecision(std::numeric_limits<T>::digits10 + 1);
		
		return hnc::to_string(in, o, iomanips...);
	}

	// Specialization for std::string
	std::string to_string(std::string const & in)
	{
		return in;
	}

	// Specialization for char const * const
	std::string to_string(char const * const in)
	{
		return std::string(in);
	}
}

#endif
