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


#ifndef HNC_OPTIONAL_HPP
#define HNC_OPTIONAL_HPP

#include <iostream>
#include <stdexcept>


namespace hnc
{
	/**
	 * @brief hnc::optional of T contains the value or not
	 * 
	 * @code
	   #include <hnc/optional.hpp>
	   @endcode
	 * 
	 * Even if the value is not present, the value exists with the default value. @n
	 * If you want not this, use hnc::optional_ptr of T
	 * 
	 * @note Consider std::optional (maybe for C++17) and boost::optional
	 */
	template <class T>
	class optional
	{
	private:
		
		/// True if value exists, false otherwise
		bool m_is_present;
		
		/// Value
		T m_value;
		
	public:
		
		/// @brief Constructor by default
		optional() : m_is_present(false), m_value() { }
		
		/// @brief Constructor
		/// @param[in] value Value
		optional(T const & value) : m_is_present(true), m_value(value) { }
		
		/// @brief Operator bool
		/// @return true is the value is present, false otherwise
		constexpr explicit operator bool() const { return m_is_present; }
		
		/// @brief Get the value
		/// @pre The value must be present
		/// @return the value
		T & value()
		{
			#ifndef NDEBUG
			if (m_is_present == false) { throw std::out_of_range("value is not present in hnc::optional<T>"); }
			#endif
			return m_value;
		}
		
		/// @brief Get const access to the value
		/// @pre The value must be present
		/// @return a const access to the value
		T const & value() const
		{
			#ifndef NDEBUG
			if (m_is_present == false) { throw std::out_of_range("value is not present in hnc::optional<T>"); }
			#endif
			return m_value;
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
	
	/// @brief Operator << between a std::ostream and a hnc::optional<T>
	/// @param[in,out] o        Output stream
	/// @param[in]     optional A hnc::optional<T>
	/// @return the output stream
	template <class T>
	std::ostream & operator << (std::ostream & o, hnc::optional<T> const & optional)
	{
		if (optional) { o << "{ " << *optional << " }"; }
		else { o << "{}"; }
		
		return o;
	}
}

#endif
