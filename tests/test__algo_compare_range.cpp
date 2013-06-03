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

#include <hnc/algo/compare_range.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	{
		std::vector<int> c0(0);
		std::vector<int> c1(0);
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin(), c0.end(), c1.begin(), c1.end()) == true,
			"hnc::algo::compare_range comparison of empty vector fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c0({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> c1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin(), c0.end(), c1.begin(), c1.end()) == true,
			"hnc::algo::compare_range comparison of {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c0({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
		std::list<int> c1({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin(), c0.end(), c1.begin(), c1.end()) == true,
			"hnc::algo::compare_range comparison of {9, 8, 7, 6, 5, 4, 3, 2, 1, 0} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c0({11, 11, 2, 3, 4, 5, 11, 11, 11, 11});
		std::vector<int> c1({88, 88, 2, 3, 4, 5, 88, 88, 88, 88});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin() + 2, c0.begin() + 2 + 4, c1.begin() + 2, c1.end()) == true,
			"hnc::algo::compare_range comparison of {... 2, 3, 4, 5 ...} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c0({11, 11, 2, 3, 11, 5, 11, 11, 11, 11});
		std::vector<int> c1({88, 88, 2, 3, 88, 5, 88, 88, 88, 88});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin() + 2, c0.begin() + 2 + 4, c1.begin() + 2, c1.end()) == false,
			"hnc::algo::compare_range comparison of {... 2, 3, X, 5 ...} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c0({11, 11, 2, 3, 4, 5, 11, 11, 11, 11});
		std::vector<int> c1({88, 88, 2, 3, 4, 5, 88, 88, 88, 88});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin() + 1, c0.begin() + 1 + 5, c1.begin() + 2, c1.end()) == false,
			"hnc::algo::compare_range comparison of {... X, 2, 3, 4, 5 ...} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c0({11, 11, 2, 3, 4, 5, 11, 11, 11, 11});
		std::vector<int> c1({88, 88, 2, 3, 4, 5, 88, 88, 88, 88});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin() + 2, c0.begin() + 2 + 5, c1.begin() + 2, c1.end()) == false,
			"hnc::algo::compare_range comparison of {... 2, 3, 4, 5, X ...} fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c0({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		std::list<int> c1(0);
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin(), c0.end(), c1.begin(), c1.end()) == false,
			"hnc::algo::compare_range comparison of {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} with {} fails\n"
		);
	}

	++nb_test;
	{
		std::vector<int> c0({2, 3, 4, 5});
		std::vector<int> c1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
		nb_test -= hnc::test::warning
		(
			hnc::algo::compare_range(c0.begin(), c0.begin() + 4, c1.begin() + 2, c1.end()) == true,
			"hnc::algo::compare_range comparison of {2, 3, 4, 5} and {... 2, 3, 4, 5 ...} fails\n"
		);
	}

	// The compilation must fails
// 	{
// 		std::vector<int> c0({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
// 		std::vector<float> c1({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
// 		hnc::algo::compare_range(c0.begin(), c0.end(), c1.begin(), c1.end());
// 	}

	hnc::test::warning(nb_test == 0, "hnc::algo::compare_range: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
