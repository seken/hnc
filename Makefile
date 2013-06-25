# Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

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


all:
	@echo ""
	@echo "Usage:"
	@echo ""
	@echo "  mkdir -p build && cd build && cmake .. # To compile hnc library (first step)"
	@echo ""
	@echo "  make clean                             # To clean (remove all no-source files)"
	@echo ""

clean:
	rm -rf build/* doc/html/* doc/latex/*
	rm -rf *~
	cd include/hnc/ && rm -rf *~ algo/*~ gnuplot/*~ iterator/*~ math/*~ mpi/*~ openmp/*~ ssl/*~ ssl/cipher/*~ ssl/hash/*~ ssl/public_key/*~ scheduler/*~
	rm -rf tests/*~ tests_human/*~ tests_visual/*~
