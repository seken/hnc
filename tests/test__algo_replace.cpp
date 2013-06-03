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

#include <hnc/algo/replace.hpp>
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
		hnc::algo::replace(c, c, c);
		nb_test -= hnc::test::warning
		(
			c == std::vector<int>(0),
			"hnc::algo::replace in an empty vector fails\n"
		);
	}

	++nb_test;
	{
		std::list<int> c(0);
		hnc::algo::replace(c, c, c);
		nb_test -= hnc::test::warning
		(
			c == std::list<int>(0),
			"hnc::algo::replace in an empty list fails\n"
		);
	}

	std::cout << "Common cases\n" << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':'}, std::vector<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {' '}, {' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':'}, std::vector<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {' '}, {'_'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', '_', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Common cases with std::list\n" << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':'}, std::list<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {' '}, {' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':'}, std::list<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {' '}, {'_'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', '_', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Begin & End\n" << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'t', 'e', 's', 't', ' '}, std::vector<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}, std::vector<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({' ', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' '});
		std::vector<char> r = c;
		hnc::algo::replace(r, {' '}, {'_'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'_', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' '}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({' ', ' ', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' ', ' '});
		std::vector<char> r = c;
		hnc::algo::replace(r, {' ', ' '}, {'_', '_'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'_', '_', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' ', ' '}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Begin & End with std::list\n" << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'t', 'e', 's', 't', ' '}, std::list<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}, std::list<char>(0));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({' ', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' '});
		std::list<char> r = c;
		hnc::algo::replace(r, {' '}, {'_'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'_', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' '}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({' ', ' ', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' ', ' '});
		std::list<char> r = c;
		hnc::algo::replace(r, {' ', ' '}, {'_', '_'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'_', '_', 't', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e', ' ', ' '}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Same value\n" << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'t', 'e', 's', 't'}, {'t', 'e', 's', 't'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'r', 'e', 'p', 'l', 'a', 'c', 'e'}, {'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'h', 'n', 'c'}, {'h', 'n', 'c'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Same value with std::list\n" << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'t', 'e', 's', 't'}, {'t', 'e', 's', 't'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'r', 'e', 'p', 'l', 'a', 'c', 'e'}, {'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'h', 'n', 'c'}, {'h', 'n', 'c'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Consecutive\n" << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'t', 't'}, {'t'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 'e', 's', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'e', 'e'}, {'e'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 't', 'e', 's', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {'s', 's'}, {'s'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 't', 'e', 'e', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::vector<char> r = c;
  hnc::algo::replace
		(
   hnc::algo::replace
			(
    hnc::algo::replace
				(
					r,
					{'t', 't'}, {'t'}
				),
				{'e', 'e'}, {'e'}
			),
			{'s', 's'}, {'s'}
		);
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Consecutive with std::list\n" << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'t', 't'}, {'t'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 'e', 's', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'e', 'e'}, {'e'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 't', 'e', 's', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::list<char> r = c;
		hnc::algo::replace(r, {'s', 's'}, {'s'});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 't', 'e', 'e', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 't', 'e', 'e', 's', 's', 't', 't'});
		std::list<char> r = c;
  hnc::algo::replace
		(
   hnc::algo::replace
			(
    hnc::algo::replace
				(
					r,
					{'t', 't'}, {'t'}
				),
				{'e', 'e'}, {'e'}
			),
			{'s', 's'}, {'s'}
		);
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', 't'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "std::string\n" << std::endl;

	++nb_test;
	{
		std::string c = "a std::string";
		std::string r = c;
		hnc::algo::replace(r, std::string("a "), std::string("works with "));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == "works with std::string",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Complete container\n" << std::endl;

	++nb_test;
	{
		std::string c = "replace all";
		std::string r = c;
		hnc::algo::replace(r, std::string("replace all"), std::string("all replaced"));
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == "all replaced",
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Iterator\n" << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, r.begin() + 4, r.begin() + 15, {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, r.begin() + 5, r.begin() + 15, {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::vector<char> r = c;
		hnc::algo::replace(r, r.begin() + 4, r.begin() + 14, {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;


	std::cout << "Iterator with std::list\n" << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, std::next(r.begin(), 4), std::next(r.begin(), 15), {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, std::next(r.begin(), 5), std::next(r.begin(), 15), {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::list<char> c({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'});
		std::list<char> r = c;
		hnc::algo::replace(r, std::next(r.begin(), 4), std::next(r.begin(), 14), {' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' '}, {' '});
		std::cout << c << "\n" << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r == decltype(r)({'t', 'e', 's', 't', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'h', 'n', 'c', ':', ':', 'a', 'l', 'g', 'o', ':', ':', 'r', 'e', 'p', 'l', 'a', 'c', 'e'}),
			"hnc::algo::replace fails\n"
		);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::algo::replace: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
