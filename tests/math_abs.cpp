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

#include <hnc/math/abs.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	++nb_test;
	{
		int const n = 54;
		int const r = hnc::math::abs(n);
		std::cout << "Absolute value of " << n << " is " << r << std::endl;
		nb_test -= hnc::test::warning(r == 54, "hnc::math::abs fails\n");
	}
	
	++nb_test;
	{
		int const n = -42;
		int const r = hnc::math::abs(n);
		std::cout << "Absolute value of " << n << " is " << r << std::endl;
		nb_test -= hnc::test::warning(r == 42, "hnc::math::abs fails\n");
	}
	
	++nb_test;
	{
		double const n = -21.73;
		double const r = hnc::math::abs(n);
		std::cout << "Absolute value of " << n << " is " << r << std::endl;
		nb_test -= hnc::test::warning(r == 21.73, "hnc::math::abs fails\n");
	}
	
	++nb_test;
	{
		float const n = 42.21f;
		float const r = hnc::math::abs(n);
		std::cout << "Absolute value of " << n << " is " << r << std::endl;
		nb_test -= hnc::test::warning(r == 42.21f, "hnc::math::abs fails\n");
	}
	
	hnc::test::warning(nb_test == 0, "hnc::math::abs: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return nb_test;
}
