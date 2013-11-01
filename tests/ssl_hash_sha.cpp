// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr
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

#include <hnc/ssl/hash/sha.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// You can test return with: echo -n "Compute sha256" | openssl sha256

	++nb_test;
	{
		std::string const v = "Compute sha";
		hnc::ssl::hash::sha_raw_data r = hnc::ssl::hash::sha(v);
		std::cout << "sha of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(hnc::to_string(r) == "7ebf0e04e7704896290789fd7c3ba189fade4b7f", "hnc::ssl::hash::sha fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::sha_raw_data(), "hnc::ssl::hash::sha fails\n");
		#endif
	}

	++nb_test;
	{
		std::string const v = "Compute sha1";
		hnc::ssl::hash::sha1_raw_data r = hnc::ssl::hash::sha1(v);
		std::cout << "sha1 of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(hnc::to_string(r) == "60f85a47f9f4df7055505e45cdc02690c1da8252", "hnc::ssl::hash::sha1 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::sha1_raw_data(), "hnc::ssl::hash::sha1 fails\n");
		#endif
	}

	++nb_test;
	{
		std::string const v = "Compute sha224";
		hnc::ssl::hash::sha224_raw_data r = hnc::ssl::hash::sha224(v);
		std::cout << "sha224 of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(hnc::to_string(r) == "f0ea0d0bbd2ab390b90df2a7f5392952cadcbd4a0baaa8d474a27eb2", "hnc::ssl::hash::sha224 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::sha224_raw_data(), "hnc::ssl::hash::sha224 fails\n");
		#endif
	}

	++nb_test;
	{
		std::string const v = "Compute sha256";
		hnc::ssl::hash::sha256_raw_data r = hnc::ssl::hash::sha256(v);
		std::cout << "sha256 of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(hnc::to_string(r) == "b246c81159b2902a66a95b52b5bacd9e0fc3f37de0bed1ae326176ff7514bc3e", "hnc::ssl::hash::sha256 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::sha256_raw_data(), "hnc::ssl::hash::sha256 fails\n");
		#endif
	}

	++nb_test;
	{
		std::string const v = "Compute sha384";
		hnc::ssl::hash::sha384_raw_data r = hnc::ssl::hash::sha384(v);
		std::cout << "sha384 of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(hnc::to_string(r) == "89b9355c4231600cbaa995a4b53107dc63dc62591a1ce0b415cf550f8aaf02303ce8f12e5e7a40d92a22dced206abaeb", "hnc::ssl::hash::sha384 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::sha384_raw_data(), "hnc::ssl::hash::sha384 fails\n");
		#endif
	}

	++nb_test;
	{
		std::string const v = "Compute sha512";
		hnc::ssl::hash::sha512_raw_data r = hnc::ssl::hash::sha512(v);
		std::cout << "sha512 of \"" << v << "\" = " << r << std::endl;
		#ifndef NO_HNC_SSL
		nb_test -= hnc::test::warning(hnc::to_string(r) == "57aca0e7590d3d0722e74bb4f6b820c5f6bda588bd6ba0de4bf88f8fab6892abd4253d73eb011216a85ba42e789ca646d1a849fab2b4e1c8986269b6110aab6b", "hnc::ssl::hash::sha512 fails\n");
		#else
		nb_test -= hnc::test::warning(r == hnc::ssl::hash::sha512_raw_data(), "hnc::ssl::hash::sha512 fails\n");
		#endif
	}

	hnc::test::warning(nb_test == 0, "hnc::ssl::hash::sha: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
