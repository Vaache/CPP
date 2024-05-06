#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange::dbData("data.csv");
	}
	catch(const mstd::ExpHandler& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}