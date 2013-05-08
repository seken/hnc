// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_SLEEP_HPP
#define HNC_SLEEP_HPP

#include <thread>
#include <chrono>


namespace hnc
{
	/**
	 * @brief Sleep function with different units
	 *
	 * @code
	 * #include <hnc/sleep.hpp>
	 * @endcode
	 */
	namespace sleep
	{
		/**
		 * @brief Sleep h hours
		 * @param[in] h hours
		 */
		void h(unsigned int const h)
		{
			std::this_thread::sleep_for(std::chrono::hours(h));
		}

		/**
		 * @brief Sleep m minutes
		 * @param[in] m minutes
		 */
		void min(unsigned int const m)
		{
			std::this_thread::sleep_for(std::chrono::minutes(m));
		}

		/**
		 * @brief Sleep s seconds
		 * @param[in] s seconds
		 */
		void s(unsigned int const s)
		{
			std::this_thread::sleep_for(std::chrono::seconds(s));
		}

		/**
		 * @brief Sleep ms milliseconds
		 * @param[in] ms milliseconds
		 */
		void ms(unsigned int const ms)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		}

		/**
		 * @brief Sleep us microseconds
		 * @param[in] us microseconds
		 */
		void us(unsigned int const us)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(us));
		}

		/**
		 * @brief Sleep ns nanoseconds
		 * @param[in] ns nanoseconds
		 */
		void ns(unsigned int const ns)
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(ns));
		}
	}
}

#endif
