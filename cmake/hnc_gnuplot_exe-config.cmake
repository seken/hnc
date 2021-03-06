# Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# Find Gnuplot executable

# HNC_GNUPLOT_EXE - Gnuplot executable (false if not found)


find_program(HNC_GNUPLOT_EXE NAMES gnuplot)

if (HNC_GNUPLOT_EXE)
	
	message(STATUS "Gnuplot executable found =) ${HNC_GNUPLOT_EXE}")
	
else()
	
	message(STATUS "Gnuplot executable not found :(")
	
endif()
