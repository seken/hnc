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
#include <algorithm>
#include <string>
#include <vector>
#include <list>

#include <hnc/algo.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	int nb_test = 0;
	
	// std::vector<int>
	
	++nb_test;
	{
		std::vector<int> c({4, 8, 7, 6, 2});
		std::cout << c << std::endl;
		
		auto & r = hnc::algo::random_element(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::vector<int> const c({4, 8, 7, 6, 2});
		std::cout << c << std::endl;
		
		auto const & r = hnc::algo::random_element(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::vector<int> const c({4, 8, 7, 6, 2});
		std::cout << c << std::endl;
		
		auto r = hnc::algo::random_element_copy(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	// std::list<std::string>
	
	++nb_test;
	{
		std::list<std::string> c({"A", "std::list", "of", "std::string"});
		std::cout << c << std::endl;
		
		auto & r = hnc::algo::random_element(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::list<std::string> c({"A", "std::list", "of", "std::string"});
		std::cout << c << std::endl;
		
		auto const & r = hnc::algo::random_element(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::list<std::string> c({"A", "std::list", "of", "std::string"});
		std::cout << c << std::endl;
		
		auto r = hnc::algo::random_element_copy(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	// std::string
	
	++nb_test;
	{
		std::string c("A std::string");
		std::cout << c << std::endl;
		
		auto & r = hnc::algo::random_element(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::string c("A std::string");
		std::cout << c << std::endl;
		
		auto const & r = hnc::algo::random_element(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::string c("A std::string");
		std::cout << c << std::endl;
		
		auto r = hnc::algo::random_element_copy(c);
		std::cout << r << std::endl;
		
		nb_test -= hnc::test::warning(std::find(c.begin(), c.end(), r) != c.end(), "hnc::ago::random_element fails with " + hnc::to_string(c) + "\n");
	}
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::algo::random_element: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return 0;
}
