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
#include <stdexcept>

#include <hnc/assert.hpp>
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
		std::cout << "hnc::hassert(1 == 1) ";
		try
		{
			#ifndef NDEBUG
			hnc::hassert(1 == 1, "-> Test: 1 == 1");
			#endif
			--nb_test;
		}
		catch(std::exception const & e) { std::cout << e.what(); }
		std::cout << std::endl;
	}

	++nb_test;
	{
		std::cout << "hnc::hassert(1 == 0) ";
		try
		{
			#ifndef NDEBUG
			hnc::hassert(1 == 0, "-> Test: 1 == 0");
			#endif
		}
		catch(std::exception const & e) { std::cout << e.what(); --nb_test; }
		std::cout << std::endl;
	}

	++nb_test;
	{
		std::cout << "hnc::hassert(1 == 1) ";
		try
		{
			#ifndef NDEBUG
			hnc::hassert(1 == 1, std::logic_error("-> Test: 1 == 1"));
			#endif
			--nb_test;
		}
		catch (std::exception const & e) { std::cout << e.what(); }
		std::cout << std::endl;
	}

	++nb_test;
	{
		std::cout << "hnc::hassert(1 == 0) ";
		try
		{
			#ifndef NDEBUG
			hnc::hassert(1 == 0, std::logic_error("-> Test: 1 == 0"));
			#endif
		}
		catch (std::exception const & e) { std::cout << e.what(); --nb_test; }
		std::cout << std::endl;
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::hassert: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
