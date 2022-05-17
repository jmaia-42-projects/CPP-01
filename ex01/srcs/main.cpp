/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:50:35 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/17 16:14:16 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

static void	testHorde(int N, std::string name);

int	main(void)
{
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
