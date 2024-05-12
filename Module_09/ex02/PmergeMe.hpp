#ifndef _PMERGER_ME_HPP
# define _PMERGER_ME_HPP

# define _ERROR_ARG_ "Error: Invalid arguments."
# define _ERROR_EMPTY_ "Error: Empty arguments."
# define _ERROR_NEGATIVE_ "Error: Negative arguments."
# define _ERROR_OVERFLOW_ "Error: An overflowing argument."

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <sstream>

class PmergeMe
{
public:
	static std::deque<int> deq;
	static std::vector<int> vect;
private:
	PmergeMe();
	PmergeMe(const PmergeMe & other);
	PmergeMe& operator=(const PmergeMe & other);
	~PmergeMe();

private:
	static bool isPulusDigit(const std::string & arg);
	static void fill_cont(const std::string& arg);
	template <typename Cont>
		static void _sort_pairs_(Cont& arr, size_t lenght);
	template <typename Cont>
		static void block_swap(Cont& arr, int a, int b);
public:
	static void valid_args(int ac, char **av);
	static void _PmergeMe_();
};

#endif