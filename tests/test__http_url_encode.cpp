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

#include <hnc/http/url_encode.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;

	int nb_test = 0;

	++nb_test;
	{
		std::string const data = "https://fr.wikipedia.org/wiki/American_Standard_Code_for_Information_Interchange";
		std::string const ref = "https%3A%2F%2Ffr.wikipedia.org%2Fwiki%2FAmerican_Standard_Code_for_Information_Interchange";
		std::string const result = hnc::http::url_encode(data);
		std::cout << data << " => " << result << " (ref = " << ref << ")" << std::endl;
		nb_test -= hnc::test::warning(result == ref, "hnc::http::url_encode(" + data + ") fails\n");
	}

	++nb_test;
	{
		std::string const data = "Hello Günter";
		std::string const ref = "Hello%20G%C3%BCnter";
		std::string const result = hnc::http::url_encode(data);
		std::cout << data << " => " << result << " (ref = " << ref << ")" << std::endl;
		nb_test -= hnc::test::warning(result == ref, "hnc::http::url_encode(" + data + ") fails\n");
	}

	++nb_test;
	{
		std::string const data = "";
		std::string const ref = "";
		std::string const result = hnc::http::url_encode(data);
		std::cout << data << " => " << result << " (ref = " << ref << ")" << std::endl;
		nb_test -= hnc::test::warning(result == ref, "hnc::http::url_encode(" + data + ") fails\n");
	}
	
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::http::url_encode: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
