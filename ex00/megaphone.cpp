#include <iostream>
#include <string>

void ft_strupper(char *str)
{
	while (*str)
	{
		*str = std::toupper(*str);
		str++;
	}
}

int main(int ac , char **av)
{ 
	if (ac < 2)
		return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *", 0;	
	for(int i = 1; i < ac ; i++)
	{	
		ft_strupper(av[i]);
		std::cout << av[i] ;
	}
	return 0;
}