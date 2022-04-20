#include <string>
#include <iomanip>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor Called" << std::endl;
	this->_stock = 0;
	return;
}

Fixed::Fixed( Fixed const & cp )
{
	std::cout << "Copy constructor Called" << std::endl;
	*this = cp;
	return;
}

Fixed::~Fixed( void )
{
	std::cout << "Destuctor Called" << std::endl;
	return;
}

Fixed & Fixed::operator=(Fixed const & bambi)
{
	std::cout << "Copy assignement operator Called" << std::endl;
	this->_stock = bambi.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "GetRawBits member function Called" << std::endl;
	return(this->_stock);
}

void	Fixed::setRawBits( int const raw )
{
	this->_stock = raw;
}

int const Fixed::_cstock = 0;
