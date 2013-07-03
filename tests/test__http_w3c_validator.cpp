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
#include <string>

#include <hnc/http/w3c_validator.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	std::cout << hnc::terminal::result << "Tests with std::string" << hnc::terminal::reset << std::endl << std::endl;
	{
		// HTML code to validate
		std::string const xhtml_code =
			"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" "\n"
			"" "\n"
			"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\">" "\n"
			"" "\n"
			"\t" "<head>" "\n"
			"\t" "\t" "<title>Title</title>" "\n"
			"\t" "\t" "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" "\n" "\n"
			"\t" "</head>" "\n"
			"" "\n"
			"<body>\n"
			"</body>\n"
			"" "\n"
			"</html>\n";

		// HTML code to validate
		std::string const xhtml_code_error =
			"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" "\n"
			"" "\n"
			"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\">" "\n"
			"" "\n"
			"\t" "<head>" "\n"
			"\t" "\t" "<title>Title</title>" "\n"
			"\t" "\t" "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" "\n" "\n"
			"\t" "</head>" "\n"
			"" "\n"
			"<body>\n"
			"</body>\n"
			"" "\n";
			//"</html>\n";

		// HTML code to validate
		std::string const html_code_warning =
			"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">" "\n"
			"" "\n"
			"<html>" "\n"
			"" "\n"
			"\t" "<head>" "\n"
			"\t" "\t" "<title>Title</title>" "\n"
			"\t" "</head>" "\n"
			"" "\n"
			"<body>\n"
			"<p>\n"
			"</p>\n"
			"</body>\n"
			"" "\n"
			"</html>\n";

		// Valid
		++nb_test;
		{
			std::cout << hnc::terminal::info << xhtml_code << hnc::terminal::reset << std::endl;
			hnc::http::w3c_validator r(xhtml_code);
			std::cout << r << std::endl;
			#ifndef NO_HNC_Boost_Asio
				nb_test -= hnc::test::warning(r.validity(), "hnc::http::w3c_validator fails\n");
			#else
				--nb_test;
			#endif
		}

		// Error
		++nb_test;
		{
			std::cout << hnc::terminal::info << xhtml_code_error << hnc::terminal::reset << std::endl;
			hnc::http::w3c_validator r(xhtml_code_error);
			std::cout << r << std::endl;
			#ifndef NO_HNC_Boost_Asio
				nb_test -= hnc::test::warning(r.validity() == false, "hnc::http::w3c_validator fails\n");
			#else
				--nb_test;
			#endif
		}

		// Warning
		++nb_test;
		{
			std::cout << hnc::terminal::info << html_code_warning << hnc::terminal::reset << std::endl;
			hnc::http::w3c_validator r(html_code_warning);
			std::cout << r << std::endl;
			#ifndef NO_HNC_Boost_Asio
				nb_test -= hnc::test::warning(r.validity() && r.warnings().size() >= 1, "hnc::http::w3c_validator fails\n");
			#else
				--nb_test;
			#endif
		}
	}

	std::cout << hnc::terminal::result << "Tests with hnc::html::webpage" << hnc::terminal::reset << std::endl << std::endl;
	{
		// HTML code to validate
		hnc::html::webpage const xhtml_code
		(
			hnc::html::head("Title").use_xhtml(),
			hnc::html::doctype::xhtml_1d0_strict()
		);

		// HTML code to validate
		hnc::html::webpage xhtml_code_error
		(
			hnc::html::head("Title").use_xhtml(),
			hnc::html::doctype::xhtml_1d0_strict()
		);
		xhtml_code_error.set_data("</html>");

		// HTML code to validate
		hnc::html::webpage const html_code_warning
		(
			hnc::html::head("Title").use_html4(),
			hnc::html::doctype::html_4d01_strict(),
			hnc::lang::lang_code()
		);

		// Valid
		++nb_test;
		{
			std::cout << hnc::terminal::info << xhtml_code << hnc::terminal::reset << std::endl;
			hnc::http::w3c_validator r(xhtml_code);
			std::cout << r << std::endl;
			#ifndef NO_HNC_Boost_Asio
				nb_test -= hnc::test::warning(r.validity(), "hnc::http::w3c_validator fails\n");
			#else
				--nb_test;
			#endif
		}

		// Error
		++nb_test;
		{
			std::cout << hnc::terminal::info << xhtml_code_error << hnc::terminal::reset << std::endl;
			hnc::http::w3c_validator r(xhtml_code_error);
			std::cout << r << std::endl;
			#ifndef NO_HNC_Boost_Asio
				nb_test -= hnc::test::warning(r.validity() == false, "hnc::http::w3c_validator fails\n");
			#else
				--nb_test;
			#endif
		}

		// Warning
		++nb_test;
		{
			std::cout << hnc::terminal::info << html_code_warning << hnc::terminal::reset << std::endl;
			hnc::http::w3c_validator r(html_code_warning);
			std::cout << r << std::endl;
			#ifndef NO_HNC_Boost_Asio
				nb_test -= hnc::test::warning(r.validity() && r.warnings().size() >= 1, "hnc::http::w3c_validator fails\n");
			#else
				--nb_test;
			#endif
		}
	}

	hnc::test::warning(nb_test == 0, "hnc::http::w3c_validator: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
