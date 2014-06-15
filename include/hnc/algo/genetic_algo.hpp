// Copyright © 2013, 2014 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_ALGO_GENETIC_ALGO_HPP
#define HNC_ALGO_GENETIC_ALGO_HPP

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <functional>

#include "../log_level.hpp"
#include "../terminal.hpp"
#include "../ostream_std.hpp"

namespace hnc
{
	namespace algo
	{
		/**
		 * @brief Genetic algorithm namespace
		 * 
		 * @code
		   #include <hnc/algo.hpp>
		   @endcode
		 */
		namespace genetic_algo
		{
			/// Typedef for archipelago
			template <class T>
			using archipelago = std::vector<T>;

			/// Typedef for island
			template <class T>
			using island = std::vector<T>;

			/// @brief Container for a solution and its grade
			/// @note Surchage operator < (compare grade) to use std::sort algorithm
			template <class solution_t, class grade_t>
			class solution_grade
			{
				public:

					/// Solution
					solution_t solution;

					/// Grade
					grade_t grade;

					/// @brief Constructor
					/// @param solution The solution
					/// @param grade The grade
					solution_grade(solution_t const & solution = solution_t(), grade_t const & grade = grade_t()) :
						solution(solution), grade(grade)
					{ }

					/// @brief To sort solutions
					/// @param[in] solution An other solution
					/// @return true if my solution's grade >= solution's grade
					bool operator <(solution_grade const & solution) const
					{
						return (solution.grade < grade);
					}
			};
			
			/// @brief Operator << between a std::ostream and a hnc::algo::genetic_algo::solution_grade<solution_t, grade_t>
			/// @param[in,out] o        Output stream
			/// @param[in]     solution A hnc::algo::genetic_algo::solution_grade<solution_t, grade_t>
			/// @return the output stream
			template <class solution_t, class grade_t>
			std::ostream & operator <<(std::ostream & o, hnc::algo::genetic_algo::solution_grade<solution_t, grade_t> const & solution)
			{
				o << "(" << solution.solution << ", " << solution.grade << ")";
				return o;
			}
			
			/// @brief Return std::chrono::steady_clock::now().time_since_epoch().count() as a unsigned int
			/// @return std::chrono::steady_clock::now().time_since_epoch().count() as a unsigned int
			unsigned int steady_clock_now() { return static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()); }

			/// Log levels
			enum log_level_t {no_log, minimal_log, minimal_plus_log, archipelago_log, island_log, solution_grade_log};

			/**
			 * @brief Genetic algorithm
			 *
			 * @code
			   #include <hnc/algo.hpp>
			   @endcode
			 * 
			 * TODO
			 */
			template
			<
				class solution_t,
				class grade_t,
				class T,
				class random_distribution_t = std::uniform_int_distribution<std::size_t>,
				class random_engine_t = std::mt19937
			>
			class genetic_algo
			{
			private:

				/// Object contains evolve functions
				T & m_evolve_functions;

				/// Solutions & grades
				std::vector<archipelago<island<solution_grade<solution_t, grade_t>>>> m_solutions_grades;

				/// Distibution to choose if we do a crossover and a mutation
				std::uniform_real_distribution<double> m_random_double;

				/// Distibution to choose a solution form an island
				std::vector<archipelago<random_distribution_t>> m_random_solution_index;

				/// Random engine per thread
				std::vector<random_engine_t> m_random_engines;

				/// Number of generations
				unsigned int m_number_of_generation;

				/// Number of generations max
				unsigned int const m_number_of_generation_max;

				/// Probability have a crossover
				double const m_crossover_probability;

				/// Probability have a mutation
				double const m_mutation_probability;

				/// Number of generations to do between a island migration
				unsigned int const m_nb_generation_between_island_migration;

				/// Number of solution who migrate in island
				std::size_t const m_nb_migration_per_island;

				/// Number of generations to do between a archipelago migration
				unsigned int const m_nb_generation_between_archipelago_migration;

				/// Number of time a solution was the best
				int m_nb_same_solution;

				/// Number of time the best solution can be the same (-1 if no stop)
				int const m_nb_same_solution_max;

				/// Number of solution who migrate in archipelago
				std::size_t m_nb_migration_per_archipelago;

				/// Log level
				log_level_t const m_log_level;

				/// After "m_max_time" seconds, algo stops
				std::chrono::duration<double> const m_max_time;

				/// Time elapsed since evolve
				std::chrono::duration<double> m_time_elapsed;

				/// Number of generation between copy best solution
				unsigned int const m_nb_generation_between_copy_best_solution;

				/// Actual best solution
				solution_grade<solution_t, grade_t> m_best_solution;

			public:

				/// @brief Constructor
				/// @param[in] evolve_functions                            Class contains generate_solution, evaluate_solution, crossover, mutation and stop fonctions
				/// @param[in] nb_archipelago                              Number of archipelagos
				/// @param[in] nb_island_per_archipelago                   Number of islands per archipelago
				/// @param[in] nb_solution_per_island                      Number of solutions per island
				/// @param[in] number_of_generation                        Number of max generations (0 if no stop with the number of generations)
				/// @param[in] crossover_probability                       Probability a solution have to do a crossover
				/// @param[in] mutation_probability                        Probability a solution have to do a mutation
				/// @param[in] nb_migration_per_island                     Number of solutions migrate during the migration between islands
				/// @param[in] nb_migration_per_archipelago                Number of solutions migrate during the migration between archipelagos
				/// @param[in] nb_generation_between_island_migration      Number of generations between two migration between islands
				/// @param[in] nb_generation_between_archipelago_migration Number of generations between two migration between archipelagos
				/// @param[in] nb_same_solution_max                        Number of time the best solution can be the same (-1 if no stop)
				/// @param[in] max_time                                    After this time (in seconds), genetic algorithm stops (0. if no stop)
				/// @param[in] log_level                                   Log level (no_log, minimal_log, minimal_plus_log, archipelago_log, island_log, solution_grade_log)
				/// @param[in] nb_generation_between_copy_best_solution    Number of generation between copy best solution for external acces during computing (-1 if no copy)
				/// @param[in] generate_seed                               Function to generate seed
				genetic_algo(
					T & evolve_functions,
					std::size_t const nb_archipelago,
					std::size_t const nb_island_per_archipelago,
					std::size_t const nb_solution_per_island,
					unsigned int const number_of_generation = 100,
					double const crossover_probability = 0.7,
					double const mutation_probability = 0.01,
					std::size_t const nb_migration_per_island = 3,
					std::size_t const nb_migration_per_archipelago = 2,
					unsigned int const nb_generation_between_island_migration = 5,
					unsigned int const nb_generation_between_archipelago_migration = 10,
					int const nb_same_solution_max = 20,
					std::chrono::duration<double> const max_time = std::chrono::duration<double>(0.),
					log_level_t const log_level = no_log,
					unsigned int const nb_generation_between_copy_best_solution = 1,
					std::function<unsigned int ()> const & generate_seed = steady_clock_now
				) :
					m_evolve_functions(evolve_functions),
					m_solutions_grades(nb_archipelago, archipelago<island<solution_grade<solution_t, grade_t>>>(nb_island_per_archipelago, island<solution_grade<solution_t, grade_t>>(nb_solution_per_island))),
					m_random_double(0., 1.),
					m_random_solution_index(nb_archipelago, archipelago<random_distribution_t>(nb_island_per_archipelago)),
					m_random_engines(1, random_engine_t(generate_seed())),
					m_number_of_generation(1),
					m_number_of_generation_max(number_of_generation),
					m_crossover_probability(crossover_probability),
					m_mutation_probability(mutation_probability),
					m_nb_generation_between_island_migration(nb_generation_between_island_migration),
					m_nb_migration_per_island(std::min(nb_migration_per_island, nb_solution_per_island)),
					m_nb_generation_between_archipelago_migration(nb_generation_between_archipelago_migration),
					m_nb_same_solution(0),
					m_nb_same_solution_max(nb_same_solution_max),
					m_nb_migration_per_archipelago(std::min(nb_migration_per_archipelago, nb_solution_per_island)),
					m_log_level(log_level),
					m_max_time(max_time),
					m_time_elapsed(0.),
					m_nb_generation_between_copy_best_solution(nb_generation_between_copy_best_solution)
				{
					hnc::out(m_log_level, minimal_log) << "Create genetic algorithm" << std::endl;
					hnc::out(m_log_level, minimal_plus_log) << "  " << "(Number of max generations = " << m_number_of_generation_max << ")" << std::endl;
					hnc::out(m_log_level, minimal_plus_log) << "  " << "(Max time                  = " << m_max_time.count() << ")" << std::endl;
					hnc::out(m_log_level, minimal_log) << "  " << "+ Generate the population" << std::endl;

					// Generate the population + distribution
					for (std::size_t archipelago = 0; archipelago < m_solutions_grades.size(); ++archipelago)
					{
						hnc::out(m_log_level, archipelago_log) << "  " << "  " << "Archipelago " << archipelago << "/" << m_solutions_grades.size() << std::endl;

						for (std::size_t island = 0; island < m_solutions_grades[archipelago].size(); ++island)
						{
							hnc::out(m_log_level, island_log) << "  " << "  " << "  " << "Island " << island << "/" << m_solutions_grades[archipelago].size() << std::endl;

							// Create uniform distribution for select solution in island
							{
								auto & distribution = m_random_solution_index[archipelago][island];
								distribution = random_distribution_t(0, m_solutions_grades[archipelago][island].size() - 1);
							}

							// Generate solution for island
							for (auto & solution : m_solutions_grades[archipelago][island])
							{
								// Generate a solution
								solution.solution = m_evolve_functions.generate_solution(m_random_engines[0]);
								// Evaluate the solution
								solution.grade = m_evolve_functions.evaluate_solution(solution.solution);
							}
							// Sort population
							std::sort(m_solutions_grades[archipelago][island].begin(), m_solutions_grades[archipelago][island].end());

							for (auto & solution : m_solutions_grades[archipelago][island])
							{
								hnc::out(m_log_level, solution_grade_log) << "  " << "  " << "  " << "  " << "Solution: " << solution << std::endl;
							}
						}
					}
				}

				/// @brief Solve the problem
				void evolve()
				{
					hnc::out(m_log_level, minimal_log) << "Evolve genetic algorithm" << std::endl;

					// Get actual best solution
					m_best_solution = get_best_solution();
					// Get its grade
					grade_t best_solution_grade = m_best_solution.grade;

					// Time
					auto const time_start = std::chrono::system_clock::now();

					// Continue while
					while
					(
						// Number of generations
						(m_number_of_generation_max == 0 || m_number_of_generation <= m_number_of_generation_max) &&
						// Time
						(m_max_time <= std::chrono::duration<double>(0.) || m_max_time >= m_time_elapsed) &&
						// The best solution is the same
						(m_nb_same_solution_max <= -1 || m_nb_same_solution <= m_nb_same_solution_max) &&
						// User continue
						! m_evolve_functions.stop(m_best_solution.solution, m_best_solution.grade)
					)
					{
						hnc::out(m_log_level, minimal_log) << "  " << "Generation " << m_number_of_generation << " / " << m_number_of_generation_max << " - Best solution = " << m_best_solution;
						if (m_log_level == minimal_log) { std::cout.flush(); }
						hnc::out(m_log_level, minimal_plus_log) << " (" << m_nb_same_solution << " / " << m_nb_same_solution_max << " times with the same grade)" << std::endl;

						// Crossover & mutation
						crossover_and_mutation();

						// Migration between islands
						if (m_number_of_generation % m_nb_generation_between_island_migration == 0) { migration_between_islands(); }

						// Migration between archipelagos
						if (m_number_of_generation % m_nb_generation_between_archipelago_migration == 0) { migration_between_archipelagos(); }

						// Next generation
						++m_number_of_generation;

						// Get actual best solution
						solution_grade<solution_t, grade_t> const & best_solution = get_best_solution();
						// Copy the best solution
						if (m_number_of_generation % m_nb_generation_between_copy_best_solution == 0)
						{
							m_best_solution = best_solution;
						}
						// Update number of time the solution was the best
						if (best_solution.grade == best_solution_grade) { ++m_nb_same_solution; }
						else { best_solution_grade = best_solution.grade; m_nb_same_solution = 0; }

						// Time elapsed
						m_time_elapsed = std::chrono::duration<double>(std::chrono::system_clock::now() - time_start);

						hnc::out(m_log_level, minimal_log) << hnc::terminal::delete_line_string();
					}

					hnc::out(m_log_level, minimal_log) << "End at generation " << m_number_of_generation << " / " << m_number_of_generation_max << std::endl;
					hnc::out(m_log_level, minimal_log) << "The best solution is " << m_best_solution;
					hnc::out(m_log_level, minimal_plus_log) << " (" << m_nb_same_solution << " / " << m_nb_same_solution_max << " times with the same grade)";
					hnc::out(m_log_level, minimal_log) << std::endl;
				}

				/// @brief Return the best solution (we have)
				/// @return the best solution (we have)
				solution_grade<solution_t, grade_t> const & best_solution() const { return m_best_solution; }

				/// @brief Return the number of archipelagos
				/// @return the number of archipelagos
				std::size_t number_of_archipelago() const { return m_solutions_grades.size(); }

				/// @brief Return the number of islands per archipelago
				/// @return the number of islands per archipelago
				std::size_t number_of_island_per_archipelago(std::size_t archipelago = 0) const { return m_solutions_grades.at(archipelago).size(); }

				/// @brief Return the number of solutions per island per archipelago
				/// @return the number of solutions per island per archipelago
				std::size_t number_of_solution_per_island_per_archipelago(std::size_t archipelago = 0, std::size_t island = 0) const { return m_solutions_grades.at(archipelago).at(island).size(); }

				/// @brief Return the number of generations
				/// @return the number of generations
				unsigned int number_of_generation() const { return m_number_of_generation; }

				/// @brief Return the number of generations max
				/// @return the nNumber of generations max
				unsigned int number_of_generation_max() const { return m_number_of_generation_max; }

				/// @brief Return the probability have a crossover
				/// @return the probability have a crossover
				double crossover_probability() const { return m_crossover_probability; }

				/// @brief Return the probability have a mutation
				/// @return the probability have a mutation
				double mutation_probability() const { return m_mutation_probability; }

				/// @brief Return the number of generations to do between a island migration
				/// @return the number of generations to do between a island migration
				unsigned int nb_generation_between_island_migration() const { return m_nb_generation_between_island_migration; }

				/// @brief Return the number of solutions who migrate in island
				/// @return the number of solutions who migrate in island
				std::size_t nb_migration_per_island() const { return m_nb_migration_per_island; }

				/// @brief Return the number of generations to do between a archipelago migration
				/// @return the number of generations to do between a archipelago migration
				unsigned int nb_generation_between_archipelago_migration() const { return m_nb_generation_between_archipelago_migration; }

				/// @brief Return the number of time a solution was the best
				/// @return the number of time a solution was the best
				int number_of_times_same_best_solution() const { return m_nb_same_solution; }

				/// @brief Return the number of time the best solution can be the same
				/// @return the number of time the best solution can be the same
				int number_of_times_same_best_solution_max() const { return m_nb_same_solution_max; }

				/// @brief Return the number of solutions who migrate in archipelago
				/// @return the number of solutions who migrate in archipelago
				std::size_t nb_migration_per_archipelago() const { return m_nb_migration_per_archipelago; }

				/// @brief Return the time elapsed
				/// @return the time elapsed
				double time_elapsed() const { return m_time_elapsed.count(); }

			private:

				/// @brief Crossover & mutation
				void crossover_and_mutation()
				{
					hnc::out(m_log_level, minimal_plus_log) << "  " << "+ Crossover & mutation" << std::endl;

					// Do crossover and mutation
					for (std::size_t archipelago = 0; archipelago < m_solutions_grades.size(); ++archipelago)
					{
						hnc::out(m_log_level, archipelago_log) << "  " << "  " << "Archipelago " << archipelago << "/" << m_solutions_grades.size() << std::endl;

						#pragma omp parallel for
						for (std::size_t island = 0; island < m_solutions_grades[archipelago].size(); ++island)
						{
							hnc::out(m_log_level, island_log) << "  " << "  " << "  " << "Island " << island << "/" << m_solutions_grades[archipelago].size() << std::endl;

							// Get uniform distribution for select solution in island
							auto & random_solution_index = m_random_solution_index[archipelago][island];

							// To stock new generation
							hnc::algo::genetic_algo::island<solution_grade<solution_t, grade_t>> new_generation;
							// We can estimate the size with crossover and mutation probabilities
							new_generation.reserve(std::size_t((m_crossover_probability + m_mutation_probability + 0.1) * m_solutions_grades[archipelago][island].size()));

							std::size_t nb_solution = m_solutions_grades[archipelago][island].size();

							// Crossover and mutation
							for (auto & solution : m_solutions_grades[archipelago][island])
							{
								// Do a crossover ?
								if (m_random_double(m_random_engines[0]) <= m_crossover_probability)
								{
									auto const & random_solution = m_solutions_grades[archipelago][island][random_solution_index(m_random_engines[0])];
									if (solution.solution != random_solution.solution)
									{
										auto new_solution = m_evolve_functions.crossover(solution.solution, random_solution.solution, m_random_engines[0]);
										new_generation.push_back(solution_grade<solution_t, grade_t>(new_solution, m_evolve_functions.evaluate_solution(new_solution)));

										hnc::out(m_log_level, solution_grade_log) << "  " << "  " << "  " << "  " << "Crossover: " << solution << " + " << random_solution << " -> " << new_generation.back() << std::endl;
									}
								}

								// Do a mutation ?
								if (m_random_double(m_random_engines[0]) <= m_mutation_probability)
								{
									auto new_solution = m_evolve_functions.mutation(solution.solution, m_random_engines[0]);
									new_generation.push_back(solution_grade<solution_t, grade_t>(new_solution, m_evolve_functions.evaluate_solution(new_solution)));

									hnc::out(m_log_level, solution_grade_log) << "  " << "  " << "  " << "  " << "Mutation:  " << solution << " -> " << new_generation.back() << std::endl;
								}
							}

							// Put new generation into solutions
							m_solutions_grades[archipelago][island].insert
							(
								m_solutions_grades[archipelago][island].end(),
								new_generation.begin(), new_generation.end()
							);

							// Sort population
							std::sort(m_solutions_grades[archipelago][island].begin(), m_solutions_grades[archipelago][island].end());

							// Resize
							m_solutions_grades[archipelago][island].resize(nb_solution);

							for (auto & solution : m_solutions_grades[archipelago][island])
							{
								hnc::out(m_log_level, solution_grade_log) << "  " << "  " << "  " << "  " << "Solution:  " << solution << std::endl;
							}
						}
					}
				}

				/// @brief Migration between islands
				void migration_between_islands()
				{
					hnc::out(m_log_level, minimal_plus_log) << "  " << "+ Migration between islands" << std::endl;

					for (auto & archipelago : m_solutions_grades)
					{
						hnc::out(m_log_level, archipelago_log) << "  " << "  " << "Archipelago" << std::endl;

						for (std::size_t island = 0; island < archipelago.size(); ++island)
						{
							hnc::out(m_log_level, island_log) << "  " << "  " << "  " << "Island " << island << "/" << archipelago.size() << std::endl;

							// Get previous island index
							std::size_t previous_island = (island == 0) ? (archipelago.size() - 1) : (island - 1);
							// Replace x worst solutions by the x bests
							for (std::size_t i = 0; i < m_nb_migration_per_island; ++i)
							{
								auto & worst_solution = archipelago[island][archipelago[island].size() - 1 - i];
								auto & best_solution = archipelago[previous_island][i];
								hnc::out(m_log_level, solution_grade_log) << "  " << "  " << "  " << worst_solution << " <- " << best_solution << std::endl;
								worst_solution = best_solution;
							}
							std::sort(archipelago[island].begin(), archipelago[island].end());
						}
					}
				}

				/// @brief Migration between archipelagos
				void migration_between_archipelagos()
				{
					hnc::out(m_log_level, minimal_plus_log) << "  " << "+ Migration between archipelagos" << std::endl;

					for (std::size_t archipelago = 0; archipelago < m_solutions_grades.size(); ++archipelago)
					{
						hnc::out(m_log_level, archipelago_log) << "  " << "  " << "Archipelago " << archipelago << "/" << m_solutions_grades.size() << std::endl;

						// Get previous archipelago index
						std::size_t previous_archipelago = (archipelago == 0) ? (m_solutions_grades.size() - 1) : (archipelago - 1);
						// Replace x worst solutions by the x bests
						for (std::size_t i = 0; i < m_nb_migration_per_archipelago; ++i)
						{
							auto & worst_solution = m_solutions_grades[archipelago][0][m_solutions_grades[archipelago][0].size() - 1 - i];
							auto & best_solution = m_solutions_grades[previous_archipelago][0][i];
							hnc::out(m_log_level, solution_grade_log) << "  " << "  " << "  " << "  " << worst_solution << " <- " << best_solution << std::endl;
							worst_solution = best_solution;
						}
						std::sort(m_solutions_grades[archipelago][0].begin(), m_solutions_grades[archipelago][0].end());
					}
				}

				/// @brief Return a reference of the best solution
				/// @return a reference of the best solution
				solution_grade<solution_t, grade_t> const & get_best_solution() const
				{
					// Possible solution is the best solution of the first archipelago of the first island
					solution_grade<solution_t, grade_t> const * best_solution = & m_solutions_grades[0][0][0];
					// Check other solution
					for (auto const & archipelago : m_solutions_grades)
					{
						for (auto const & island : archipelago)
						{
							auto const & solution = island[0];
							if (best_solution->grade < solution.grade)
							{
								best_solution = & solution;
							}
						}
					}
					// Return a reference
					return *best_solution;
				}
			};
		}
	}
}

#endif
