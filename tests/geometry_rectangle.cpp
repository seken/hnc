// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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
#include <fstream>
#include <string>

#include <hnc/geometry/rectangle.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// Constructors
	
	std::cout << hnc::terminal::info << "Constructors" << hnc::terminal::reset << std::endl;

	++nb_test;
	{
		hnc::geometry::rectangle<int> r;
		std::cout << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.left == 0 && r.top == 0 && r.width == 0 && r.height == 0 && r.right() == 0 && r.bottom() == 0,
			"hnc::geometry::rectangle " + hnc::to_string(r) + " fails\n"
		);
	}

	++nb_test;
	{
		hnc::geometry::rectangle<int> r(0, 0, 10, 10);
		std::cout << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.left == 0 && r.top == 0 && r.width == 10 && r.height == 10 && r.right() == 10 && r.bottom() == 10,
			"hnc::geometry::rectangle " + hnc::to_string(r) + " fails\n"
		);
	}

	++nb_test;
	{
		hnc::geometry::rectangle<unsigned int> r(5, 7, 10, 3);
		std::cout << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.left == 5 && r.top == 7 && r.width == 10 && r.height == 3 && r.right() == 15 && r.bottom() == 10,
			"hnc::geometry::rectangle " + hnc::to_string(r) + " fails\n"
		);
	}

	++nb_test;
	{
		hnc::geometry::rectangle<int> r;
		r = { 1, 1, 9, 14 };
		std::cout << r << std::endl;
		nb_test -= hnc::test::warning
		(
			r.left == 1 && r.top == 1 && r.width == 9 && r.height == 14 && r.right() == 10 && r.bottom() == 15,
			"hnc::geometry::rectangle " + hnc::to_string(r) + " fails\n"
		);
	}
	
	std::cout << std::endl;
	
	// Operator == and !=

	++nb_test;
	{
		hnc::geometry::rectangle<int> r0(1, 2, 3, 4);
		hnc::geometry::rectangle<int> r1(1, 2, 3, 4);
		std::cout << r0 << std::endl;
		std::cout << r1 << std::endl;
		nb_test -= hnc::test::warning
		(
			r0 == r1 && ((r0 != r1) == false),
			"hnc::geometry::rectangle " + hnc::to_string(r0) + " comparaison fails\n"
		);
	}

	++nb_test;
	{
		hnc::geometry::rectangle<int> r0(1, 1, 1, 1);
		hnc::geometry::rectangle<int> r1(1, 1, 1, 2);
		std::cout << r0 << std::endl;
		std::cout << r1 << std::endl;
		nb_test -= hnc::test::warning
		(
			r0 != r1 && ((r0 == r1) == false),
			"hnc::geometry::rectangle " + hnc::to_string(r0) + " comparaison fails\n"
		);
	}
	
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::geometry::rectangle: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
