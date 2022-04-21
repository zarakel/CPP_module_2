#include <string>
#include <iomanip>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void )
{
	this->_stock = 0;
	return;
}

Fixed::Fixed( int const i )
{
	this->_stock = i << this->_cstock;
	return;
}

Fixed::Fixed( float const f )
{
	this->_stock = roundf(f  * ( 1 << this->_cstock ) );
	return;
}


Fixed::Fixed( Fixed const & cp )
{
	*this = cp;
	return;
}

Fixed::~Fixed( void )
{
	return;
}

Fixed & Fixed::operator=(Fixed const & bambi)
{
	this->_stock = bambi._stock;
	return *this;
}

Fixed  Fixed::operator++( void )
{
	this->_stock += roundf(0.00390625 * ( 1 << this->_cstock ) );
	return *this;
}

Fixed  Fixed::operator++( int )
{
	Fixed result = *this;
	this->_stock += roundf(0.00390625 * ( 1 << this->_cstock ));
	return result;
}

Fixed  Fixed::operator--( void )
{
	this->_stock -= roundf(0.00390625 * ( 1 << this->_cstock ) );
	return *this;
}

Fixed  Fixed::operator--( int )
{
	Fixed result = *this;

	this->_stock -= roundf(0.00390625 * ( 1 << this->_cstock ));
	return result;
}

Fixed  Fixed::operator+(Fixed const & bambi) const
{
	Fixed result;

	result._stock = this->_stock + bambi._stock;
	return result;
}

Fixed  Fixed::operator-(Fixed const & bambi) const
{
	Fixed result;

	result._stock = this->_stock - bambi._stock;
	return result;
}

Fixed  Fixed::operator*(Fixed const & bambi) const
{
	Fixed result;

	result._stock = (this->_stock * bambi._stock) >> this->_cstock;
	return result;
}

Fixed  Fixed::operator/(Fixed const & bambi) const
{
	Fixed result;

	result._stock = this->_stock / bambi._stock;
	return result;
}

Fixed  Fixed::operator<(Fixed const & bambi) const
{
	if (this->_stock < bambi._stock)
		return 1;
	return 0;
}

Fixed  Fixed::operator>(Fixed const & bambi) const
{
	if (this->_stock > bambi._stock)
		return 1;
	return 0;
}

Fixed  Fixed::operator>=(Fixed const & bambi) const
{
	if (this->_stock >= bambi._stock)
		return 1;
	return 0;
}

Fixed  Fixed::operator<=(Fixed const & bambi) const
{
	if (this->_stock <= bambi._stock)
		return 1;
	return 0;
}

Fixed  Fixed::operator==(Fixed const & bambi) const
{
	if (this->_stock == bambi._stock)
		return 1;
	return 0;
}

Fixed  Fixed::operator!=(Fixed const & bambi) const
{
	if (this->_stock != bambi._stock)
		return 1;
	return 0;
}

std::ostream & operator<<( std::ostream & os, Fixed const & mo )
{
	os << mo.toFloat();
	return os;
}

int	Fixed::getRawBits( void ) const
{
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

Fixed	Fixed::min( Fixed A, Fixed B )
{
	if (A._stock <= B._stock)
		return A;
	else
	return B;
}

Fixed const	Fixed::minConst( Fixed const A, Fixed const B )
{
	if (A._stock <= B._stock)
		return A;
	else
	return B;
}

Fixed	Fixed::max( Fixed A, Fixed B )
{
	if (A._stock > B._stock)
		return A;
	else
	return B;
}

Fixed const	Fixed::maxConst( Fixed const A, Fixed const B )
{
	if (A._stock >= B._stock)
		return A;
	else
	return B;
}

int const Fixed::_cstock = 8;
