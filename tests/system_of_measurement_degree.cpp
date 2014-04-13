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
#include <hnc/system_of_measurement/radian.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	nb_test += 3;
	{
		std::cout << "Default constructor" << std::endl;
		hnc::degree<double> angle_double; std::cout << angle_double << std::endl;
		hnc::degree<int> angle_int; std::cout << angle_int << std::endl;
		hnc::degree<char> angle_char; std::cout << angle_char << std::endl;
// 		hnc::degree<std::string> angle_string; // Must fails at compile time
		nb_test -= hnc::test::warning(angle_double.value() == 0.0, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle_int.value() == 0, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle_char.value() == char(0), "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 4;
	{
		std::cout << "Constructor with value" << std::endl;
		hnc::degree<int> angle(1); std::cout << angle << std::endl;
		nb_test -= hnc::test::warning(angle.value() == 1, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle.value() == angle.degree_value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle == hnc::degree<int>(1), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle != hnc::degree<int>(0), "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 4;;
	{
		std::cout << "Copy constructor" << std::endl;
		hnc::degree<float> angle(hnc::degree<float>(42)); std::cout << angle << std::endl;
		nb_test -= hnc::test::warning(angle.value() == 42, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle.value() == angle.degree_value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle == hnc::degree<float>(42), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle != hnc::degree<float>(0), "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 4;
	{
		std::cout << "Operator=" << std::endl;
		hnc::degree<float> angle; angle = hnc::degree<float>(73); std::cout << angle << std::endl;
		nb_test -= hnc::test::warning(angle.value() == 73, "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle.value() == angle.degree_value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle == hnc::degree<float>(73), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle != hnc::degree<float>(0), "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 3;
	{
		std::cout << "Constructor with hnc::radian" << std::endl;
		hnc::radian<double> angle_radian(1.42); std::cout << angle_radian << " (" << angle_radian.degree_value() << "°)" << std::endl;
		hnc::degree<double> angle_degree(angle_radian); std::cout << angle_degree << " (" << angle_degree.radian_value() << "r)" << std::endl;
		nb_test -= hnc::test::warning(angle_degree.value() == angle_radian.degree_value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle_degree.radian_value() == angle_radian.value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle_degree == angle_radian, "hnc::degree fails\n");
	}
	std::cout << std::endl;

	nb_test += 3;
	{
		std::cout << "Operator= with hnc::radian" << std::endl;
		hnc::radian<double> angle_radian(1.57079); std::cout << angle_radian << " (" << angle_radian.degree_value() << "°)" << std::endl;
		hnc::degree<double> angle_degree; angle_degree = angle_radian; std::cout << angle_degree << " (" << angle_degree.radian_value() << "r)" << std::endl;
		nb_test -= hnc::test::warning(angle_degree.value() == angle_radian.degree_value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle_degree.radian_value() == angle_radian.value(), "hnc::degree fails\n");
		nb_test -= hnc::test::warning(angle_degree == angle_radian, "hnc::degree fails\n");
	}
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::degree: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
