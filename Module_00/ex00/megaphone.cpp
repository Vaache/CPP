#include <iostream>

int main(int ac, char **av)
{
	int	i = 0;
	int	j;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	while (av && av[++i])
	{
		j = 0;
		if (i > 1)
			std::cout << " ";
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				std::cout << (char)toupper(av[i][j]);
			else 
				std::cout << av[i][j];
			j++;
		}
	}
	std::cout << std::endl;
	return 0;
}
