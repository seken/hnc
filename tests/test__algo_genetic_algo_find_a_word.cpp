#include <iostream>
#include <random>

#include <hnc/algo/genetic_algo.hpp>

class search_a_word
{
private:

	/// Distribution to generate solution
	std::uniform_int_distribution<char> m_random_char;

	/// Distribution to crossover
	std::bernoulli_distribution m_random_bool;

	/// Distribution to crossover
	std::uniform_int_distribution<int> m_random_int;

	/// We need the target for evaluate solution
	std::string const m_target;

public:

	/**
	 * Constructor
	 * @param target The word we search (we need it for evaluate solutions)
	 */
	search_a_word(std::string const & target) :
		m_random_char(32, 126),
		m_random_bool(0.5),
		m_random_int(0, target.size() - 1),
		m_target(target)
	{ }

	/// @return a new pseudo generated solution
	std::string generate_solution(std::mt19937 & random_engine)
	{
		std::string solution;
		solution.resize(m_target.size());
		for (auto & c : solution) { c = m_random_char(random_engine); }
		return solution;
	}

	/**
	 * Evaluate a solution
	 * @param solution A solution
	 * @return grade for solution
	 */
	unsigned int evaluate_solution(std::string const & solution)
	{
		int grade = 0;
		for (std::size_t i = 0; i < m_target.size(); ++i)
		{
			if (solution[i] == m_target[i]) { ++grade; }
		}
		return grade;
	}

	/**
	 * Crossover between two solution
	 * @param solution0 First solution
	 * @param solution1 Second solution
	 * @param random_engine A random engine
	 * @return the new solution
	 */
	std::string crossover(std::string const & solution0, std::string const & solution1, std::mt19937 & random_engine)
	{
		std::string new_solution; new_solution.resize(solution0.size());
		for (std::size_t i = 0; i < solution0.size(); ++i)
		{
			if (m_random_bool(random_engine)) { new_solution[i] = solution0[i]; }
			else { new_solution[i] = solution1[i]; }
		}
		return new_solution;
	}

	/**
	 * Crossover of a solution
	 * @param solution initial solution
	 * @param random_engine A random engine
	 * @return the new solution
	 */
	std::string mutation(std::string const & solution, std::mt19937 & random_engine)
	{
		std::string new_solution(solution);
		new_solution[m_random_int(random_engine)] = m_random_char(random_engine);
		return new_solution;
	}

	/**
	 * Get best solution and grade to know if genetic algo stops
	 * @param best_solution The actual best solution
	 * @param grade Best solution's grade
	 * @return true if stop
	 */
	bool stop(std::string const & /*best_solution*/, unsigned int const & grade) const
	{
		return (grade == m_target.size());
	}

};


int main()
{
	// Word we search (only ascii between 33 and 126)
	std::string const target = "Hello world!";

	std::cout << "We search the word: " << target << std::endl;

	// Create fonctions
	search_a_word evolve_functions(target);

	// Create population
	hnc::algo::genetic_algo::genetic_algo<std::string, unsigned int, search_a_word> ga
	(
		evolve_functions,
		2,                                 // nb_archipelago,
		4,                                 // nb_island_per_archipelago,
		50,                                // nb_solution_per_island,
		-1,                                // number_of_generation = 100,
		0.7,                               // crossover_probability = 0.7,
		0.01,                              // mutation_probability = 0.01,
		3,                                 // nb_migration_per_island = 3,
		2,                                 // nb_migration_per_archipelago = 2,
		5,                                 // nb_generation_between_island_migration = 5,
		10,                                // nb_generation_between_archipelago_migration = 10,
		-1,                                // nb_same_solution_max = 20,
		std::chrono::duration<double>(0.), // max_time = std::chrono::duration<double>(0.),
		hnc::algo::genetic_algo::minimal_plus_log,         // log_level = no_log, minimal_log, minimal_plus_log, archipelago_log, island_log, solution_grade_log
		1,                                 // nb_generation_between_copy_best_solution = 1
		hnc::algo::genetic_algo::system_clock_now          // std::function<unsigned int ()> const & generate_seed = system_clock_now()
	);
	// Star genetic algo
	ga.evolve();

	// Display result
	std::cout << "The best solution is " << ga.best_solution() << std::endl;

	// Display stats
	std::cout << "Solution found:" << std::endl;
	std::cout << "  " << "in " << ga.time_elapsed() << " seconds" << std::endl;
	std::cout << "  " << "with " << ga.number_of_generation() << " / " << ga.number_of_generation_max() << " generations" << std::endl;
	std::cout << "  " << "with " << ga.number_of_archipelago() << " archipelagos," << std::endl;
	std::cout << "  " << "     " << ga.number_of_island_per_archipelago() << " islands per archipelago," << std::endl;
	std::cout << "  " << "     " << ga.number_of_solution_per_island_per_archipelago() << " solutions per island" << std::endl;
	std::cout << "  " << "with a probability of " << ga.crossover_probability() << " for crossovers, and " << ga.mutation_probability() << " for mutations" << std::endl;
	std::cout << "  " << "with " << ga.nb_generation_between_island_migration() << " generations between " << ga.nb_migration_per_island() << " solutions do island migration" << std::endl;
	std::cout << "  " << "with " << ga.nb_generation_between_archipelago_migration() << " generations between " << ga.nb_migration_per_archipelago() << " solutions do archipelago migration" << std::endl;

	return (ga.best_solution().solution == target) ? 0 : 1;
}
