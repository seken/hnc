// Copyright © 2012 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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

#include <hnc/args.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main(int argc, char * * argv)
{
	int nb_test = 0;
	
	hnc::args args(argc, argv, "Description of your program", "Version & Author");

	// One option with arguments
	auto arg_n = args.add_option({"--n", "--N"}, {"i", "j", "k"}, "Get 3 ints, must be present", std::make_tuple(0, 0, 0), true);
	auto arg_m = args.add_option({"--m", "--M"}, {"i", "j", "k"}, "Get 3 ints, must be present", std::make_tuple(0, 0, 0), true);
	auto arg_x_y = args.add_option({"--x_y", "--X_Y"}, {"x", "y"}, "Get 2 ints", std::make_tuple(0, 0));
	auto arg_u = args.add_option({"--u", "--U"}, {"i", "j", "k"}, "Get 3 ints, must be present", std::make_tuple(0, 0, 0), true);
	auto arg_v = args.add_option({"--v", "--V"}, {"i", "j", "k"}, "Get 3 ints", std::make_tuple(0, 0, 0));
	auto arg_c = args.add_option({"--c", "--C"}, {"c", "c", "c"}, "Get 4 chars", std::make_tuple('a', 'a', 'a'));
	auto arg_t = args.add_option({"--t", "--T"}, {"i", "s", "c", "b"}, "Get int, string, char, bool", std::make_tuple(0, std::string(""), 'a', false));

	// Display the args (same as help)
	std::cout << args << std::endl;
	// You can display: args.usage(), args.help(), args.version() too

	// Display the arguments
	std::cout << "Arguments:" << std::endl;
	for (auto const & arg : args.raw_args())
	{
		std::cout << "    " << arg << std::endl;
	}
	std::cout << std::endl;

	// Display the option given
	std::cout << std::boolalpha;
	std::cout << "Options:" << std::endl;
	std::cout << "    " << "--n   " << arg_n << std::endl;
	std::cout << "    " << "--m   " << arg_m << std::endl;
	std::cout << "    " << "--x_y " << arg_x_y << std::endl;
	std::cout << "    " << "--u   " << arg_u << std::endl;
	std::cout << "    " << "--v   " << arg_v << std::endl;
	std::cout << "    " << "--c   " << arg_c << std::endl;
	std::cout << "    " << "--t   " << arg_t << std::endl;
	std::cout << std::endl;

	std::cout << "Errors:" << std::endl;
	for (auto const & error : args.errors())
	{
		std::cout << "    " << hnc::terminal::error << error.what() << hnc::terminal::color_reset << std::endl;
	}
	std::cout << std::endl;

	nb_test += 8;
	nb_test -= hnc::test::warning(arg_n == std::make_tuple(21, 42, 73), "--n 21 42 73 is given\n");
	nb_test -= hnc::test::warning(arg_m == std::make_tuple(0, 0, 0), "--m is not given\n");
	nb_test -= hnc::test::warning(arg_x_y == std::make_tuple(800, 600), "--x_y 800 600 is given\n");
	nb_test -= hnc::test::warning(arg_u == std::make_tuple(0, 0, 0), "--u is given without valid arguments\n");
	nb_test -= hnc::test::warning(arg_v == std::make_tuple(0, 0, 0), "--v is given without valid arguments\n");
	nb_test -= hnc::test::warning(arg_c == std::make_tuple('d','e', 'f'), "--c d e f is given\n");
	nb_test -= hnc::test::warning(arg_t == std::make_tuple(42, std::string("One word"), 'c', true), "--t \"42\" \"One word\" \"c\" \"1\" is given\n");
	nb_test -= hnc::test::warning(args.errors().size() == 3, "--m is not given --u --v have not all arguments\n");
	
	hnc::test::warning(nb_test == 0, "hnc::arg " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
