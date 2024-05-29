/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:04:20 by agiraud           #+#    #+#             */
/*   Updated: 2022/09/30 15:38:54 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>


int		main(int argc, char **argv)
{
	std::string	str;
	int			i = 0;
	int			j = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (j < argc)
	{
		i = 0;
		str = argv[j];
		while (str[i])
		{
			str[i] = toupper(str[i]);
			i++;
		}
		std::cout << str;
		str = "\0";
		j++;
	}
	std::cout << std::endl;
	return (0);
}
