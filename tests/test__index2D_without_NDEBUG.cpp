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


#if defined(NDEBUG)
	#undef NDEBUG
#endif

#include <iostream>

#include <hnc/index2D.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	#if defined(NDEBUG)
		std::cout << "With NDEBUG" << std::endl;
	#else
		std::cout << "Without NDEBUG" << std::endl;
		--nb_test;
	#endif

	++nb_test;
	{
		std::size_t i = 0;
		std::size_t j = 0;
		std::size_t rowSize = 10;
		std::size_t i2DRef = 0;
		std::size_t i2D = hnc::index2D::index1D(i, j, rowSize);
		std::cout << "@[" << i << "][" << j << "] (row size = " << rowSize << ") -> " << i2D << std::endl;
		nb_test -= hnc::test::warning(i2D == i2DRef, "hnc::index2D::index1D(" + hnc::to_string(i) + ", " + hnc::to_string(j) + ", " + hnc::to_string(rowSize) + ") = " + hnc::to_string(i2D) + " instead of " + hnc::to_string(i2DRef) + "\n");
	}

	++nb_test;
	{
		std::size_t i = 7;
		std::size_t j = 8;
		std::size_t rowSize = 4;
		std::size_t i2DRef = 36;
		std::size_t i2D = hnc::index2D::index1D(i, j, rowSize);
		std::cout << "@[" << i << "][" << j << "] (row size = " << rowSize << ") -> " << i2D << std::endl;
		nb_test -= hnc::test::warning(i2D == i2DRef, "hnc::index2D::index1D(" + hnc::to_string(i) + ", " + hnc::to_string(j) + ", " + hnc::to_string(rowSize) + ") = " + hnc::to_string(i2D) + " instead of " + hnc::to_string(i2DRef) + "\n");
	}

	++nb_test;
	{
		std::size_t i = 9;
		std::size_t j = 2;
		std::size_t rowSize = 23;
		std::size_t i2DRef = 209;
		std::size_t i2D = hnc::index2D::index1D(i, j, rowSize);
		std::cout << "@[" << i << "][" << j << "] (row size = " << rowSize << ") -> " << i2D << std::endl;
		nb_test -= hnc::test::warning(i2D == i2DRef, "hnc::index2D::index1D(" + hnc::to_string(i) + ", " + hnc::to_string(j) + ", " + hnc::to_string(rowSize) + ") = " + hnc::to_string(i2D) + " instead of " + hnc::to_string(i2DRef) + "\n");
	}

	++nb_test;
	{
		std::size_t i = 1;
		std::size_t j = 6;
		std::size_t rowSize = 42;
		std::size_t i2DRef = 48;
		std::size_t i2D = hnc::index2D::index1D(i, j, rowSize);
		std::cout << "@[" << i << "][" << j << "] (row size = " << rowSize << ") -> " << i2D << std::endl;
		nb_test -= hnc::test::warning(i2D == i2DRef, "hnc::index2D::index1D(" + hnc::to_string(i) + ", " + hnc::to_string(j) + ", " + hnc::to_string(rowSize) + ") = " + hnc::to_string(i2D) + " instead of " + hnc::to_string(i2DRef) + "\n");
	}

	++nb_test;
	{
		std::size_t i = 4;
		std::size_t j = 5;
		std::size_t rowSize = 0;
		try
		{
			std::size_t i2D = hnc::index2D::index1D(i, j, rowSize);
			hnc::test::warning(false,"@[" + hnc::to_string(i) + "][" + hnc::to_string(j) + "] (row size = " + hnc::to_string(rowSize) + ") -> " + hnc::to_string(i2D) + " (invalid argument, do not check the no sence result)\n");
		}
		catch (std::exception const & e)
		{
			std::cout << "@[" << i << "][" << j << "] (row size = " << rowSize << ") -> " << e.what() << std::endl;
			--nb_test;
		}
	}

	hnc::test::warning(nb_test == 0, "hnc::index2D::index1D: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
