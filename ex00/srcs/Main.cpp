/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:50:35 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/12 12:08:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

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
}
