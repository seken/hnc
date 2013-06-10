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


#ifndef HNC_EXCEPT_HPP
#define HNC_EXCEPT_HPP

#include <exception>
#include <stdexcept>


namespace hnc
{
	/**
	 * @brief Extends std::exception, std::logic_error and std::runtime_error
	 *
	 * @code
	 * #include <hnc/except.hpp>
	 * @endcode
	 *
	 * std::exception @n
	 * http://www.cplusplus.com/reference/exception/exception/ @n
	 * http://en.cppreference.com/w/cpp/error/exception
	 *
	 * std::logic_error @n
	 * http://www.cplusplus.com/reference/stdexcept/logic_error/ @n
	 * http://en.cppreference.com/w/cpp/error/logic_error
	 *
	 * std::runtime_error @n
	 * http://www.cplusplus.com/reference/stdexcept/runtime_error/ @n
	 * http://en.cppreference.com/w/cpp/error/runtime_error
	 */
	namespace except
	{
		/// Exception to report incomplete implementation
		class incomplete_implementation : public std::logic_error
		{
		public:

			/**
			 * @brief Constructor
			 *
			 * @param[in] what_arg Description of the error
			 */
			explicit incomplete_implementation (std::string const & what_arg) :
				std::logic_error(what_arg)
			{ }

			/// @copydoc hnc::except::incomplete_implementation::incomplete_implementation(std::string const &)
			explicit incomplete_implementation (char const * const what_arg) :
				std::logic_error(what_arg)
			{ }

			/// Return the description of the error
			/// @return the description of the error
			virtual char const * what() const noexcept
			{
				return std::logic_error::what();
			}

			/// Destructor
			virtual ~incomplete_implementation() noexcept { }
		};

		/// Exception "file not found"
		class file_not_found : public std::runtime_error
		{
		public:

			/**
			 * @brief Constructor
			 *
			 * @param[in] what_arg Description of the error
			 */
			explicit file_not_found (std::string const & what_arg) :
				std::runtime_error(what_arg)
			{ }

			/// @copydoc hnc::except::file_not_found::file_not_found(std::string const &)
			explicit file_not_found (char const * const what_arg) :
				std::runtime_error(what_arg)
			{ }

			/// Return the description of the error
			/// @return the description of the error
			virtual char const * what() const noexcept
			{
				return std::runtime_error::what();
			}

			/// Destructor
			virtual ~file_not_found() noexcept { }
		};
	}
}

#endif
