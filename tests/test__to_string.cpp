// Copyright © 2012,2013 Lénaïc Bagnères, hnc@singularity.fr

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
#include <string>

#include <hnc/test.hpp>
#include <hnc/to_string.hpp>

int main()
{
	int nb_test = 0;

	++nb_test;
	{
		int i = 56648;
		std::string s = hnc::to_string(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == "56648", "hnc::to_string fail!\n");
	}

	++nb_test;
	{
		double i = -54664.6546;
		std::string s = hnc::to_string(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == "-54664.6546", "hnc::to_string fail!\n");
	}

	++nb_test;
	{
		char i = 'i';
		std::string s = hnc::to_string(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == "i", "hnc::to_string fail!\n");
	}

	++nb_test;
	{
		std::string i = "a std::string";
		std::string s = hnc::to_string(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == i, "hnc::to_string fail!\n");
	}

	++nb_test;
	{
		char const * const i = "a char const * const";
		std::string s = hnc::to_string(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == i, "hnc::to_string fail!\n");
	}

	hnc::test::warning(nb_test == 0, "hnc::to_string: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
