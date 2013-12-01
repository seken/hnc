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

#include <hnc/gnuplot/plot_lines.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;

	int nb_test = 0;

	std::cout << hnc::gnuplot::plot_lines() << std::endl;
	std::cout << hnc::gnuplot::plot_lines("data_filename.data") << std::endl;
	std::cout << std::endl;

	{
		std::map<std::string, int> data;
		data["A"] = 1;
		data["B"] = 2;
		data["C"] = 5;
		data["D"] = 3;
		std::cout << hnc::gnuplot::plot_lines().set_data(data).data();
		std::cout << std::endl;
	}

	hnc::test::warning(nb_test == 0, "hnc::gnuplot::plot_lines: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
