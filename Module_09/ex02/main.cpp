#include "PmergeMe.hpp"

// Time to process a range of 5 elements with std::[..] : 0.00031 us

int main(int ac, char **av)
{
	try
	{
		PmergeMe::valid_args(ac, av);
		PmergeMe::_PmergeMe_();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}