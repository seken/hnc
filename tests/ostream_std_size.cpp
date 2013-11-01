// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>

#define HNC_ostream_container_size
#include <hnc/ostream_std.hpp>
#include <hnc/test.hpp>


int main()
{
	int nb_test = 0;

	{
		std::vector<int> c(10);
		for (std::size_t i = 0; i < c.size(); ++i) { c[i] = i * 10; }
		std::cout << "Display a vector of int" << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl;

	{
		std::list<std::string> c({"It", "works", "!"});
		std::cout << "Display a list of string" << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl;

	{
		std::vector<std::vector<int>> c(3, std::vector<int>(2));
		for (std::size_t i = 0; i < c.size(); ++i)
		{
			for (std::size_t j = 0; j < c[i].size(); ++j)
			{ c[i][j] = (i + j) * 10; }
		}
		std::cout << "Display a vector of vector of int" << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl;

	{
		std::vector<std::vector<int>> c(3, std::vector<int>(2));
		for (std::size_t i = 0; i < c.size(); ++i)
		{
			for (std::size_t j = 0; j < c[i].size(); ++j)
			{ c[i][j] = (i + j) * 10; }
		}
		std::cout << "Display a tuple" << std::endl;
		std::cout << std::make_tuple("One tuple of", 3, "elements") << std::endl;
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::ostream_STL_containers: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
