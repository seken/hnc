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
#include <algorithm>

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

	// hnc::text::diff

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C"};
		std::vector<std::string> const text1 = {"A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size(),
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::cout << "Empty texts" << std::endl;
		std::vector<std::string> const text0 = { };
		std::vector<std::string> const text1 = { };
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 0,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = { };
		std::vector<std::string> const text1 = {"A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::deletion)) == diff.size(),
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C"};
		std::vector<std::string> const text1 = { };
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::insertion)) == diff.size(),
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C", "A",      "G", "C"};
		std::vector<std::string> const text1 = {"A", "T", "G", "C", "A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 8 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 1 &&
			diff.at(5) == hnc::text::diff_tag::deletion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C", "A", "T", "G", "C"};
		std::vector<std::string> const text1 = {"A", "T", "G", "C", "A",      "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 8 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 1 &&
			diff.at(5) == hnc::text::diff_tag::insertion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G",    };
		std::vector<std::string> const text1 = {"A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 1 &&
			diff.at(3) == hnc::text::diff_tag::deletion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C"};
		std::vector<std::string> const text1 = {"A", "T", "G",    };
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 1 &&
			diff.at(3) == hnc::text::diff_tag::insertion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T",         };
		std::vector<std::string> const text1 = {"A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 2 &&
			diff.at(2) == hnc::text::diff_tag::deletion && diff.at(3) == hnc::text::diff_tag::deletion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C"};
		std::vector<std::string> const text1 = {"A", "T",         };
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 2 &&
			diff.at(2) == hnc::text::diff_tag::insertion && diff.at(3) == hnc::text::diff_tag::insertion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {     "T", "G", "C"};
		std::vector<std::string> const text1 = {"A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 1 &&
			diff.at(0) == hnc::text::diff_tag::deletion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C"};
		std::vector<std::string> const text1 = {     "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 1 &&
			diff.at(0) == hnc::text::diff_tag::insertion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {          "G", "C"};
		std::vector<std::string> const text1 = {"A", "T", "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 2 &&
			diff.at(0) == hnc::text::diff_tag::deletion && diff.at(1) == hnc::text::diff_tag::deletion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"A", "T", "G", "C"};
		std::vector<std::string> const text1 = {          "G", "C"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 4 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == diff.size() - 2 &&
			diff.at(0) == hnc::text::diff_tag::insertion && diff.at(1) == hnc::text::diff_tag::insertion,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	++nb_test;
	{
		std::vector<std::string> const text0 = {"lorem ", "ipsum, ", "dolor ", "sit, ", "amet, ", "consectetur, ", "adipisci ", "elit, ", "sed ", "eius ", "mod ", "tempor ", "incidunt, ", "ut ", "labore ", "et ", "dolore ", "magna ", "aliqua"};
		std::vector<std::string> const text1 = {"dolorem ", "ipsum, ", "quia ", "dolor ", "sit, ", "amet, ", "consectetur, ", "adipisci ", "velit, ", "sed ", "quia non ", "numquam ", "eius ", "modi ", "tempora ", "incidunt, ", "ut ", "labore ", "et ", "dolore ", "magnam ", "aliquam"};
		auto diff = hnc::text::diff(text0, text1);
		hnc::text::display_diff(text0, text1, diff);
		nb_test -= hnc::test::warning
		(
			diff.size() == 28 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::equal)) == 13 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::insertion)) == 6 &&
			std::size_t(std::count(diff.begin(), diff.end(), hnc::text::diff_tag::deletion)) == 9,
			"hnc::text::diff fails\n"
		);
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::text: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
