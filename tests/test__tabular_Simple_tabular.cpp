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


#include "test__tabular.hpp"


int main()
{
	std::cout << std::endl;

	int nb_test = 0;

	++nb_test;
	{
		std::vector<std::vector<double>> data
		({
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
			{20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
			{40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
			{60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
			{80, 81, 82, 83, 84, 85, 86, 87, 88, 89},
			{100, 101, 102, 103, 104, 105, 106, 107, 108, 109}
		});
		std::vector<std::string> header({"h0", "h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8", "h9"});
		std::vector<std::string> footer({"f0", "f1", "f2", "..."});

		hnc::tabular tabular(data, "Simple tabular", header, footer);

		validate(nb_test, tabular);
	}

	hnc::test::warning(nb_test == 0, "hnc::tabular: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
