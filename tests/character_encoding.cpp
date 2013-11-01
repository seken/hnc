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

#include <hnc/character_encoding.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

	std::cout << "Base class" << std::endl;
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::encoding();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Unicode" << std::endl;
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::utf8();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::utf16();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::utf32();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "ASCII" << std::endl;
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::ascii();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::us_ascii();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "ISO 8859" << std::endl;
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::iso_8859_15();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Microsoft Windows character sets" << std::endl;
	{
		hnc::character_encoding::encoding charset_code = hnc::character_encoding::windows_1252();
		std::cout << charset_code.code() << "\n\t" << charset_code.description() << " (" << charset_code << ")" << std::endl;
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::character_encoding: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
