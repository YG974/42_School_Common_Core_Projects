#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
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
		float	toFloat ( void ) const;
		int		toInt ( void ) const;

		// Operators overload
		Fixed & operator= ( Fixed const &src );

		// Constructor & Destructor
		Fixed ( const Fixed &src );		// Copy Constructor
		Fixed ( const int nb );			// Int Constructor
		Fixed ( const float nb );		// Float Constructor
		Fixed();						// Default Constructor
		~Fixed();						// Destructor

};

// std ostream Overload << operator
std::ostream & operator<< (std::ostream & o, Fixed const &src);

#endif
