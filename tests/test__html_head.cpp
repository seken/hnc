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

#include <hnc/html/head.hpp>
#include <hnc/html/webpage.hpp>
#include <hnc/http/w3c_validator.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;

	int nb_test = 0;

	// Function to validate html
	auto validate = [&nb_test](hnc::html::head const & html_head) -> void
	{
		// Webpage
		std::string html_webpage = hnc::html::webpage(html_head, hnc::html::doctype::xhtml_1d0_strict()).html();
		//std::cout << html_webpage << std::endl;

		// Validator
		hnc::http::w3c_validator w3c_validator(html_webpage, hnc::http::w3c_validator::server_local());
		//for (std::string const & line : w3c_validator.raw_result()) { std::cout << line << std::endl; }

		// Display
		if (w3c_validator.validity())
		{
			--nb_test;
			std::cout << hnc::terminal::result << "This code is valid" << hnc::terminal::reset << std::endl;
		}
		else
		{
			std::cout << hnc::terminal::error << "This code is not valid:" << hnc::terminal::reset << std::endl;
			std::cout << html_webpage << std::endl;
		}
		std::cout << w3c_validator << std::endl;
	};

	// Tests

	++nb_test;
	{
		hnc::html::head h("Title");
		std::cout << hnc::terminal::info << h << hnc::terminal::reset << std::endl;
		validate(h);
	}
	std::cout << std::endl;

	++nb_test;
	{
		hnc::html::head h("Title - HTML 5");
		h.use_html5();
		std::cout << hnc::terminal::info << h << hnc::terminal::reset << std::endl;
		validate(h);
	}
	std::cout << std::endl;

	++nb_test;
	{
		hnc::html::head h("Title - XHTML");
		h.use_xhtml();
		std::cout << hnc::terminal::info << h << hnc::terminal::reset << std::endl;
		validate(h);
	}
	std::cout << std::endl;

	++nb_test;
	{
		hnc::html::head h("Title - HTML 4");
		h.use_html4();
		std::cout << hnc::terminal::info << h << hnc::terminal::reset << std::endl;
		validate(h);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::html::head: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
