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
#include <fstream>
#include <string>

#include <hnc/text.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	// hnc::text::string_to_vector_of_lines

	++nb_test;
	{
		std::string const text = "";
		std::vector<std::string> const lines = hnc::text::string_to_vector_of_lines(text);
		std::cout << hnc::terminal::info << "Text:" << hnc::terminal::reset << std::endl << text << std::endl;
		std::cout << hnc::terminal::info << "Vector of lines:" << hnc::terminal::reset << std::endl << lines << std::endl;
		nb_test -= hnc::test::warning(lines.size() == 0, "hnc::text::string_to_vector_of_lines fails\n");
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string const text = "One line";
		std::vector<std::string> const lines = hnc::text::string_to_vector_of_lines(text);
		std::cout << hnc::terminal::info << "Text:" << hnc::terminal::reset << std::endl << text << std::endl;
		std::cout << hnc::terminal::info << "Vector of lines:" << hnc::terminal::reset << std::endl << lines << std::endl;
		nb_test -= hnc::test::warning(lines.size() == 1, "hnc::text::string_to_vector_of_lines fails\n");
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string const text = "Two \nlines";
		std::vector<std::string> const lines = hnc::text::string_to_vector_of_lines(text);
		std::cout << hnc::terminal::info << "Text:" << hnc::terminal::reset << std::endl << text << std::endl;
		std::cout << hnc::terminal::info << "Vector of lines:" << hnc::terminal::reset << std::endl << lines << std::endl;
		nb_test -= hnc::test::warning(lines.size() == 2, "hnc::text::string_to_vector_of_lines fails\n");
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string const text = "Three \nlines\n.";
		std::vector<std::string> const lines = hnc::text::string_to_vector_of_lines(text);
		std::cout << hnc::terminal::info << "Text:" << hnc::terminal::reset << std::endl << text << std::endl;
		std::cout << hnc::terminal::info << "Vector of lines:" << hnc::terminal::reset << std::endl << lines << std::endl;
		nb_test -= hnc::test::warning(lines.size() == 3, "hnc::text::string_to_vector_of_lines fails\n");
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string const text = "This is a example with true lines.\nThis example contains multiples lines.\nEach line contains muiltiple words.";
		std::vector<std::string> const lines = hnc::text::string_to_vector_of_lines(text);
		std::cout << hnc::terminal::info << "Text:" << hnc::terminal::reset << std::endl << text << std::endl;
		std::cout << hnc::terminal::info << "Vector of lines:" << hnc::terminal::reset << std::endl << lines << std::endl;
		nb_test -= hnc::test::warning(lines.size() == 3, "hnc::text::string_to_vector_of_lines fails\n");
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::string const text = "This is a example with true lines.This example contains multiples lines.Each line contains muiltiple words.The dimiter is the dot.";
		std::vector<std::string> const lines = hnc::text::string_to_vector_of_lines(text, '.');
		std::cout << hnc::terminal::info << "Text:" << hnc::terminal::reset << std::endl << text << std::endl;
		std::cout << hnc::terminal::info << "Vector of lines:" << hnc::terminal::reset << std::endl << lines << std::endl;
		nb_test -= hnc::test::warning(lines.size() == 4, "hnc::text::string_to_vector_of_lines fails\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::text: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
