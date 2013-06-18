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

#include <hnc/ssl/hash/md2.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// You can test return with: echo -n "Compute md2" | openssl md2

	++nb_test;
	{
		std::string const v = "Compute md2";
		hnc::ssl::hash::md2_raw_data r = hnc::ssl::hash::md2(v);
		std::cout << "md2 of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::md2_raw_data(), "hnc::ssl::hash::md2 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::md2_raw_data(), "hnc::ssl::hash::md2 fails\n");
		#endif
	}

	hnc::test::warning(nb_test == 0, "hnc::ssl::hash::md2: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
