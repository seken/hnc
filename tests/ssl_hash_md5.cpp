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

#include <hnc/ssl/hash/md5.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// You can test return with: echo -n "Compute md5" | openssl md5

	++nb_test;
	{
		std::string const v = "Compute md5";
		hnc::ssl::hash::md5_raw_data r = hnc::ssl::hash::md5(v);
		std::cout << "md5 of \"" << v << "\" = " << r << std::endl;
		#ifndef hnc_no_openssl
		nb_test -= hnc::test::warning(hnc::to_string(r) == "a1d93510e969cf5ea83c8827728da77e", "hnc::ssl::hash::md5 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::md5_raw_data(), "hnc::ssl::hash::md5 fails\n");
		#endif
	}

	hnc::test::warning(nb_test == 0, "hnc::ssl::hash::md5: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
