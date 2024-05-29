#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <float.h>
#include <cstring>

class Converter 
{
    public:
        Converter( void );
        Converter(std::string str);
        Converter(const Converter &rhs);
        Converter& operator=(const Converter &rhs);
        ~Converter( void );

        bool    convert(std::string str);

        bool    checkInt(std::string str);
        bool    checkFloat(std::string str);
        bool    checkDouble(std::string str);

        bool    checkFloatPseudo(std::string str);
        bool    checkDoublePseudo(std::string str);


    private:
        char        _c;
        long int    _i;
        float       _f;
        double      _d;

        std::string     _str;
        unsigned int    _strlen;

};

std::ostream& operator<<( std::ostream &o, const Converter &rhs );

#endif