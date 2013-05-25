// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <iostream>
#include <vector>

#include <hnc/mpi/future.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


// Just a display, no return
// You need override the operator()
class remote_compute_display : public hnc::mpi::functor
{
public:

	// Function
	void operator()() override
	{
		std::cout << "remote_compute_display\n";
	}

private:

	#ifndef NO_HNC_Boost_Serialization

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, unsigned int const /*version*/)
	{
		ar & boost::serialization::base_object<hnc::mpi::functor>(*this);
	}
	
	#endif
};

#ifndef NO_HNC_Boost_Serialization
BOOST_CLASS_EXPORT(remote_compute_display)
#endif


// Compute a int
// You need:
//   - have result_t type
//   - override the operator()
//   - overload "result_t move_result()" to send your result with std::move
class remote_compute_int : public hnc::mpi::functor
{
public:

	// Result type
	using result_t = int;

private:

	// Result
	result_t r;

public:

	// Function
	void operator()() override
	{
		std::cout << "remote_compute_int\n";
		r = 21 * 42 * 73;
	}

	// Return the result with std::move
	result_t move_result() { return std::move(r); }

	// Send the result with send_result(T)
	void get(int const tag_result) const override { send_result(r, tag_result); }

private:

	#ifndef NO_HNC_Boost_Serialization

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, unsigned int const /*version*/)
	{
		ar & boost::serialization::base_object<hnc::mpi::functor>(*this);
		ar & r;
	}
	
	#endif
};

#ifndef NO_HNC_Boost_Serialization
BOOST_CLASS_EXPORT(remote_compute_int)
#endif


// Compute factorial n
// You need:
//   - have result_t type
//   - override the operator()
//   - overload "result_t move_result()" to send your result with std::move
//   - default constructor (for Boost Serialization)
class remote_compute_factorial : public hnc::mpi::functor
{
public:

	// Result type
	using result_t = int;

private:

	// !n
	unsigned int n;

	// Result
	result_t r;

public:

	// Constructor take n and initizialize the result
	remote_compute_factorial(unsigned int const n) : n(n), r(1) { }

	// Function
	void operator()() override
	{
		std::cout << "remote_compute_factorial " + hnc::to_string(n) + "\n";
		for (unsigned int i = 2; i <= n; i++)
		{
			r *= i;
		}
	}

	// Return the result with std::move
	result_t move_result() { return std::move(r); }

	// Send the result with send_result(T)
	void get(int const tag_result) const override { send_result(r, tag_result); }

private:

	#ifndef NO_HNC_Boost_Serialization

	friend class boost::serialization::access;

	// Boost Serialization need default constructor
	remote_compute_factorial() : n(0), r(1) { }

	template<class Archive>
	void serialize(Archive & ar, unsigned int const /*version*/)
	{
		ar & boost::serialization::base_object<hnc::mpi::functor>(*this);
		ar & n;
		ar & r;
	}

	#endif
};

#ifndef NO_HNC_Boost_Serialization
BOOST_CLASS_EXPORT(remote_compute_factorial)
#endif


// Compute the sum of the std::vector
// You need:
//   - have result_t type
//   - override the operator()
//   - overload "result_t move_result()" to send your result with std::move
//   - default constructor (for Boost Serialization)
class remote_compute_vector_sum : public hnc::mpi::functor
{
public:

	// Result type
	using result_t = int;

private:

	// vector
	std::vector<int> v;

	// Result
	result_t sum;

public:

	// Constructor take n and initizialize the result
	remote_compute_vector_sum(std::vector<int> const & v) : v(v), sum(0) { }

	// Function
	void operator()() override
	{
		std::cout << "remote_compute_vector_sum " + hnc::to_string(v) + "\n";
		for (int const e : v)
		{
			sum += e;
		}
	}

	// Return the result with std::move
	result_t move_result() { return std::move(sum); }

	// Send the result with send_result(T)
	void get(int const tag_result) const override { send_result(sum, tag_result); }

private:

	#ifndef NO_HNC_Boost_Serialization

	friend class boost::serialization::access;

	// Boost Serialization need default constructor
	remote_compute_vector_sum() : sum(0) { }

	template<class Archive>
	void serialize(Archive & ar, unsigned int const /*version*/)
	{
		ar & boost::serialization::base_object<hnc::mpi::functor>(*this);
		ar & v;
		ar & sum;
	}

	#endif
};

#ifndef NO_HNC_Boost_Serialization
BOOST_CLASS_EXPORT(remote_compute_vector_sum)
#endif


#ifndef NO_HNC_Boost_MPI
int main(int argc, char * argv[])
#else
int main()
#endif
{
	int nb_test = 0;

	#ifndef NO_HNC_Boost_MPI
	hnc_mpi_environment(env);
	#endif

	// Test this on different processors
	for (unsigned int processor = 0; processor < 8; ++processor)
	{
		std::cout << "Computation on processor " << processor << std::endl;
		
		// Display
		{
			remote_compute_display functor;
			hnc::mpi::future<void> f(functor, processor);
		}
		std::cout << std::endl;

		// Return int
		++nb_test;
		{
			remote_compute_int functor;
			hnc::mpi::future<int> f(functor, processor);
			int r = f.get();
			nb_test -= hnc::test::warning(r == 64386, "remote_compute_int must return 64386, not " + hnc::to_string(r) + " \n");
			std::cout << r << std::endl;
		}
		std::cout << std::endl;

		// Factorial

		++nb_test;
		{
			remote_compute_factorial functor(5);
			hnc::mpi::future<int> f(functor, processor);
			int r = f.get();
			nb_test -= hnc::test::warning(r == 120, "Factorial (remote_compute_factorial) 5 is 120, not " + hnc::to_string(r) + " \n");
			std::cout << r << std::endl;
		}
		std::cout << std::endl;

		++nb_test;
		{
			remote_compute_factorial functor(10);
			hnc::mpi::future<int> f(functor, processor);
			int r = f.get();
			nb_test -= hnc::test::warning(r == 3628800, "Factorial (remote_compute_factorial) 10 is 3628800, not " + hnc::to_string(r) + " \n");
			std::cout << r << std::endl;
		}
		std::cout << std::endl;

		// Vector sum

		++nb_test;
		{
			remote_compute_vector_sum functor({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
			hnc::mpi::future<int> f(functor, processor);
			int r = f.get();
			nb_test -= hnc::test::warning(r == 55, "Sum (remote_compute_vector_sum) of {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} is 55, not " + hnc::to_string(r) + " \n");
			std::cout << r << std::endl;
		}
		std::cout << std::endl;

		++nb_test;
		{
			remote_compute_vector_sum functor({21, 11, 5, 3, 1, 1});
			hnc::mpi::future<int> f(functor, processor);
			int r = f.get();
			nb_test -= hnc::test::warning(r == 42, "Sum (remote_compute_vector_sum) of {21, 11, 5, 3, 1, 1} is 42, not " + hnc::to_string(r) + " \n");
			std::cout << r << std::endl;
		}
		std::cout << std::endl;
	}

	// Shuffle
	nb_test += 5;
	{
		// Functor
		remote_compute_display functor_display;
		remote_compute_int functor_int;
		remote_compute_factorial functor_factorial_5(5);
		remote_compute_factorial functor_factorial_10(10);
		remote_compute_vector_sum functor_sum_55({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
		remote_compute_vector_sum functor_sum_42({21, 11, 5, 3, 1, 1});
		// Futures
		hnc::mpi::future<void> f0(functor_display, 1);
		hnc::mpi::future<int> f1(functor_int, 1);
		hnc::mpi::future<int> f2(functor_factorial_5, 1);
		hnc::mpi::future<int> f3(functor_factorial_10, 1);
		hnc::mpi::future<int> f4(functor_sum_55, 1);
		hnc::mpi::future<int> f5(functor_sum_42, 1);
		// Get
		int r5 = f5.get();
		int r4 = f4.get();
		int r3 = f3.get();
		int r2 = f2.get();
		int r1 = f1.get();
		// Tests & displays
		nb_test -= hnc::test::warning(r1 == 64386, "remote_compute_int must return 64386, not " + hnc::to_string(r1) + " \n");
		nb_test -= hnc::test::warning(r2 == 120, "Factorial (remote_compute_factorial) 5 is 120, not " + hnc::to_string(r2) + " \n");
		nb_test -= hnc::test::warning(r3 == 3628800, "Factorial (remote_compute_factorial) 10 is 3628800, not " + hnc::to_string(r3) + " \n");
		nb_test -= hnc::test::warning(r4 == 55, "Sum (remote_compute_vector_sum) of {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} is 55, not " + hnc::to_string(r4) + " \n");
		nb_test -= hnc::test::warning(r5 == 42, "Sum (remote_compute_vector_sum) of {21, 11, 5, 3, 1, 1} is 42, not " + hnc::to_string(r5) + " \n");
		std::cout << r1 << std::endl;
		std::cout << r2 << std::endl;
		std::cout << r3 << std::endl;
		std::cout << r4 << std::endl;
		std::cout << r5 << std::endl;
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::mpi::future: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
