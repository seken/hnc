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
#include <thread>
#include <vector>

#include <hnc/print.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/terminal.hpp>
#include <hnc/sleep.hpp>
#include <hnc/random.hpp>


void test_print(bool const mutex)
{
	auto const print_fct = []() -> void
	{
		hnc::sleep::ns(hnc::random::uniform(1u, 3u));
		hnc::print("Test", ' ', "hnc::print", ':', ' ', 42, ", ", 3.14, ", ", std::string("std::string"), '\n');
	};
	
	auto const print_mutex_fct = []() -> void
	{
		hnc::sleep::ns(hnc::random::uniform(1u, 3u));
		hnc::print_mutex("Test", ' ', "hnc::print", ':', ' ', 42, ", ", 3.14, ", ", std::string("std::string"), '\n');
	};
	
	std::vector<std::thread> threads;
	for (unsigned int i = 0; i < 33; ++i)
	{
		threads.emplace_back(mutex ? print_mutex_fct : print_fct);
	}
	
	for (auto & thread : threads)
	{
		thread.join();
	}
}


int main()
{
	int nb_test = 0;
	
	std::cout << hnc::terminal::info << "hnc::print" << hnc::terminal::reset << std::endl;
	test_print(false);
	
	std::cout << hnc::terminal::info << "hnc::print_mutex" << hnc::terminal::reset << std::endl;
	test_print(true);
	
	hnc::test::warning(nb_test == 0, "hnc::print " + hnc::to_string(nb_test) + " test fail!\n");
	
	return nb_test;
}
