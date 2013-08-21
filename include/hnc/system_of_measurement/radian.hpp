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
 * @brief Just for std::ostream & operator<<(std::ostream & o, hnc::radian<T> const & angle_radian)
 */

#ifndef HNC_SYSTEM_OF_MEASUREMENT_RADIAN_HPP
#define HNC_SYSTEM_OF_MEASUREMENT_RADIAN_HPP

#include <type_traits>


namespace hnc
{
	/**
	 * @brief Radian (angle)
	 *
	 * @code
	 * #include <hnc/system_of_measurement.hpp>
	 * @endcode
	 *
	 * @b From http://en.wikipedia.org/wiki/Radian @n
	 * The radian is the standard unit of angular measure, used in many areas of mathematics. An angle's measurement in radians is numerically equal to the length of a corresponding arc of a unit circle, so one radian is just under 57.3 degrees (when the arc length is equal to the radius). The unit was formerly an SI supplementary unit, but this category was abolished in 1995 and the radian is now considered an SI derived unit. The SI unit of solid angle measurement is the steradian.
	 */
	template <class T>
	class radian
	{

	static_assert(std::is_arithmetic<T>::value, "hnc::radian works for arithmetic types only");

	private:

		/// Value of the angle in radian
		T m_value;

	public:

		/// Default construtor
		explicit radian(T const radian_value = T(0)) : m_value(radian_value) { }

		/**
		 * @brief Return the radian value
		 * @return the radian value
		 */
		T value() const { return m_value; }

		/// @copydoc hnc::radian::value
		T radian_value() const { return value(); }
	};
}

/**
 * @brief Display a hnc::radian
 *
 * @param[out] o            Out stream
 * @param[in]  angle_radian Angle
 *
 * @return the out stream
 */
template <class T>
std::ostream & operator<<(std::ostream & o, hnc::radian<T> const & angle_radian)
{
	o << angle_radian.value() << "rad";
	return o;
}

#endif
