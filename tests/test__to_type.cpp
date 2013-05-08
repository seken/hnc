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
#include <string>
#include <limits>
#include <cmath>

#include <hnc/test.hpp>
#include <hnc/to_type.hpp>
#include <hnc/to_string.hpp>

int main()
{
	int nb_test = 0;

	std::cout << "std::string to int" << std::endl;
	++nb_test;
	{
		std::string i = "512";
		int s = hnc::to_<int>(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == 512, "hnc::to_type(" + hnc::to_string(i) + ") fail!\n");
	}
	std::cout << std::endl;

	std::cout << "std::string to double" << std::endl;
	++nb_test;
	{
		std::string i = "546.545";
		double s = hnc::to_<double>(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == 546.545, "hnc::to_type(" + hnc::to_string(i) + ") fail!\n");
	}
	std::cout << std::endl;

	// Test specialization
	
	std::cout << "std::string to std::string" << std::endl;
	++nb_test;
	{
		std::string i = "std::string to std::string";
		std::string s = hnc::to_<std::string>(i);
		std::cout << s << " == " << i << std::endl;
		nb_test -= hnc::test::warning(s == "std::string to std::string", "hnc::to_type(" + i + ") fail!\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::to_type: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
