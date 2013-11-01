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

#include <hnc/test.hpp>
#include <hnc/to_double.hpp>
#include <hnc/to_string.hpp>

int main()
{
	int nb_test = 0;

	std::cout << "Test hnc::to_double with int input" << std::endl;
	++nb_test;
	{
		int e = 0;
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == e, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		int e = 6464;
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == e, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		int e = -55646;
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == e, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	std::cout << std::endl;

	std::cout << "Test hnc::to_int with double input" << std::endl;
	++nb_test;
	{
		double e = 0.;
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == e, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		double e = 64.64;
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == e, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		double e = -556.46;
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == e, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	std::cout << std::endl;

	std::cout << "Test hnc::to_double with char input" << std::endl;
	++nb_test;
	{
		char e = '0';
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		char e = '5';
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 5, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		char e = 'a';
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		char e = '_';
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	++nb_test;
	{
		char e = '.';
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0, "hnc::to_double(" + hnc::to_string(e) + ") fail!\n");
	}
	std::cout << std::endl;

	std::cout << "Test hnc::to_double with std::string input" << std::endl;
	++nb_test;
	{
		std::string e = "0";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0, "hnc::to_double(" + e + ") fail!\n");
	}
	++nb_test;
	{
		std::string e = "6849.684";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 6849.684, "hnc::to_double(" + e + ") fail!\n");
	}
	++nb_test;
	{
		std::string e = ".5466";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0.5466, "hnc::to_double(" + e + ") fail!\n");
	}
	++nb_test;
	{
		std::string e = "-5.4686";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == -5.4686, "hnc::to_double(" + e + ") fail!\n");
	}
	++nb_test;
	{
		std::string e = "54.96zehtyhj";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 54.96, "hnc::to_double(" + e + ") fail!\n");
	}
	++nb_test;
	{
		std::string e = "rgerg5646";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0., "hnc::to_double(" + e + ") fail!\n");
	}
	++nb_test;
	{
		std::string e = "ezfzef456fzef";
		double i = hnc::to_double(e);
		std::cout << e << " == " << i << std::endl;
		nb_test -= hnc::test::warning(i == 0., "hnc::to_double(" + e + ") fail!\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::to_double: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
