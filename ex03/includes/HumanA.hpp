/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:35:18 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/13 07:11:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon		*weapon;
		std::string	name;
	public:
		HumanA(std::string name, Weapon &weapon);

		void	setWeapon(Weapon &weapon);

		void	attack(void);
};

#endif
