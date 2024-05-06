#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::string str = "Hello World";
	std::string::iterator it = str.begin();
	for (; it != str.end(); ++ it)
		std::cout << *it;

	std::cout << std::endl;
	std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
	std::vector<int>::iterator it1 = arr.begin();
	advace(it1, 3);
	for (; it1 != arr.end(); ++ it1)
		std::cout << *it1;
}