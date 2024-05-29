#include "Converter.hpp"

Converter::Converter(void) : _c('\0'), _i(0), _f(0.0f), _d(0.0)
{}

Converter::Converter( const Converter &rhs)
{
    *this = rhs;
}

Converter& Converter::operator=(const Converter &rhs)
{
    (void)rhs;
    return *this;
}

Converter::~Converter(void)
{}

bool        Converter::checkInt(std::string str)
{
    unsigned int i = 0;

    if (str[0] == '+' || str[0] == '-')
        i++;
    while (i < _strlen)
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool        Converter::checkFloat(std::string str)
{
    unsigned int i = 0;
    int point = 0;

    if (str[_strlen - 1] != 'f')
        return (false);
    if (str[0] == '+' || str[0] == '-')
        i++;
    while (i < _strlen - 1)
    {
        if (str[i] == '.')
			point++;
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		i++;
    }
    if (point > 1)
        return (false);
    return (true);    
}

bool        Converter::checkFloatPseudo(std::string str)
{
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return (true);
    return (false);
}

bool        Converter::checkDouble(std::string str)
{
    unsigned int i = 0;
    int point = 0;

    if (str[0] == '+' || str[0] == '-')
        i++;
    while (i < _strlen)
    {
        if (str[i] == '.')
			point++;
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		i++;
    }
    if (point > 1)
        return (false);
    if (std::atoi(str.c_str()) > 2147483647 || std::atoi(str.c_str()) < -2147483648)
        return (false);
    return (true);    
}

bool        Converter::checkDoublePseudo(std::string str)
{
    if (str == "nan" || str == "-inf" || str == "+inf")
        return (true);
    return (false);
}

bool        Converter::convert(std::string _str)
{
    if (_strlen == 1 && !isdigit(_str[0]))
    {
        _c = _str[0];
		_i = static_cast<long>(_c);
		_d = static_cast<double>(_c);
		_f = static_cast<float>(_c);
    }
    else if (checkInt(_str) == true)
    {
        _i = std::atoi(_str.c_str());
		_c = static_cast<char>(_i);
		_d = static_cast<double>(_i);
		_f = static_cast<float>(_i);
    }
    else if (checkFloat(_str) == true || checkFloatPseudo(_str) == true)
    {
        _f = std::atof(_str.c_str());
		_c = static_cast<char>(_f);
		_i = static_cast<long>(_f);
		_d = static_cast<double>(_f);
    }
    else if (checkDouble(_str) == true || checkDoublePseudo(_str) == true)
    {
        _d = std::atof(_str.c_str());
		_c = static_cast<char>(_d);
		_i = static_cast<long>(_d);
		_f = static_cast<float>(_d);
    }
    else
        return (false);
    return (true);
}

Converter::Converter(std::string str) : _str(str)
{
    _strlen = str.length();

    if ( convert(_str) )
    {
        if(isprint(_c) && _i > 0 && _i < 127)
            std::cout << "char: '" << _c << "'" << std::endl;
		else if (_i < 0 || _i >= 127)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(_c))
			std::cout << "char: Non displayable" << std::endl;
		if (checkDoublePseudo(_str) == true || checkFloatPseudo(_str) == true)
			std::cout << "int: impossible" << std::endl;
        else if (INT_MAX < std::atof(_str.c_str()) || INT_MIN > std::atof(_str.c_str()))
            std::cout << "int: impossible(overflow)" << std::endl;
		else
			std::cout << "int: " << _i << std::endl;
        if ((INT_MAX < std::atof(_str.c_str()) || INT_MIN > std::atof(_str.c_str())) && (checkFloatPseudo(_str) != true && checkDoublePseudo(_str) != true))
        {
            std::cout <<  "float: impossible(overflow)" << std::endl;
		    std::cout << "double: impossible(oveflow)" << std::endl;
        }
        else if (_i != (int)_f && (checkFloatPseudo(_str) != true && checkDoublePseudo(_str) != true))
        {
            std::cout <<  "float: impossible(overflow)" << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "double: " << _d << std::endl;
        }
        else
        {
            if (_str == "+inff" || _str == "+inf")
            {
                std::cout << std::fixed << std::setprecision(1) << "float: +" << _f << "f" << std::endl;
     	    	std::cout << std::fixed << std::setprecision(1) << "double: +" << _d << std::endl;
            }
            else
            {
                std::cout << std::fixed << std::setprecision(1) << "float: " << _f << "f" << std::endl;
    		    std::cout << std::fixed << std::setprecision(1) << "double: " << _d << std::endl;
            }
        }
    }
    else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}