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

#include <hnc/math/gcd.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	// 54 and 24
	
	++nb_test;
	{
		int const a = 54;
		int const b = 24;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 6, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = 24;
		int const b = 54;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 6, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = -54;
		int const b = -24;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 6, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = -54;
		int const b = 24;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 6, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = 54;
		int const b = -24;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 6, "hnc::math::gcd fails\n");
	}
	
	// 42 and 56
	
	++nb_test;
	{
		int const a = 42;
		int const b = 56;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 14, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = 56;
		int const b = 42;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 14, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = -42;
		int const b = -56;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 14, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = -42;
		int const b = 56;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 14, "hnc::math::gcd fails\n");
	}
	
	++nb_test;
	{
		int const a = 42;
		int const b = -56;
		int const gcd = hnc::math::gcd(a, b);
		std::cout << "gcd of " << a << " and " << b << " is " << gcd << std::endl;
		nb_test -= hnc::test::warning(gcd == 14, "hnc::math::gcd fails\n");
	}
	
	hnc::test::warning(nb_test == 0, "hnc::math::gcd: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return nb_test;
}
