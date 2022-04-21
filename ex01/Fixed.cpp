#include <string>
#include <iomanip>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void )
{
	std::cout << "Default constructor Called" << std::endl;
	this->_stock = 0;
	return;
}

Fixed::Fixed( int const i )
{
	std::cout << "Int constructor called" << std::endl;
	this->_stock = i << this->_cstock;
	return;
}

Fixed::Fixed( float const f )
{
	std::cout << "Float constructor called" << std::endl;
	this->_stock = roundf(f  * ( 1 << this->_cstock ) );
	std::cout << this->_stock << std::endl;
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

std::ostream & operator<<( std::ostream & os, Fixed const & mo )
{
	os << mo.toFloat();
	return os;
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

int	Fixed::toInt( void ) const
{
	return ( (int)this->_stock >> this->_cstock );
}


float	Fixed::toFloat( void ) const
{
	return ( (float)this->_stock / ( 1 << this->_cstock ) );
}

int const Fixed::_cstock = 8;
