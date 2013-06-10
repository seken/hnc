// Copyright © 2012 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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
	
	hnc::test::warning(nb_test == 0, "hnc::except " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
