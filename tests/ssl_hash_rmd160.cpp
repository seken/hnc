// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/ssl/hash/rmd160.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// You can test return with: echo -n "Compute rmd160" | openssl rmd160

	++nb_test;
	{
		std::string const v = "Compute rmd160";
		hnc::ssl::hash::rmd160_raw_data r = hnc::ssl::hash::rmd160(v);
		std::cout << "rmd160 of \"" << v << "\" = " << r << std::endl;
		#ifndef hnc_no_openssl
		nb_test -= hnc::test::warning(hnc::to_string(r) == "344fba566d913cd611c1e66098e4e5fe0a998ed5", "hnc::ssl::hash::rmd160 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::rmd160_raw_data(), "hnc::ssl::hash::rmd160 fails\n");
		#endif
	}

	hnc::test::warning(nb_test == 0, "hnc::ssl::hash::rmd160: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
