// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/terminal.hpp>
#include <hnc/sleep.hpp>
#include <hnc/test.hpp>


int main()
{
	int nb_test = 0;

	std::cout << std::endl;
	
	std::cout << "Deleted this line in 1 second..."; std::cout.flush();
	hnc::sleep::s(1);
	hnc::terminal::delete_line();
	std::cout << "Line deleted" << std::endl;
	std::cout << std::endl;

	std::cout << "Deleted there lines in 1 second..." << std::endl;
	std::cout << "Deleted there lines in 1 second..." << std::endl;
	std::cout << "Deleted there lines in 1 second..." << std::endl;
	std::cout << "..."; std::cout.flush();
	hnc::sleep::s(1);
	hnc::terminal::delete_line(4);
	std::cout << "Lines deleted" << std::endl;
	std::cout << std::endl;

// 	std::cout << "Deleted the end of this line in 1 second..."; std::cout.flush();
// 	hnc::sleep::s(1);
// 	hnc::terminal::back(15);
// 	std::cout << ". End of line deleted" << std::endl;
// 	std::cout << std::endl;

	std::cout << "Display some colors:" << std::endl;
	std::cout << "- " << hnc::terminal::color::black << "black" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::white << "white" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::red << "red" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::light_red << "light red" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::green << "green" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::light_green << "light green" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::orange << "orange" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::light_orange << "light orange" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::blue << "blue" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::light_blue << "light blue" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::magenta << "magenta" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::light_magenta << "light magenta" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::cyan << "cyan" << hnc::terminal::color::reset << std::endl;
	std::cout << "- " << hnc::terminal::color::light_cyan << "light cyan" << hnc::terminal::color::reset << std::endl;
	std::cout << std::endl;

	std::cout << "Display some background colors:" << std::endl;
	std::cout << "- " << hnc::terminal::background_color::black << "black" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::white << "white" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::red << "red" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::green << "green" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::orange << "orange" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::blue << "blue" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::magenta << "magenta" << hnc::terminal::background_color::reset << std::endl;
	std::cout << "- " << hnc::terminal::background_color::cyan << "cyan" << hnc::terminal::background_color::reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::error << "Error: Description of the error" << hnc::terminal::color_reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::warning << "Warning: Description of warning" << hnc::terminal::color_reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::result << "Result: One result" << hnc::terminal::color_reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::debug << "Debug: Debug information" << hnc::terminal::color_reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::info;
	std::cout << "Info: color can works" << std::endl;
	std::cout << "      in multiline" << std::endl;
	std::cout << hnc::terminal::color_reset;
	std::cout << std::endl;

	std::cout << hnc::terminal::color::red << hnc::terminal::background_color::cyan <<
		" Red on cyan " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::cyan << hnc::terminal::background_color::red <<
		" Cyan on red " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::black << hnc::terminal::background_color::white <<
		" Black on white " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::white << hnc::terminal::background_color::black <<
		" White on black " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::green << hnc::terminal::background_color::orange <<
		" Green on orange " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::orange << hnc::terminal::background_color::green <<
		" Orange on green " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::blue << hnc::terminal::background_color::magenta <<
		" Blue on magenta " << hnc::terminal::color_reset << std::endl;
	std::cout << hnc::terminal::color::magenta << hnc::terminal::background_color::blue <<
		" Magenta on blue " << hnc::terminal::color_reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::bold << "Bold text" << hnc::terminal::bold_end << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::underline << "Underlined text" << hnc::terminal::underline_end << std::endl;
	std::cout << std::endl;
	
	std::cout << hnc::terminal::color::cyan << hnc::terminal::background_color::red << hnc::terminal::underline <<
		" Cyan on red underlined text " << hnc::terminal::reset << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::color::red << hnc::terminal::background_color::cyan << hnc::terminal::underline << hnc::terminal::bold <<
		" Red on cyan bold and underlined text " << hnc::terminal::reset << std::endl;
	std::cout << std::endl;

	std::cout << "Basic text" << std::endl;
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::terminal: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
