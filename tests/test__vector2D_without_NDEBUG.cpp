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

#define hnc_ostream_container_data
#include <hnc/vector2D.hpp>
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

	// Create a vector2D
	hnc::vector2D<int> ref(4, 5);
	std::cout << "Reference:\n" << ref << "\n" << std::endl;

	// Safe acces
	
	++nb_test;
	{
		bool except = false;
		try
		{
			std::cout << "Check acces .at(10, 10) == 0 -> " << (ref.at(10, 10) == 0) << std::endl;
		}
		catch(std::out_of_range const & e)
		{
			except = true;
		}
		nb_test -= hnc::test::warning(except, "vector2D safe access .at(i, j) does not work\n");
	}

	// Unsafe acces (safe without NDEBUG)

// 	++nb_test;
// 	{
// 		bool except = false;
// 		try
// 		{
// 			std::cout << "Check acces (10, 10) == 0 -> " << (ref(10, 10) == 0) << std::endl;
// 		}
// 		catch(std::out_of_range const & e)
// 		{
// 			except = true;
// 		}
// 		nb_test -= hnc::test::warning(except, "vector2D safe access (without NDEBUG) (i, j) does not work\n");
// 	}
// 
// 	++nb_test;
// 	{
// 		bool except = false;
// 		try
// 		{
// 			std::cout << "Check acces [10][10] == 0 -> " << (ref[10][10] == 0) << std::endl;
// 		}
// 		catch(std::out_of_range const & e)
// 		{
// 			except = true;
// 		}
// 		nb_test -= hnc::test::warning(except, "vector2D safe access (without NDEBUG) [i][j] does not work\n");
// 	}

	hnc::test::warning(nb_test == 0, "hnc::vector2D: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
