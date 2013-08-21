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

#include <hnc/gnuplot/x_tics.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


// This functions tests the hnc::gnuplot::axis_tics derivated class
template <class axis_tics_class>
void test_axis_tics_class()
{
	std::cout << std::endl;
	
	std::cout << "Empty tics: \"" << axis_tics_class() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().axis() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().border() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().axis().border() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().border().axis() << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().axis().border().axis_or_border_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().mirror() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().no_mirror() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().mirror().no_mirror() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().no_mirror().mirror() << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().mirror().no_mirror().mirror_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().tic_marks_in() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().tic_marks_out() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().tic_marks_in().tic_marks_out() << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().tic_marks_out().tic_marks_in() << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().tic_marks_in().tic_marks_out().tic_marks_in_or_out_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().scale(1.5) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().scale(1.0, 0.5) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().scale(1.5).scale(1.0, 0.5) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().scale(1.0, 0.5).scale(1.5) << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().scale(1.0, 0.5).scale_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().rotate(hnc::degree<double>(45)) << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().rotate(hnc::degree<double>(45)).rotate_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().offset(0, 1) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().offset(1, 1, 0) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().offset(0, 1).offset(1, 1, 0) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().offset(1, 1, 0).offset(0, 1) << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().offset(1, 1, 0).offset_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << axis_tics_class().font("font name") << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().font("font name", 12) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().font("font name").font("font name", 12) << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().font("font name", 12).font("font name") << std::endl;
	std::cout << std::endl;
	std::cout << "Empty tics: \"" << axis_tics_class().font("font name", 12).font_default() << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << axis_tics_class().axis().mirror().tic_marks_in().scale(1.5).rotate(hnc::degree<double>(45)).offset(0, 1).font("font name") << std::endl;
	std::cout << std::endl;
	std::cout << axis_tics_class().border().no_mirror().tic_marks_out().scale(1.0, 0.5).offset(1, 1, 0).font("font name", 12) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	std::cout << hnc::terminal::info << "Test hnc::gnuplot::x_tics" << hnc::terminal::reset << std::endl;
	test_axis_tics_class<hnc::gnuplot::x_tics>();

	std::cout << hnc::terminal::info << "Test hnc::gnuplot::y_tics" << hnc::terminal::reset << std::endl;
	test_axis_tics_class<hnc::gnuplot::y_tics>();

	std::cout << hnc::terminal::info << "Test hnc::gnuplot::z_tics" << hnc::terminal::reset << std::endl;
	test_axis_tics_class<hnc::gnuplot::z_tics>();

	std::cout << hnc::terminal::info << "Test hnc::gnuplot::x2_tics" << hnc::terminal::reset << std::endl;
	test_axis_tics_class<hnc::gnuplot::x2_tics>();

	std::cout << hnc::terminal::info << "Test hnc::gnuplot::y2_tics" << hnc::terminal::reset << std::endl;
	test_axis_tics_class<hnc::gnuplot::y2_tics>();

	hnc::test::warning(nb_test == 0, "hnc::gnuplot::x_range: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
