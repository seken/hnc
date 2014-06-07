// Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

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
#include <fstream>

#include <hnc/serialization.hpp>
#include <hnc/filesystem.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


class human_t
{
private:
	
	std::vector<std::string> m_first_names;
	
	std::string m_name;
	
	unsigned int m_age;
	
public:
	
	human_t() = default;
	
	human_t
	(
		std::vector<std::string> const & first_names,
		std::string const & name,
		unsigned int const age
	) :
		m_first_names(first_names),
		m_name(name),
		m_age(age)
	{ }
	
	std::vector<std::string> const & first_names() const { return m_first_names; }
	
	std::string const & name() const { return m_name; }
	
	unsigned int age() const { return m_age; }
	
	hnc_generate_serialize_method(m_first_names, m_name, m_age)
};

std::ostream & operator<<(std::ostream & o, human_t const & human)
{
	if (human.name().empty() == false)
	{
		for (auto const & first_name : human.first_names())
		{
			o << first_name;
			if (&first_name != &human.first_names().back()) { o << ","; }
			o << " ";
		}
		
		o << human.name() << " ";
		
		o << "(age = " << human.age() << ")";
	}
	else
	{
		o << "NULL";
	}
	
	return o;
}

bool operator==(human_t const & a, human_t const & b)
{
	return
	(
		a.first_names() == b.first_names(),
		a.name() == b.name(),
		a.age() == b.age()
	);
}


class test_serialization_const_t
{
private:
	
	std::string m_member;
	
public:
	
	test_serialization_const_t(std::string const & member = "member") : m_member(member) { }
	
	hnc_generate_serialize_method(m_member)
	
	void before_save_serialization() const
	{
		std::cout << "- before_save_serialization const" << std::endl;
	}
	
	void after_save_serialization() const
	{
		std::cout << "- after_save_serialization const" << std::endl;
	}
	
	void before_load_serialization() const
	{
		std::cout << "- before_load_serialization const" << std::endl;
	}
	
	void after_load_serialization() const
	{
		std::cout << "- after_load_serialization const" << std::endl;
	}
};


class test_serialization_no_const_t
{
private:
	
	std::string m_member;
	
public:
	
	test_serialization_no_const_t(std::string const & member = "member") : m_member(member) { }
	
	hnc_generate_serialize_method(m_member)
	
	void before_save_serialization()
	{
		std::cout << "- before_save_serialization" << std::endl;
	}
	
	void after_save_serialization()
	{
		std::cout << "- after_save_serialization" << std::endl;
	}
	
	void before_load_serialization()
	{
		std::cout << "- before_load_serialization" << std::endl;
	}
	
	void after_load_serialization()
	{
		std::cout << "- after_load_serialization" << std::endl;
	}
};


class test_serialization_t
{
private:
	
	std::string m_member;
	
public:
	
	test_serialization_t(std::string const & member = "member") : m_member(member) { }
	
	hnc_generate_serialize_method(m_member)
	
	void before_save_serialization() const
	{
		std::cout << "- before_save_serialization const" << std::endl;
	}
	
	void after_save_serialization() const
	{
		std::cout << "- after_save_serialization const" << std::endl;
	}
	
	void before_load_serialization() const
	{
		std::cout << "- before_load_serialization const" << std::endl;
	}
	
	void after_load_serialization() const
	{
		std::cout << "- after_load_serialization const" << std::endl;
	}
	
	void before_save_serialization()
	{
		std::cout << "- before_save_serialization" << std::endl;
	}
	
	void after_save_serialization()
	{
		std::cout << "- after_save_serialization" << std::endl;
	}
	
	void before_load_serialization()
	{
		std::cout << "- before_load_serialization" << std::endl;
	}
	
	void after_load_serialization()
	{
		std::cout << "- after_load_serialization" << std::endl;
	}
};


int main()
{
	int nb_test = 0;
	
	#ifdef hnc_no_boost_serialization
	
		std::cout << "Just test hnc/serialization.hpp include" << std::endl;
		
	#else
	
		std::cout << std::boolalpha;
		
		std::cout << "std::string:\n";
		std::cout << "- serializable              = " << hnc::have_serialize_method<std::string>() << std::endl;
		std::cout << "- before_save_serialization const = " << hnc::have_before_save_serialization_method_const<std::string>() << std::endl;
		std::cout << "- before_save_serialization       = " << hnc::have_before_save_serialization_method<std::string>() << std::endl;
		std::cout << "- after_save_serialization const  = " << hnc::have_after_save_serialization_method_const<std::string>() << std::endl;
		std::cout << "- after_save_serialization        = " << hnc::have_after_save_serialization_method<std::string>() << std::endl;
		std::cout << "- before_load_serialization const = " << hnc::have_before_load_serialization_method_const<std::string>() << std::endl;
		std::cout << "- before_load_serialization       = " << hnc::have_before_load_serialization_method<std::string>() << std::endl;
		std::cout << "- after_load_serialization const  = " << hnc::have_after_load_serialization_method_const<std::string>() << std::endl;
		std::cout << "- after_load_serialization        = " << hnc::have_after_load_serialization_method<std::string>() << std::endl;
		std::cout << std::endl;
		
		std::cout << "human_t:\n";
		std::cout << "- serializable              = " << hnc::have_serialize_method<human_t>() << std::endl;
		std::cout << "- before_save_serialization const = " << hnc::have_before_save_serialization_method_const<human_t>() << std::endl;
		std::cout << "- before_save_serialization       = " << hnc::have_before_save_serialization_method<human_t>() << std::endl;
		std::cout << "- after_save_serialization const  = " << hnc::have_after_save_serialization_method_const<human_t>() << std::endl;
		std::cout << "- after_save_serialization        = " << hnc::have_after_save_serialization_method<human_t>() << std::endl;
		std::cout << "- before_load_serialization const = " << hnc::have_before_load_serialization_method_const<human_t>() << std::endl;
		std::cout << "- before_load_serialization       = " << hnc::have_before_load_serialization_method<human_t>() << std::endl;
		std::cout << "- after_load_serialization const  = " << hnc::have_after_load_serialization_method_const<human_t>() << std::endl;
		std::cout << "- after_load_serialization        = " << hnc::have_after_load_serialization_method<human_t>() << std::endl;
		std::cout << std::endl;
		
		std::cout << "test_serialization_const_t:\n";
		std::cout << "- serializable              = " << hnc::have_serialize_method<test_serialization_const_t>() << std::endl;
		std::cout << "- before_save_serialization const = " << hnc::have_before_save_serialization_method_const<test_serialization_const_t>() << std::endl;
		std::cout << "- before_save_serialization       = " << hnc::have_before_save_serialization_method<test_serialization_const_t>() << std::endl;
		std::cout << "- after_save_serialization const  = " << hnc::have_after_save_serialization_method_const<test_serialization_const_t>() << std::endl;
		std::cout << "- after_save_serialization        = " << hnc::have_after_save_serialization_method<test_serialization_const_t>() << std::endl;
		std::cout << "- before_load_serialization const = " << hnc::have_before_load_serialization_method_const<test_serialization_const_t>() << std::endl;
		std::cout << "- before_load_serialization       = " << hnc::have_before_load_serialization_method<test_serialization_const_t>() << std::endl;
		std::cout << "- after_load_serialization const  = " << hnc::have_after_load_serialization_method_const<test_serialization_const_t>() << std::endl;
		std::cout << "- after_load_serialization        = " << hnc::have_after_load_serialization_method<test_serialization_const_t>() << std::endl;
		std::cout << std::endl;
		
		std::cout << "test_serialization_no_const_t:\n";
		std::cout << "- serializable              = " << hnc::have_serialize_method<test_serialization_no_const_t>() << std::endl;
		std::cout << "- before_save_serialization const = " << hnc::have_before_save_serialization_method_const<test_serialization_no_const_t>() << std::endl;
		std::cout << "- before_save_serialization       = " << hnc::have_before_save_serialization_method<test_serialization_no_const_t>() << std::endl;
		std::cout << "- after_save_serialization const  = " << hnc::have_after_save_serialization_method_const<test_serialization_no_const_t>() << std::endl;
		std::cout << "- after_save_serialization        = " << hnc::have_after_save_serialization_method<test_serialization_no_const_t>() << std::endl;
		std::cout << "- before_load_serialization const = " << hnc::have_before_load_serialization_method_const<test_serialization_no_const_t>() << std::endl;
		std::cout << "- before_load_serialization       = " << hnc::have_before_load_serialization_method<test_serialization_no_const_t>() << std::endl;
		std::cout << "- after_load_serialization const  = " << hnc::have_after_load_serialization_method_const<test_serialization_no_const_t>() << std::endl;
		std::cout << "- after_load_serialization        = " << hnc::have_after_load_serialization_method<test_serialization_no_const_t>() << std::endl;
		std::cout << std::endl;
		
		std::cout << "test_serialization_t:\n";
		std::cout << "- serializable              = " << hnc::have_serialize_method<test_serialization_t>() << std::endl;
		std::cout << "- before_save_serialization const = " << hnc::have_before_save_serialization_method_const<test_serialization_t>() << std::endl;
		std::cout << "- before_save_serialization       = " << hnc::have_before_save_serialization_method<test_serialization_t>() << std::endl;
		std::cout << "- after_save_serialization const  = " << hnc::have_after_save_serialization_method_const<test_serialization_t>() << std::endl;
		std::cout << "- after_save_serialization        = " << hnc::have_after_save_serialization_method<test_serialization_t>() << std::endl;
		std::cout << "- before_load_serialization const = " << hnc::have_before_load_serialization_method_const<test_serialization_t>() << std::endl;
		std::cout << "- before_load_serialization       = " << hnc::have_before_load_serialization_method<test_serialization_t>() << std::endl;
		std::cout << "- after_load_serialization const  = " << hnc::have_after_load_serialization_method_const<test_serialization_t>() << std::endl;
		std::cout << "- after_load_serialization        = " << hnc::have_after_load_serialization_method<test_serialization_t>() << std::endl;
		std::cout << std::endl;
		
		std::cout << "boost::archive::text_oarchive is a save archive = " << hnc::is_save_archive<boost::archive::text_oarchive>() << std::endl;
		std::cout << "boost::archive::text_iarchive is a save archive = " << hnc::is_save_archive<boost::archive::text_iarchive>() << std::endl;
		std::cout << "boost::archive::text_oarchive is a load archive = " << hnc::is_load_archive<boost::archive::text_oarchive>() << std::endl;
		std::cout << "boost::archive::text_iarchive is a load archive = " << hnc::is_load_archive<boost::archive::text_iarchive>() << std::endl;
		std::cout << std::endl;
		
		++nb_test;
		{
			human_t a({ "Saoirse", "Sigourney" }, "Rianne", 42);
			human_t b;
			std::cout << "Before:" << std::endl;
			std::cout << "    " "a = " << a << std::endl;
			std::cout << "    " "b = " << b << std::endl;
			
			auto const filename = hnc::filesystem::tmp_filename();
			
			{
				std::ofstream file(filename);
				boost::archive::text_oarchive oarchive(file);
				oarchive << a;
			}
			
			{
				std::ifstream file(filename);
				boost::archive::text_iarchive iarchive(file);
				iarchive >> b;
			}
			
			std::cout << "After:" << std::endl;
			std::cout << "    " "a = " << a << std::endl;
			std::cout << "    " "b = " << b << std::endl;
			
			nb_test -= hnc::test::warning(a == b, "hnc::serialization: " + hnc::to_string(nb_test) + " test fail!\n");
		}
		std::cout << std::endl;
	
		{
			std::cout << "test_serialization_const_t:\n";
			test_serialization_const_t t;
			
			auto const filename = hnc::filesystem::tmp_filename();
			
			std::cout << "save:\n";
			{
				std::ofstream file(filename);
				boost::archive::text_oarchive oarchive(file);
				oarchive << t;
			}
			
			std::cout << "load:\n";
			{
				std::ifstream file(filename);
				boost::archive::text_iarchive iarchive(file);
				iarchive >> t;
			}
		}
		std::cout << std::endl;
	
		{
			std::cout << "test_serialization_no_const_t:\n";
			test_serialization_no_const_t t;
			
			auto const filename = hnc::filesystem::tmp_filename();
			
			std::cout << "save:\n";
			{
				std::ofstream file(filename);
				boost::archive::text_oarchive oarchive(file);
				oarchive << t;
			}
			
			std::cout << "load:\n";
			{
				std::ifstream file(filename);
				boost::archive::text_iarchive iarchive(file);
				iarchive >> t;
			}
		}
		std::cout << std::endl;
	
		{
			std::cout << "test_serialization_t:\n";
			test_serialization_t t;
			
			auto const filename = hnc::filesystem::tmp_filename();
			
			std::cout << "save:\n";
			{
				std::ofstream file(filename);
				boost::archive::text_oarchive oarchive(file);
				oarchive << t;
			}
			
			std::cout << "load:\n";
			{
				std::ifstream file(filename);
				boost::archive::text_iarchive iarchive(file);
				iarchive >> t;
			}
		}
		std::cout << std::endl;
		
	#endif

	hnc::test::warning(nb_test == 0, "hnc::serialization: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
