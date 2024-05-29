#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

template<class T>
class Array
{
    private:
        
        T*              _array;
        unsigned int    _size;
        
    public:

        Array( void );
        Array(unsigned int n);
        Array(const Array &rhs);
        Array<T> &operator=(const Array &rhs);
	    ~Array();

        T &operator[](unsigned int i) const
        {
            if (i >= _size || i < 0)
                throw OutException();
            return (_array[i]);
        }

        unsigned int    size() const
        {
            return (_size);
        }

        class OutException : public std::exception
        {
        public:
            virtual const char* what() const throw() { return "Index is not in the array";}
        };


};

template<class T>
Array<T>::Array(void)
{
    _size = 0;
    _array = new T();   
}

template<class T>
Array<T>::Array(unsigned int n)
{
    _size = n;
    _array = new T[n];
}

template <class T>
Array<T>::Array(const Array &rhs)
{
    *this = rhs;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	unsigned int i = 0;

    if (this != &rhs)
    {
        delete [] _array;
        _size = rhs._size;
        _array = new T[_size];
	    while (i < _size)
	    {
            _array[i] = rhs._array[i];
		    i++;
	    }
    }
    return (*this);
}

template <class T>
Array<T>::~Array()
{
	delete[] _array;
}

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr )
{
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}

#endif