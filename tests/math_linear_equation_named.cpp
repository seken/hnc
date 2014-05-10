// Copyright © 2014 David Guinehut, dvdg@singularity.fr

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

#include <hnc/math/linear_equation_named.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>

int main()
{
	int nb_test = 0;

	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq;
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
	
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>(), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({1},{"x"});
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>({1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>(), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({1, 2}, {"x", "x'"});
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>({1, 2}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x", "x'"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>(), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({}, {"x"}, {1}, {"A"});
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>({1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>({"A"}), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({}, {}, {2, 1}, {"A", "A'"});
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>({2, 1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>({"A", "A'"}), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({2, 5, 1}, {"x", "x'", "x''"}, {1, 3, 4}, {"A", "A'", "A''"});
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>({2, 5, 1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>({1, 3, 4}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x", "x'", "x''"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>({"A", "A'", "A''"}), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({1}, {"x"}, {}, {}, 42);
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>({1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>(), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 42, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>(), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<int> eq({1, 2}, {"x", "y"}, {1}, {"P"}, 73, hnc::math::relational_operator::greater_than_or_equal_to);
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<int>({1, 2}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<int>({1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 73, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::greater_than_or_equal_to, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x", "y"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>({"P"}), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 6;
	{
		hnc::math::linear_equation_named<double> eq({21.73, 2, 7.1}, {"x", "y", "z"}, {42.21}, {"NP"}, 0, hnc::math::relational_operator::less_than);
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		nb_test -= hnc::test::warning(eq.linear_equation().unknown_variables_coeff == std::vector<double>({21.73, 2, 7.1}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().parameters_coeff == std::vector<double>({42.21}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().constant == 0, "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.linear_equation().relational_operator == hnc::math::relational_operator::less_than, "hnc::math::linear_equation_named default constructor fails!\n");
		
		nb_test -= hnc::test::warning(eq.unknown_variables_name() == std::vector<std::string>({"x", "y", "z"}), "hnc::math::linear_equation_named default constructor fails!\n");
		nb_test -= hnc::test::warning(eq.parameters_name() == std::vector<std::string>({"NP"}), "hnc::math::linear_equation_named default constructor fails!\n");
	}
	
	nb_test += 7;
	{
		hnc::math::linear_equation_named<int> eq_io;
		hnc::math::linear_equation_named<int> eq({21,2}, {"x", "y"}, {1}, {"NP"}, 42, hnc::math::relational_operator::greater_than);
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		// Output of eq
		std::ostringstream o1, o2;
		o1 << eq; 
		
		// Parse "21x + 2y + NP + 42 < 0"
		std::istringstream i(o1.str());
		i >> eq_io;
		
		// Output of eq_io
		o2 << eq_io;
		
		nb_test -= hnc::test::warning(o1.str() == o2.str(), "hnc::math::linear_equation_named istream operator fails!\n");
		
		nb_test -= hnc::test::warning(eq_io.linear_equation().unknown_variables_coeff == std::vector<int>({21, 2}), "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.linear_equation().parameters_coeff == std::vector<int>({1}), "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.linear_equation().constant == 42, "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.linear_equation().relational_operator == hnc::math::relational_operator::greater_than, "hnc::math::linear_equation_named istream operator fails!\n");
		
		nb_test -= hnc::test::warning(eq_io.unknown_variables_name() == std::vector<std::string>({"x", "y"}), "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.parameters_name() == std::vector<std::string>({"NP"}), "hnc::math::linear_equation_named istream operator fails!\n");
	}
	
	nb_test += 7;
	{
		hnc::math::linear_equation_named<double> eq_io;
		hnc::math::linear_equation_named<double> eq({21.73, 2, 7.1}, {"x", "y", "z"}, {42.21}, {"NP"}, 0, hnc::math::relational_operator::less_than);
		std::cout << eq << std::endl;
		std::cout << eq.linear_equation() << std::endl;
		
		// Output of eq
		std::ostringstream o1, o2;
		o1 << eq; 
		
		// Parse "21.73x + 2y + 7.1z + 42.21NP < 0"
		std::istringstream i(o1.str());
		i >> eq_io;
		
		// Output of eq_io
		o2 << eq_io;
		
		nb_test -= hnc::test::warning(o1.str() == o2.str(), "hnc::math::linear_equation_named istream operator fails!\n");
		
		nb_test -= hnc::test::warning(eq_io.linear_equation().unknown_variables_coeff == std::vector<double>({21.73, 2, 7.1}), "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.linear_equation().parameters_coeff == std::vector<double>({42.21}), "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.linear_equation().constant == 0.0, "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.linear_equation().relational_operator == hnc::math::relational_operator::less_than, "hnc::math::linear_equation_named istream operator fails!\n");
		
		nb_test -= hnc::test::warning(eq_io.unknown_variables_name() == std::vector<std::string>({"x", "y", "z"}), "hnc::math::linear_equation_named istream operator fails!\n");
		nb_test -= hnc::test::warning(eq_io.parameters_name() == std::vector<std::string>({"NP"}), "hnc::math::linear_equation_named istream operator fails!\n");
	}
	
	hnc::test::warning(nb_test == 0, "hnc::math::linear_equation_named: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
 
