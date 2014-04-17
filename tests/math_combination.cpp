// Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

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


#include <iostream>
#include <string>
#include <vector>
#include <list>

#include <hnc/math/combination.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	// std::vector

	++nb_test;
	{
		std::vector<char> values = { 'a', 'b', 'c', 'd', 'e' };

		std::vector<std::vector<char>> r = hnc::math::combinations(values, 2);
		
		std::cout << "2-combinations of " << values << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<char>>({{'a', 'b'}, {'a', 'c'}, {'a', 'd'}, {'a', 'e'}, {'b', 'c'}, {'b', 'd'}, {'b', 'e'}, {'c', 'd'}, {'c', 'e'}, {'d', 'e'}}),
			"hnc::math::combinations fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> values = { 'a', 'b', 'c' };

		std::vector<std::vector<char>> r = hnc::math::combinations(values, 1);
		
		std::cout << "1-combinations of " << values << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<char>>({{'a'}, {'b'}, {'c'}}),
			"hnc::math::combinations fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> values = { 'a', 'b', 'c' };

		std::vector<std::vector<char>> r = hnc::math::combinations(values, 3);
		
		std::cout << "3-combinations of " << values << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<char>>({{'a', 'b', 'c'}}),
			"hnc::math::combinations fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<std::string> values = { "a", "b", "c" };

		std::list<std::list<std::string>> r = hnc::math::combinations(values, 2);
		
		std::cout << "2-combinations of " << values << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::list<std::list<std::string>>({{"a", "b"}, {"a", "c"}, {"b", "c"}}),
			"hnc::math::combinations fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> values = { 'a', 'b', 'c' };

		std::vector<std::vector<char>> r = hnc::math::combinations_all(values);
		
		std::cout << "All combinations of " << values << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<char>>({{'a'}, {'a', 'b'}, {'a', 'b', 'c'}, {'a', 'c'}, {'b'}, {'b', 'c'}, {'c'}}),
			"hnc::math::combinations_all fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> values = { "a", "b", "c", "d", "e" };

		std::vector<std::vector<std::string>> r = hnc::math::combinations_all(values);
		
		std::cout << "All combinations of " << values << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<std::string>>({{"a"}, {"a", "b"}, {"a", "b", "c"}, {"a", "b", "c", "d"}, {"a", "b", "c", "d", "e"}, {"a", "b", "c", "e"}, {"a", "b", "d"}, {"a", "b", "d", "e"}, {"a", "b", "e"}, {"a", "c"}, {"a", "c", "d"}, {"a", "c", "d", "e"}, {"a", "c", "e"}, {"a", "d"}, {"a", "d", "e"}, {"a", "e"}, {"b"}, {"b", "c"}, {"b", "c", "d"}, {"b", "c", "d", "e"}, {"b", "c", "e"}, {"b", "d"}, {"b", "d", "e"}, {"b", "e"}, {"c"}, {"c", "d"}, {"c", "d", "e"}, {"c", "e"}, {"d"}, {"d", "e"}, {"e"}}),
			"hnc::math::combinations_all fails\n"
		);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::combination: " + hnc::to_string(nb_test) + " test fail!\n");

	return 0;
}
