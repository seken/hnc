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
#include <stdexcept>

#include <hnc/test.hpp>
#include <hnc/terminal.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	{
		std::cout << "hnc::test::warning(1 == 1) ";
		nb_test -= hnc::test::warning(1 == 1, "-> Test: 1 == 1");
		std::cout << std::endl;
	}

	++nb_test;
	{
		std::cout << "hnc::test::warning(1 == 0) ";
		int r = hnc::test::warning(1 == 0, "-> Test: 1 == 0");
		if (r == 0) { --nb_test; }
		std::cout << std::endl;
	}

	++nb_test;
	{
		std::cout << "hnc::test::error(1 == 1) ";
		nb_test -= hnc::test::error(1 == 1, "-> Test: 1 == 1");
		std::cout << std::endl;
	}

	++nb_test;
	{
		std::cout << "hnc::test::error(1 == 0) ";
		try { hnc::test::error(1 == 0, "-> Test: 1 == 0"); }
		catch(std::exception const & e) { --nb_test; }
		std::cout << std::endl;
	}

	if (nb_test != 0)
	{
		std::cout << hnc::terminal::warning << "hnc::test: " << nb_test << " test fail!" << hnc::terminal::color_reset << std::endl;
	}

	return nb_test;
}
