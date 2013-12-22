// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/copy_ptr.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


class A
{
public:
	
	virtual ~A() { }
	
	hnc_generate_clone_method(A, A)
	
	virtual void display(std::ostream & o) const { o << "one_A"; }
};

class B : public A
{
public:
	
	virtual ~B() { }
	
	hnc_generate_clone_method(A, B)
	
	virtual void display(std::ostream & o) const override { o << "one_B"; }
};

std::ostream & operator<<(std::ostream & o, A const & v) { v.display(o); return o; }


int main()
{
	int nb_test = 0;
	
	nb_test += 5;
	{
		hnc::copy_ptr<double> p = hnc::make_copy_ptr<double>(73.42);
		hnc::copy_ptr<double> p_copy_constructor(p);
		hnc::copy_ptr<double> p_copy_assignement; p_copy_assignement = p;
		std::cout << p << std::endl;
		std::cout << p_copy_constructor << std::endl;
		std::cout << p_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(*p == 73.42, "hnc::make_copy_ptr<double>(73.42) fails\n");
		nb_test -= hnc::test::warning(*p_copy_constructor == 73.42, "Copy constructor fails\n");
		nb_test -= hnc::test::warning(*p_copy_assignement == 73.42, "Copy assignement fails\n");
		
		hnc::copy_ptr<double> p0 = p;
		hnc::copy_ptr<double> p1 = p;
		hnc::copy_ptr<double> p_move_constructor(std::move(p0));
		hnc::copy_ptr<double> p_move_assignement = hnc::make_copy_ptr<double>(21.0); p_move_assignement = std::move(p1);
		std::cout << p0 << std::endl;
		std::cout << p1 << std::endl;
		std::cout << p_move_constructor << std::endl;
		std::cout << p_move_assignement << std::endl;
		nb_test -= hnc::test::warning(bool(p0) == false && *p_move_constructor == 73.42, "Move constructor fails\n");
		nb_test -= hnc::test::warning(bool(p1) == false && *p_move_assignement == 73.42, "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 5;
	{
		hnc::copy_ptr<int> p = hnc::make_copy_ptr<int>(42);
		hnc::copy_ptr<int> p_copy_constructor(p);
		hnc::copy_ptr<int> p_copy_assignement; p_copy_assignement = p;
		std::cout << p << std::endl;
		std::cout << p_copy_constructor << std::endl;
		std::cout << p_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(*p == 42, "hnc::make_copy_ptr<int>(42) fails\n");
		nb_test -= hnc::test::warning(*p_copy_constructor == 42, "Copy constructor fails\n");
		nb_test -= hnc::test::warning(*p_copy_assignement == 42, "Copy assignement fails\n");
		
		hnc::copy_ptr<int> p0 = p;
		hnc::copy_ptr<int> p1 = p;
		hnc::copy_ptr<int> p_move_constructor(std::move(p0));
		hnc::copy_ptr<int> p_move_assignement = hnc::make_copy_ptr<int>(21); p_move_assignement = std::move(p1);
		std::cout << p0 << std::endl;
		std::cout << p1 << std::endl;
		std::cout << p_move_constructor << std::endl;
		std::cout << p_move_assignement << std::endl;
		nb_test -= hnc::test::warning(bool(p0) == false && *p_move_constructor == 42, "Move constructor fails\n");
		nb_test -= hnc::test::warning(bool(p1) == false && *p_move_assignement == 42, "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 5;
	{
		hnc::copy_ptr<std::string> p = hnc::make_copy_ptr<std::string>("hnc::copy_ptr of std::string");
		hnc::copy_ptr<std::string> p_copy_constructor(p);
		hnc::copy_ptr<std::string> p_copy_assignement; p_copy_assignement = p;
		std::cout << p << std::endl;
		std::cout << p_copy_constructor << std::endl;
		std::cout << p_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(*p == "hnc::copy_ptr of std::string", "hnc::make_copy_ptr<std::string>(\"hnc::copy_ptr of std::string\") fails\n");
		nb_test -= hnc::test::warning(*p_copy_constructor == "hnc::copy_ptr of std::string", "Copy constructor fails\n");
		nb_test -= hnc::test::warning(*p_copy_assignement == "hnc::copy_ptr of std::string", "Copy assignement fails\n");
		
		hnc::copy_ptr<std::string> p0 = p;
		hnc::copy_ptr<std::string> p1 = p;
		hnc::copy_ptr<std::string> p_move_constructor(std::move(p0));
		hnc::copy_ptr<std::string> p_move_assignement = hnc::make_copy_ptr<std::string>("default value"); p_move_assignement = std::move(p1);
		std::cout << p0 << std::endl;
		std::cout << p1 << std::endl;
		std::cout << p_move_constructor << std::endl;
		std::cout << p_move_assignement << std::endl;
		nb_test -= hnc::test::warning(bool(p0) == false && *p_move_constructor == "hnc::copy_ptr of std::string", "Move constructor fails\n");
		nb_test -= hnc::test::warning(bool(p1) == false && *p_move_assignement == "hnc::copy_ptr of std::string", "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 5;
	{
		hnc::copy_ptr<A> p = hnc::make_copy_ptr<A>();
		hnc::copy_ptr<A> p_copy_constructor(p);
		hnc::copy_ptr<A> p_copy_assignement; p_copy_assignement = p;
		std::cout << p << std::endl;
		std::cout << p_copy_constructor << std::endl;
		std::cout << p_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(hnc::to_string(p) == "one_A", "hnc::make_copy_ptr<int>(42) fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(p_copy_constructor) == "one_A", "Constructor fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(p_copy_assignement) == "one_A", "Copy assignement fails\n");
		
		hnc::copy_ptr<A> p0 = p;
		hnc::copy_ptr<A> p1 = p;
		hnc::copy_ptr<A> p_move_constructor(std::move(p0));
		hnc::copy_ptr<A> p_move_assignement; p_move_assignement = std::move(p1);
		std::cout << p0 << std::endl;
		std::cout << p1 << std::endl;
		std::cout << p_move_constructor << std::endl;
		std::cout << p_move_assignement << std::endl;
		nb_test -= hnc::test::warning(bool(p0) == false && hnc::to_string(p_move_constructor) == "one_A", "Move constructor fails\n");
		nb_test -= hnc::test::warning(bool(p1) == false && hnc::to_string(p_move_assignement) == "one_A", "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 9;
	{
		hnc::copy_ptr<B> p = hnc::make_copy_ptr<B>();
		hnc::copy_ptr<B> p_copy_constructor(p);
		hnc::copy_ptr<A> p_copy_constructor_A(p);
		hnc::copy_ptr<B> p_copy_assignement; p_copy_assignement = p;
		hnc::copy_ptr<A> p_copy_assignement_A; p_copy_assignement_A = p;
		std::cout << p << std::endl;
		std::cout << p_copy_constructor << std::endl;
		std::cout << p_copy_constructor_A << std::endl;
		std::cout << p_copy_assignement << std::endl;
		std::cout << p_copy_assignement_A << std::endl;
		nb_test -= hnc::test::warning(hnc::to_string(p) == "one_B", "hnc::make_copy_ptr<int>(42) fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(p_copy_constructor) == "one_B", "hnc::copy_ptr<B> copy constructor fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(p_copy_constructor_A) == "one_B", "Copy constructor (A) fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(p_copy_assignement) == "one_B", "Copy assignement fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(p_copy_assignement_A) == "one_B", "Copy assignement (A) fails\n");
		
		hnc::copy_ptr<B> p0 = p;
		hnc::copy_ptr<B> p1 = p;
		hnc::copy_ptr<B> p2 = p;
		hnc::copy_ptr<B> p3 = p;
		hnc::copy_ptr<B> p_move_constructor(std::move(p0));
		hnc::copy_ptr<A> p_move_constructor_A(std::move(p2));
		hnc::copy_ptr<B> p_move_assignement; p_move_assignement = std::move(p1);
		hnc::copy_ptr<A> p_move_assignement_A; p_move_assignement_A = std::move(p3);
		std::cout << p0 << std::endl;
		std::cout << p1 << std::endl;
		std::cout << p2 << std::endl;
		std::cout << p3 << std::endl;
		std::cout << p_move_constructor << std::endl;
		std::cout << p_move_constructor_A << std::endl;
		std::cout << p_move_assignement << std::endl;
		std::cout << p_move_assignement_A << std::endl;
		nb_test -= hnc::test::warning(bool(p0) == false && hnc::to_string(p_move_constructor) == "one_B", "Move constructor fails\n");
		nb_test -= hnc::test::warning(bool(p1) == false && hnc::to_string(p_move_assignement) == "one_B", "Move assignement fails\n");
		nb_test -= hnc::test::warning(bool(p2) == false && hnc::to_string(p_move_constructor_A) == "one_B", "Move constructor (A) fails\n");
		nb_test -= hnc::test::warning(bool(p3) == false && hnc::to_string(p_move_assignement_A) == "one_B", "Move assignement (A) fails\n");
	}
	std::cout << std::endl;
	
	{
		// Default constructor
		hnc::copy_ptr<A> p;
		std::cout << p << std::endl; // nullptr
		
		// Create a A
		p = hnc::make_copy_ptr<A>();
		std::cout << p << std::endl; // one_A
		
		// Create a B
		p = hnc::make_copy_ptr<B>();
		std::cout << p << std::endl; // one_B
		
		// Copy the pointer
		hnc::copy_ptr<A> p_copy = p;
		std::cout << p_copy << std::endl; // one_B
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::copy_ptr: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
