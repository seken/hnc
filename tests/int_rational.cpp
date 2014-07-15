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
#include <sstream>

#include <hnc/int.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	++nb_test;
	{
		hnc::rational<int> const r(5);
		std::cout << "Rational = " << r << std::endl;
		nb_test -= hnc::test::warning(r.numerator() == 5 && r.denominator() == 1, "hnc::rational fails\n");
	}
	
	++nb_test;
	{
		hnc::rational<unsigned int> const r(10, 2);
		std::cout << "Rational = " << r << std::endl;
		nb_test -= hnc::test::warning(r.numerator() == 5u && r.denominator() == 1u, "hnc::rational fails\n");
	}
	
	++nb_test;
	{
		hnc::rational<int> const r(63, 462);
		std::cout << "Rational = " << r << std::endl;
		nb_test -= hnc::test::warning(r.numerator() == 3 && r.denominator() == 22, "hnc::rational fails\n");
	}
	
	++nb_test;
	{
		hnc::rational<int> const r(-63, -462);
		std::cout << "Rational = " << r << std::endl;
		nb_test -= hnc::test::warning(r.numerator() == 3 && r.denominator() == 22, "hnc::rational fails\n");
	}
	
	++nb_test;
	{
		hnc::rational<int> const r(-63, 462);
		std::cout << "Rational = " << r << std::endl;
		nb_test -= hnc::test::warning(r.numerator() == -3 && r.denominator() == 22, "hnc::rational fails\n");
	}
	
	++nb_test;
	{
		hnc::rational<int> const r(63, -462);
		std::cout << "Rational = " << r << std::endl;
		nb_test -= hnc::test::warning(r.numerator() == -3 && r.denominator() == 22, "hnc::rational fails\n");
	}
	
	hnc::test::warning(nb_test == 0, "hnc::rational: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return nb_test;
}
