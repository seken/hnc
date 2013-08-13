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
#include <fstream>

#include <hnc/latex/article.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;

	int nb_test = 0;

	{
		hnc::latex::article latex_article("Title", "Author");
		std::cout << latex_article << std::endl;

		std::ofstream f("hnc_latex_article.tex");
		f << latex_article << std::endl;
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::latex::article: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
