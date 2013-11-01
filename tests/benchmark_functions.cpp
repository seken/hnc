// Copyright © 2012,2013 Lénaïc Bagnères, hnc@singularity.fr

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
#include <string>
#include <vector>

#include <hnc/benchmark_functions.hpp>
#include <hnc/sleep.hpp>
#include <hnc/system.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	{
		auto benchmark_functions = hnc::benchmark_functions
		(
			{
				{ []() -> void { hnc::sleep::ms(20); }, "v0" },
				{ []() -> void { hnc::sleep::ms(40); }, "v1" },
				{ []() -> void { hnc::sleep::ms(60); }, "v2" },
				{ []() -> void { hnc::sleep::ms(80); }, "v3" },
				{ []() -> void { hnc::sleep::ms(30); }, "v4" },
				{ []() -> void { hnc::sleep::ms(50); }, "v5" },
				{ []() -> void { hnc::sleep::ms(60); }, "v6" }
			},
			"Title",
			"hnc_benchmark_functions_gnuplot",
			3
		);
		hnc::benchmark const & benchmark = std::get<0>(benchmark_functions);
		hnc::gnuplot::gnuplot_boxes & gnuplot = std::get<1>(benchmark_functions);
		hnc::tabular const & tabular = std::get<2>(benchmark_functions);

		// Bench
		std::cout << benchmark << std::endl;
		std::cout << std::endl;

		// Gnuplot
		std::cout << gnuplot.script() << std::endl;
		std::cout << gnuplot.data().at(0).second << std::endl;
		std::cout << std::endl;
		gnuplot.write_script_in_file();
		gnuplot.write_data_in_file();
		hnc::system("gnuplot", gnuplot.script_filename());

		// Tabular
		std::cout << tabular << std::endl;
		std::cout << std::endl;
	}

	hnc::test::warning(nb_test == 0, "hnc::benchmark_functions: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
