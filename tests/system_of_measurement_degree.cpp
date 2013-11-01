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
#include <fstream>
#include <string>

#include <hnc/system_of_measurement/degree.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	++nb_test;
	{
		std::cout << "Create default angles" << std::endl;
		hnc::degree<double> angle_double; std::cout << angle_double << std::endl;
		hnc::degree<int> angle_int; std::cout << angle_int << std::endl;
		hnc::degree<char> angle_char; std::cout << angle_char << std::endl;
// 		hnc::degree<std::string> angle_string; // Must fails at compile time
		nb_test -= hnc::test::warning(true, "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 2;
	{
		std::cout << "hnc::degree<int> angle(90);" << std::endl;
		hnc::degree<int> angle(90); std::cout << angle << std::endl;
		nb_test -= hnc::test::warning(angle.value() == 90, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle.value() == angle.degree_value(), "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 2;
	{
		std::cout << "hnc::degree<double> angle = hnc::degree<double>(3.14);" << std::endl;
		hnc::degree<double> angle = hnc::degree<double>(3.14); std::cout << angle << std::endl;
		nb_test -= hnc::test::warning(angle.value() == 3.14, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle.value() == angle.degree_value(), "hnc::degree fails\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::degree: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
