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

#include <hnc/lang.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	auto get_lang_code = [](hnc::lang::lang_code const & lang_code) -> std::string
	{
		return "ISO 639-1=\"" + lang_code.iso_639_1() + "\" ISO 639-2=\"" + lang_code.iso_639_2() + "\" ISO 639-1=\"" + lang_code.iso_639_3() + "\" html=\"" + lang_code.html() + "\" no_lang=" + hnc::to_string(lang_code.no_lang()) + " Name=\"" + lang_code.name() + "\" (" + hnc::to_string(lang_code) + ")";
	};

	std::cout << "No lang (base class)" << std::endl;
	{
		hnc::lang::lang_code lang_code = hnc::lang::lang_code();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	
	std::cout << "A" << std::endl;
	{
		hnc::lang::lang_code lang_code = hnc::lang::afar();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::abkhazian();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::afrikaans();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::akan();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::albanian();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::amharic();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::arabic();
		std::cout << get_lang_code(lang_code) << std::endl;
	}
	{
		hnc::lang::lang_code lang_code = hnc::lang::aragonese();
		std::cout << get_lang_code(lang_code) << std::endl;
	}

	std::cout << "D" << std::endl;
	{
		hnc::lang::lang_code lang_code = hnc::lang::german();
		std::cout << get_lang_code(lang_code) << std::endl;
	}

	std::cout << "E" << std::endl;
	{
		hnc::lang::lang_code lang_code = hnc::lang::english();
		std::cout << get_lang_code(lang_code) << std::endl;
	}

	std::cout << "F" << std::endl;
	{
		hnc::lang::lang_code lang_code = hnc::lang::french();
		std::cout << get_lang_code(lang_code) << std::endl;
	}

	hnc::test::warning(nb_test == 0, "hnc::lang::lang_code: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
