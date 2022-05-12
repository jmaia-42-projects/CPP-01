/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:50:35 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/12 12:33:47 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

static void	testHorde(int N, std::string name);

int	main(void)
{
	std::cout << "--- Creating zombie on Stack and annoucing it... ---" << std::endl;
	Zombie	stackZombie = Zombie("Alice");
	stackZombie.announce();

	std::cout << "--- Creating zombie on Heap and announcing it... ---" << std::endl;
	Zombie	*heapZombie = newZombie("Bob");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "--- Let the zombie do everything, this is randomChump... ---" << std::endl;
	randomChump("Carol");

	/*	*** Ex01 => Moar brainz! *** */
	std::cout << std::endl;
	std::cout << "----- Moar brainz! -----" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Creating normal horde ---" << std::endl;
	testHorde(3, "Alice");

	std::cout << "--- Creating solo horde ---" << std::endl;
	testHorde(1, "Bob");

	std::cout << "--- Creating empty horde ---" << std::endl;
	testHorde(0, "Carol");

	std::cout << "--- Creating negative horde ---" << std::endl;
	testHorde(-1, "Dave");
}

static void	testHorde(int N, std::string name)
{
	Zombie	*horde;

	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
