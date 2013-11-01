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

	// One option with one argument
	int arg_n = args.add_option({"--n", "--N"}, "i", "Get a int, must be present", 0, true);
	int arg_m = args.add_option({"--m", "--M"}, "i", "Get a int", 0);
	int arg_x = args.add_option({"--x", "--X"}, "i", "Get a int, must be present", 0, true);
	int arg_y = args.add_option({"--y", "--Y"}, "i", "Get a int", 73);
	int arg_u = args.add_option({"--u", "--U"}, "i", "Get a int", 0, true);
	int arg_v = args.add_option({"--v", "--V"}, "i", "Get a int", 0);
	char arg_c = args.add_option({"--c", "--C"}, "c", "Get a char, must be present", 'a', true);
	std::string arg_w = args.add_option({"--w", "--W"}, "s", "Get a string, must be present", std::string(""), true);
	std::string arg_s = args.add_option({"--s", "--S"}, "s", "Get a string, must be present", std::string(""), true);

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
	std::cout << "    " << "--n " << arg_n << std::endl;
	std::cout << "    " << "--m " << arg_m << std::endl;
	std::cout << "    " << "--x " << arg_x << std::endl;
	std::cout << "    " << "--y " << arg_y << std::endl;
	std::cout << "    " << "--u " << arg_u << std::endl;
	std::cout << "    " << "--v " << arg_v << std::endl;
	std::cout << "    " << "--c " << arg_c << std::endl;
	std::cout << "    " << "--w " << arg_w << std::endl;
	std::cout << "    " << "--s " << arg_s << std::endl;
	std::cout << std::endl;

	std::cout << "Errors:" << std::endl;
	for (auto const & error : args.errors())
	{
		std::cout << "    " << hnc::terminal::error << error.what() << hnc::terminal::color_reset << std::endl;
	}
	std::cout << std::endl;

	nb_test += 10;
	nb_test -= hnc::test::warning(arg_n == 21, "--n 21 is given\n");
	nb_test -= hnc::test::warning(arg_m == 42, "--m 42 is given\n");
	nb_test -= hnc::test::warning(arg_x == 0, "--x is not given\n");
	nb_test -= hnc::test::warning(arg_y == 73, "--y is not given\n");
	nb_test -= hnc::test::warning(arg_u == 0, "--u is given without argument\n");
	nb_test -= hnc::test::warning(arg_v == 0, "--v is given without argument\n");
	nb_test -= hnc::test::warning(arg_c == 'c', "--c c is given\n");
	nb_test -= hnc::test::warning(arg_w == "word", "--w word is given\n");
	nb_test -= hnc::test::warning(arg_s == "A few words is a sentence", "--s A few words is a sentence is given\n");
	nb_test -= hnc::test::warning(args.errors().size() == 3, "--x is not given --u --v have not argument\n");
	
	hnc::test::warning(nb_test == 0, "hnc::arg " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
