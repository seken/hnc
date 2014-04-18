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


#ifndef TEST__TABULAR
#define TEST__TABULAR

#include <iostream>
#include <fstream>

#include <hnc/tabular.hpp>
#include <hnc/system.hpp>
#include <hnc/http/w3c_validator.hpp>
#include <hnc/filesystem.hpp>
#include <hnc/string.hpp>
#include <hnc/algo.hpp>
#include <hnc/latex/article.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


// Display and write and validate HTML tabular
void validate(int & nb_test, hnc::tabular const & tabular)
{
	// Basename
	std::string const basename = "hnc_tabular_" + hnc::algo::replace_all_copy(tabular.title(), " "_s, "_"_s);

	// Txt

	std::cout << tabular << std::endl;
	std::cout << std::endl;

	// LaTeX

	hnc::latex::article latex_article(tabular.title(), "Author");
	latex_article.use_package("array");
	latex_article.use_package("multirow");
	latex_article.set_data(tabular.latex());

	std::cout << tabular.latex() << std::endl;
	std::cout << std::endl;

	{
		std::ofstream f(basename + ".tex");
		f << latex_article.latex() << std::endl;
	}

	// HTML

	hnc::html::webpage html_webpage(hnc::html::head(tabular.title()), hnc::html::doctype::xhtml_1d0_strict());
	html_webpage.set_data(tabular.html());
	hnc::http::w3c_validator html_validation(html_webpage);

	if (html_validation.validity())
	{
		std::cout << hnc::terminal::result << "This code is valid" << hnc::terminal::reset << std::endl;
		--nb_test;
	}
	else
	{
		std::cout << hnc::terminal::error << "This code is not valid" << hnc::terminal::reset << std::endl;
	}
	std::cout << tabular.html() << std::endl;
	std::cout << std::endl;

	{
		std::ofstream f(basename + ".html");
		f << html_webpage << std::endl;
	}
}

#endif
