#include "BitcoinExchange.hpp"
#include <sstream>
std::map<std::string, double> BitcoinExchange::MAP;
std::string BitcoinExchange::value;
std::string BitcoinExchange::key;
std::string err;
char BitcoinExchange::sym;

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
	size_t dash = 2;
	size_t symb = 1;
	while (42)
	{
		if ((pos = line.find(sym, pos)) == std::string::npos)
			break;
		symb--;
		pos++;
	}
	std::string str = line.substr(0, line.find(BitcoinExchange::sym));
	pos = 0;
	while (42)
	{
		if ((pos = str.find('-', pos)) == std::string::npos)
			break;
		dash--;
		pos++;
	}
	if (line.find(BitcoinExchange::sym, 0) == std::string::npos || line.find(BitcoinExchange::sym, 0) + 1 == line.size() \
			|| symb != 0 || dash != 0)
		{
			if (BitcoinExchange::sym != '|')
				err = _ERROR_INVALID_DATA_;
			else
			{
				err = _ERROR_BAD_INPUT_;
				err += line.substr(0, line.find('|', 0));
			}
			return false;
		}
	return true;
}

bool BitcoinExchange::validData(const std::string& str, std::map<int,int>& cal)
{
	std::string data = str.substr(0, str.find(BitcoinExchange::sym, 0));
	std::string year = data.substr(0, data.find('-', 0));
	data = str.substr(str.find('-', 0) + 1, str.find(BitcoinExchange::sym, 0));
	std::string month = data.substr(0, data.find('-', 0));
	data = str.substr(0, str.find(BitcoinExchange::sym, 0));
	std::string day;
		day = data.substr(data.find_last_of('-', -1) + 1, data.size());
	if (sym == '|')
		day.pop_back();
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

/* VALIDATION DATA FILE*/

void BitcoinExchange::dbData(const std::string FileName)
{
	BitcoinExchange::sym = ',';
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
		if (!line.empty())
		{
			if (!BitcoinExchange::validCharacters(line) \
				|| !BitcoinExchange::validData(line.substr(0,line.find(',',0)), cal) \
				|| !BitcoinExchange::is_all_num(line.substr(line.find(',', 0) + 1, line.size()), 1))
			{
				BitcoinExchange::MAP.clear();
				throw mstd::ExpHandler(err);
			}
			BitcoinExchange::key = line.substr(0, line.find(',',0));
			BitcoinExchange::value = line.substr(line.find(',', 0) + 1, line.size());
			BitcoinExchange::MAP[key] = std::stod(line.substr(line.find(',',0) + 1, line.size()));
		}
	}
	if (BitcoinExchange::MAP.empty())
		throw mstd::ExpHandler(_ERROR_EMPTY_FILE_);
	// std::map<std::string,double>::iterator it = BitcoinExchange::MAP.begin();
	// for (; it != BitcoinExchange::MAP.end(); ++ it)
	// 	std::cout << it->first << "," << it->second << std::endl;
}


/* VALIDATION INPUT FILE*/

bool BitcoinExchange::validInputCoin(const std::string & str)
{
	if (str.empty())
	{
		err = _ERROR_INVALID_COIN_;
		return false;
	}
	std::string::const_iterator it = str.cbegin();
	if (*it == '-')
	{
		err = _ERROR_NEGATIVE_NUMBER_;
		return false;
	}
	if (*it == '+')
		++ it;
	size_t dot = 0;
	while (it != str.cend())
	{
		if (*it == '.')
			++ dot;
		else if (*it < '0' || *it > '9')
		{
			err = _ERROR_INVALID_COIN_;
			err += " => [" + str + "]";
			return false;
		}
		++ it;
	}
	if (dot > 1)
	{
		err = _ERROR_INVALID_COIN_;
		err += " => [" + str + "]";
		return false;
	}
	if ((dot && std::atof(str.c_str()) > 1000.0) || (!dot && (str.size() > 4 || std::atoi(str.c_str()) > 1000)))
	{
		err = _ERROR_LARGE_NUMBER_;
		return false;
	}
	return true;
}

void BitcoinExchange::validInput(const char * FileName)
{
	BitcoinExchange::sym = '|';
	std::ifstream inFile(FileName);
	if (!inFile.is_open())
		throw mstd::ExpHandler(err = _ERROR_CAN_NOT_OPEN_FILE_);
	std::string line;
	getline(inFile, line);
	if (line.empty())
		throw mstd::ExpHandler(_ERROR_EMPTY_FILE_);
	std::map<int, int> cal;
	BitcoinExchange::creat_cal(cal);
	while (getline(inFile, line))
	{
		if (!line.empty())
		{
			if (!BitcoinExchange::validCharacters(line) || !BitcoinExchange::validData(line, cal) \
					|| !BitcoinExchange::validInputCoin(line.substr(line.find('|', 0) + 2, line.size())))
				std::cout << err << std::endl;
			else
			{
				std::map<std::string, double>::iterator it = BitcoinExchange::MAP.upper_bound(line.substr(0, line.find(BitcoinExchange::sym, 0) - 1));
				if (it != BitcoinExchange::MAP.begin())
					-- it;
				const double num = std::strtod(line.substr(line.find('|', 0) + 2, line.size()).c_str(), NULL);
				std::cout << line.substr(0, line.find(BitcoinExchange::sym, 0) - 1);
				std::cout << " => " << num << " = " << num * it->second << std::endl;

			}
		}
	}
	BitcoinExchange::MAP.clear();
}

/*
	2011-01-03 => 3 = 0.9
	2011-01-03 => 2 = 0.6
	2011-01-03 => 1 = 0.3
	2011-01-03 => 1.2 = 0.36
	2011-01-09 => 1 = 0.32
	Error: not a positive number.
	Error: bad input => 2001-42-42
	2012-01-11 => 1 = 7.1
	Error: too large a number.
*/