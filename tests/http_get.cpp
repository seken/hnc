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

#include <hnc/http/get.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	// Get a HTTP Get with Boost.Asio to validate the HTTP GET http_get_request
	auto validate = [&nb_test](hnc::http::get const & http_get_request)
	{
		try
		{
			std::vector<std::string> result = http_get_request.request();
			--nb_test;

			for (std::size_t i = 0; i < std::min(std::size_t(15), result.size()); ++i)
			{
				std::cout << result[i] << std::endl;
			}
			std::cout << "... (" << result.size() << " lines in total)" << std::endl;
		}
		catch (std::string const & e)
		{
			hnc::test::warning(false, "Can not connect: " + e + "\n");
			--nb_test;
		}
	};

	// HTML code to validate
	std::string const xhtml_code =
		"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" "\n"
		"" "\n"
		"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"fr\" lang=\"fr\">" "\n"
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

	// Tests

	// Base
	++nb_test;
	{
		hnc::url url("www.boost.org", "/", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;
		
		hnc::http::get http_get_request(url);
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Without path
	++nb_test;
	{
		hnc::url url("www.boost.org", "", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url);
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// With user agent
	++nb_test;
	{
		hnc::url url("www.boost.org", "/", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url, "hnc_http_get_test_program");
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Wrong result (not HTTP/1.1 200 OK)
	++nb_test;
	{
		hnc::url url("localhost", "/w3c-validator/check", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url);
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Resul ok with parameter
	++nb_test;
	{
		hnc::url url("localhost", "/w3c-validator/check", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url, "fragment", xhtml_code);
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Resul ok with parameter and user agent
	++nb_test;
	{
		hnc::url url("localhost", "/w3c-validator/check", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url, "fragment", xhtml_code, "hnc_http_get_test_program");
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Resul ok with parameters
	++nb_test;
	{
		hnc::url url("localhost", "/w3c-validator/check", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url, "fragment", xhtml_code, "output", "soap12");
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Resul ok with parameters and user agent
	++nb_test;
	{
		hnc::url url("localhost", "/w3c-validator/check", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url, "fragment", xhtml_code, "output", "soap12", "hnc_http_get_test_program");
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	// Resul ok with parameters and user agent
	++nb_test;
	{
		hnc::url url("localhost", "/w3c-validator/check", "http");
		std::cout << hnc::terminal::info << url << hnc::terminal::reset << std::endl;

		hnc::http::get http_get_request(url, "fragment", xhtml_code, "output", "soap12", "verbose", 1, "hnc_http_get_test_program");
		std::cout << http_get_request << std::endl;

		validate(http_get_request);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::http::get: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
