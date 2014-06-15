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

#include <hnc/value_ptr.hpp>
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

std::ostream & operator <<(std::ostream & o, A const & v) { v.display(o); return o; }


int main()
{
	int nb_test = 0;
	
	nb_test += 5;
	{
		hnc::value_ptr<double> v(73.42);
		hnc::value_ptr<double> v_copy_constructor(v);
		hnc::value_ptr<double> v_copy_assignement; v_copy_assignement = v;
		std::cout << v << std::endl;
		std::cout << v_copy_constructor << std::endl;
		std::cout << v_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(*v == 73.42, "Constructor fails\n");
		nb_test -= hnc::test::warning(*v_copy_constructor == 73.42, "Copy constructor fails\n");
		nb_test -= hnc::test::warning(*v_copy_assignement == 73.42, "Copy assignement fails\n");
		
		hnc::value_ptr<double> v0 = v;
		hnc::value_ptr<double> v1 = v;
		hnc::value_ptr<double> v_move_constructor(std::move(v0));
		hnc::value_ptr<double> v_move_assignement(21.0); v_move_assignement = std::move(v1);
// 		std::cout << v0 << std::endl;
// 		std::cout << v1 << std::endl;
		std::cout << v_move_constructor << std::endl;
		std::cout << v_move_assignement << std::endl;
		nb_test -= hnc::test::warning(/**v0 == 0.0 &&*/ *v_move_constructor == 73.42, "Move constructor fails\n");
		nb_test -= hnc::test::warning(/**v1 == 0.0 &&*/ *v_move_assignement == 73.42, "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 5;
	{
		hnc::value_ptr<int> v(42);
		hnc::value_ptr<int> v_copy_constructor(v);
		hnc::value_ptr<int> v_copy_assignement; v_copy_assignement = v;
		std::cout << v << std::endl;
		std::cout << v_copy_constructor << std::endl;
		std::cout << v_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(*v == 42, "Constructor fails\n");
		nb_test -= hnc::test::warning(*v_copy_constructor == 42, "Copy constructor fails\n");
		nb_test -= hnc::test::warning(*v_copy_assignement == 42, "Copy assignement fails\n");
		
		hnc::value_ptr<int> v0 = v;
		hnc::value_ptr<int> v1 = v;
		hnc::value_ptr<int> v_move_constructor(std::move(v0));
		hnc::value_ptr<int> v_move_assignement(21); v_move_assignement = std::move(v1);
// 		std::cout << v0 << std::endl;
// 		std::cout << v1 << std::endl;
		std::cout << v_move_constructor << std::endl;
		std::cout << v_move_assignement << std::endl;
		nb_test -= hnc::test::warning(/**v0 == 0.0 &&*/ *v_move_constructor == 42, "Move constructor fails\n");
		nb_test -= hnc::test::warning(/**v1 == 0.0 &&*/ *v_move_assignement == 42, "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 5;
	{
		hnc::value_ptr<std::string> v("hnc::value_ptr of std::string");
		hnc::value_ptr<std::string> v_copy_constructor(v);
		hnc::value_ptr<std::string> v_copy_assignement; v_copy_assignement = v;
		std::cout << v << std::endl;
		std::cout << v_copy_constructor << std::endl;
		std::cout << v_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(*v == "hnc::value_ptr of std::string", "Constructor fails\n");
		nb_test -= hnc::test::warning(*v_copy_constructor == "hnc::value_ptr of std::string", "Copy constructor fails\n");
		nb_test -= hnc::test::warning(*v_copy_assignement == "hnc::value_ptr of std::string", "Copy assignement fails\n");
		
		hnc::value_ptr<std::string> v0 = v;
		hnc::value_ptr<std::string> v1 = v;
		hnc::value_ptr<std::string> v_move_constructor(std::move(v0));
		hnc::value_ptr<std::string> v_move_assignement("default value"); v_move_assignement = std::move(v1);
// 		std::cout << v0 << std::endl;
// 		std::cout << v1 << std::endl;
		std::cout << v_move_constructor << std::endl;
		std::cout << v_move_assignement << std::endl;
		nb_test -= hnc::test::warning(/**v0 == 0.0 &&*/ *v_move_constructor == "hnc::value_ptr of std::string", "Move constructor fails\n");
		nb_test -= hnc::test::warning(/**v1 == 0.0 &&*/ *v_move_assignement == "hnc::value_ptr of std::string", "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 5;
	{
		hnc::value_ptr<A> v;
		hnc::value_ptr<A> v_copy_constructor(v);
		hnc::value_ptr<A> v_copy_assignement; v_copy_assignement = v;
		std::cout << v << std::endl;
		std::cout << v_copy_constructor << std::endl;
		std::cout << v_copy_assignement << std::endl;
		nb_test -= hnc::test::warning(hnc::to_string(v) == "one_A", "Constructor fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(v_copy_constructor) == "one_A", "Copy constructor fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(v_copy_assignement) == "one_A", "Copy assignement fails\n");
		
		hnc::value_ptr<A> v0 = v;
		hnc::value_ptr<A> v1 = v;
		hnc::value_ptr<A> v_move_constructor(std::move(v0));
		hnc::value_ptr<A> v_move_assignement; v_move_assignement = std::move(v1);
// 		std::cout << v0 << std::endl;
// 		std::cout << v1 << std::endl;
		std::cout << v_move_constructor << std::endl;
		std::cout << v_move_assignement << std::endl;
		nb_test -= hnc::test::warning(/**v0 == 0.0 &&*/ hnc::to_string(v_move_constructor) == "one_A", "Move constructor fails\n");
		nb_test -= hnc::test::warning(/**v1 == 0.0 &&*/ hnc::to_string(v_move_assignement) == "one_A", "Move assignement fails\n");
	}
	std::cout << std::endl;
	
	nb_test += 9;
	{
		hnc::value_ptr<B> v;
		hnc::value_ptr<B> v_copy_constructor(v);
		hnc::value_ptr<A> v_copy_constructor_A(v);
		hnc::value_ptr<B> v_copy_assignement; v_copy_assignement = v;
		hnc::value_ptr<A> v_copy_assignement_A; v_copy_assignement_A = v;
		std::cout << v << std::endl;
		std::cout << v_copy_constructor << std::endl;
		std::cout << v_copy_constructor_A << std::endl;
		std::cout << v_copy_assignement << std::endl;
		std::cout << v_copy_assignement_A << std::endl;
		nb_test -= hnc::test::warning(hnc::to_string(v) == "one_B", "Constructor fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(v_copy_constructor) == "one_B", "hnc::value_ptr<B> copy constructor fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(v_copy_constructor_A) == "one_B", "Copy constructor (A) fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(v_copy_assignement) == "one_B", "Copy assignement fails\n");
		nb_test -= hnc::test::warning(hnc::to_string(v_copy_assignement_A) == "one_B", "Copy assignement (A) fails\n");
		
		hnc::value_ptr<B> v0 = v;
		hnc::value_ptr<B> v1 = v;
		hnc::value_ptr<B> v2 = v;
		hnc::value_ptr<B> v3 = v;
		hnc::value_ptr<B> v_move_constructor(std::move(v0));
		hnc::value_ptr<A> v_move_constructor_A(std::move(v2));
		hnc::value_ptr<B> v_move_assignement; v_move_assignement = std::move(v1);
		hnc::value_ptr<A> v_move_assignement_A; v_move_assignement_A = std::move(v3);
// 		std::cout << v0 << std::endl;
// 		std::cout << v1 << std::endl;
// 		std::cout << v2 << std::endl;
// 		std::cout << v3 << std::endl;
		std::cout << v_move_constructor << std::endl;
		std::cout << v_move_constructor_A << std::endl;
		std::cout << v_move_assignement << std::endl;
		std::cout << v_move_assignement_A << std::endl;
		nb_test -= hnc::test::warning(/*bool(v0) == false &&*/ hnc::to_string(v_move_constructor) == "one_B", "Move constructor fails\n");
		nb_test -= hnc::test::warning(/*bool(v1) == false &&*/ hnc::to_string(v_move_assignement) == "one_B", "Move assignement fails\n");
		nb_test -= hnc::test::warning(/*bool(v2) == false &&*/ hnc::to_string(v_move_constructor_A) == "one_B", "Move constructor (A) fails\n");
		nb_test -= hnc::test::warning(/*bool(v3) == false &&*/ hnc::to_string(v_move_assignement_A) == "one_B", "Move assignement (A) fails\n");
	}
	std::cout << std::endl;
	
	{
		// Create a A
		hnc::value_ptr<A> a = A();
		std::cout << a << std::endl; // one_A
		
		// Create a B
		hnc::value_ptr<A> b = B();
		std::cout << b << std::endl; // one_B
		
		// Copy
		hnc::value_ptr<A> c = b;
		std::cout << c << std::endl; // one_B
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::value_ptr: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
