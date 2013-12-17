// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_CLONE_HPP
#define HNC_CLONE_HPP

#include "sfinae.hpp"


namespace hnc
{
	/// @brief is not cloneable
	template <class T, class sfinae_valid_type = void>
	class is_cloneable : public std::false_type
	{ };
	
	/// @brief is cloneable
	template <class T>
	class is_cloneable<T, typename this_type<decltype(std::declval<T&>().clone())>::is_valid> : public std::true_type
	{ };
}

namespace hnc
{
	/// @brief Clone the object with copy constructor
	/// @param[in] t   An object
	/// @param[in] tag std::false_type
	/// @return a clone of the object
	template <class T>
	T clone(T const & v, std::false_type const /*tag*/)
	{
		return T(v);
	}
	
	template <class T>
	auto clone(T const & v, std::true_type const /*tag*/) -> decltype(v.clone())
	{
		return v.clone();
	}
	
	/// @brief Clone the object with .clone() method
	/// @param[in] t   An object
	/// @param[in] tag std::true_type
	/// @return a clone of the object
	template <class T>
	auto clone(T const & v) -> decltype(hnc::clone(v, hnc::is_cloneable<T>()))
	{
		return hnc::clone(v, hnc::is_cloneable<T>());
	}
}

#endif
