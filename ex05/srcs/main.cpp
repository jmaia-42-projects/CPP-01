/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:24:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/17 15:36:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

int	main(void)
{
	Harl	harl;

	std::cout << "-- DEBUG MODE --" << std::endl;
	harl.complain(std::string("DEBUG"));
	std::cout << "-- INFO MODE --" << std::endl;
	harl.complain(std::string("INFO"));
	std::cout << "-- WARNING MODE --" << std::endl;
	harl.complain(std::string("WARNING"));
	std::cout << "-- ERROR MODE --" << std::endl;
	harl.complain(std::string("ERROR"));
	std::cout << "-- UNKNOWN MODE --" << std::endl;
	harl.complain(std::string("UNKNOWN"));
}
