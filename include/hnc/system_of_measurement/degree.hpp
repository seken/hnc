// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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


/**
 * @file
 * @brief Just for std::ostream & operator<<(std::ostream & o, hnc::degree<T> const & angle_degree)
 */

#ifndef HNC_SYSTEM_OF_MEASUREMENT_DEGREE_HPP
#define HNC_SYSTEM_OF_MEASUREMENT_DEGREE_HPP

#include <type_traits>


namespace hnc
{
	/**
	 * @brief Degree (angle)
	 *
	 * @code
	 * #include <hnc/system_of_measurement.hpp>
	 * @endcode
	 *
	 * @b From http://en.wikipedia.org/wiki/Degree_%28angle%29 @n
	 * A degree (in full, a degree of arc, arc degree, or arcdegree), usually denoted by ° (the degree symbol), is a measurement of plane angle, representing @f$ \frac{1}{360} @f$ of a full rotation; one degree is equivalent to @f$ \frac{\Pi}{180} @f$ radians. It is not an SI unit, as the SI unit for angles is radian, but it is mentioned in the SI brochure as an accepted unit.
	 */
	template <class T>
	class degree
	{

	static_assert(std::is_arithmetic<T>::value, "hnc::degree works for arithmetic types only");
		
	private:

		/// Value of the angle in degree
		T m_value;

	public:

		/// Default construtor
		explicit degree(T const degree_value = T(0)) : m_value(degree_value) { }

		/**
		 * @brief Return the degree value
		 * @return the degree value
		 */
		T value() const { return m_value; }

		/// @copydoc hnc::degree::value
		T degree_value() const { return value(); }
	};
}

/**
 * @brief Display a hnc::degree
 *
 * @param[out] o            Out stream
 * @param[in]  angle_degree Angle
 *
 * @return the out stream
 */
template <class T>
std::ostream & operator<<(std::ostream & o, hnc::degree<T> const & angle_degree)
{
	o << angle_degree.value() << "°";
	return o;
}

#endif
