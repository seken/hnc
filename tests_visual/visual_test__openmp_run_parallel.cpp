// Copyright © 2012,2013 Lénaïc Bagnères, hnc@singularity.fr

// This file is part of hnc.

// hnc is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// hnc is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with hnc. If not, see <http://www.gnu.org/licenses/>


#include <iostream>
#include <string>
#include <functional>

#include <hnc/openmp/run_parallel.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


// You can use a fonction
void fct()
{
	std::cout << "fct" << std::endl;
}

// You can use a functor object
class obj_fct_t
{
private:

	int m;

public:

	obj_fct_t(int const i = 0) : m(i) { }

	void operator()()
	{
		std::cout << "functor object" + hnc::to_string(m) << std::endl;
	}
};


int main()
{
	// You can use a lambda function
	auto lambda_fct = []() { std::cout << "lambda_fct" << std::endl; };

	// A instance of functor object
	obj_fct_t obj_fct(42);

	int nb_test = 0;

	std::cout << "Use fonction:" << std::endl;
	hnc::openmp::run_parallel(fct);
	std::cout << std::endl;

	std::cout << "Use fonction, functor object:" << std::endl;
	hnc::openmp::run_parallel(fct, obj_fct);
	std::cout << std::endl;

	std::cout << "Use fonction, functor object, lambda function:" << std::endl;
	hnc::openmp::run_parallel(fct, obj_fct, lambda_fct);
	std::cout << std::endl;

	std::cout << "Use fonction, functor object, lambda function, fonction:" << std::endl;
	hnc::openmp::run_parallel(fct, obj_fct, lambda_fct, fct);
	std::cout << std::endl;

	std::cout << "Use fonction, functor object, lambda function, fonction, functor object:" << std::endl;
	hnc::openmp::run_parallel(fct, obj_fct, lambda_fct, fct, obj_fct);
	std::cout << std::endl;

	std::cout << "Use fonction, functor object, lambda function, fonction, functor object, lambda function:" << std::endl;
	hnc::openmp::run_parallel(fct, obj_fct, lambda_fct, fct, obj_fct, lambda_fct);
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::openmp::run_parallel: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
