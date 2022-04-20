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
		~Fixed( void );
		Fixed &	operator=(Fixed const & bambi);
		int		getRawBits ( void ) const;
		void	setRawBits ( int const raw );
	private:
		int					_stock;
		int const static	_cstock;
};

#endif
