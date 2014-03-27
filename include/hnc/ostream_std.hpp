// Copyright © 2012, 2014 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_OSTREAM_STD_HPP
#define HNC_OSTREAM_STD_HPP

#include <iostream>
#include <tuple>
#include <map>


namespace std
{
	/**
	 * @brief Display a container like std::vector, std::list
	 *
	 * @code
	  #include <hnc/ostream_std.hpp>
	  @endcode
	 *
	 * @param[in,out] o Output stream
	 * @param[in]     c A std container
	 *
	 * @return the output stream
	 */
	template <class T, template <class, class Alloc = std::allocator<T>> class container>
	std::ostream & operator<<(std::ostream & o, container<T> const & c)
	{
		o << "{";
			// Display data
			for (T const & e : c)
			{
				if (&e != &c.front()) { o << ", "; }
				o << e;
			}
		o << "}";
		
		// Return stream
		return o;
	}

	/**
	 * @brief Display a std::map
	 *
	 * @code
	   #include <hnc/ostream_std.hpp>
	   @endcode
	 *
	 * @param[in,out] o   Output stream
	 * @param[in]     map A std::map
	 *
	 * @return the output stream
	 */
	template <class key_t, class value_t>
	std::ostream & operator<<(std::ostream & o, std::map<key_t, value_t> const & map)
	{
		o << "{";
		
		for (auto key_value_it = map.begin(); key_value_it != map.end(); ++key_value_it)
		{
			key_t const & key = key_value_it->first;
			value_t const & value = key_value_it->second;
			
			if (key_value_it != map.begin()) { o << ", "; }
			o << key << ": " << value;
		}
		
		o << "}";
		
		return o;
	}

	namespace
	{
		// Compile-time counter
		template <std::size_t>
		class static_int_counter { };

		// Print n elements of a tuple
		template <class tuple, std::size_t n>
		void print_tuple(std::ostream & o, tuple const & t, static_int_counter<n>)
		{
			print_tuple(o, t, static_int_counter<n - 1>());
			o << ", " << std::get<n>(t);
		}

		// Print last element of a tuple
		template <class tuple>
		void print_tuple(std::ostream & o, tuple const & t, static_int_counter<0>)
		{
			o << std::get<0>(t);
		}
	}

	/**
	 * @brief Display a std::tuple
	 *
	 * @code
	   #include <hnc/ostream_std.hpp>
	   @endcode
	 * 
	 * @param[in,out] o Output stream
	 * @param[in]     t A std::tuple
	 *
	 * @return the output stream
	 */
	template <class... T>
	std::ostream & operator<<(std::ostream & o, std::tuple<T...> const & t)
	{
		o << "(";
		print_tuple(o, t, static_int_counter<sizeof...(T) - 1>());
		o << ")";
		return o;
	}
}

#endif
