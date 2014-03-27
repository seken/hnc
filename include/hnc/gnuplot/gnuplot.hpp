// Copyright © 2012-2014 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_GNUPLOT_GNUPLOT_HPP
#define HNC_GNUPLOT_GNUPLOT_HPP

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "output_terminal.hpp"
#include "x_range.hpp"
#include "x_tics.hpp"
#include "style.hpp"
#include "plot.hpp"
#include "../to_string.hpp"
#include "../hnc.hpp"


namespace hnc
{
	namespace gnuplot
	{
		/**
		 * @brief Interface for Gnuplot class
		 *
		 * @code
		   #include <hnc/gnuplot.hpp>
		   @endcode
		 * 
		 * Provides some functions to get and set script and data
		 *
		 * @b From @b Wikipedia http://en.wikipedia.org/wiki/Gnuplot @n
		 * "gnuplot is a command-line program that can generate two- and three-dimensional plots of functions, data, and data fits. It is frequently used for publication-quality graphics as well as education. The program runs on all major computers and operating systems (GNU/Linux, Unix, Microsoft Windows, Mac OS X, and others). It is a program with a fairly long history, dating back to 1986. Despite its name, this software is not distributed under the GNU General Public License (GPL), opting for its own more restrictive open source license instead."
		 *
		 * You can get the script and the data for the script. @n
		 * After write (output_filename is a param given to the constructor):
		 * - script in the output_filename.gnuplot file
		 * - data in the output_filename.data file
		 *
		 * @code
		   // hnc::gnuplot::gnuplot_daughter_class gp(...);
		   
		   // Set titles and data and ...
		  
		   // Write in files
		   gp.write_script_in_file();
		   gp.write_data_in_file();
		  
		   // Script
		   std::cout << "# Script filename = " << gp.script_filename() << std::endl;
		   std::cout << gp.script() << std::endl;
		  
		   // Data
		   for (std::pair<std::string, std::string> const & data : gp.data())
		   {
		   	std::string const & data_filename = data.first;
		   	std::string const & data_value = data.second;
		   	std::cout << "# Data filename = " << data_filename << std::endl;
		   	std::cout << data_value << std::endl;
		   }
		   
		   // Plot (run gnuplot) (#include <hnc/system.hpp>)
		   hnc::system("gnuplot", gp.script_filename());
		   @endcode
		 *
		 * You can run in a terminal:
		 * @code
		   $ gnuplot output_filename.gnuplot
		   @endcode
		 */
		class gnuplot
		{
		protected:

			/// Output filename asked by user
			std::string m_output_filename;

			/// Gnuplot script filename
			std::string m_scrip_filename;

			// Script
			
			/// Comments
			std::string m_comments = "# Gnuplot script generated by hnc " + hnc::version() + " \"" + hnc::codename() + "\"" "\n";
			
			/// Terminal output
			std::string m_terminal_output;

			// Data plot

			/// Title
			std::string m_title = "set title 'Title'\n";

			/// xlabel
			std::string m_x_label = "set xlabel 'x label'\n";

			/// ylabel
			std::string m_y_label = "set ylabel 'y label'\n";

		public:

			/// x_range
			hnc::gnuplot::x_range x_range;

			/// y_range
			hnc::gnuplot::y_range y_range;

			/// x_tics
			hnc::gnuplot::x_tics x_tics;

			/// y_tics
			hnc::gnuplot::y_tics y_tics;

		protected:

			/// style
			std::vector<hnc::gnuplot::style> m_style;

			/// plots
			std::vector<hnc::gnuplot::plot> m_plots;

			// Data

			/// Comments
			std::string m_data_comments = "# Gnuplot data generated by hnc " + hnc::version() + " \"" + hnc::codename() + "\"" "\n";
			
		public:

			/// @brief Constructor
			/// @param[in] terminal_output Terminal output hnc::gnuplot::output_terminal_pdf, hnc::gnuplot::output_terminal_svg, hnc::gnuplot::output_terminal_png
			template <class terminal_output_t>
			gnuplot(terminal_output_t const & terminal_output)
			{
				set_terminal_output(terminal_output);
			}

			/// @brief Destructor
			virtual ~gnuplot() = 0;

			/// @brief Set the terminal output
			/// @param[in] terminal_output Terminal output hnc::gnuplot::output_terminal_pdf, hnc::gnuplot::output_terminal_svg, hnc::gnuplot::output_terminal_png
			template <class terminal_output_t>
			void set_terminal_output(terminal_output_t const & terminal_output)
			{
				m_output_filename = terminal_output.output_filename();
				m_scrip_filename = m_output_filename + ".gnuplot";
				m_terminal_output = hnc::to_string(terminal_output);
			}

			// Script & data in file

			/// @brief Write the script in the script_filename() file
			/// @return true if the file has been writen, false otherwise
			bool write_script_in_file() /*const*/
			{
				std::ofstream f(script_filename());

				if (f.good() == false) { return false; }

				f << script();
				
				return true;
			}

			/// @brief Write all data in the data_filename() file
			/// @return true if the file has been writen, false otherwise
			bool write_data_in_file() /*const*/
			{
				bool r = true;

				for (std::pair<std::string, std::string> const & data : this->data())
				{
					std::string const & data_filename = data.first;
					std::string const & data_value = data.second;
					
					// Write file
					std::ofstream f(data_filename);
					
					if (f.good() == false) { r = false; }

					f << data_value;
				}

				return r;
			}

			// Script & data

			/// @brief Return the script
			/// @return the script
			virtual std::string script() /*const*/
			{
				std::string script;
				// Comments
				if (m_comments != "")        { script += m_comments + "\n"; }
				// Outpout
				if (m_terminal_output != "") { script += m_terminal_output + "\n"; }
				// Control
				
				// Data
				script += m_title;
				script += "\n";
				script += m_x_label;
				script += m_y_label;
				script += "\n";
				script += hnc::to_string(x_range);
				script += hnc::to_string(y_range);
				script += "\n";
				script += hnc::to_string(x_tics);
				script += hnc::to_string(y_tics);
				script += "\n";
				for (auto const & style : m_style) { script += hnc::to_string(style); }
				script += "\n";
				// Plot
				std::vector<hnc::gnuplot::plot> plots = gnuplot_plots();
				if (plots.size() != 0) { script += "plot "; }
				for (auto const & plot : plots)
				{
					if (&plot != &plots.front()) { script += "     "; }
					script += hnc::to_string(plot);
					if (&plot != &plots.back()) { script += ", \\\n"; }
				}
				// Return
				script += "\n";
				return script;
			}

			/**
			 * @brief Return the data
			 * 
			 * The data is a std::vector of two std::string:
			 * - the first is the filename for data
			 * - the second is the data (for this filename)
			 * 
			 * @return the data
			 */
			virtual std::vector<std::pair<std::string, std::string>> data() /*const*/
			{
				// For the return
				std::vector<std::pair<std::string, std::string>> data;
				
				// For all plot
				for (auto const & plot : gnuplot_plots())
				{
					// Get data
					std::string tmp;
					if (m_data_comments != "") { tmp += m_data_comments + "\n"; }
					tmp += plot.data();
					// Add data
					data.push_back(std::make_pair(plot.data_filename(), tmp));
				}
				
				// Return
				return data;
			}

			/// @brief Return the minimum data value
			/// @return the minimum data value
			virtual double min_data_value() const = 0;

			/// @brief Return the maximum data value
			/// @return the maximum data value
			virtual double max_data_value() const = 0;

			// Filename

			/// @brief Return the output (picture) filename
			/// @return the output (picture) filename
			std::string const & output_filename() const { return m_output_filename; }

			/// @brief Return the Gnuplot script filename
			/// @return the Gnuplot script filename
			std::string const & script_filename() const { return m_scrip_filename; }

			/**
			 * @brief Return the data filenames
			 * 
			 * The data is can be in several files
			 * 
			 * @return the data filenames
			 */
			std::vector<std::string> data_filename() /*const*/
			{
				// For the return
				std::vector<std::string> data_filename;
				// For all plot
				for (auto const & plot : gnuplot_plots())
				{
					data_filename.push_back(plot.data_filename());
				}
				// Return
				return data_filename;
			}

			// Comments
			
			/// @brief Return the comments
			/// @return the comments
			std::string const & comments() const { return m_comments; }

			/// @brief Add comments
			/// @param[in] comment The comments to add without '#' and without the final '\n'
			void add_comment(std::string const & comment) { m_comments += "#" + comment + "\n"; }

			/// @brief Replace the comments
			/// @param[in] comments The comments
			void set_comments(std::string const & comments) { m_comments = comments; }

			// Title

			/// @brief Return the title
			/// @return the title
			std::string const & title() const { return m_title; }

			/// @brief Set the title
			/// @param[in] title The title
			void set_title(std::string const & title) { m_title = "set title '" + title + "'\n"; }

			// x_label y_label

			/// @brief Return the x_label
			/// @return the x_label
			std::string const & x_label() const { return m_x_label; }

			/// @brief Set the x_label
			/// @param[in] x_label The x_label
			void set_x_label(std::string const & x_label) { m_x_label = "set xlabel '" + x_label + "'\n"; }

			/// @brief Return the y_label
			/// @return the y_label
			std::string const & y_label() const { return m_y_label; }

			/// @brief Set the y_label
			/// @param[in] y_label The y_label
			void set_y_label(std::string const & y_label) { m_y_label = "set ylabel '" + y_label + "'\n"; }

			// Data comments

			/// @brief Return the data comments
			/// @return the data comments
			std::string const & data_comments() const { return m_data_comments; }

			/// @brief Add data comments
			/// @param[in] data_comment The data comments to add without '#' and without the final '\n'
			void add_data_comment(std::string const & data_comment) { m_data_comments += "#" + data_comment + "\n"; }

			/// @brief Replace the data comments
			/// @param[in] data_comments The data comments
			void set_data_comments(std::string const & data_comments) { m_data_comments = data_comments; }

		protected:

			/**
			 * @brief Return the plot
			 *
			 * When we access the plot, daughter class can overrite this getter to replace plot by the good one @n
			 * Mother class access to m_plots for write only by this method
			 *
			 * @return the plot
			 */
			virtual std::vector<hnc::gnuplot::plot> & gnuplot_plots() = 0;
		};
		
		inline gnuplot::~gnuplot() { }

		inline std::vector<hnc::gnuplot::plot> & gnuplot::gnuplot_plots() { return m_plots; }
	}
}

#endif
