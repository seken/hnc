// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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


#if !defined(NDEBUG)
	#define NDEBUG
#endif

#include <iostream>
#include <string>
#include <stdexcept>

#include <hnc/optional.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	#if defined(NDEBUG)
		std::cout << "With NDEBUG" << std::endl;
		--nb_test;
	#else
		std::cout << "Without NDEBUG" << std::endl;
	#endif
	
	nb_test += 4;
	{
		hnc::optional<std::string> maybe;
		std::cout << maybe << std::endl;
		std::cout << "sizeof = " << sizeof(maybe) << std::endl;
		
		nb_test -= hnc::test::warning(bool(maybe) == false, "hnc::optional default constructor fails\n");
		
// 		try { std::cout << maybe.value() << std::endl; }
// 		catch (std::exception const & e) { std::cout << e.what() << std::endl; --nb_test; }
// 		
// 		try { maybe.value() = "one_string"; }
// 		catch (std::exception const & e) { std::cout << e.what() << std::endl; --nb_test; }
// 		
// 		try { std::cout << *maybe << std::endl; }
// 		catch (std::exception const & e) { std::cout << e.what() << std::endl; --nb_test; }
// 		
// 		try { *maybe = "one_string"; }
// 		catch (std::exception const & e) { std::cout << e.what() << std::endl; --nb_test; }
		
		maybe = hnc::optional<std::string>("one_string");
		std::cout << maybe << std::endl;
		nb_test -= hnc::test::warning(bool(maybe) == true, "maybe = hnc::optional<std::string>(\"one_string\"); fails\n");
		
		maybe = hnc::optional<std::string>();
		std::cout << maybe << std::endl;
		nb_test -= hnc::test::warning(bool(maybe) == false, "maybe = hnc::optional<std::string>(); fails\n");
		
		maybe = std::string("one_other_string");
		std::cout << maybe << std::endl;
		nb_test -= hnc::test::warning(bool(maybe) == true, "maybe = hnc::optional<std::string>(\"one_other_string\"); fails\n");
		
		std::cout << maybe.value() << std::endl;
		std::cout << *maybe << std::endl;
		
		maybe.value() = "direct_write";
		std::cout << maybe << std::endl;
		
		*maybe = "another_direct_write";
		std::cout << maybe << std::endl;
		
		std::cout << "Size = " << maybe->size() << std::endl;
		
		maybe->clear();
		std::cout << maybe << std::endl;
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::optional: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
