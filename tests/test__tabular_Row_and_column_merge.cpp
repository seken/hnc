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
		std::vector<std::vector<std::string>> data
		({
			{"A-B", "",    "C|F|I"},
			{"D",   "E|H", ""},
			{"G",   "",    ""}
		});
		std::vector<std::string> header({"header"});
		std::vector<std::string> footer({"footer"});

		hnc::tabular tabular(data, "Row and column merge", header, footer);
		tabular.header().at(0).merge_row(3);
		tabular.data().at(0).at(0).merge_row(2); // "A-B"
		tabular.data().at(1).at(1).merge_col(2); // "E|H"
		tabular.data().at(0).at(2).merge_col(3); // "C|F|I"
		tabular.footer().at(0).merge_row(3);

		validate(nb_test, tabular);
	}

	hnc::test::warning(nb_test == 0, "hnc::tabular: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
