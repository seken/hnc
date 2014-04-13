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

#include <hnc/ssl/hash/md4.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// You can test return with: echo -n "Compute md4" | openssl md4

	++nb_test;
	{
		std::string const v = "Compute md4";
		hnc::ssl::hash::md4_raw_data r = hnc::ssl::hash::md4(v);
		std::cout << "md4 of \"" << v << "\" = " << r << std::endl;
		#ifndef hnc_no_openssl
		nb_test -= hnc::test::warning(hnc::to_string(r) == "eb7bf78d690e331ae59373004fa253f4", "hnc::ssl::hash::md4 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::md4_raw_data(), "hnc::ssl::hash::md4 fails\n");
		#endif
	}

	hnc::test::warning(nb_test == 0, "hnc::ssl::hash::md4: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
