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

#include <hnc/gnuplot/gnuplot_lines.hpp>
#include <hnc/system.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;

	int nb_test = 0;
	
	{
		std::map<std::string, int> data;
		data["A"] = 1;
		data["B"] = 2;
		data["C"] = 5;
		data["D"] = 3;
		data["E"] = 4;
		data["F"] = 2;
		data["G"] = 1;
		
		hnc::gnuplot::gnuplot_lines gp
		(
			hnc::gnuplot::output_terminal_png("hnc_gnuplot_gnuplot_lines").size(640, 480),
			data
		);
		gp.plot().set_title("lines legend");

		gp.set_title("hnc::gnuplot::gnuplot\\_lines");
		gp.y_range.range(0, gp.max_data_value() + 1);
		
		// Write in files
		gp.write_script_in_file();
		gp.write_data_in_file();

		// Script
		std::cout << "# Script filename = " << gp.script_filename() << std::endl;
		std::cout << gp.script() << std::endl;
		
		// Data
		for (std::pair<std::string, std::string> const & data : gp.data())
		{
			std::string const & data_filename = data.first;
			std::string const & data_value = data.second;
			std::cout << "# Data filename = " << data_filename << std::endl;
			std::cout << data_value << std::endl;
		}

		// Min max data value
		nb_test += 2;
		{
			std::cout << "Minimum data value = " << gp.min_data_value() << std::endl;
			std::cout << "Maximum data value = " << gp.max_data_value() << std::endl;
			nb_test -= hnc::test::warning(gp.min_data_value() == 1, "hnc::gnuplot::gnuplot_lines:min_data_value fails\n");
			nb_test -= hnc::test::warning(gp.max_data_value() == 5, "hnc::gnuplot::gnuplot_lines:max_data_value fails\n");
		}
		std::cout << std::endl;

		hnc::system("gnuplot", gp.script_filename());
		std::cout << "You can copy \"" << gp.output_filename() << "\" in doc/img/ (and convert it in .eps with Gimp)" << std::endl;
		std::cout << std::endl;
	}

	hnc::test::warning(nb_test == 0, "hnc::gnuplot::gnuplot_lines: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
