// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

// This file is part of hnc.

// hnc is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// hnc is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with hnc. If not, see <http://www.gnu.org/licenses/>


#ifndef HNC_MATH_NTH_ROOT_HPP
#define HNC_MATH_NTH_ROOT_HPP

#include <cmath>
#include <stdexcept>

#include "../assert.hpp"
#include "../to_string.hpp"


namespace hnc
{
	namespace math
	{
		// Tag dispatch
		namespace
		{
			template <bool>
			struct is_integer { };
		}

		// Floating point
		template <class T>
		T nth_root(T const & a, unsigned int const n, is_integer<false>)
		{
			T r = 1;
			T delta = r;

			while (std::abs(delta / int(r)) > std::numeric_limits<T>::epsilon())
			{
				delta = r;
				// Compute
				r = (T(1) / n) * (T(n - 1) * r + (a / std::pow(r, n - 1)));
				// Get delta
				delta -= r;
			}
			
			return r;
		}

		// Integer
		// Actual algorithm works only floating point, use float for internal computation
		template <class T>
		T nth_root(T const & a, unsigned int const n, is_integer<true>)
		{
			return nth_root(float(a), n, is_integer<false>());
		}

		/**
		 * @brief nth root algorithm
		 *
		 * @code
		 * #include <hnc/math.hpp>
		 * @endcode
		 *
		 * @param[in] a @f$ a @f$ in @f$ \sqrt[n]{a} @f$
		 * @param[in] n @f$ n @f$ in @f$ \sqrt[n]{a} @f$
		 *
		 * Particular cases:
		 * - @f$ a @f$ == @f$ 0 @f$, return @f$ 0 @f$
		 * - @f$ n @f$ == @f$ 0 @f$, return @f$ 1 @f$
		 * - @f$ n @f$ == @f$ 1 @f$, return @f$ a @f$
		 * - @f$ n @f$ == @f$ 2 @f$, return std::sqrt(@f$ a @f$)
		 * - @f$ n @f$ == @f$ 3 @f$, return std::cbrt(@f$ a @f$)
		 *
		 * https://en.wikipedia.org/wiki/Nth_root_algorithm @n
		 * https://fr.wikipedia.org/wiki/Algorithme_de_calcul_de_la_racine_n-i%C3%A8me
		 *
		 * @pre If @f$ n @f$ is odd: @f$ a > 0 @f$
		 *
		 * @exception std::domain_error if @f$ n \% 2 = 0 @f$ and @f$ a < 0 @f$
		 *
		 * @return the nth root
		 */
		template <class T>
		T nth_root(T const & a, unsigned int const n)
		{
			static_assert(std::numeric_limits<T>::is_specialized, "hnc::math::nth_root works for arithmetic types only");
			
			// If n is even and a < 0
			if (n % 2 == 0 && a < T(0))
			{
				hnc::hassert(false, std::domain_error("hnc::math::nth_root, Can not compute the " + hnc::to_string(n) + "th root of a negative number (" + hnc::to_string(a) + ")"));
			}

			// a == 0
			if (a == T(0)) { return T(0); }

			// n == 0
			if (n == 0) { return T(1); }

			// n == 1
			if (n == 1) { return a; }

			// sqrt
			if (n == 2) { return std::sqrt(a); }

			// cbrt
			if (n == 3) { return std::cbrt(a); }

			// General
			return nth_root(a, n, is_integer<std::numeric_limits<T>::is_integer>());
		}
// 		template <class T>
// 		T nth_root(T const & a, unsigned int const n)
// 		{

// 			std::cout << std::numeric_limits<T>::epsilon() << std::endl;
// 			std::cout << std::numeric_limits<T>::is_integer << std::endl;
// 			std::cout << std::endl;
// 			
// 			return 0;
// 		}

		
	}
}

#endif
