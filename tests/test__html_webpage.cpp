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

#include <hnc/html/webpage.hpp>
#include <hnc/http/w3c_validator.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;

	int nb_test = 0;

	// To validate webpage with w3c_validator
	auto validate = [&nb_test](hnc::html::webpage const & page) -> void
	{
		std::cout << hnc::terminal::info << page << hnc::terminal::reset << std::endl;

		hnc::http::w3c_validator r(page);
		std::cout << r << std::endl;

		#ifndef NO_HNC_Boost_Asio
			nb_test -= hnc::test::warning(r.validity(), "hnc::http::w3c_validator fails\n");
		#else
			--nb_test;
		#endif
	};

	// Tests

	++nb_test;
	{
		hnc::html::webpage const page
		(
			hnc::html::head("Title")
		);
		validate(page);
	}

	++nb_test;
	{
		hnc::html::webpage const page
		(
			hnc::html::head("Title - HTML"),
			hnc::html::doctype::html()
		);
		validate(page);
	}

	++nb_test;
	{
		hnc::html::webpage const page
		(
			hnc::html::head("Title - XHTML"),
			hnc::html::doctype::xhtml_1d0_strict()
		);
		validate(page);
	}

	++nb_test;
	{
		hnc::html::webpage const page
		(
			hnc::html::head("Title - HTML 4"),
			hnc::html::doctype::html_4d01_strict()
		);
		validate(page);
	}

	// Test with data

	++nb_test;
	{
		hnc::html::webpage page
		(
			hnc::html::head("Title")
		);
		page.set_data("<p>HTML code from test of hnc::html::webpage</p>");
		validate(page);
	}

	++nb_test;
	{
		hnc::html::webpage page
		(
			hnc::html::head("Title - HTML"),
			hnc::html::doctype::html()
		);
		page.set_data("<p>HTML code from test of hnc::html::webpage</p>");
		validate(page);
	}

	++nb_test;
	{
		hnc::html::webpage page
		(
			hnc::html::head("Title - XHTML"),
			hnc::html::doctype::xhtml_1d0_strict()
		);
		page.set_data("<p>HTML code from test of hnc::html::webpage</p>");
		validate(page);
	}

	++nb_test;
	{
		hnc::html::webpage page
		(
			hnc::html::head("Title - HTML 4"),
			hnc::html::doctype::html_4d01_strict()
		);
		page.set_data("<p>HTML code from test of hnc::html::webpage</p>");
		validate(page);
	}

	hnc::test::warning(nb_test == 0, "hnc::html::webpage: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
