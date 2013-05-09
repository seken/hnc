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

//#include <hnc/header_you_test.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// Do test
	++nb_test;
	{
		// Do test
		nb_test -= hnc::test::warning(true, "Return 1 if the condition is true, 0 else\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::header_you_test: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
