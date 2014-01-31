// Copyright © 2014 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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

#include <hnc/math/linear_equation.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq;
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({1});
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>({1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({1, 2});
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>({1, 2}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({}, {1});
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>({1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({}, {2, 1});
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>({2, 1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({2, 5, 1}, {1, 3, 4});
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>({2, 5, 1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>({1, 3, 4}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({1}, {}, 42);
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>({1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>(), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 42, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<int> eq({1, 0, 2}, {0, 0, 1}, 73, hnc::math::relational_operator::greater_than_or_equal_to);
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<int>({1, 0, 2}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<int>({0, 0, 1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 73, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::greater_than_or_equal_to, "hnc::math::linear_equation default constructor fails!\n");
	}

	nb_test += 4;
	{
		hnc::math::linear_equation<double> eq({21.73, 2, 7.1}, {42.21}, 0, hnc::math::relational_operator::less_than);
		std::cout << eq << std::endl;
		nb_test -= hnc::test::warning(eq.unknown_variables_coeff == std::vector<double>({21.73, 2, 7.1}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_coeff == std::vector<double>({42.21}), "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.constant == 0.0, "hnc::math::linear_equation default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.relational_operator == hnc::math::relational_operator::less_than, "hnc::math::linear_equation default constructor fails!\n");
	}

	hnc::test::warning(nb_test == 0, "hnc::math::linear_equation: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
