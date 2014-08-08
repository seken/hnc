#include <iostream>
#include <random>

#include <hnc/algo/genetic_algo.hpp>
#include <hnc/random.hpp>
#include <hnc/unused.hpp>
#include <hnc/int.hpp>


class search_a_word
{
private:

	/// Random char
	hnc::random::uniform_t<char> m_random_char;

	/// Random bool
	hnc::random::uniform_t<bool> m_random_bool;

	/// Random std::size_t
	hnc::random::uniform_t<std::size_t> m_random_size_t;

	/// We need the target to evaluate solution
	std::string const m_target;

public:

	/// @brief Constructor
	/// @param target The word we search (we need it for evaluate solutions)
	search_a_word(std::string const & target) :
		m_random_char(32, 126),
		m_random_bool(),
		m_random_size_t(0, target.empty() ? std::size_t(0) : target.size() - 1),
		m_target(target)
	{ }

	/// @brief Return a new solution
	/// @return a new solution
	std::string generate_solution()
	{
		std::string solution;
		solution.resize(m_target.size());
		for (auto & c : solution) { c = m_random_char(); }
		return solution;
	}

	/// @brief Evaluate a solution
	/// @param solution A solution
	/// @return grade of the solution
	unsigned int evaluate_solution(std::string const & solution)
	{
		unsigned int grade = 0;
		
		for (std::size_t i = 0; i < m_target.size(); ++i)
		{
			if (solution[i] == m_target[i]) { ++grade; }
		}
		
		return hnc::uint_t(solution.size()) - grade;
	}

	/// @brief Crossover between two solutions
	/// @param solution_a    First solution
	/// @param solution_b    Second solution
	/// @return the new solution
	std::string crossover(std::string const & solution_a, std::string const & solution_b)
	{
		std::string new_solution; new_solution.resize(solution_a.size());
		
		for (std::size_t i = 0; i < solution_a.size(); ++i)
		{
			if (m_random_bool()) { new_solution[i] = solution_a[i]; }
			else { new_solution[i] = solution_b[i]; }
		}
		
		return new_solution;
	}

	/// @brief Mutation of a solution
	/// @param solution Initial solution
	/// @return the new solution
	std::string mutation(std::string const & solution)
	{
		std::string new_solution(solution);
		
		new_solution[m_random_size_t()] = m_random_char();
		
		return new_solution;
	}

	/// @brief Get best solution and grade to know if genetic algo stops
	/// @param best_solution The actual best solution
	/// @param grade Best solution's grade
	/// @return true to stop, false otherwise
	bool stop(std::string const & best_solution, unsigned int const & grade) const
	{
		hnc_unused(best_solution);
		return (grade == 0);
	}

};


int main()
{
	// Word we search (only ascii between 33 and 126)
	std::string const target = "Hello world!";
	
	std::cout << "We search the word: " << target << std::endl;
	
	hnc::algo::genetic_algo::genetic_algo<std::string, unsigned int, search_a_word> ga
	(
		search_a_word(target),
		1, // nb_archipelago
		hnc::openmp::nb_thread_max(), // nb_island_per_archipelago
		500, // nb_solution_per_island
		0.7, // crossover_probability = 0.7
		0.2, // mutation_probability = 0.1
		3, // nb_migration_per_island = 3
		5, // nb_generation_between_island_migration = 5
		2, // nb_migration_per_archipelago = 2
		10, // nb_generation_between_archipelago_migration = 10
		100, // nb_same_solution_max = 20
		0, // nb_generation_max = 0
		0.0, // max_time = 0.0
		hnc::algo::genetic_algo::log_level_t::minimal_plus_log // no_log, minimal_log, minimal_plus_log, archipelago_log, island_log, solution_grade_log
	);
	std::cout << std::endl;
	
	// Display result
	std::cout << "The best solution is " << ga.best_solution() << std::endl;
	std::cout << std::endl;
	
	// Display stats
	std::cout << "Solution found:" << std::endl;
	std::cout << "  " << "in " << ga.time_elapsed() << " seconds" << std::endl;
	std::cout << "  " << "with " << ga.nb_generation() << " / " << ga.nb_generation_max << " generations" << std::endl;
	std::cout << "  " << "with " << ga.nb_archipelago << " archipelagos," << std::endl;
	std::cout << "  " << "     " << ga.nb_island_per_archipelago << " islands per archipelago," << std::endl;
	std::cout << "  " << "     " << ga.nb_solution_per_island << " solutions per island" << std::endl;
	std::cout << "  " << "with a probability of " << ga.crossover_probability << " for crossovers, and " << ga.mutation_probability << " for mutations" << std::endl;
	std::cout << "  " << "with " << ga.nb_generation_between_island_migration << " generations between " << ga.nb_migration_per_island << " solutions do island migration" << std::endl;
	std::cout << "  " << "with " << ga.nb_generation_between_archipelago_migration << " generations between " << ga.nb_migration_per_archipelago << " solutions do archipelago migration" << std::endl;
	std::cout << std::endl;
	
	return (ga.best_solution().solution == target) ? 0 : 1;
}
