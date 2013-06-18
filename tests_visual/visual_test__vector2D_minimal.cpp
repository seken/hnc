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
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>

#include <hnc/vector2D_minimal.hpp>
#include <hnc/test.hpp>


int main()
{
	{
		hnc::vector2D_minimal<int> c(5, 10, 42);
		std::cout << c << std::endl;
	}
	std::cout << std::endl;

	{
		hnc::vector2D_minimal<double> c(5, 10, 73.21);
		std::cout << c << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
