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

#include <hnc/algo/split.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	int nb_test = 0;

	// std::vector

	std::cout << "std::vector" << std::endl;

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 4;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && r.at(0) == std::vector<int>({0, 1, 2, 3}) && r.at(1) == std::vector<int>({5, 6, 7, 8, 9}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 0;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && r.at(0) == std::vector<int>({}) && r.at(1) == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 9;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && r.at(0) == std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}) && r.at(1) == std::vector<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 42;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 1 && r.at(0) == c,
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({1, 2, 0, 3, 4, 0, 5, 6, 0, 7, 8, 0, 9});
		int d = 0;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 5 && r.at(0) == std::vector<int>({1, 2}) && r.at(1) == std::vector<int>({3, 4}) && r.at(2) == std::vector<int>({5, 6}) && r.at(3) == std::vector<int>({7, 8}) && r.at(4) == std::vector<int>({9}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0});
		int d = 0;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && r.at(0) == std::vector<int>({}) && r.at(1) == std::vector<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 0});
		int d = 0;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 3 && r.at(0) == std::vector<int>({}) && r.at(1) == std::vector<int>({}) && r.at(2) == std::vector<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({0, 0, 0});
		int d = 0;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 4 && r.at(0) == std::vector<int>({}) && r.at(1) == std::vector<int>({}) && r.at(2) == std::vector<int>({}) && r.at(3) == std::vector<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c({});
		int d = 0;
		std::vector<std::vector<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 0,
			"hnc::algo::split fails\n"
		);
	}

	std::cout << std::endl;

	// std::string

	++nb_test;
	{
		std::string c = "";
		char d = ' ';
		std::vector<std::string> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = '" << d << "') \"" << c << "\" => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 0,
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "test with spaces";
		char d = ' ';
		std::vector<std::string> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = '" << d << "') \"" << c << "\" => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == std::vector<std::string>({"test", "with", "spaces"}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "a";
		char d = 'a';
		std::vector<std::string> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = '" << d << "') \"" << c << "\" => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == std::vector<std::string>({"", ""}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "no delimiter in this string";
		char d = 'z';
		std::vector<std::string> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = '" << d << "') \"" << c << "\" => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.at(0) == c,
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::string c = "_test_with_underscores_";
		char d = '_';
		std::vector<std::string> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = '" << d << "') \"" << c << "\" => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == std::vector<std::string>({"", "test", "with", "underscores", ""}),
			"hnc::algo::split fails\n"
		);
	}

	std::cout << std::endl;

	// std::list (copy of std::vector tests)

	std::cout << "std::list" << std::endl;

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 4;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && *(r.begin()) == std::list<int>({0, 1, 2, 3}) && *std::next(r.begin(), 1) == std::list<int>({5, 6, 7, 8, 9}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 0;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && *(r.begin()) == std::list<int>({}) && *std::next(r.begin(), 1) == std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 9;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && *(r.begin()) == std::list<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}) && *std::next(r.begin(), 1) == std::list<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		int d = 42;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 1 && *(r.begin()) == c,
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({1, 2, 0, 3, 4, 0, 5, 6, 0, 7, 8, 0, 9});
		int d = 0;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 5 && *(r.begin()) == std::list<int>({1, 2}) && *std::next(r.begin(), 1) == std::list<int>({3, 4}) && *std::next(r.begin(), 2) == std::list<int>({5, 6}) && *std::next(r.begin(), 3) == std::list<int>({7, 8}) && *std::next(r.begin(), 4) == std::list<int>({9}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0});
		int d = 0;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 2 && *(r.begin()) == std::list<int>({}) && *std::next(r.begin(), 1) == std::list<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 0});
		int d = 0;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 3 && *(r.begin()) == std::list<int>({}) && *std::next(r.begin(), 1) == std::list<int>({}) && *std::next(r.begin(), 2) == std::list<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({0, 0, 0});
		int d = 0;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 4 && *(r.begin()) == std::list<int>({}) && *std::next(r.begin(), 1) == std::list<int>({}) && *std::next(r.begin(), 2) == std::list<int>({}) && *std::next(r.begin(), 3) == std::list<int>({}),
			"hnc::algo::split fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c({});
		int d = 0;
		std::vector<std::list<int>> r = hnc::algo::split(c, d);
		std::cout << "Split (delimiter = " << d << ") " << c << " => " << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.size() == 0,
			"hnc::algo::split fails\n"
		);
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::algo::split: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
