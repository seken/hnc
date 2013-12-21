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

#include <hnc/clone.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


class A
{
public:
	virtual ~A() { }
	std::unique_ptr<A> clone() const { std::cout << "A::clone()" << std::endl; return std::unique_ptr<A>(new A(*this)); }
	virtual void display(std::ostream & o) const { o << "one_A"; }
};

class B : public A
{
public:
	virtual ~B() { }
	virtual void display(std::ostream & o) const override { o << "one_B"; }
};


class C
{
public:
	virtual ~C() { }
	virtual void display(std::ostream & o) const { o << "one_C"; }
};

class D : public C
{
public:
	virtual ~D() { }
	std::unique_ptr<D> clone() const { return std::unique_ptr<D>(new D(*this)); }
	virtual void display(std::ostream & o) const override { o << "one_D"; }
};


class E
{
public:
	virtual ~E() { }
	virtual std::unique_ptr<E> clone() const { std::cout << "E::clone()" << std::endl; return std::unique_ptr<E>(new E(*this)); }
	virtual void display(std::ostream & o) const { o << "one_E"; }
};

class F : public E
{
public:
	virtual ~F() { }
	virtual std::unique_ptr<E> clone() const override { std::cout << "F::clone()" << std::endl; return std::unique_ptr<E>(new F(*this)); }
	virtual void display(std::ostream & o) const override { o << "one_F"; }
};

class G : public E, public hnc::cloneable<E, G>
{
public:
	virtual ~G() { }
	using hnc::cloneable<E, G>::clone;
	virtual void display(std::ostream & o) const override { o << "one_G"; }
};


class H : public hnc::cloneable<H, H>
{
public:
	virtual ~H() { }
	virtual void display(std::ostream & o) const { o << "one_H"; }
};

class I : public H, public hnc::cloneable<H, I>
{
public:
	virtual ~I() { }
	using hnc::cloneable<H, I>::clone;
	virtual void display(std::ostream & o) const override { o << "one_I"; }
};

class J : public I, public hnc::cloneable<H, J>
{
public:
	virtual ~J() { }
	using hnc::cloneable<H, J>::clone;
	virtual void display(std::ostream & o) const override { o << "one_J"; }
};


class K
{
public:
	virtual ~K() { }
	hnc_generate_clone_method(K, K)
	virtual void display(std::ostream & o) const { o << "one_K"; }
};

class L : public K
{
public:
	virtual ~L() { }
	hnc_generate_clone_method(K, L)
	virtual void display(std::ostream & o) const { o << "one_L"; }
};

class M : public L
{
public:
	virtual ~M() { }
	hnc_generate_clone_method(K, M)
	virtual void display(std::ostream & o) const { o << "one_M"; }
};


std::ostream & operator<<(std::ostream & o, A const & v) { v.display(o); return o; }
std::ostream & operator<<(std::ostream & o, C const & v) { v.display(o); return o; }
std::ostream & operator<<(std::ostream & o, E const & v) { v.display(o); return o; }
std::ostream & operator<<(std::ostream & o, H const & v) { v.display(o); return o; }
std::ostream & operator<<(std::ostream & o, K const & v) { v.display(o); return o; }

template <class T>
std::ostream & operator<<(std::ostream & o, std::unique_ptr<T> const & p) { o << *p; return o; }


template <class T>
void test_is_cloneable_and_clone
(
	T const & t, std::string const & type_name,
	bool const expected_result, std::string const & expected_clone_display,
	int & nb_test
)
{
	nb_test += 4;
	
	if (hnc::is_cloneable<T>())
	{
		std::cout << type_name << " is cloneable" << std::endl;
	}
	else
	{
		std::cout << type_name << " is not cloneable" << std::endl;
	}
	nb_test -= hnc::test::warning(hnc::is_cloneable<T>() == expected_result, type_name + " should be hnc::is_cloneable\n");
	
	auto clone = hnc::to_string(hnc::clone(t));
	auto clone_of_clone = hnc::to_string(hnc::clone(clone));
	auto clone_to_unique_ptr = hnc::clone_to_unique_ptr(t);
	std::cout << "Original                 = " << hnc::to_string(t) << std::endl;
	std::cout << "Clone                    = " << hnc::to_string(clone) << std::endl;
	std::cout << "Clone of clone           = " << hnc::to_string(clone_of_clone) << std::endl;
	std::cout << "Clone to std::unique_ptr = " << hnc::to_string(*clone_to_unique_ptr) << std::endl;
	nb_test -= hnc::test::warning(hnc::to_string(clone) == expected_clone_display, "hnc::clone display fails with a " + type_name + "\n");
	nb_test -= hnc::test::warning(hnc::to_string(clone_of_clone) == expected_clone_display, "hnc::clone of clone display fails with a " + type_name + "\n");
	nb_test -= hnc::test::warning(hnc::to_string(*clone_to_unique_ptr) == expected_clone_display, "hnc::clone_to_unique_ptr display fails with a " + type_name + "\n");
	std::cout << std::endl;
}


int main()
{
	int nb_test = 0;
	
	test_is_cloneable_and_clone('c', "char", false, "c", nb_test);
	test_is_cloneable_and_clone(std::string("string"), "std::string", false, "string", nb_test);
	test_is_cloneable_and_clone(42, "int", false, "42", nb_test);
	test_is_cloneable_and_clone(21.42f, "float", false, "21.42", nb_test);
	test_is_cloneable_and_clone(73.42, "double", false, "73.42", nb_test);
	
	test_is_cloneable_and_clone(A(), "A", true, "one_A", nb_test);
	test_is_cloneable_and_clone(B(), "B", true, "one_A", nb_test); // B has not override the .clone() method
	
	test_is_cloneable_and_clone(C(), "C", false, "one_C", nb_test);
	test_is_cloneable_and_clone(D(), "D", true, "one_D", nb_test);
	
	test_is_cloneable_and_clone(E(), "E", true, "one_E", nb_test);
	test_is_cloneable_and_clone(F(), "F", true, "one_F", nb_test);
	test_is_cloneable_and_clone(G(), "G", true, "one_G", nb_test);
	
	test_is_cloneable_and_clone(H(), "H", true, "one_H", nb_test);
	test_is_cloneable_and_clone(I(), "I", true, "one_I", nb_test);
	test_is_cloneable_and_clone(J(), "J", true, "one_J", nb_test);
	
	test_is_cloneable_and_clone(K(), "K", true, "one_K", nb_test);
	test_is_cloneable_and_clone(L(), "L", true, "one_L", nb_test);
	test_is_cloneable_and_clone(M(), "M", true, "one_M", nb_test);

	hnc::test::warning(nb_test == 0, "hnc::clone: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
