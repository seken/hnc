// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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


#ifndef HNC_TEXT_HPP
#define HNC_TEXT_HPP

#include <string>
#include <vector>
#include <sstream>


namespace hnc
{
	/**
	 * @brief Text manipulation
	 *
	 * @code
	 * #include <hnc/text.hpp>
	 * @endcode
	 */
	namespace text
	{
		/**
		 * @brief String to vector of lines
		 * 
		 * @param[in] text  Text in a a std::string
		 * @param[in] delim Line separator ('\\n' by default)
		 * 
		 * @return the vector of lines
		 */
		std::vector<std::string> string_to_vector_of_lines(std::string const & text, char const delim = '\n')
		{
			std::vector<std::string> lines;
			
			// Put text in a stream
			std::istringstream is(text);
			
			// Get each line
			std::string line;
			while (std::getline(is, line, delim))
			{
				// Save line
				lines.push_back(line);
			}
			
			return lines;
		}
	}
}

#endif
