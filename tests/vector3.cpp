// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/vector3.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// Constructors
	
	std::cout << hnc::terminal::info << "Constructors" << hnc::terminal::reset << std::endl;

	++nb_test;
	{
		hnc::vector3<int> v;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(v.x == 0 && v.y == 0 && v.z == 0, "hnc::vector3 " + hnc::to_string(v) + " fails\n");
	}

	++nb_test;
	{
		hnc::vector3<unsigned int> v(1, 2, 3);
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(v.x == static_cast<unsigned int>(1) && v.y == static_cast<unsigned int>(2) && v.z == static_cast<unsigned int>(3), "hnc::vector3 " + hnc::to_string(v) + " fails\n");
	}

	++nb_test;
	{
		hnc::vector3<float> v(hnc::vector3<float>(0.5, 1.5, 2.5));
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(v.x == 0.5f && v.y == 1.5f && v.z == 2.5f, "hnc::vector3 " + hnc::to_string(v) + " fails\n");
	}

	++nb_test;
	{
		hnc::vector3<int> v(1, 2, 3); v = hnc::vector3<int>(-1, -2, -3);
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(v.x == -1 && v.y == -2 && v.z == -3, "hnc::vector3 " + hnc::to_string(v) + " fails\n");
	}
	
	std::cout << std::endl;
	
	// Operator == and !=

	++nb_test;
	{
		hnc::vector3<int> v0(1, 2, 3);
		hnc::vector3<int> v1(1, 2, 3);
		std::cout << v0 << " == " << v1 << std::endl;
		nb_test -= hnc::test::warning(v0 == v1 && (v0 != v1) == false, "hnc::vector3 " + hnc::to_string(v0) + " == " + hnc::to_string(v1) + " fails\n");
	}

	++nb_test;
	{
		hnc::vector3<double> v0(3.14, 42, 21);
		hnc::vector3<double> v1(3.14, 42, 73);
		std::cout << v0 << " != " << v1 << std::endl;
		nb_test -= hnc::test::warning(v0 != v1 && (v0 == v1) == false, "hnc::vector3 " + hnc::to_string(v0) + " != " + hnc::to_string(v1) + " fails\n");
	}
	
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::vector3: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
