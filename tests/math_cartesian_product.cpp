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


#include <iostream>
#include <string>
#include <vector>
#include <list>

#include <hnc/math/cartesian_product.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	// std::vector

	std::cout << "std::vector" << std::endl;
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::vector<std::string>> vs
		(
			{
				{"1", "2", "3"},
				{"a", "b"},
				{"I", "II", "III"}
				//{"_", "*", "%", "@"}
			}
		);

		std::vector<std::vector<std::string>> r = hnc::math::cartesian_product(vs);
		
		std::cout << "Cartesian product of " << vs << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<std::string>>({{"1", "a", "I"}, {"1", "a", "II"}, {"1", "a", "III"}, {"1", "b", "I"}, {"1", "b", "II"}, {"1", "b", "III"}, {"2", "a", "I"}, {"2", "a", "II"}, {"2", "a", "III"}, {"2", "b", "I"}, {"2", "b", "II"}, {"2", "b", "III"}, {"3", "a", "I"}, {"3", "a", "II"}, {"3", "a", "III"}, {"3", "b", "I"}, {"3", "b", "II"}, {"3", "b", "III"}}),
			"hnc::math::cartesian_product fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::vector<std::string>> vs
		(
			{
				{"1", "2", "3"},
				{"a", "b"},
				{"I", "II", "III"},
				{"_", "*", "%", "@"}
			}
		);

		std::vector<std::vector<std::string>> r = hnc::math::cartesian_product(vs);

		std::cout << "Cartesian product of " << vs << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<std::string>>({{"1", "a", "I", "_"}, {"1", "a", "I", "*"}, {"1", "a", "I", "%"}, {"1", "a", "I", "@"}, {"1", "a", "II", "_"}, {"1", "a", "II", "*"}, {"1", "a", "II", "%"}, {"1", "a", "II", "@"}, {"1", "a", "III", "_"}, {"1", "a", "III", "*"}, {"1", "a", "III", "%"}, {"1", "a", "III", "@"}, {"1", "b", "I", "_"}, {"1", "b", "I", "*"}, {"1", "b", "I", "%"}, {"1", "b", "I", "@"}, {"1", "b", "II", "_"}, {"1", "b", "II", "*"}, {"1", "b", "II", "%"}, {"1", "b", "II", "@"}, {"1", "b", "III", "_"}, {"1", "b", "III", "*"}, {"1", "b", "III", "%"}, {"1", "b", "III", "@"}, {"2", "a", "I", "_"}, {"2", "a", "I", "*"}, {"2", "a", "I", "%"}, {"2", "a", "I", "@"}, {"2", "a", "II", "_"}, {"2", "a", "II", "*"}, {"2", "a", "II", "%"}, {"2", "a", "II", "@"}, {"2", "a", "III", "_"}, {"2", "a", "III", "*"}, {"2", "a", "III", "%"}, {"2", "a", "III", "@"}, {"2", "b", "I", "_"}, {"2", "b", "I", "*"}, {"2", "b", "I", "%"}, {"2", "b", "I", "@"}, {"2", "b", "II", "_"}, {"2", "b", "II", "*"}, {"2", "b", "II", "%"}, {"2", "b", "II", "@"}, {"2", "b", "III", "_"}, {"2", "b", "III", "*"}, {"2", "b", "III", "%"}, {"2", "b", "III", "@"}, {"3", "a", "I", "_"}, {"3", "a", "I", "*"}, {"3", "a", "I", "%"}, {"3", "a", "I", "@"}, {"3", "a", "II", "_"}, {"3", "a", "II", "*"}, {"3", "a", "II", "%"}, {"3", "a", "II", "@"}, {"3", "a", "III", "_"}, {"3", "a", "III", "*"}, {"3", "a", "III", "%"}, {"3", "a", "III", "@"}, {"3", "b", "I", "_"}, {"3", "b", "I", "*"}, {"3", "b", "I", "%"}, {"3", "b", "I", "@"}, {"3", "b", "II", "_"}, {"3", "b", "II", "*"}, {"3", "b", "II", "%"}, {"3", "b", "II", "@"}, {"3", "b", "III", "_"}, {"3", "b", "III", "*"}, {"3", "b", "III", "%"}, {"3", "b", "III", "@"}}),
			"hnc::math::cartesian_product fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::vector<int>> vs
		(
			{
				{1, 2, 3},
				{00, 00},
				{9, 9, 9}
			}
		);

		std::vector<std::vector<int>> r = hnc::math::cartesian_product(vs);

		std::cout << "Cartesian product of " << vs << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::vector<std::vector<int>>({{1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}}),
			"hnc::math::cartesian_product fails\n"
		);
	}
	std::cout << std::endl;

	// std::list

	std::cout << "std::list" << std::endl;
	std::cout << std::endl;

	++nb_test;
	{
		std::list<std::list<std::string>> vs
		(
			{
				{"1", "2", "3"},
				{"a", "b"},
				{"I", "II", "III"}
				//{"_", "*", "%", "@"}
			}
		);

		std::list<std::list<std::string>> r = hnc::math::cartesian_product(vs);

		std::cout << "Cartesian product of " << vs << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::list<std::list<std::string>>({{"1", "a", "I"}, {"1", "a", "II"}, {"1", "a", "III"}, {"1", "b", "I"}, {"1", "b", "II"}, {"1", "b", "III"}, {"2", "a", "I"}, {"2", "a", "II"}, {"2", "a", "III"}, {"2", "b", "I"}, {"2", "b", "II"}, {"2", "b", "III"}, {"3", "a", "I"}, {"3", "a", "II"}, {"3", "a", "III"}, {"3", "b", "I"}, {"3", "b", "II"}, {"3", "b", "III"}}),
			"hnc::math::cartesian_product fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<std::list<std::string>> vs
		(
			{
				{"1", "2", "3"},
				{"a", "b"},
				{"I", "II", "III"},
				{"_", "*", "%", "@"}
			}
		);

		std::list<std::list<std::string>> r = hnc::math::cartesian_product(vs);

		std::cout << "Cartesian product of " << vs << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::list<std::list<std::string>>({{"1", "a", "I", "_"}, {"1", "a", "I", "*"}, {"1", "a", "I", "%"}, {"1", "a", "I", "@"}, {"1", "a", "II", "_"}, {"1", "a", "II", "*"}, {"1", "a", "II", "%"}, {"1", "a", "II", "@"}, {"1", "a", "III", "_"}, {"1", "a", "III", "*"}, {"1", "a", "III", "%"}, {"1", "a", "III", "@"}, {"1", "b", "I", "_"}, {"1", "b", "I", "*"}, {"1", "b", "I", "%"}, {"1", "b", "I", "@"}, {"1", "b", "II", "_"}, {"1", "b", "II", "*"}, {"1", "b", "II", "%"}, {"1", "b", "II", "@"}, {"1", "b", "III", "_"}, {"1", "b", "III", "*"}, {"1", "b", "III", "%"}, {"1", "b", "III", "@"}, {"2", "a", "I", "_"}, {"2", "a", "I", "*"}, {"2", "a", "I", "%"}, {"2", "a", "I", "@"}, {"2", "a", "II", "_"}, {"2", "a", "II", "*"}, {"2", "a", "II", "%"}, {"2", "a", "II", "@"}, {"2", "a", "III", "_"}, {"2", "a", "III", "*"}, {"2", "a", "III", "%"}, {"2", "a", "III", "@"}, {"2", "b", "I", "_"}, {"2", "b", "I", "*"}, {"2", "b", "I", "%"}, {"2", "b", "I", "@"}, {"2", "b", "II", "_"}, {"2", "b", "II", "*"}, {"2", "b", "II", "%"}, {"2", "b", "II", "@"}, {"2", "b", "III", "_"}, {"2", "b", "III", "*"}, {"2", "b", "III", "%"}, {"2", "b", "III", "@"}, {"3", "a", "I", "_"}, {"3", "a", "I", "*"}, {"3", "a", "I", "%"}, {"3", "a", "I", "@"}, {"3", "a", "II", "_"}, {"3", "a", "II", "*"}, {"3", "a", "II", "%"}, {"3", "a", "II", "@"}, {"3", "a", "III", "_"}, {"3", "a", "III", "*"}, {"3", "a", "III", "%"}, {"3", "a", "III", "@"}, {"3", "b", "I", "_"}, {"3", "b", "I", "*"}, {"3", "b", "I", "%"}, {"3", "b", "I", "@"}, {"3", "b", "II", "_"}, {"3", "b", "II", "*"}, {"3", "b", "II", "%"}, {"3", "b", "II", "@"}, {"3", "b", "III", "_"}, {"3", "b", "III", "*"}, {"3", "b", "III", "%"}, {"3", "b", "III", "@"}}),
			"hnc::math::cartesian_product fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<std::list<int>> vs
		(
			{
				{1, 2, 3},
				{00, 00},
				{9, 9, 9}
			}
		);

		std::list<std::list<int>> r = hnc::math::cartesian_product(vs);

		std::cout << "Cartesian product of " << vs << ":" << std::endl;
		std::cout << r << std::endl;

		nb_test -= hnc::test::warning
		(
			r == std::list<std::list<int>>({{1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {1, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {2, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}, {3, 0, 9}}),
			"hnc::math::cartesian_product fails\n"
		);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::cartesian_product: " + hnc::to_string(nb_test) + " test fail!\n");

	return 0;
}
