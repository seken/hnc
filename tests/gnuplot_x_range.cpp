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

#include <hnc/gnuplot/x_range.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	std::cout << hnc::gnuplot::x_range() << std::endl;
	std::cout << hnc::gnuplot::x_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::x_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::x_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::x_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::y_range() << std::endl;
	std::cout << hnc::gnuplot::y_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::y_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::y_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::y_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::z_range() << std::endl;
	std::cout << hnc::gnuplot::z_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::z_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::z_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::z_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::x2_range() << std::endl;
	std::cout << hnc::gnuplot::x2_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::x2_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::x2_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::x2_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::y2_range() << std::endl;
	std::cout << hnc::gnuplot::y2_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::y2_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::y2_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::y2_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::cb_range() << std::endl;
	std::cout << hnc::gnuplot::cb_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::cb_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::cb_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::cb_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::r_range() << std::endl;
	std::cout << hnc::gnuplot::r_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::r_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::r_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::r_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::t_range() << std::endl;
	std::cout << hnc::gnuplot::t_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::t_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::t_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::t_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::u_range() << std::endl;
	std::cout << hnc::gnuplot::u_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::u_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::u_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::u_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	std::cout << hnc::gnuplot::vr_range() << std::endl;
	std::cout << hnc::gnuplot::vr_range().range(0, 10).reverse().writeback() << std::endl;
	std::cout << hnc::gnuplot::vr_range().range(0.1, 0.9).reverse().no_reverse() << std::endl;
	std::cout << hnc::gnuplot::vr_range().range(21.42, 73).writeback().no_writeback() << std::endl;
	std::cout << hnc::gnuplot::vr_range().no_reverse().no_writeback() << std::endl;
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::gnuplot::x_range: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
