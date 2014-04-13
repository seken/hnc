// Copyright © 2012,2013 Lénaïc Bagnères, hnc@singularity.fr

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
#include <vector>

#include <hnc/vector2D.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// Create a vector2D
	hnc::vector2D<int> ref(4, 5);
	{
		unsigned int i = 10;
		for (std::size_t row = 0; row < ref.nb_row(); ++row)
		{
			for (std::size_t col = 0; col < ref.nb_col(); ++col)
			{
				ref(row, col) = int(i++);
			}
		}
	}
	std::cout << "Reference:\n" << ref << "\n" << std::endl;

	// Same value in std::vector
	std::vector<int> ref_vector;
	for (std::size_t row = 0; row < ref.nb_row(); ++row)
	{
		for (std::size_t col = 0; col < ref.nb_col(); ++col)
		{
			ref_vector.push_back(ref(row, col));
		}
	}

	// Check acces
	
	++nb_test;
	{
		bool same_value = true;
		// 0
		if (ref.at(0, 0) != 10) { same_value = false; }
		if (ref.at(0, 1) != 11) { same_value = false; }
		if (ref.at(0, 2) != 12) { same_value = false; }
		if (ref.at(0, 3) != 13) { same_value = false; }
		if (ref.at(0, 4) != 14) { same_value = false; }
		// 1
		if (ref.at(1, 0) != 15) { same_value = false; }
		if (ref.at(1, 1) != 16) { same_value = false; }
		if (ref.at(1, 2) != 17) { same_value = false; }
		if (ref.at(1, 3) != 18) { same_value = false; }
		if (ref.at(1, 4) != 19) { same_value = false; }
		// 2
		if (ref.at(2, 0) != 20) { same_value = false; }
		if (ref.at(2, 1) != 21) { same_value = false; }
		if (ref.at(2, 2) != 22) { same_value = false; }
		if (ref.at(2, 3) != 23) { same_value = false; }
		if (ref.at(2, 4) != 24) { same_value = false; }
		// 3
		if (ref.at(3, 0) != 25) { same_value = false; }
		if (ref.at(3, 1) != 26) { same_value = false; }
		if (ref.at(3, 2) != 27) { same_value = false; }
		if (ref.at(3, 3) != 28) { same_value = false; }
		if (ref.at(3, 4) != 29) { same_value = false; }
		nb_test -= hnc::test::warning(same_value, "vector2D reference values are false (with at access)\n");
	}

	++nb_test;
	{
		bool same_value = true;
		{
			std::size_t i = 0;
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref(row, col) != ref_vector.at(i)) { same_value = false; }
					++i;
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D reference values are false with fonctor acces\n");
	}

	++nb_test;
	{
		bool same_value = true;
		{
			std::size_t i = 0;
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref.at(row, col) != ref_vector.at(i)) { same_value = false; }
					++i;
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D reference values are false with at acces\n");
	}

	++nb_test;
	{
		bool same_value = true;
		{
			std::size_t i = 0;
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref(row, col) != ref_vector.at(i)) { same_value = false; }
					++i;
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D reference values are false with for range loop\n");
	}

	++nb_test;
	{
		bool same_value = true;
		{
			std::size_t i = 0;
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref[row][col] != ref_vector.at(i)) { same_value = false; }
					++i;
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D reference values are false with [row][col] access\n");
	}
	
	++nb_test;
	{
		bool same_value = true;
		// 0
		if (ref.front()[0] != 10) { same_value = false; }
		if (ref.front()[1] != 11) { same_value = false; }
		if (ref.front()[2] != 12) { same_value = false; }
		if (ref.front()[3] != 13) { same_value = false; }
		if (ref.front()[4] != 14) { same_value = false; }
		nb_test -= hnc::test::warning(same_value, "vector2D .front() fails\n");
	}
	
	++nb_test;
	{
		bool same_value = true;
		// 0
		if (ref.back()[0] != 25) { same_value = false; }
		if (ref.back()[1] != 26) { same_value = false; }
		if (ref.back()[2] != 27) { same_value = false; }
		if (ref.back()[3] != 28) { same_value = false; }
		if (ref.back()[4] != 29) { same_value = false; }
		nb_test -= hnc::test::warning(same_value, "vector2D .back() fails\n");
	}
	
	++nb_test;
	{
		bool same_value = true;
		// 0
		if (ref[0].front() != 10) { same_value = false; }
		if (ref[1].front() != 15) { same_value = false; }
		if (ref[2].front() != 20) { same_value = false; }
		if (ref[3].front() != 25) { same_value = false; }
		nb_test -= hnc::test::warning(same_value, "vector2D [i].front() fails\n");
	}
	
	++nb_test;
	{
		bool same_value = true;
		// 0
		if (ref[0].back() != 14) { same_value = false; }
		if (ref[1].back() != 19) { same_value = false; }
		if (ref[2].back() != 24) { same_value = false; }
		if (ref[3].back() != 29) { same_value = false; }
		nb_test -= hnc::test::warning(same_value, "vector2D [i].back() fails\n");
	}

	// Check constructors

	++nb_test;
	{
		hnc::vector2D<int> ref_copy(ref);
		bool same_value = true;
		{
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref(row, col) != ref_copy.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D constructor copy does not work\n");
	}
	
	++nb_test;
	{
		std::vector<std::vector<int>> values(4, std::vector<int>(5));
		values.at(0).at(0)=10; values.at(0).at(1)=11; values.at(0).at(2)=12; values.at(0).at(3)=13; values.at(0).at(4)=14;
		values.at(1).at(0)=15; values.at(1).at(1)=16; values.at(1).at(2)=17; values.at(1).at(3)=18; values.at(1).at(4)=19;
		values.at(2).at(0)=20; values.at(2).at(1)=21; values.at(2).at(2)=22; values.at(2).at(3)=23; values.at(2).at(4)=24;
		values.at(3).at(0)=25; values.at(3).at(1)=26; values.at(3).at(2)=27; values.at(3).at(3)=28; values.at(3).at(4)=29;
		hnc::vector2D<int> v(values);
		bool same_value = true;
		{
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref(row, col) != v.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D std::vector<std::vector<int>> constructor does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		bool same_value = true;
		{
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref(row, col) != v.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D { {10, 11, 12}, {20, 21, 22} } constructor does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> ref_copy; ref_copy = ref;
		bool same_value = true;
		{
			for (std::size_t row = 0; row < ref.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < ref.nb_col(); ++col)
				{
					if (ref(row, col) != ref_copy.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D copy does not work\n");
	}

	// Check operator == and !=

	++nb_test;
	{
		hnc::vector2D<int> v({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning(v == v, "vector2D operator == test a. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning(v0 == v1, "vector2D operator == test b. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{99,99,99,99,99}, {99,99,99,99,99}, {99,99,99,99,99}, {99,99,99,99,99}});
		nb_test -= hnc::test::warning((v0 == v1) == false, "vector2D operator == test c. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{99,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning((v0 == v1) == false, "vector2D operator == test d. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,99}});
		nb_test -= hnc::test::warning((v0 == v1) == false, "vector2D operator == test e. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{10,11,12,13,14}, {15,16,17,18,99}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning((v0 == v1) == false, "vector2D operator == test f. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{99,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning(v0 != v1, "vector2D operator != test a. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,99}});
		nb_test -= hnc::test::warning(v0 != v1, "vector2D operator != test b. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{10,11,12,13,14}, {15,16,17,18,99}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning(v0 != v1, "vector2D operator != test c. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning((v != v) == false, "vector2D operator != test a. fails\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v0({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		hnc::vector2D<int> v1({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
		nb_test -= hnc::test::warning((v0 != v1) == false, "vector2D operator != test b. fails\n");
	}

	// Check add row

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_row_before(1, 21);
		std::cout << "add_row_before(1, 21):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {21,21,21,21,21}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col)
						!= values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_row_before does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_row_after(1, 21);
		std::cout << "add_row_after(1, 21):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {15,16,17,18,19}, {21,21,21,21,21}, {20,21,22,23,24}, {25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_row_after does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_row_before(0, 21);
		std::cout << "add_row_before(0, 21):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{21,21,21,21,21}, {10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_row_before does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_row_after(0, 21);
		std::cout << "add_row_after(0, 21):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {21,21,21,21,21}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_row_after does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_row_before(4, 21);
		std::cout << "add_row_before(4, 21):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}, {21,21,21,21,21}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_row_before does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_row_after(3, 21);
		std::cout << "add_row_after(3, 21):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}, {21,21,21,21,21}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_row_after does not work\n");
	}

	#ifndef NDEBUG
	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		bool except = false;
		try
		{
			v.add_row_before(5, 21);
		}
		catch(std::out_of_range const & e)
		{
			except = true;
		}
		nb_test -= hnc::test::warning(except, "vector2D add_row_before (invalid id row) does not work\n");
	}
	#endif

	#ifndef NDEBUG
	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		bool except = false;
		try
		{
			v.add_row_after(4, 21);
		}
		catch(std::out_of_range const & e)
		{
			except = true;
		}
		nb_test -= hnc::test::warning(except, "vector2D add_row_before (invalid id row) does not work\n");
	}
	#endif

	// Check add column

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_before(3, 42);
		std::cout << "add_col_before(3, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,42,13,14}, {15,16,17,42,18,19}, {20,21,22,42,23,24}, {25,26,27,42,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_before does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_after(3, 42);
		std::cout << "add_col_after(3, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,42,14}, {15,16,17,18,42,19}, {20,21,22,23,42,24}, {25,26,27,28,42,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_after does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_before(0, 42);
		std::cout << "add_col_before(0, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{42,10,11,12,13,14}, {42,15,16,17,18,19}, {42,20,21,22,23,24}, {42,25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_before does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_after(0, 42);
		std::cout << "add_col_after(0, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,42,11,12,13,14}, {15,42,16,17,18,19}, {20,42,21,22,23,24}, {25,42,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_after does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_before(4, 42);
		std::cout << "add_col_before(4, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,42,14}, {15,16,17,18,42,19}, {20,21,22,23,42,24}, {25,26,27,28,42,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_before does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_after(4, 42);
		std::cout << "add_col_after(4, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14,42}, {15,16,17,18,19,42}, {20,21,22,23,24,42}, {25,26,27,28,29,42}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_after does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.add_col_before(5, 42);
		std::cout << "add_col_before(5, 42):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14,42}, {15,16,17,18,19,42}, {20,21,22,23,24,42}, {25,26,27,28,29,42}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D add_col_before does not work\n");
	}

	#ifndef NDEBUG
	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		bool except = false;
		try
		{
			v.add_col_before(6, 42);
		}
		catch(std::out_of_range const & e)
		{
			except = true;
		}
		nb_test -= hnc::test::warning(except, "vector2D add_col_before (invalid id col) does not work\n");
	}
	#endif

	#ifndef NDEBUG
	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		bool except = false;
		try
		{
			v.add_col_after(5, 42);
		}
		catch(std::out_of_range const & e)
		{
			except = true;
		}
		nb_test -= hnc::test::warning(except, "vector2D add_col_before (invalid id col) does not work\n");
	}
	#endif

	// Check remove line

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.remove_line(0);
		std::cout << "remove_line(0):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{15,16,17,18,19}, {20,21,22,23,24}, {25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D remove_line does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.remove_line(2);
		std::cout << "remove_line(2):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {15,16,17,18,19}, {25,26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D remove_line does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.remove_line(3);
		std::cout << "remove_line(3):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13,14}, {15,16,17,18,19}, {20,21,22,23,24}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D remove_line does not work\n");
	}

	#ifndef NDEBUG
	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		bool except = false;
		try
		{
			v.remove_line(4);
		}
		catch(std::out_of_range const & e)
		{
			except = true;
			std::cout << "Could not remove line 4: nb rows = " << v.nb_row() << ", nb columns = " << v.nb_col() << "\n" << std::endl;
		}
		nb_test -= hnc::test::warning(except, "vector2D remove_line (invalid id line) does not work\n");
	}
	#endif

	// Check remove column

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.remove_column(0);
		std::cout << "remove_column(0):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{11,12,13,14}, {16,17,18,19}, {21,22,23,24}, {26,27,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D remove_column does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.remove_column(2);
		std::cout << "remove_column(2):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,13,14}, {15,16,18,19}, {20,21,23,24}, {25,26,28,29}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D remove_column does not work\n");
	}

	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		v.remove_column(4);
		std::cout << "remove_column(4):\n" << v << "\n" << std::endl;
		bool same_value = true;
		{
			hnc::vector2D<int> values({{10,11,12,13}, {15,16,17,18}, {20,21,22,23}, {25,26,27,28}});
			for (std::size_t row = 0; row < values.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < values.nb_col(); ++col)
				{
					if (v.at(row, col) != values.at(row, col)) { same_value = false; }
				}
			}
		}
		nb_test -= hnc::test::warning(same_value, "vector2D remove_column does not work\n");
	}

	#ifndef NDEBUG
	++nb_test;
	{
		hnc::vector2D<int> v(ref);
		bool except = false;
		try
		{
			v.remove_column(5);
		}
		catch(std::out_of_range const & e)
		{
			except = true;
			std::cout << "Could not remove column 5: nb rows = " << v.nb_row() << ", nb columns = " << v.nb_col() << "\n" << std::endl;
		}
		nb_test -= hnc::test::warning(except, "vector2D remove_column (invalid id line) does not work\n");
	}
	#endif

	// Check iterators

	{
		hnc::vector2D<int> v(ref);
		std::cout << "Play with .begin() & .end()" << std::endl;
		std::cout << (*v.begin())[0] << std::endl;
		std::cout << (*(v.end() - 1))[0] << std::endl;
		std::cout << "Play with .begin().begin() & .end().end()" << std::endl;
		std::cout << v.begin()->begin()[0] << std::endl;
		std::cout << ((v.end() - 1)->end() - 1)[0] << std::endl;
		std::cout << std::endl;
	}

	nb_test += 2;
	{
		hnc::vector2D<int> v(ref);
		std::cout << "Read the first element of each lines:" << std::endl;
		std::vector<int> read0;
		{
			for (std::size_t row = 0; row < v.nb_row(); ++row)
			{
				std::size_t col = 0;
				std::cout << v[row][col] << " ";
				read0.push_back(v[row][col]);
			}
			std::cout << std::endl;
		}
		std::cout << "Read the first element of each lines with iterator:" << std::endl;
		std::vector<int> read1;
		{
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				std::cout << (*it)[0] << " ";
				read1.push_back((*it)[0]);
			}
			std::cout << std::endl;
		}
		std::cout << "Read the first element of each lines with for (l : v):" << std::endl;
		std::vector<int> read2;
		{
			for (auto l : v)
			{
				std::cout << l[0] << " ";
				read2.push_back(l[0]);
			}
			std::cout << std::endl;
		}
		nb_test -= hnc::test::warning(read0 == read1, "Read the first element of each lines with begin/end does not work\n");
		nb_test -= hnc::test::warning(read1 == read2, "Read the first element of each lines with begin/end does not work\n");
		std::cout << std::endl;
	}

	nb_test += 2;
	{
		hnc::vector2D<int> v(ref);
		std::cout << "Read the second line:" << std::endl;
		std::vector<int> read0;
		{
			std::size_t row = 1;
			for (std::size_t col = 0; col < v.nb_col(); ++col)
			{
				std::cout << v[row][col] << " ";
				read0.push_back(v[row][col]);
			}
			std::cout << std::endl;
		}
		std::cout << "Read the second line with iterator:" << std::endl;
		std::vector<int> read1;
		{
			std::size_t row = 1;
			for (auto it = v[row].begin(); it != v[row].end(); ++it)
			{
				std::cout << *it << " ";
				read1.push_back(*it);
			}
			std::cout << std::endl;
		}
		std::cout << "Read the second line with for (e : l):" << std::endl;
		std::vector<int> read2;
		{
			std::size_t row = 1;
			for (auto const & e : v[row])
			{
				std::cout << e << " ";
				read2.push_back(e);
			}
			std::cout << std::endl;
		}
		nb_test -= hnc::test::warning(read0 == read1, "Read the second line with begin/end does not work\n");
		nb_test -= hnc::test::warning(read1 == read2, "Read the second line with begin/end does not work\n");
		std::cout << std::endl;
	}

	{
		hnc::vector2D<unsigned int> v(4, 5);
		{
			unsigned int i = 10;
			for (std::size_t row = 0; row < v.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < v.nb_col(); ++col)
				{
					v(row, col) = i++;
				}
			}
		}
		{
			std::cout << "Affichage begin end" << std::endl;
			unsigned int i = 10;
			for (auto it_l = v.begin(); it_l != v.end(); ++it_l)
			{
				for (auto it_e = it_l->begin(); it_e != it_l->end(); ++it_e)
				{
					++nb_test;
					nb_test -= hnc::test::warning(*it_e == i++, "read access begin end fail\n");
					std::cout << *it_e << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "Affichage begin end" << std::endl;
			unsigned int i = 10;
			for (auto it_l = v.begin(); it_l != v.end(); ++it_l)
			{
				for (auto it_e = it_l->begin(); it_e != it_l->end(); ++it_e)
				{
					++nb_test;
					nb_test -= hnc::test::warning(*it_e == i++, "read access begin end fail\n");
					std::cout << *it_e << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
	
	{
		hnc::vector2D<unsigned int> v(4, 9);
		{
			unsigned int i = 10;
			std::cout << "Write" << std::endl;
			for (std::size_t row = 0; row < v.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < v.nb_col(); ++col)
				{
					v(row, col) = ++i;
					std::cout << v(row, col) << " ";
				}
			}
			std::cout << std::endl;
		}
		{
			unsigned int i = 10;
			std::cout << "Read with for (auto const & l : v) for (auto const & e : l)" << std::endl;
			for (auto const & l : v)
			{
				for (auto const & e : l)
				{
					std::cout << e << " ";
					++nb_test;
					nb_test -= hnc::test::warning(e == ++i, "read access for range loop fail\n");
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		hnc::vector2D<unsigned int> v(4, 9);
		{
			unsigned int i = 10;
			std::cout << "Write with for (auto & l : v) for (auto & e : l)" << std::endl;
			for (auto & l : v)
			{
				for (auto & e : l)
				{
					e = ++i;
					std::cout << e << " ";
				}
			}
			std::cout << std::endl;
		}
		{
			unsigned int i = 10;
			std::cout << "Read" << std::endl;
			for (std::size_t row = 0; row < v.nb_row(); ++row)
			{
				for (std::size_t col = 0; col < v.nb_col(); ++col)
				{
					std::cout << v(row, col) << " ";
					++nb_test;
					nb_test -= hnc::test::warning(v(row, col) == ++i, "read access for range loop fail\n");
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		hnc::vector2D<unsigned int> v(4, 9);
		{
			unsigned int i = 10;
			std::cout << "Write" << std::endl;
			for (int row = int(v.nb_row() - 1); row > 0; --row)
			{
				for (int col = int(v.nb_col() - 1); col > 0; --col)
				{
					v(std::size_t(row), std::size_t(col)) = (unsigned int)(++i);
					std::cout << v(std::size_t(row), std::size_t(col)) << " ";
				}
			}
			std::cout << std::endl;
		}
		{
			unsigned int i = 10;
			std::cout << "Read with reverse iterator" << std::endl;
			for (auto it_l = v.rbegin(); it_l != v.rend(); ++it_l)
			{
				for (auto it_e = it_l->rbegin(); it_e != it_l->rend(); ++it_e)
				{
					std::cout << *it_e << " ";
					++nb_test;
					nb_test -= hnc::test::warning(*it_e == ++i, "read access for range loop fail\n");
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		hnc::vector2D<unsigned int> v(4, 9);
		{
			unsigned int i = 10;
			std::cout << "Write with reverse iterator" << std::endl;
			for (auto it_l = v.rbegin(); it_l != v.rend(); ++it_l)
			{
				for (auto it_e = it_l->rbegin(); it_e != it_l->rend(); ++it_e)
				{
					*it_e = ++i;
					std::cout << *it_e << " ";
				}
			}
			std::cout << std::endl;
		}
		{
			unsigned int i = 10;
			std::cout << "Read" << std::endl;
			for (int row = int(v.nb_row() - 1); row > 0; --row)
			{
				for (int col = int(v.nb_col() - 1); col > 0; --col)
				{
					std::cout << v(std::size_t(row), std::size_t(col)) << " ";
					++nb_test;
					nb_test -= hnc::test::warning(v(std::size_t(row), std::size_t(col)) == ++i, "read access for range loop fail\n");
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	hnc::test::warning(nb_test == 0, "hnc::vector2D: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
