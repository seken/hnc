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


#include <string>
#include <iostream>

#include <hnc/url.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	{
		hnc::url url = hnc::url();
		std::string const ref = "";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name");
		std::string const ref = "serveur_name";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name", "/path");
		std::string const ref = "serveur_name/path";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name", "/path", "http");
		std::string const ref = "http://serveur_name/path";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name", "/path", "http", 80);
		std::string const ref = "http://serveur_name:80/path";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name", "/path", "git", 0, "login");
		std::string const ref = "git://login@serveur_name/path";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name", "/path", "ftp", 0, "login", "pwd");
		std::string const ref = "ftp://login:pwd@serveur_name/path";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	++nb_test;
	{
		hnc::url url = hnc::url("serveur_name", "/path", "ftp", 21, "login", "pwd");
		std::string const ref = "ftp://login:pwd@serveur_name:21/path";
		std::cout << url << std::endl;
		nb_test -= hnc::test::warning(url.to_string() == ref, "hnc::url fails: \"" + url.to_string() + "\" instead of \"" + ref + "\"\n");
	}

	hnc::test::warning(nb_test == 0, "hnc::url: " + hnc::to_string(nb_test) + " test fail!\n");
	std::cout << std::endl;

	return nb_test;
}
