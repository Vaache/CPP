#include "BitcoinExchange.hpp"
#include <sstream>
std::map<std::string, double> BitcoinExchange::MAP;
std::string BitcoinExchange::value;
std::string BitcoinExchange::key;
std::string err;

BitcoinExchange::BitcoinExchange()
{ }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{ (void)other; }

BitcoinExchange::~BitcoinExchange()
{ }
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{ (void)other; return *this; }

void BitcoinExchange::creat_cal(std::map<int,int>& cal)
{
	for (int i = 1; i <= 12; ++ i)
	{
		if (i < 8)
		{
			if (i == 2)
				cal.insert(std::make_pair(i,28));
			else if (!(i % 2))
				cal.insert(std::make_pair(i,30));
			else
				cal.insert(std::make_pair(i,31));
		}
		else
		{
			if (i % 2)
				cal.insert(std::make_pair(i,30));
			else
				cal.insert(std::make_pair(i,31));
		}
	}
	
}

bool BitcoinExchange::validCharacters(const std::string& line)
{
	size_t pos = 0;
	size_t comma = 1;
	size_t dash = 2;
	std::string str = line.substr(0, line.find(','));
	while (42)
	{
		if ((pos = line.find(',', pos)) == std::string::npos)
			break;
		comma--;
		pos++;
	}
	pos = 0;
	while (42)
	{
		if ((pos = str.find('-', pos)) == std::string::npos)
			break;
		dash--;
		pos++;
	}
	if (line.find(',', 0) == std::string::npos || line.find(',', 0) + 1 == line.size() \
			|| comma != 0 || dash != 0)
		{
			err = _ERROR_INVALID_DATA_;
			return false;
		}
	return true;
}

bool BitcoinExchange::validData(const std::string& str, std::map<int,int>& cal)
{
	std::string data = str.substr(0, str.find(',', 0));
	std::string year = data.substr(0, data.find('-', 0));
	data = str.substr(str.find('-', 0) + 1, str.find(',', 0));
	std::string month = data.substr(0, data.find('-', 0));
	data = str.substr(0, str.find(',', 0));
	std::string day = data.substr(data.find_last_of('-', -1) + 1, data.size());

	if (year.size() != 4 || std::atoi(year.c_str()) < 2009 || std::atoi(year.c_str()) > 2022 \
		|| !BitcoinExchange::is_all_num(year, 0))
	{
		err = _ERROR_INVALID_YEAR_;
		err += " => [" + year + "]";
		return false;
	}
	std::map<int,int>::const_iterator it = cal.cbegin();
	for (; it != cal.cend(); ++ it)
		if (it->first == std::atoi(month.c_str()))
			break;
	if (it == cal.cend() || month.size() != 2 || !BitcoinExchange::is_all_num(month, 0))
	{
		err = _ERROR_INVALID_MONTH_;
		err += " => [" + month + "]";
		return false;
	}
	if (!(std::atoi(year.c_str()) % 4))
		cal[2] = 29;
	else
		cal[2] = 28;
	if (it->second < std::atoi(day.c_str()) || std::atoi(day.c_str()) < 1 \
				|| day.size() != 2 || !BitcoinExchange::is_all_num(day, 0))
	{
		err = _ERROR_INVALID_DAY_;
		err += " => [" + day + "]";
		return false;
	}
	return true;
}

bool BitcoinExchange::is_all_num(const std::string& coin, int flag)
{
	std::string::const_iterator it = coin.cbegin();
	size_t dot = 0;
	if (flag)
	{
		for (; it != coin.cend(); ++ it)
		{
			if (*it == '.')
				dot ++;
			else if (*it < '0'|| *it > '9' || \
				std::stod(coin) > 66063.56 || std::stod(coin) < 0)
			{
				err = _ERROR_INVALID_COIN_;
				err += " => [" + coin + "]";
				return false;
			}
		}
		if (dot > 1)
		{
			err = _ERROR_INVALID_COIN_;
			err += " => [" + coin + "]";
			return false;
		}
	}
	else
	{
		for (; it != coin.cend(); ++ it)
			if (*it < '0'|| *it > '9')
				return false;
	}
	return true;
}

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
	std::map<int, int> cal;
	BitcoinExchange::creat_cal(cal);
	while (getline(inFile, line))
	{
		if (!BitcoinExchange::validCharacters(line) || !BitcoinExchange::validData(line.substr(0,line.find(',',0)), cal) \
				|| !BitcoinExchange::is_all_num(line.substr(line.find(',',0) + 1, line.size()), 1))
		{
			BitcoinExchange::MAP.clear();
			throw mstd::ExpHandler(err);
		}
		BitcoinExchange::key = line.substr(0, line.find(',',0));
		BitcoinExchange::value = line.substr(line.find(',', 0) + 1, line.size());
		BitcoinExchange::MAP[key] = std::stold(line.substr(line.find(',',0) + 1, line.size()));
	}
	std::map<std::string,double>::iterator it = BitcoinExchange::MAP.begin();
	for (; it != BitcoinExchange::MAP.end(); ++ it)
		std::cout << it->first << "," << it->second << std::endl;
}

