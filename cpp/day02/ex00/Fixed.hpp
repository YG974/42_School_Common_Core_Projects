#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class	Fixed
{
	private :

		int					_nb;
		static const int	_bits_nb = 8;

	public :

		// SETTER
		void	setRawBits ( int const raw );

		// GETTER
		int		getRawBits ( void ) const;

		// Operators overload
		Fixed & operator= ( Fixed const &src );

		// Constructor & Destructor
		Fixed ( const Fixed &src );		// Copy Constructor
		Fixed ( int nb );				// Init Constructor
		Fixed();						// Default Constructor
		~Fixed();						// Destructor

};

#endif
