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


#include <iostream>
#include <string>
#include <vector>

#include <hnc/scheduler/iteration.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int func_value = 0;

void func0(int const & start, int const & end)
{
	for (int i = start; i < end; ++i)
	{
		++func_value;
	}
}

void func1(int const & start, int const & end)
{
	for (int i = start; i < end; ++i)
	{
		++func_value;
	}
}


class fonctor
{
public:
	fonctor(std::vector<std::vector<int>> & tab2D) : r_tab2D(tab2D) { }

	void operator()(std::size_t const & start, std::size_t const & end)
	{
		for (std::size_t i = start; i < end; ++i)
		{
			for (std::size_t j = 0; j < r_tab2D.size(); ++j)
			{
				r_tab2D[i][j] += int(i * j);
			}
		}
	}
	
private:
	std::vector<std::vector<int>> & r_tab2D;
};


int main()
{
	int nb_test = 0;

	std::vector<std::vector<int>> tab2D_ref(200, std::vector<int>(200, 0)); // Dimension i must equal to dimension j !
	for (std::size_t i = 0; i < tab2D_ref.size(); ++i)
	{
		for (std::size_t j = 0; j < tab2D_ref.size(); ++j)
		{
			tab2D_ref[i].resize(tab2D_ref.size());
			tab2D_ref[i][j] += int(i * j);
		}
	}

	// Testing tab2D
	{
		std::vector<std::vector<int>> tab2D(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

		// Declare some versions
		auto version0 = [&](std::size_t const & start, std::size_t const & end) -> void
		{
			for (std::size_t i = start; i < end; ++i)
			{
				for (std::size_t j = 0; j < tab2D_ref.size(); ++j)
				{
					tab2D[i][j] += int(i * j);
				}
			}
		};
		auto version1 = version0;
		auto version2 = [&](std::size_t const & start, std::size_t const & end) -> void
		{
			for (std::size_t j = 0; j < tab2D_ref.size(); ++j)
			{
				for (std::size_t i = start; i < end; ++i)
				{
					tab2D[i][j] += int(i * j);
				}
			}
		};
			
		++nb_test;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions;
			versions.push_back(version0);
			versions.push_back(version1);
			versions.push_back(version2);

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(8), std::size_t(16));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and push_back, no final i needed)\n");
		}

		++nb_test;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions({version0, version1, version2});

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(16), std::size_t(8));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and { }, no final i needed)\n");
		}

		++nb_test;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			// Compute
			hnc::scheduler::iteration
			(
				std::size_t(0), std::size_t(tab2D.size()),
				{version0, version1, version2}
			);

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (inline vector of std::function { }, no final i needed)\n");
		}
	}

	// Test with fonctor (with reference)
	{
		std::vector<std::vector<int>> tab2D(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

		++nb_test;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions;
			versions.push_back(fonctor(tab2D));
			versions.push_back(fonctor(tab2D));

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(8), std::size_t(16));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (fonctor) (vector of std::function and push_back, no final i needed)\n");
		}

		++nb_test;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions({fonctor(tab2D), fonctor(tab2D)});

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(16), std::size_t(8));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (fonctor) (vector of std::function and { }, no final i needed)\n");
		}

		++nb_test;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			// Compute
			hnc::scheduler::iteration
			(
				std::size_t(0), std::size_t(tab2D.size()),
				{fonctor(tab2D), fonctor(tab2D), fonctor(tab2D)}
			);

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (fonctor) (inline vector of std::function { }, no final i needed)\n");
		}
	}

	// Testing tab2D and i and j
	{
		std::vector<std::vector<int>> tab2D(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));
		std::size_t i;
		std::size_t j;

		// Declare some versions
		auto version0 = [&](std::size_t const & start, std::size_t const & end) -> void
		{
			for (i = start; i < end; ++i)
			{
				for (j = 0; j < tab2D_ref.size(); ++j)
				{
					tab2D[i][j] += int(i * j);
				}
			}
		};
		auto version1 = version0;
		auto version2 = [&](std::size_t const & start, std::size_t const & end) -> void
		{
			for (j = 0; j < tab2D_ref.size(); ++j)
			{
				for (i = start; i < end; ++i)
				{
					tab2D[i][j] += int(i * j);
				}
			}
		};

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions;
			versions.push_back(version0);
			versions.push_back(version1);
			versions.push_back(version2);

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(1), std::size_t(1));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and push_back, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size(), "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() (vector of std::function and push_back, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size(), "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() (vector of std::function and push_back, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions({version0, version1, version2});

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(1), std::size_t(0));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size(), "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() (vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size(), "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() (vector of std::function and { }, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			// Compute
			hnc::scheduler::iteration
			(
				std::size_t(0), std::size_t(tab2D.size()),
				{version0, version1, version1},
				std::size_t(0), std::size_t(1)
			);

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (inline vector of std::function { }, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size(), "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() (inline vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size(), "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() (inline vector of std::function and { }, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions;
			versions.push_back(version0);
			versions.push_back(version1);
			versions.push_back(version2);

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(199), std::size_t(199));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and push_back, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size(), "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() (199) (vector of std::function and push_back, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size(), "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() (199) (vector of std::function and push_back, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions({version0, version1, version2});

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(200), std::size_t(200));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size(), "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() (200) (vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size(), "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() (200) (vector of std::function and { }, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			// Compute
			hnc::scheduler::iteration
			(
				std::size_t(0), std::size_t(tab2D.size()),
				{version0, version1, version1},
				std::size_t(201), std::size_t(201)
			);

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (inline vector of std::function { }, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size(), "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() (201) (inline vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size(), "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() (201) (inline vector of std::function and { }, i and j needed)\n");
		}
	}

	// Testing tab2D and i and j with step use
	{
		tab2D_ref = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));
		for (std::size_t i = 0; i < tab2D_ref.size(); i += 3)
		{
			for (std::size_t j = 0; j < tab2D_ref.size(); j += 7)
			{
				tab2D_ref[i].resize(tab2D_ref.size());
				tab2D_ref[i][j] += int(i * j);
			}
		}
		
		std::vector<std::vector<int>> tab2D(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));
		std::size_t i;
		std::size_t j;

		// Declare some versions
		auto version0 = [&](std::size_t const & start, std::size_t const & end) -> void
		{
			for (i = start; i < end; i += 3)
			{
				for (j = 0; j < tab2D_ref.size(); j += 7)
				{
					tab2D[i][j] += int(i * j);
				}
			}
		};
		auto version1 = version0;
		auto version2 = [&](std::size_t const & start, std::size_t const & end) -> void
		{
			for (j = 0; j < tab2D_ref.size(); j += 7)
			{
				for (i = start; i < end; i += 3)
				{
					tab2D[i][j] += int(i * j);
				}
			}
		};

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions;
			versions.push_back(version0);
			versions.push_back(version1);
			versions.push_back(version2);

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(1), std::size_t(1), std::size_t(3));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and push_back, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size() + 1, "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() + 1 (magic value) (vector of std::function and push_back, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size() + 3, "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() + 3 (magic value) (vector of std::function and push_back, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			std::vector<std::function<void(std::size_t const &, std::size_t const &)>> versions({version0, version1, version2});

			// Compute
			hnc::scheduler::iteration(std::size_t(0), std::size_t(tab2D.size()), versions, std::size_t(3), std::size_t(7), std::size_t(3));

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size() + 1, "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() + 1 (magic value) (vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size() + 3, "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() + 3 (magic value) (vector of std::function and { }, i and j needed)\n");
		}

		nb_test += 3;
		{
			tab2D = std::vector<std::vector<int>>(tab2D_ref.size(), std::vector<int>(tab2D_ref.size(), 0));

			// Compute
			hnc::scheduler::iteration
			(
				std::size_t(0), std::size_t(tab2D.size()),
				{version0, version1, version1},
				std::size_t(21), std::size_t(42), std::size_t(3)
			);

			nb_test -= hnc::test::warning(tab2D == tab2D_ref, "tab2D not equal tab2D_ref (inline vector of std::function { }, i and j needed)\n");
			nb_test -= hnc::test::warning(i == tab2D_ref.size() + 1, "i = " + hnc::to_string(i) + " not equal tab2D_ref.size() + 1 (magic value) (inline vector of std::function and { }, i and j needed)\n");
			nb_test -= hnc::test::warning(j == tab2D_ref.size() + 3, "j = " + hnc::to_string(j) + " not equal tab2D_ref.size() + 3 (magic value) (inline vector of std::function and { }, i and j needed)\n");
		}
	}

	// Test with function
	++nb_test;
	{
		// Compute
		hnc::scheduler::iteration
		(
			0, 420,
			std::vector<std::function<void(int const &, int const &)>>({func0, func1})
		);

		nb_test -= hnc::test::warning(func_value == 420, "func_value = " + hnc::to_string(func_value) + " != 420\n");
	}

	hnc::test::warning(nb_test == 0, "hnc::scheduler::iteration: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
