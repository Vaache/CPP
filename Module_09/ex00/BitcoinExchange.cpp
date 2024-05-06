#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::MAP;
std::string BitcoinExchange::value;
std::string BitcoinExchange::key;

BitcoinExchange::BitcoinExchange()
{ }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{ (void)other; }

BitcoinExchange::~BitcoinExchange()
{ }
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{ (void)other; return *this; }

void BitcoinExchange::dbData(std::string FileName)
{
	std::ifstream inFile(FileName.c_str());
	if (!inFile.is_open())
		throw mstd::ExpHandler(_ERROR_CAN_NOT_OPEN_FILE_);
	std::string line;
	getline(inFile, line);
	if (line.empty())
		throw mstd::ExpHandler(_ERROR_EMPTY_FILE_);
	if (line != "date,exchange_rate")
		throw mstd::ExpHandler(_ERROR_DATA_FORMAT_);
	while (getline(inFile, line))
	{
		if (!BitcoinExchange::validCharacters(line) || !BitcoinExchange::validData(line))
		{
			BitcoinExchange::MAP.clear();
			throw mstd::ExpHandler(_ERROR_INVALID_DATA_);
		}
	}
}

bool BitcoinExchange::validCharacters(const std::string& str)
{
	size_t pos = 0;
	size_t comma = 0;
	size_t dash = 0;
	while (42)
	{
		if ((pos = str.find(',', pos)) == std::string::npos)
			break;
		comma++;
		pos++;
	}
	pos = 0;
	while (42)
	{
		if ((pos = str.find('-', pos)) == std::string::npos)
			break;
		dash++;
		pos++;
	}
	if (str.find(',', 0) == std::string::npos || str.find(',', 0) + 1 == str.size() \
			|| comma != 1 || dash != 2)
		return false;
	return true;
}

bool BitcoinExchange::validData(const std::string& str)
{
	std::string data = str.substr(0, str.find(',', 0));
	std::string year = data.substr(0, data.find('-', 0));
	data = str.substr(0, str.find(',', 0));
	std::string month = data.substr(data.find('-', 0) + 1, data.find_last_of('-', 0));
	data = str.substr(0, str.find(',', 0));
	std::string day = data.substr(data.find_last_of('-', -1) + 1, data.size());
	std::cout << "year --> " << year << std::endl;
	std::cout << "Month --> " << month << std::endl;
	std::cout << "day --> " << day << std::endl;
	return true;
}
