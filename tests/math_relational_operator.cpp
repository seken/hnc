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

#include <hnc/math/relational_operator.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	std::cout << "                hnc::math::relational_operator::equal_to " << hnc::math::relational_operator::equal_to << std::endl;
	std::cout << "            hnc::math::relational_operator::not_equal_to " << hnc::math::relational_operator::not_equal_to << std::endl;
	std::cout << "            hnc::math::relational_operator::greater_than " << hnc::math::relational_operator::greater_than << std::endl;
	std::cout << "               hnc::math::relational_operator::less_than " << hnc::math::relational_operator::less_than << std::endl;
	std::cout << "hnc::math::relational_operator::greater_than_or_equal_to " << hnc::math::relational_operator::greater_than_or_equal_to << std::endl;
	std::cout << "   hnc::math::relational_operator::less_than_or_equal_to " << hnc::math::relational_operator::less_than_or_equal_to << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::relational_operator: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
