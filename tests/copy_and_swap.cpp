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
#include <memory>

#include <hnc/copy_and_swap.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


class A
{ };

class B
{
public:
	
	int v;
	
	void swap(B & b) { std::cout << ".swap(B &) method is call" << std::endl; std::swap(v, b.v); }
};

class C
{
public:
	
	int v;
	
	void swap(C & c) { std::cout << ".swap(C &) method is call" << std::endl; std::swap(v, c.v); }
};

hnc_overload_std_swap_with_swap_method_for_class(C)

template <class T>
class D
{
public:
	
	T v;
	
	void swap(D<T> & d) { std::cout << ".swap(D<T> &) method is call" << std::endl; std::swap(v, d.v); }
};

hnc_overload_std_swap_with_swap_method_for_template_class(D<T>, class T)

class E
{
public:
	
	int v;
	
	E(int const v = 0) : v(v) { }
	
	E(E const & e) : v(e.v) { }
	
	E(E && e) : v(e.v) { e.v = 0; }
	
	hnc_generate_copy_and_move_assignment(E)
	
	void swap(E & e) { std::cout << ".swap(E &) method is call" << std::endl; std::swap(v, e.v); }
};

hnc_overload_std_swap_with_swap_method_for_class(E)

class F
{
public:
	
	int v;
	
	F(int const v = 0) : v(v) { }
	
	F(F const & f) : v(f.v) { }
	
	F(F && f) : v(f.v) { f.v = 0; }
	
	virtual ~F() { }
	
	hnc_generate_virtual_copy_and_move_assignment(F)
	
	void swap(F & f) { std::cout << ".swap(F &) method is call" << std::endl; std::swap(v, f.v); }
};

hnc_overload_std_swap_with_swap_method_for_class(F)


int main()
{
	int nb_test = 0;
	
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<int>() == false, "hnc::is_swappable_with_swap_method<int> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<double>() == false, "hnc::is_swappable_with_swap_method<double> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<char>() == false, "hnc::is_swappable_with_swap_method<char> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<std::string>() == true, "hnc::is_swappable_with_swap_method<std::string> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<std::unique_ptr<int>>() == true, "hnc::is_swappable_with_swap_method<std::unique_ptr<int>> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<A>() == false, "hnc::is_swappable_with_swap_method<A> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<B>() == true, "hnc::is_swappable_with_swap_method<B> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<C>() == true, "hnc::is_swappable_with_swap_method<C> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<D<int>>() == true, "hnc::is_swappable_with_swap_method<D> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<E>() == true, "hnc::is_swappable_with_swap_method<E> fails!\n");
	++nb_test;
	nb_test -= hnc::test::warning(hnc::is_swappable_with_swap_method<F>() == true, "hnc::is_swappable_with_swap_method<F> fails!\n");
	
	B b0; B b1; std::swap(b0, b1); b0.swap(b1);
	std::cout << std::endl;
	
	C c0; C c1; std::swap(c0, c1); c0.swap(c1);
	std::cout << std::endl;
	
	D<int> d0; D<int> d1; std::swap(d0, d1); d0.swap(d1);
	std::cout << std::endl;
	
	E e0(42); E e1(73); std::swap(e0, e1); e0.swap(e1);
	std::cout << std::endl;
	
	F f0(42); F f1(73); std::swap(f0, f1); f0.swap(f1);
	std::cout << std::endl;
	
	nb_test += 2;
	E e_move_constructor(std::move(e0));
	E e_move_assignment; e_move_assignment = std::move(e1);
	nb_test -= hnc::test::warning(e_move_constructor.v == 42 && e0.v == 0, "Move constructor of E fails!\n");
	nb_test -= hnc::test::warning(e_move_assignment.v == 73 && e1.v == 0, "Move assignment of E fails!\n");
	std::cout << std::endl;
	
	nb_test += 2;
	F f_move_constructor(std::move(f0));
	F f_move_assignment; f_move_assignment = std::move(f1);
	nb_test -= hnc::test::warning(f_move_constructor.v == 42 && f0.v == 0, "Move constructor of F fails!\n");
	nb_test -= hnc::test::warning(f_move_assignment.v == 73 && f1.v == 0, "Move assignment of F fails!\n");
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::copy_and_swap: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return nb_test;
}
