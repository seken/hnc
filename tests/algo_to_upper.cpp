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
#include <string>
#include <vector>

#include <hnc/algo/to_upper.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	{
		std::string s("A example with std::string.");
		
		std::cout << s << std::endl;
		hnc::algo::to_upper(s);
		std::cout << s << std::endl;
		std::cout << std::endl;
		
		nb_test -= hnc::test::warning(s == "A EXAMPLE WITH STD::STRING.", "hnc::algo::to_upper fails\n");
	}

	++nb_test;
	{
		std::vector<char> s({ 'A', ' ', 'e', 'x', 'a', 'm', 'p', 'l', 'e', ' ', 'w', 'i', 't', 'h', ' ', 's', 't', 'd', ':', ':', 'v', 'e', 'c', 't', 'o', 'r', '<', 'c', 'h', 'a', 'r', '>', '.' });
		
		std::cout << s << std::endl;
		hnc::algo::to_upper(s);
		std::cout << s << std::endl;
		std::cout << std::endl;
		
		nb_test -= hnc::test::warning(s == std::vector<char>({ 'A', ' ', 'E', 'X', 'A', 'M', 'P', 'L', 'E', ' ', 'W', 'I', 'T', 'H', ' ', 'S', 'T', 'D', ':', ':', 'V', 'E', 'C', 'T', 'O', 'R', '<', 'C', 'H', 'A', 'R', '>', '.' }), "hnc::algo::to_upper fails\n");
	}

	++nb_test;
	{
		std::string s("A example with std::string.");
		
		std::cout << s << std::endl;
		auto const copy = hnc::algo::to_upper_copy(s);
		std::cout << s << std::endl;
		std::cout << copy << std::endl;
		std::cout << std::endl;
		
		nb_test -= hnc::test::warning(s == "A example with std::string." && copy == "A EXAMPLE WITH STD::STRING.", "hnc::algo::to_upper fails\n");
	}

	++nb_test;
	{
		std::vector<char> s({ 'A', ' ', 'e', 'x', 'a', 'm', 'p', 'l', 'e', ' ', 'w', 'i', 't', 'h', ' ', 's', 't', 'd', ':', ':', 'v', 'e', 'c', 't', 'o', 'r', '<', 'c', 'h', 'a', 'r', '>', '.' });
		
		std::cout << s << std::endl;
		auto const copy = hnc::algo::to_upper_copy(s);
		std::cout << s << std::endl;
		std::cout << copy << std::endl;
		std::cout << std::endl;
		
		nb_test -= hnc::test::warning(s == std::vector<char>({ 'A', ' ', 'e', 'x', 'a', 'm', 'p', 'l', 'e', ' ', 'w', 'i', 't', 'h', ' ', 's', 't', 'd', ':', ':', 'v', 'e', 'c', 't', 'o', 'r', '<', 'c', 'h', 'a', 'r', '>', '.' }) && copy == std::vector<char>({ 'A', ' ', 'E', 'X', 'A', 'M', 'P', 'L', 'E', ' ', 'W', 'I', 'T', 'H', ' ', 'S', 'T', 'D', ':', ':', 'V', 'E', 'C', 'T', 'O', 'R', '<', 'C', 'H', 'A', 'R', '>', '.' }), "hnc::algo::to_upper fails\n");
	}

	hnc::test::warning(nb_test == 0, "hnc::algo::to_upper: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
