#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <string>
# include <iomanip>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & cp );
		Fixed( int const i );
		Fixed( float const f );
		~Fixed( void );

		Fixed &	operator=( Fixed const & bambi );
		Fixed  operator++( void );
		Fixed  operator++( int );
		Fixed  operator--( void );
		Fixed  operator--( int );
		Fixed	operator+( Fixed const & bambi ) const;
		Fixed  operator-(Fixed const & bambi) const;
		Fixed  operator*(Fixed const & bambi) const;
		Fixed  operator/(Fixed const & bambi) const;
		Fixed  operator<(Fixed const & bambi) const;
		Fixed  operator>(Fixed const & bambi) const;
		Fixed  operator>=(Fixed const & bambi) const;
		Fixed  operator<=(Fixed const & bambi) const;
		Fixed  operator==(Fixed const & bambi) const;
		Fixed  operator!=(Fixed const & bambi) const;

		int	getRawBits ( void ) const;
		void	setRawBits ( int const raw );
		int	toInt( void ) const;
		float	toFloat( void ) const;
		static Fixed		min( Fixed A, Fixed B );
		static Fixed const	minConst( Fixed const A, Fixed const B );
		static Fixed		max( Fixed A, Fixed B );
		static Fixed const	maxConst( Fixed const A, Fixed const B );

		
	private:
		int			_stock;
		int const static	_cstock;
};

std::ostream & 	operator<<( std::ostream & os, Fixed const & mo );


#endif
