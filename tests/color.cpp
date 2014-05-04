// Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

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
#include <iterator>

#include <hnc/color.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	++nb_test;
	{
		hnc::color c;
		std::cout << c << std::endl;
		std::cout << c.html() << std::endl;
		nb_test -= hnc::test::warning(c.r == 0 && c.g == 0 && c.b == 0 && c.a == 255, "hnc::color fails!\n");
	}
	
	++nb_test;
	{
		hnc::color c(255, 255, 255);
		std::cout << c << std::endl;
		std::cout << c.html() << std::endl;
		nb_test -= hnc::test::warning(c.r == 255 && c.g == 255 && c.b == 255 && c.a == 255, "hnc::color fails!\n");
	}
	
	++nb_test;
	{
		hnc::color c(101, 102, 103, 104);
		std::cout << c << std::endl;
		std::cout << c.html() << std::endl;
		nb_test -= hnc::test::warning(c.r == 101 && c.g == 102 && c.b == 103 && c.a == 104, "hnc::color fails!\n");
	}
	
	++nb_test;
	{
		hnc::color c{104, 103, 102};
		std::cout << c << std::endl;
		std::cout << c.html() << std::endl;
		nb_test -= hnc::test::warning(c.r == 104 && c.g == 103 && c.b == 102 && c.a == 255, "hnc::color fails!\n");
	}
	
	++nb_test;
	{
		hnc::color c(1, 2, 3, 255);
		std::cout << c << std::endl;
		std::cout << c.html() << std::endl;
		nb_test -= hnc::test::warning(c == hnc::color(1, 2, 3, 255), "hnc::color fails!\n");
	}
	
	hnc::test::warning(nb_test == 0, "hnc::color " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
