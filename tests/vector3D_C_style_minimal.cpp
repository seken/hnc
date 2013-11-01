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

#include <hnc/vector3D_C_style_minimal.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>

int main()
{
	int nb_test = 0;

	// Default constructor
	++nb_test;
	{
		hnc::vector3D_C_style_minimal<int> v;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(v.size_x() == 0 && v.size_y() == 0, "hnc::vector3D_C_style_minimal default constructor fails\n");
	}
	std::cout << std::endl;

	// Constructor
	++nb_test;
	{
		hnc::vector3D_C_style_minimal<float> v(5, 10, 7);
		bool test = v.size_x() == 5 && v.size_y() == 10 && v.size_z() == 7;
		for (std::size_t x = 0; x < 5; ++x)
		{
			for (std::size_t y = 0; y < 10; ++y)
			{
				for (std::size_t z = 0; z < 7; ++z)
				{
					if (v[x][y][z] != 0) { test = false; }
				}
			}
		}
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector3D_C_style_minimal constructor 5 size_x, 10 size_y, 7 size_z fails\n");
	}
	std::cout << std::endl;

	// Test display
	{
		hnc::vector3D_C_style_minimal<int> v(5, 10, 7);
		int value = 1000;
		for (std::size_t x = 0; x < v.size_x(); ++x)
		{
			for (std::size_t y = 0; y < v.size_y(); ++y)
			{
				for (std::size_t z = 0; z < v.size_z(); ++z)
				{
					v[x][y][z] = ++value;
				}
			}
		}
		std::cout << v << std::endl;
	}
	std::cout << std::endl;

	// Constructor
	++nb_test;
	{
		hnc::vector3D_C_style_minimal<double> v(8, 4, 2, 21);
		bool test = v.size_x() == 8 && v.size_y() == 4 && v.size_z() == 2;
		for (std::size_t x = 0; x < v.size_x(); ++x)
		{
			for (std::size_t y = 0; y < v.size_y(); ++y)
			{
				for (std::size_t z = 0; z < v.size_z(); ++z)
				{
					if (v[x][y][z] != 21) { test = false; }
				}
			}
		}
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector3D_C_style_minimal constructor 8 size_x, 4 size_y, 2 size_z, default value = 21 fails\n");
	}
	std::cout << std::endl;

	// Move constructor
	nb_test += 2;
	{
		hnc::vector3D_C_style_minimal<int> v_base(3, 2, 4, 42);
		hnc::vector3D_C_style_minimal<int> v = std::move(v_base);
		bool test = v.size_x() == 3 && v.size_y() == 2 && v.size_z() == 4;
		for (std::size_t x = 0; x < v.size_x(); ++x)
		{
			for (std::size_t y = 0; y < v.size_y(); ++y)
			{
				for (std::size_t z = 0; z < v.size_z(); ++z)
				{
					if (v[x][y][z] != 42) { test = false; }
				}
			}
		}
		std::cout << v_base << std::endl;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector3D_C_style_minimal constructor 3 size_x, 2 size_y, 4 size_z, default value = 42 fails\n");
		nb_test -= hnc::test::warning(v_base.size_x() == 0 && v_base.size_y() == 0, "hnc::vector3D_C_style_minimal move constructor fails\n");
	}
	std::cout << std::endl;

	// Move assignement operator
	nb_test += 2;
	{
		hnc::vector3D_C_style_minimal<float> v_base(5, 3, 2, 73);
		hnc::vector3D_C_style_minimal<float> v;
		v = std::move(v_base);
		bool test = v.size_x() == 5 && v.size_y() == 3 && v.size_z() == 2;
		for (std::size_t x = 0; x < v.size_x(); ++x)
		{
			for (std::size_t y = 0; y < v.size_y(); ++y)
			{
				for (std::size_t z = 0; z < v.size_z(); ++z)
				{
					if (v[x][y][z] != 73) { test = false; }
				}
			}
		}
		std::cout << v_base << std::endl;
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector3D_C_style_minimal move assignement operator 5 size_x, 3 size_y, 2 size_z, default value = 73 fails\n");
		nb_test -= hnc::test::warning(v_base.size_x() == 0 && v_base.size_y() == 0, "hnc::vector3D_C_style_minimal move assignement operator fails\n");
	}
	std::cout << std::endl;

	// Assignement operator
	nb_test += 2;
	{
		hnc::vector3D_C_style_minimal<double> v_base(3, 5, 7, 12);
		hnc::vector3D_C_style_minimal<double> v;
		v = v_base;
		bool test = v.size_x() == 3 && v.size_y() == 5 && v.size_z() == 7;
		for (std::size_t x = 0; x < v.size_x(); ++x)
		{
			for (std::size_t y = 0; y < v.size_y(); ++y)
			{
				for (std::size_t z = 0; z < v.size_z(); ++z)
				{
					if (v[x][y][z] != 12) { test = false; }
				}
			}
		}
		bool test_base = v_base.size_x() == 3 && v_base.size_y() == 5 && v_base.size_z() == 7;
		for (std::size_t x = 0; x < v_base.size_x(); ++x)
		{
			for (std::size_t y = 0; y < v_base.size_y(); ++y)
			{
				for (std::size_t z = 0; z < v_base.size_z(); ++z)
				{
					if (v_base[x][y][z] != 12) { test = false; }
				}
			}
		}
		std::cout << v << std::endl;
		std::cout << v_base << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector3D_C_style_minimal operator= (copy) 3 size_x, 5 size_y, 7 size_z, default value = 12 fails\n");
		nb_test -= hnc::test::warning(test_base, "hnc::vector3D_C_style_minimal operator= (original) 3 size_x, 5 size_y, 7 size_z, default value = 12 fails\n");
	}
	std::cout << std::endl;

	// operator []
	++nb_test;
	{
		hnc::vector3D_C_style_minimal<int> v(4, 8, 5);
		{
			int value = 10;
			for (std::size_t x = 0; x < v.size_x(); ++x)
			{
				for (std::size_t y = 0; y < v.size_y(); ++y)
				{
					for (std::size_t z = 0; z < v.size_z(); ++z)
					{
						v[x][y][z] = ++value;
					}
				}
			}
		}
		bool test = v.size_x() == 4 && v.size_y() == 8 && v.size_z() == 5;
		{
			int value = 10;
			for (std::size_t x = 0; x < v.size_x(); ++x)
			{
				for (std::size_t y = 0; y < v.size_y(); ++y)
				{
					for (std::size_t z = 0; z < v.size_z(); ++z)
					{
						if (v[x][y][z] != ++value) { test = false; }
					}
				}
			}
		}
		std::cout << v << std::endl;
		nb_test -= hnc::test::warning(test, "hnc::vector3D_C_style_minimal operator[] 4 size_x, 8 size_y, 5 size_z fails\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::vector3D_C_style_minimal: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
