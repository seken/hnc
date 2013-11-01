// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

// This file is part of hnc.

// hnc is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// hnc is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with hnc. If not, see <http://www.gnu.org/licenses/>


#include <iostream>

#include <hnc/gnuplot/output_terminal.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	std::cout << hnc::terminal::info << "Output terminal png" << hnc::terminal::reset << std::endl << std::endl;
	std::cout << hnc::gnuplot::output_terminal_png("output_filename") << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_png("output_filename").size(1024, 600).enhanced() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_png("output_filename").no_enhanced().font("Verdana", 10) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_png("output_filename").font("Verdana", 10).no_font() << std::endl;
	std::cout << std::endl;
	std::cout << "output_filename = " << hnc::gnuplot::output_terminal_png("output_filename").output_filename() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::info << "Output terminal svg" << hnc::terminal::reset << std::endl << std::endl;
	std::cout << hnc::gnuplot::output_terminal_svg("output_filename") << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_svg("output_filename").size(1024, 600).enhanced() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_svg("output_filename").no_enhanced().font("Verdana", 10) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_svg("output_filename").font("Verdana", 10).no_font() << std::endl;
	std::cout << std::endl;
	std::cout << "output_filename = " << hnc::gnuplot::output_terminal_svg("output_filename").output_filename() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::info << "Output terminal pdf" << hnc::terminal::reset << std::endl << std::endl;
	std::cout << hnc::gnuplot::output_terminal_pdf("output_filename") << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_pdf("output_filename").size_in_cm(20, 15).enhanced() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_pdf("output_filename").size_in_inches(10, 7.5).enhanced() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_pdf("output_filename").no_enhanced().font("Verdana", 10) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_pdf("output_filename").font("Verdana", 10).no_font() << std::endl;
	std::cout << std::endl;
	std::cout << "output_filename = " << hnc::gnuplot::output_terminal_pdf("output_filename").output_filename() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::info << "Output terminal postscript" << hnc::terminal::reset << std::endl << std::endl;
	std::cout << hnc::gnuplot::output_terminal_postscript("output_filename") << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_postscript("output_filename").no_size() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_postscript("output_filename").size_in_cm(20, 15).enhanced() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_postscript("output_filename").size_in_inches(10, 7.5).no_enhanced().font("Verdana", 10) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_postscript("output_filename").font("Verdana", 10).no_font() << std::endl;
	std::cout << std::endl;
	std::cout << "output_filename = " << hnc::gnuplot::output_terminal_postscript("output_filename").output_filename() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::info << "Output terminal epslatex" << hnc::terminal::reset << std::endl << std::endl;
	std::cout << hnc::gnuplot::output_terminal_epslatex("output_filename") << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_epslatex("output_filename").size_in_cm(20, 15) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_epslatex("output_filename").size_in_inches(10, 7.5) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_epslatex("output_filename").standalone() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_epslatex("output_filename").standalone().no_standalone() << std::endl;
	std::cout << std::endl;
	std::cout << "output_filename = " << hnc::gnuplot::output_terminal_epslatex("output_filename").output_filename() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::terminal::info << "Output terminal wxt" << hnc::terminal::reset << std::endl << std::endl;
	std::cout << hnc::gnuplot::output_terminal_wxt() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_wxt().size(1024, 600).enhanced() << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_wxt().no_enhanced().font("Verdana", 10) << std::endl;
	std::cout << std::endl;
	std::cout << hnc::gnuplot::output_terminal_wxt().font("Verdana", 10).no_font() << std::endl;
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::gnuplot::output_terminal: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
