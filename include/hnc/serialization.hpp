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


#ifndef HNC_SERIALIZATION_HPP
#define HNC_SERIALIZATION_HPP

#include "boost_serialization_std.hpp"
#include "unused.hpp"


namespace hnc
{
	/**
	 * @brief End of hnc::serialize function (do nothing)
	 * 
	 * @code
	   	#include <hnc/serialization.hpp>
	   @endcode
	 * 
	 * @param[in] archive Archive
	 * @param[in] version Version
	 */
	template <class archive_t>
	void serialize(archive_t & archive, unsigned int const version)
	{
		hnc_unused(archive);
		hnc_unused(version);
	}
	
	/**
	 * @brief hnc::serialize const function
	 * 
	 * @code
	   	#include <hnc/serialization.hpp>
	   @endcode
	 * 
	 * @param[in,out] archive Archive
	 * @param[in]     version Version
	 * @param[in]     t       A T
	 * @param[in]     args    Variadic template arguments list
	 */
	template <class archive_t, class T, class... args_t>
	void serialize(archive_t & archive, unsigned int const version, T const & t, args_t const & ... args)
	{
		archive & t;
		hnc::serialize(archive, version, args...);
	}
	
	/**
	 * @brief hnc::serialize function
	 * 
	 * @code
	   	#include <hnc/serialization.hpp>
	   @endcode
	 * 
	 * @param[in,out] archive Archive
	 * @param[in]     version Version
	 * @param[out]    t       A T
	 * @param[out]    args    Variadic template arguments list
	 */
	template <class archive_t, class T, class... args_t>
	void serialize(archive_t & archive, unsigned int const version, T & t, args_t & ... args)
	{
		archive & t;
		hnc::serialize(archive, version, args...);
	}
}

/**
 * @brief Generate .serialize() methods
 *
 * This macro generate the .serialize() const and .serialize() methods for Boost.Serialization
 *
 * @code
   	#include <hnc/serialization.hpp>
   @endcode
 *
 * @code
   class A
   {
   private:
   
   	std::string a;
   	std::string b;
   	std::string c;
   
   public:
   
   	hnc_generate_serialize_method(a, b, c)
   };
   @endcode
 */
#define hnc_generate_serialize_method(...) \
	\
	template <class archive_t> \
	void serialize(archive_t & archive, unsigned int const version = 0) const \
	{ \
		hnc::serialize(archive, version, __VA_ARGS__); \
	} \
	\
	template <class archive_t> \
	void serialize(archive_t & archive, unsigned int const version = 0) \
	{ \
		hnc::serialize(archive, version, __VA_ARGS__); \
	} \


#endif
