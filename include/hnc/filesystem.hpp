// Copyright © 2012 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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


#ifndef HNC_FILESYSTEM_HPP
#define HNC_FILESYSTEM_HPP

#include <string>
#include <algorithm>
#include <cstdio>
#include <fstream>


namespace hnc
{
	/**
	 * @brief Basic manipulation of files and directory
	 *
	 * @code
	 * #include <hnc/filesystem.hpp>
	 * @endcode
	 *
	 * @image html hnc_filesystem.png
	 * @image latex hnc_filesystem.eps
	 *
	 * @note The default directory separator is '/', use hnc::filesystem::directory_separator to change it
	 * 
	 * @note Consider Boost.Filesystem and C++14
	 */
	namespace filesystem
	{
		/**
		 * @brief Directory separator (e.g. '/' by default, '/' on GNU/Linux and all (including Windows), '\' for Windows only)
		 * 
		 * The default directory separator is '/', works on GNU/Linux, Unix and Windows
		 *
		 * http://en.wikipedia.org/wiki/Path_%28computing%29
		 */
		namespace directory_separator
		{
			/// @brief Default (common) directory separator: GNU/Linux, Unix, BSD, Android, MAC OS X, ... and Windows
			char const common = '/';

			/// @brief Directory separator for Windows only
			char const windows = '\\';

			/// @brief Directory separator for Classic Mac OS
			char const classic_mac_os = ':';

			/// @brief Directory separator for TOPS-20, RSX-11, OpenVMS, RISC OS, NonStop Kernel
			char const dot = '.';

			/// @brief Directory separator for Stratus VOS
			char const greater_than = '>';
		}

		/**
		 * @brief Return the filename of a pathname
		 *
		 * @param[in] pathname            Pathname
		 * @param[in] directory_separator Directory separator char (hnc::filesystem::directory_separator::common by default)
		 *
		 * @return the filename of a pathname
		 */
		std::string filename
		(
			std::string const & pathname,
			char const directory_separator = hnc::filesystem::directory_separator::common
		)
		{
			// Get last separator
			auto it = std::find(pathname.rbegin(), pathname.rend(), directory_separator);
			// Separator found
			if (it != pathname.rend())
			{
				return std::string(it.base(), pathname.end());
			}
			// No separator found
			else
			{
				return pathname;
			}
		}

		/**
		 * @brief Return the dirname of a pathname (without the final directory separator)
		 *
		 * @param[in] pathname            Pathname
		 * @param[in] directory_separator Directory separator char (hnc::filesystem::directory_separator::common by default)
		 *
		 * @return the dirname of a pathname (without the final directory separator)
		 */
		std::string dirname
		(
			std::string const & pathname,
			char const directory_separator = hnc::filesystem::directory_separator::common
		)
		{
			// Get last separator
			auto it = std::find(pathname.rbegin(), pathname.rend(), directory_separator);
			// Separator found
			if (it != pathname.rend())
			{
				++it;
				return std::string(pathname.begin(), it.base());
			}
			// No separator found
			else
			{
				return "";
			}
		}

		/**
		 * @brief Return the basename of a pathname
		 *
		 * @param[in] pathname            Pathname
		 * @param[in] directory_separator Directory separator char (hnc::filesystem::directory_separator::common by default)
		 *
		 * @return the basename of a pathname
		 */
		std::string basename
		(
			std::string const & pathname,
			char const directory_separator = hnc::filesystem::directory_separator::common
		)
		{
			// Get filename
			std::string filename = hnc::filesystem::filename(pathname, directory_separator);
			// Get last separator
			auto it = std::find(filename.rbegin(), filename.rend(), '.');
			// Separator found
			if (it != filename.rend())
			{
				++it;
				return std::string(filename.begin(), it.base());
			}
			// No separator found
			else
			{
				return filename;
			}
		}

		/**
		 * @brief Return the extension of a file (without the '.')
		 *
		 * @param[in] pathname            Pathname
		 * @param[in] directory_separator Directory separator char (hnc::filesystem::directory_separator::common by default)
		 *
		 * @return the extension of a file (without the '.')
		 */
		std::string extension
		(
			std::string const & pathname,
			char const directory_separator = hnc::filesystem::directory_separator::common
		)
		{
			// Get filename
			std::string filename = hnc::filesystem::filename(pathname, directory_separator);
			// Get last separator
			auto it = std::find(filename.rbegin(), filename.rend(), '.');
			// Separator found
			if (it != filename.rend())
			{
				return std::string(it.base(), filename.end());
			}
			// No separator found
			else
			{
				return "";
			}
		}

		/**
		 * @brief Return a temporary filename (with tmpnam function from cstdio)
		 *
		 * http://www.cplusplus.com/reference/cstdio/tmpnam/
		 *
		 * @return the temporary filename
		 */
		std::string tmp_filename()
		{
			// Generate filename
			char filename_buffer[L_tmpnam];
			std::string filename = std::tmpnam(filename_buffer);
			// fopen and fclose file (else fstream does not work...)
			FILE * f = std::fopen(filename.c_str(), "w");
			std::fclose(f);
			// Return
			return filename;
		}

		/**
		 * @brief Remove a file (with remove function from cstdio)
		 *
		 * http://www.cplusplus.com/reference/cstdio/tmpnam/
		 * 
		 * @param[in] pathname Pathname
		 */
		void remove(std::string const & pathname)
		{
			std::remove(pathname.c_str());
		}

		/**
		 * @brief Return true if the file exists, false otherwise
		 *
		 * @param[in] pathname Pathname wanted
		 *
		 * @return true if the file exists, false otherwise
		 */
		bool file_exists(std::string const & pathname)
		{
			std::ifstream f(pathname);
			return f;
		}

		/**
		 * @brief Return a available filename based on user's proposition (no safe in multi-thread context)
		 *
		 * @param[in] pathname_wanted Pathname wanted
		 * @param[in] separator       Separator between pathname wanted and number is the function generate a filename
		 * @param[in] directory_separator Directory separator char (hnc::filesystem::directory_separator::common by default)
		 *
		 * @return a available filename
		 */
		std::string filename_without_overwrite
		(
			std::string const & pathname,
			std::string const & separator = "_",
			char const directory_separator = hnc::filesystem::directory_separator::common
		)
		{
			// File does not exist
			if (hnc::filesystem::file_exists(pathname) == false)
			{
				return pathname;
			}
			// File exists
			else
			{
				// To generate new pathname
				std::string const dirname = hnc::filesystem::dirname(pathname);
				std::string const basename = hnc::filesystem::basename(pathname);
				std::string const extension = [&pathname]() -> std::string
				{
					std::string r = hnc::filesystem::extension(pathname);
					if (r != "") { r = "." + r; }
					return r;
				}();
				// Find the next available pathname
				std::string available_pathname = pathname;
				unsigned int i = 0;
				do
				{
					available_pathname = dirname + directory_separator + basename + separator + std::to_string(i) + extension;
					++i;
				}
				while (hnc::filesystem::file_exists(available_pathname) == true);
				// Return
				return available_pathname;
			}
		}
	}
}

#endif
