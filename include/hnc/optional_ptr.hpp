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


#ifndef HNC_OPTIONAL_PTR_HPP
#define HNC_OPTIONAL_PTR_HPP

#include <iostream>

#include "copy_ptr.hpp"


namespace hnc
{
	/**
	 * @brief hnc::optional_ptr of T contains the value or not
	 * 
	 * If the value is not present, the value does not exist. @n
	 * If you want not this, use hnc::optional of T
	 * 
	 * @note Consider std::optional (maybe for C++17) and boost::optional
	 */
	template <class T>
	class optional_ptr : private hnc::copy_ptr<T>
	{
	public:
		
		/// @brief Constructor by default
		optional_ptr() : hnc::copy_ptr<T>() { }
		
		/// @brief Constructor
		/// @param[in] value Value
		optional_ptr(T const & value) : hnc::copy_ptr<T>(hnc::clone_to_unique_ptr(value).release())
		{  }
		
		/// @brief Copy constrcutor
		/// @param[in] value Value
		optional_ptr(hnc::optional_ptr<T> const & value) :
			hnc::copy_ptr<T>((value) ? hnc::clone_to_unique_ptr(*value).release() : std::unique_ptr<T>().release())
		{ }
		
		/// @brief Operator bool
		/// @return true is the value is present, false otherwise
		constexpr explicit operator bool() const { return hnc::copy_ptr<T>::operator bool(); }
		
		/// @brief Get the value
		/// @pre The value must be present
		/// @return the value
		T & value()
		{
			#ifndef NDEBUG
			if (bool(*this) == false) { throw std::out_of_range("value is not present in hnc::optional_ptr<T>"); }
			#endif
			return hnc::copy_ptr<T>::operator*();
		}
		
		/// @brief Get const access to the value
		/// @pre The value must be present
		/// @return a const access to the value
		T const & value() const
		{
			#ifndef NDEBUG
			if (bool(*this) == false) { throw std::out_of_range("value is not present in hnc::optional_ptr<T>"); }
			#endif
			return hnc::copy_ptr<T>::operator*();
		}
		
		/// @brief Get the value
		/// @pre The value must be present
		/// @return the value
		T & operator*() { return value(); }

		/// @brief Get const access to the value
		/// @pre The value must be present
		/// @return a const access to the value
		T const & operator*() const { return value(); }
		
		/// @brief Get the value
		/// @pre The value must be present
		/// @return the value
		T * operator ->() { return &value(); }

		/// @brief Get const access to the value
		/// @pre The value must be present
		/// @return a const access to the value
		T const * operator ->() const { return &value(); }
	};
}

/**
 * @brief Display a hnc::optional_ptr of T
 *
 * @param[in,out] o Out stream
 * @param[in]     v A hnc::optional_ptr of T
 *
 * @return the out stream
 */
template <class T>
std::ostream & operator << (std::ostream & o, hnc::optional_ptr<T> const & v)
{
	if (v) { o << "{ " << *v << " }"; }
	else { o << "{}"; }
	
	return o;
}

#endif
