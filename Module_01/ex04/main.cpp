/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:57:17 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/09 17:11:14 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "You did not enter 3 arguments" << std::endl;
		return 1;
	}

	std::ifstream	inFIle(argv[1]);
	std::string		line;

	if (!inFIle)
	{
		std::cout << "cant open the file " << std::endl;
		return 1;
	}
	std::string name = argv[1];
	std::ofstream outFile(name + ".replace");
	size_t pos = 0;

	while (getline(inFIle, line))
	{
		while ((pos = line.find(argv[2], pos)) != std::string::npos)
		{
			line.erase(pos, strlen(argv[2]));
			line.insert(pos, argv[3]);
			pos += strlen(argv[3]);
		}
		outFile << line << std::endl;
		pos = 0;
	}
	return 0;
}