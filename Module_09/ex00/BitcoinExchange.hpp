#ifndef _BITCONI_EXCHANGE_HPP_
# define _BITCONI_EXCHANGE_HPP_

#define _ERROR_FILE_EXTENTION_ "Error : Incorrect file extension."
#define _ERROR_CAN_NOT_OPEN_FILE_ "Error : Can't open file."
#define _ERROR_DATA_FORMAT_ "Error : Does not match the description of the data format."
#define _ERROR_EMPTY_FILE_ "Error : File is empty."
#define _ERROR_INVALID_DATA_ "Error : The data in the file is incorrect."
#define _ERROR_INVALID_YEAR_ "Error : Year does not match"
#define _ERROR_INVALID_MONTH_ "Error : Month does not match"
#define _ERROR_INVALID_DAY_ "Error : Day does not match"
#define _ERROR_INVALID_COIN_ "Error : BitCoin does not match"


#include <iostream>
#include <iterator>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

namespace mstd
{
	class ExpHandler : public std::exception
	{
	private:
		std::string err;
	public:
		ExpHandler() throw() {}
		ExpHandler(const std::string& err) throw() : err(err)
		{}
		const char * what() const throw()
			{ return err.c_str(); }
		~ExpHandler() throw() {}
	};
};

class BitcoinExchange
{
private:
	static std::map<std::string, double> MAP;
	static std::string value;
	static std::string key;

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator= (const BitcoinExchange& other);
	~BitcoinExchange();

private:
	static void creat_cal(std::map<int,int>& cal);
	static bool validCharacters(const std::string& str);
	static bool validData(const std::string& str, std::map<int,int> &cal);
	static bool is_all_num(const std::string& coin, int flag);

public:

	static void dbData(std::string FileName);
	static void validinput(std::string FileName);
};

#endif