/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:25 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/13 07:12:52 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanA::attack(void)
{
	std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
}
