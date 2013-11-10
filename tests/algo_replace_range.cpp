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

#include <hnc/algo/replace_range.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	// Empty

	++nb_test;
	{
		std::vector<int> c(0);
		hnc::algo::replace_range(c, c.begin(), c.end(), c.begin(), c.end());
		nb_test -= hnc::test::warning
		(
			c == std::vector<int>(0),
			"hnc::algo::replace in an empty vector fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c(0);
		hnc::algo::replace_range(c, c.begin(), c.end(), c.begin(), c.end());
		nb_test -= hnc::test::warning
		(
			c == std::list<int>(0),
			"hnc::algo::replace in an empty list fails\n"
		);
	}

	// string

	++nb_test;
	{
		std::string src  = "original std::string!";
		std::string dest = "same size std::string";
		std::string c = src;
		hnc::algo::replace_range(c, c.begin(), c.end(), dest.begin(), dest.end());
		std::cout << src << "\n" << c << std::endl;
		nb_test -= hnc::test::warning
		(
			c == "same size std::string",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string src  = "a std::string";
		std::string dest = "a std::string replaced";
		std::string c = src;
		hnc::algo::replace_range(c, c.begin(), c.end(), dest);
		std::cout << src << "\n" << c << std::endl;
		nb_test -= hnc::test::warning
		(
			c == "a std::string replaced",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string src  = "a std::string";
		std::string dest = "replaced!";
		std::string c = src;
		hnc::algo::replace_range(c, c.begin(), c.end(), dest.begin(), dest.end());
		std::cout << src << "\n" << c << std::endl;
		nb_test -= hnc::test::warning
		(
			c == "replaced!",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string src  = "a std::string wtih a typo";
		std::string dest = "with";
		std::string c = src;
		hnc::algo::replace_range(c, c.begin() + 14, c.begin() + 14 + 4, dest);
		std::cout << src << "\n" << c << std::endl;
		nb_test -= hnc::test::warning
		(
			c == "a std::string with a typo",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string src  = "a std::string";
		std::string dest = "";
		std::string c = src;
		hnc::algo::replace_range(c, c.begin() + 2, c.begin() + 2 + 5, dest.begin(), dest.end());
		std::cout << src << "\n" << c << std::endl;
		nb_test -= hnc::test::warning
		(
			c == "a string",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string src  = "a string";
		std::string dest = " std::";
		std::string c = src;
		hnc::algo::replace_range(c, c.begin() + 1, c.begin() + 1 + 1, dest);
		std::cout << src << "\n" << c << std::endl;
		nb_test -= hnc::test::warning
		(
			c == "a std::string",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::algo::replace: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
