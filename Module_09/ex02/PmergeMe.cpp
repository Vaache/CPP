#include "PmergeMe.hpp"

template <typename Cont>
	void print(const Cont& container)
	{
		typename Cont::const_iterator it;
		for (it = container.begin(); it != container.end(); ++ it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

std::deque<int> PmergeMe::deq;
std::vector<int> PmergeMe::vect;

PmergeMe::PmergeMe()
{ }

PmergeMe::PmergeMe(const PmergeMe & other)
{ (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe & other)
{ (void)other; return *this; }

PmergeMe::~PmergeMe()
{ }

bool PmergeMe::isPulusDigit(const std::string & arg)
{
	std::string::const_iterator it = arg.begin();
	while (it != arg.end() && *it == ' ')
		it++;
	if (*it == '+')
		++it;
	while (it != arg.end())
	{
		if (*it == ' ')
			++ it;
		else if (*it < '0' || *it > '9')
			return false;
		else
			++ it;
	}
	return true;
}

void PmergeMe::valid_args(int ac, char **av)
{
	if (ac < 2)
			throw std::runtime_error(_ERROR_ARG_);
	for (int i = 1; av[i]; ++ i)
	{
		std::string arg(av[i]);
		if (arg.find('-', 0) != std::string::npos)
			throw std::runtime_error(_ERROR_NEGATIVE_);
		if (arg.empty())
			throw std::runtime_error(_ERROR_EMPTY_);
		if (!PmergeMe::isPulusDigit(arg))
			throw std::runtime_error(_ERROR_ARG_);
		try
		{
			PmergeMe::fill_cont(arg);
		}
		catch(...)
		{
			PmergeMe::vect.clear();
			PmergeMe::deq.clear();
			throw std::runtime_error(_ERROR_OVERFLOW_);
		}
	}
}
void PmergeMe::fill_cont(const std::string& arg)
{
	std::stringstream ss(arg);
    std::string token;
    while (std::getline(ss, token, ' '))
	{
		if (!token.empty())
		{
			if (std::atoll(token.c_str()) > INT_MAX)
				throw std::runtime_error("");
			PmergeMe::vect.push_back(std::atoi(token.c_str()));
			PmergeMe::deq.push_back(std::atoi(token.c_str()));
		}
    }
}

template <typename Cont>
	void PmergeMe::_sort_pair(Cont& arr)
	{
		size_t first = 0;
		size_t second = 1;
		while ((second * 2) <= arr.size())
		{
			if (arr[second] > arr[first])
			{
				size_t tmp = arr[second];
				arr[second] = arr[first];
				arr[first] = tmp;
			}
			second *= 2;
			first += second - 1;
		}
	}

void PmergeMe::_PmergeMe_()
{
	PmergeMe::_sort_pair(PmergeMe::vect);
	::print(PmergeMe::vect);
}