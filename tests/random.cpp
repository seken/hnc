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
#include <vector>

#include <hnc/random.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	nb_test += 2;
	{
		int const n0 = hnc::random::uniform(-73, 42);
		int const n1 = hnc::random::uniform(100, 200);
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
		nb_test -= hnc::test::warning(n0 >= -73 && n0 <= 42, "hnc::random::uniform<int> fails");
		nb_test -= hnc::test::warning(n1 >= 100 && n1 <= 200, "hnc::random::uniform<int> fails");
	}
	std::cout << std::endl;
	
	nb_test += 2;
	{
		unsigned int const n0 = hnc::random::uniform(42u, 73u);
		unsigned int const n1 = hnc::random::uniform(100u, 200u);
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
		nb_test -= hnc::test::warning(n0 >= 42 && n0 <= 73, "hnc::random::uniform<unsigned int> fails");
		nb_test -= hnc::test::warning(n1 >= 100 && n1 <= 200, "hnc::random::uniform<unsigned int> fails");
	}
	std::cout << std::endl;
	
	nb_test += 2;
	{
		float const n0 = hnc::random::uniform(0.f, 1.f);
		float const n1 = hnc::random::uniform(-1.f, 0.f);
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
		nb_test -= hnc::test::warning(n0 >= 0.f && n0 <= 1.f, "hnc::random::uniform<unsigned int> fails");
		nb_test -= hnc::test::warning(n1 >= -1.f && n1 <= 1.f, "hnc::random::uniform<unsigned int> fails");
	}
	std::cout << std::endl;
	
	nb_test += 2;
	{
		double const n0 = hnc::random::uniform(0.0, 1.0);
		double const n1 = hnc::random::uniform(-1.0, 0.0);
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
		nb_test -= hnc::test::warning(n0 >= 0.0 && n0 <= 1.0, "hnc::random::uniform<unsigned int> fails");
		nb_test -= hnc::test::warning(n1 >= -1.0 && n1 <= 1.0, "hnc::random::uniform<unsigned int> fails");
	}
	std::cout << std::endl;
	
	{
		bool const n0 = hnc::random::true_false(0.5);
		bool const n1 = hnc::random::true_false();
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
	}
	std::cout << std::endl;
	
	nb_test += 2;
	{
		auto random = hnc::random::make_uniform_t(-73, 42);
		int const n0 = random();
		int const n1 = random(100, 200);
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
		nb_test -= hnc::test::warning(n0 >= -73 && n0 <= 42, "hnc::random::uniform<int> fails");
		nb_test -= hnc::test::warning(n1 >= 100 && n1 <= 200, "hnc::random::uniform<int> fails");
	}
	std::cout << std::endl;
	
	{
		auto random = hnc::random::make_true_false_t();
		int const n0 = random();
		int const n1 = random(0.1);
		std::cout << n0 << std::endl;
		std::cout << n1 << std::endl;
	}
	std::cout << std::endl;
	
	{
		auto random = hnc::random::make_uniform_t(0, 9);
		std::vector<int> r(10, 0);
		for (unsigned int i = 0; i < 10000; ++i)
		{
			++r.at(std::size_t(random()));
		}
		for (std::size_t i =0; i < r.size(); ++i)
		{
			std::cout << i << " - " << r[i] << std::endl;
		}
	}
	std::cout << std::endl;
	
	{
		auto random = hnc::random::make_true_false_t();
		std::vector<int> r(2, 0);
		for (unsigned int i = 0; i < 1000; ++i)
		{
			if (random()) { ++r[1]; }
			if (random()) { ++r[0]; }
		}
		for (std::size_t i =0; i < r.size(); ++i)
		{
			std::cout << i << " - " << r[i] << std::endl;
		}
	}
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::random: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return 0;
}
