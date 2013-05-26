// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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


/**
 * @file
 * @brief Provides Boost Serialization for std (std::vector, std::list, ...)
 */

#ifndef HNC_BOOST_SERIALIZATION_STD_HPP
#define HNC_BOOST_SERIALIZATION_STD_HPP


#ifndef NO_HNC_Boost_Serialization

	#include <boost/serialization/export.hpp>
	
	#include <boost/serialization/array.hpp>
	#include <boost/serialization/bitset.hpp>
	#include <boost/serialization/complex.hpp>
	#include <boost/serialization/deque.hpp>
	#include <boost/serialization/list.hpp>
	#include <boost/serialization/map.hpp>
	#include <boost/serialization/factory.hpp>
	#include <boost/serialization/set.hpp>
	#include <boost/serialization/string.hpp>
	#include <boost/serialization/utility.hpp>
	#include <boost/serialization/valarray.hpp>
	#define STD std
	#include <boost/serialization/vector.hpp>
	#undef STD

#endif

#endif
