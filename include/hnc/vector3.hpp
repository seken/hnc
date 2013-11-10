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


#ifndef HNC_VECTOR3_HPP
#define HNC_VECTOR3_HPP

#include <iostream>


namespace hnc
{
	/// @brief Container for 3 values (x, y and z)
	template <class T>
	class vector3
	{
	public:

		/// x
		T x;

		/// y
		T y;

		/// z
		T z;

		/**
		 * @brief Constructor
		 * 
		 * @param x
		 * @param y
		 * @param z
		 */
		explicit vector3<T>(T const & x = T(), T const & y = T(), T const & z = T()) :
			x(x), y(y), z(z)
		{ }

		/**
		 * @brief Equality operator
		 * 
		 * @param[in] v A hnc::vector3
		 * 
		 * @return true if hnc::vector3 have same values
		 */
		bool operator==(vector3 const & v) const { return (x == v.x && y == v.y && z == v.z); }

		/**
		 * @brief Inequality operator
		 * 
		 * @param[in] v A hnc::vector3
		 * 
		 * @return true if hnc::vector3 have different values
		 */
		bool operator!=(vector3 const & v) const { return (! ((*this) == v)); }
	};
}

/**
 * @brief Display a hnc::vector3
 *
 * @param[in,out] o Out stream
 * @param[in]     v A hnc::vector3
 *
 * @return the out stream
 */
template <class T>
std::ostream & operator << (std::ostream & o, hnc::vector3<T> const & v)
{
	o << "{" << v.x << ", " << v.y << ", " << v.z << "}";
	return o;
}

#endif
