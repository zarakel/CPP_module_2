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

		int	getRawBits ( void ) const;
		void	setRawBits ( int const raw );
		float	toFloat( void ) const;
		int	toInt( void ) const;

	private:
		int			_stock;
		int const static	_cstock;
};

std::ostream & operator<<( std::ostream & os, Fixed const & mo );

#endif
