#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange::validData(av[1]);
	}
	catch(const Err::ExpHandler& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}