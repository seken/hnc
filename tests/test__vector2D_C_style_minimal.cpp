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

#define hnc_ostream_container_data

#include <hnc/vector2D_C_style_minimal.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>













#include<vector>

int main()
{
	int nb_test = 0;

	// Default constructor
	++nb_test;
	{
		hnc::vector2D_C_style_minimal<int> v;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(v.nb_row() == 0 && v.nb_col() == 0, "hnc::vector2D_C_style_minimal default constructor fails\n");
	}
	std::cout << std::endl;

	// Constructor
	++nb_test;
	{
		hnc::vector2D_C_style_minimal<float> v(5, 10);
		bool test = v.nb_row() == 5 && v.nb_col() == 10;
		for (std::size_t i = 0; i < 5; ++i)
		{
			for (std::size_t j = 0; j < 10; ++j)
			{
				if (v[i][j] != 0) { test = false; }
			}
		}
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector2D_C_style_minimal constructor 5 rows, 10 columns fails\n");
	}
	std::cout << std::endl;

	// Constructor
	++nb_test;
	{
		hnc::vector2D_C_style_minimal<double> v(8, 4, 21);
		bool test = v.nb_row() == 8 && v.nb_col() == 4;
		for (std::size_t i = 0; i < 8; ++i)
		{
			for (std::size_t j = 0; j < 4; ++j)
			{
				if (v[i][j] != 21) { test = false; }
			}
		}
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector2D_C_style_minimal constructor 8 rows, 4 columns, default value = 21 fails\n");
	}
	std::cout << std::endl;

	// Move constructor
	nb_test += 2;
	{
		hnc::vector2D_C_style_minimal<int> v_base(3, 2, 42);
		hnc::vector2D_C_style_minimal<int> v = std::move(v_base);
		bool test = v.nb_row() == 3 && v.nb_col() == 2;
		for (std::size_t i = 0; i < v.nb_row(); ++i)
		{
			for (std::size_t j = 0; j < v.nb_col(); ++j)
			{
				if (v[i][j] != 42) { test = false; }
			}
		}
		std::cout << v_base << std::endl;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector2D_C_style_minimal constructor 3 rows, 2 columns, default value = 42 fails\n");
		nb_test -= hnc::test::warning(v_base.nb_row() == 0 && v_base.nb_col() == 0, "hnc::vector2D_C_style_minimal move constructor fails\n");
	}
	std::cout << std::endl;

std::vector<double> v0(10, 4699);
std::vector<double> v1;
v1 = std::move(v0);
std::vector<double> v2 = std::move(v1);
	
	// Move assignement operator
	nb_test += 2;
	{
		hnc::vector2D_C_style_minimal<float> v_base(5, 3, 73);
		hnc::vector2D_C_style_minimal<float> v;
		v = std::move(v_base);
		bool test = v.nb_row() == 5 && v.nb_col() == 3;
		for (std::size_t i = 0; i < v.nb_row(); ++i)
		{
			for (std::size_t j = 0; j < v.nb_col(); ++j)
			{
				if (v[i][j] != 73) { test = false; }
			}
		}
		std::cout << v_base << std::endl;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector2D_C_style_minimal move assignement operator 5 rows, 3 columns, default value = 73 fails\n");
		nb_test -= hnc::test::warning(v_base.nb_row() == 0 && v_base.nb_col() == 0, "hnc::vector2D_C_style_minimal move assignement operator fails\n");
	}
	std::cout << std::endl;

	// Assignement operator
	nb_test += 2;
	{
		hnc::vector2D_C_style_minimal<double> v_base(3, 5, 12);
		hnc::vector2D_C_style_minimal<double> v;
		v = v_base;
		bool test = v.nb_row() == 3 && v.nb_col() == 5;
		for (std::size_t i = 0; i < v.nb_row(); ++i)
		{
			for (std::size_t j = 0; j < v.nb_col(); ++j)
			{
				if (v[i][j] != 12) { test = false; }
			}
		}
		bool test_base = v_base.nb_row() == 3 && v.nb_col() == 5;
		for (std::size_t i = 0; i < v_base.nb_row(); ++i)
		{
			for (std::size_t j = 0; j < v_base.nb_col(); ++j)
			{
				if (v_base[i][j] != 12) { test_base = false; }
			}
		}
		std::cout << v << std::endl;
		std::cout << v_base << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector2D_C_style_minimal operator= (copy) 3 rows, 5 columns, default value = 12 fails\n");
		nb_test -= hnc::test::warning(test_base, "hnc::vector2D_C_style_minimal operator= (original) 3 rows, 5 columns, default value = 12 fails\n");
	}
	std::cout << std::endl;

	// operator []
	++nb_test;
	{
		hnc::vector2D_C_style_minimal<int> v(4, 8);
		{
			int value = 10;
			for (std::size_t i = 0; i < v.nb_row(); ++i)
			{
				for (std::size_t j = 0; j < v.nb_col(); ++j)
				{
					v[i][j] = ++value;
				}
			}
		}
		bool test = v.nb_row() == 4 && v.nb_col() == 8;
		{
			int value = 10;
			for (std::size_t i = 0; i < v.nb_row(); ++i)
			{
				for (std::size_t j = 0; j < v.nb_col(); ++j)
				{
					if (v[i][j] != ++value) { test = false; }
				}
			}
		}
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector2D_C_style_minimal operator[] 4 rows, 8 columns fails\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::vector2D_C_style_minimal: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
