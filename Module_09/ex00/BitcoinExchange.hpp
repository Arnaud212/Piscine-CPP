/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:03:52 by agiraud           #+#    #+#             */
/*   Updated: 2023/12/15 17:03:34 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <cstdlib>
# include <cstring>

class BitcoinExchange
{
    private:
        std::map < std::string, float > _database;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &rhs);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        void storeData();
        void readFile(char *argv);
        bool checkDate(std::string date);
        float checkValue(std::string value);
        void printOutput(std::string date, float value);

};

#endif