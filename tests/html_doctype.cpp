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

#include <hnc/html/doctype.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	std::cout << "HTML" << std::endl;
	std::cout << hnc::html::doctype::html() << std::endl;
	std::cout << std::endl;

	std::cout << "HTML 5" << std::endl;
	std::cout << hnc::html::doctype::html_5() << std::endl;
	std::cout << std::endl;

	std::cout << "XHTML 1.0 Strict" << std::endl;
	std::cout << hnc::html::doctype::xhtml_1d0_strict() << std::endl;
	std::cout << std::endl;

	std::cout << "XHTML 1.0 Strict" << std::endl;
	std::cout << hnc::html::doctype::xhtml_1d0_transitional() << std::endl;
	std::cout << std::endl;

	std::cout << "XHTML 1.0 Strict" << std::endl;
	std::cout << hnc::html::doctype::xhtml_1d0_frameset() << std::endl;
	std::cout << std::endl;

	std::cout << "XHTML 1.1" << std::endl;
	std::cout << hnc::html::doctype::xhtml_1d1() << std::endl;
	std::cout << std::endl;

	std::cout << "HTML 4.01 Strict" << std::endl;
	std::cout << hnc::html::doctype::html_4d01_strict() << std::endl;
	std::cout << std::endl;

	std::cout << "HTML 4.01 Transitional" << std::endl;
	std::cout << hnc::html::doctype::html_4d01_transitional() << std::endl;
	std::cout << std::endl;

	std::cout << "HTML 4.01 Frameset" << std::endl;
	std::cout << hnc::html::doctype::html_4d01_frameset() << std::endl;
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::html::doctype: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
