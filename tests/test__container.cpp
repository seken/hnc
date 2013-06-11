// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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

#include <hnc/container.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	{
		hnc::container<int> c;
		nb_test -= hnc::test::warning(c.size() == 0, "hnc::container empty container test fail!\n");
	}

	nb_test += 4;
	{
		hnc::container<int> c(3, 21);
		nb_test -= hnc::test::warning(c.size() == 3, "hnc::container constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 21, "hnc::container constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 21, "hnc::container constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == 21, "hnc::container constructor test fail!\n");
	}

	nb_test += 3;
	{
		hnc::container<int> c(2);
		nb_test -= hnc::test::warning(c.size() == 2, "hnc::container constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 0, "hnc::container constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 0, "hnc::container constructor test fail!\n");
	}

	nb_test += 4;
	{
		hnc::container<int> c(hnc::container<int>(3, 21));
		nb_test -= hnc::test::warning(c.size() == 3, "hnc::container copy constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 21, "hnc::container copy constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 21, "hnc::container copy constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == 21, "hnc::container copy constructor test fail!\n");
	}

	nb_test += 4;
	{
		hnc::container<int> c(std::vector<int>(3, 21));
		nb_test -= hnc::test::warning(c.size() == 3, "hnc::container vector constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 21, "hnc::container vector constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 21, "hnc::container vector constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == 21, "hnc::container vector constructor test fail!\n");
	}

	nb_test += 4;
	{
		hnc::container<char> c({'a', 'b', 'c'});
		nb_test -= hnc::test::warning(c.size() == 3, "hnc::container initializer_list constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 'a', "hnc::container initializer_list constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 'b', "hnc::container initializer_list constructor test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == 'c', "hnc::container initializer_list constructor test fail!\n");
	}

	++nb_test;
	{
		hnc::container<char> c({'a', 'b', 'c'});
		nb_test -= hnc::test::warning(c == hnc::container<char>({'a', 'b', 'c'}), "hnc::container operator == test fail!\n");
	}

	++nb_test;
	{
		hnc::container<char> c({'a', 'b', 'c'});
		nb_test -= hnc::test::warning(!(c != hnc::container<char>({'a', 'b', 'c'})), "hnc::container operator != test fail!\n");
	}

	++nb_test;
	{
		hnc::container<char> c;
		c = hnc::container<char>({'a', 'b', 'c'});
		nb_test -= hnc::test::warning(c == hnc::container<char>({'a', 'b', 'c'}), "hnc::container operator = test fail!\n");
	}

	{
		hnc::container<char> c({'a', 'b', 'c'});
		std::cout << "Display a b c: ";
		for (auto const & e : c) { std::cout << e << " "; }
		std::cout << std::endl;
	}

	nb_test += 4;
	{
		hnc::container<char> c(3);
		char val = 'a';
		for (auto & e : c) { e = val++; }
		nb_test -= hnc::test::warning(c.size() == 3, "hnc::container for loop range test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 'a', "hnc::container for loop range test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 'b', "hnc::container for loop range test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == 'c', "hnc::container for loop range test fail!\n");
	}

	{
		hnc::container<char> c({'a', 'b', 'c'});
		std::cout << "Display c b a: ";
		for (auto it = c.rbegin(); it != c.rend(); ++it) { std::cout << *it << " "; }
		std::cout << std::endl;
	}

	nb_test += 4;
	{
		hnc::container<char> c(3);
		char val = 'a';
		for (auto it = c.rbegin(); it != c.rend(); ++it) { *it = val++; }
		nb_test -= hnc::test::warning(c.size() == 3, "hnc::container reverse iterator test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == 'c', "hnc::container reverse iterator test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == 'b', "hnc::container reverse iterator test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == 'a', "hnc::container reverse iterator test fail!\n");
	}

	std::cout << std::endl;
	nb_test += 11;
	{
		hnc::container<std::string> c;
		c.push_back("_");
		c.push_back("other");
		c.push_back("functions");
		c.push_back("like");
		c.push_back("front");
		c.push_back("back");
		c.push_back("and");
		c.push_back("_");
		c.front() = "test";
		c.back() = "operator<<";
		std::cout << "operator<< = " << c << std::endl;
		std::cout << "front      = " << c.front() << std::endl;
		std::cout << "back       = " << c.back() << std::endl;
		nb_test -= hnc::test::warning(c.size() == 8, "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.front() == "test", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.back() == "operator<<", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(0) == "test", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(1) == "other", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(2) == "functions", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(3) == "like", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(4) == "front", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(5) == "back", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(6) == "and", "hnc::container extra test fail!\n");
		nb_test -= hnc::test::warning(c.at(7) == "operator<<", "hnc::container extra test fail!\n");
	}
	
	hnc::test::warning(nb_test == 0, "hnc::arg " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
