/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:24:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/17 16:11:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

#define DEBUG_LEVEL 0
#define INFO_LEVEL 1
#define WARNING_LEVEL 2
#define ERROR_LEVEL 3

int	main(int ac, char **av)
{
	Harl		harl;
	int			level;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <LEVEL>" <<  std::endl;
		return (1);
	}
	level = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == av[1])
			level = i;
	}
	switch (level)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
