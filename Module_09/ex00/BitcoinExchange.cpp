#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{ }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{ (void)other; }

BitcoinExchange::~BitcoinExchange()
{ }
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{ (void)other; return *this; }

void BitcoinExchange::validData(std::string FileName)
{
	if (FileName.find_last_of('.', -1) == std::string::npos || FileName.substr(FileName.find_last_of('.', -1), FileName.size()) != ".csv")
		throw Err::ExpHandler(_ERROR_FILE_EXTENTION_);
	std::fstream inFile(FileName);
	if (!inFile.is_open())
		throw Err::ExpHandler(_ERROR_CAN_NOT_OPEN_FILE_);
	std::string line;
	size_t pipe;
	while (getline(inFile, line))
	{
		pipe = line.find('|', 0);
	}
}