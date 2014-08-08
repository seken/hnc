// Copyright © 2013, 2014 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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


#include <iostream>

#include <hnc/except.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// incomplete_implementation

	++nb_test;
	try
	{
		throw hnc::except::incomplete_implementation(std::string("hnc::except::incomplete_implementation with std::string"));
	}
	catch (hnc::except::incomplete_implementation const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	++nb_test;
	try
	{
		throw hnc::except::incomplete_implementation("hnc::except::incomplete_implementation with char const * const");
	}
	catch (hnc::except::incomplete_implementation const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	// file_not_found

	++nb_test;
	try
	{
		throw hnc::except::file_not_found(std::string("hnc::except::file_not_found with std::string"));
	}
	catch (hnc::except::file_not_found const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	++nb_test;
	try
	{
		throw hnc::except::file_not_found("hnc::except::file_not_found with char const * const");
	}
	catch (hnc::except::file_not_found const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	// parse_error

	++nb_test;
	try
	{
		throw hnc::except::parse_error(std::string("hnc::except::parse_error with std::string"));
	}
	catch (hnc::except::parse_error const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	++nb_test;
	try
	{
		throw hnc::except::parse_error("hnc::except::parse_error with char const * const");
	}
	catch (hnc::except::parse_error const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	nb_test += 3;
	try
	{
		throw hnc::except::parse_error(std::string("hnc::except::parse_error with std::string"), 42, 21);
	}
	catch (hnc::except::parse_error const & e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Line number   = " << e.line_number() << std::endl;
		std::cerr << "Column number = " << e.column_number() << std::endl;
		--nb_test;
		nb_test -= hnc::test::warning(e.line_number() == 42, "hnc::except::parse_error line number is " + hnc::to_string(e.line_number()) + " instead of 42\n");
		nb_test -= hnc::test::warning(e.column_number() == 21, "hnc::except::parse_error column number is " + hnc::to_string(e.column_number()) + " instead of 21\n");
	}
	std::cout << std::endl;

	nb_test += 3;
	try
	{
		throw hnc::except::parse_error("hnc::except::parse_error with char const * const", 73, 42);
	}
	catch (hnc::except::parse_error const & e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Line number   = " << e.line_number() << std::endl;
		std::cerr << "Column number = " << e.column_number() << std::endl;
		--nb_test;
		nb_test -= hnc::test::warning(e.line_number() == 73, "hnc::except::parse_error line number is " + hnc::to_string(e.line_number()) + " instead of 73\n");
		nb_test -= hnc::test::warning(e.column_number() == 42, "hnc::except::parse_error column number is " + hnc::to_string(e.column_number()) + " instead of 42\n");
	}
	std::cout << std::endl;

	// bad_cast

	++nb_test;
	try
	{
		throw hnc::except::bad_cast(std::string("hnc::except::bad_cast with std::string"));
	}
	catch (hnc::except::bad_cast const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;

	++nb_test;
	try
	{
		throw hnc::except::bad_cast("hnc::except::bad_cast with char const * const");
	}
	catch (hnc::except::bad_cast const & e)
	{
		std::cerr << e.what() << std::endl;
		--nb_test;
	}
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::except " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
