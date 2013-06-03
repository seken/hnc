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


#include <iostream>
#include <vector>
#include <list>
#include <string>

#include <hnc/algo/find_range.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// Empty
	std::cout << "Empty" << std::endl;

	++nb_test;
	{
		std::vector<int> c(0);
		std::vector<int> values(0);
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range of empty vector fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c(0);
		std::list<int> values(0);
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range of list vector fails\n"
		);
	}

	// string
	std::cout << "string" << std::endl;

	++nb_test;
	{
		std::string c = "a std::string";
		std::string values = "std";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin() + 2,
			"hnc::algo::find_range \"std\" in \"a std::string\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "a std::string";
		std::string values = "a";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range \"a\" in \"a std::string\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "a std::string";
		std::string values = "a std::";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range \"a std::\" in \"a std::string\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "a std::string";
		std::string values = "string";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end() - 6,
			"hnc::algo::find_range \"string\" in \"a std::string\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "a std::string";
		std::string values = "g";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end() - 1,
			"hnc::algo::find_range \"g\" in \"a std::string\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "tteesstt";
		std::string values = "tt";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range \"tt\" in \"tteesstt\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "tteesstt";
		std::string values = "ee";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin() + 2,
			"hnc::algo::find_range \"ee\" in \"tteesstt\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "tteesstt";
		std::string values = "ss";
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin() + 4,
			"hnc::algo::find_range \"ss\" in \"tteesstt\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "tteesstt";
		std::string values = "tt";
		auto it = hnc::algo::find_range(c.begin() + 1, c.end(), values);
		nb_test -= hnc::test::warning
		(
			it == c.begin() + 6,
			"hnc::algo::find_range \"tt\" in \"...teesstt\" fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "tteesstt";
		std::string values = "tt";
		auto it = hnc::algo::find_range(c.begin() + 1, c.end() - 1, values);
		nb_test -= hnc::test::warning
		(
			it == c.end() - 1,
			"hnc::algo::find_range \"tt\" in \"...eesst...\" fails\n"
		);
	}

	// vector
	std::cout << "vector" << std::endl;

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({0, 1});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range {0, 1} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({8, 9});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == std::next(c.end(), -2),
			"hnc::algo::find_range {8, 9} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({5});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == std::next(c.begin(), 5),
			"hnc::algo::find_range {5} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({3, 4, 5, 6});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == std::next(c.begin(), 3),
			"hnc::algo::find_range {3, 4, 5, 6} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({8, 9, 10});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range {8, 9, 10} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({5, 4});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range {8, 9} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::vector<int> values({-1, 0, 1});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range {-1, 0, 1} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	// list
	std::cout << "list" << std::endl;

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({0, 1});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range {0, 1} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({8, 9});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == std::next(c.end(), -2),
			"hnc::algo::find_range {8, 9} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({5});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == std::next(c.begin(), 5),
			"hnc::algo::find_range {5} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({3, 4, 5, 6});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == std::next(c.begin(), 3),
			"hnc::algo::find_range {3, 4, 5, 6} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.begin(),
			"hnc::algo::find_range {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({8, 9, 10});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range {8, 9, 10} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({5, 4});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range {8, 9} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> values({-1, 0, 1});
		auto it = hnc::algo::find_range(c, values);
		nb_test -= hnc::test::warning
		(
			it == c.end(),
			"hnc::algo::find_range {-1, 0, 1} in {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	hnc::test::warning(nb_test == 0, "hnc::algo::compare_range: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
