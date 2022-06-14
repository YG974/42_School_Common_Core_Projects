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
		// Overload assignation
		Fixed & operator= ( Fixed const &src );

		// Overload comparison / relational operators
		bool operator> ( const Fixed &src ) const;
		bool operator< ( const Fixed &src ) const;
		bool operator>= ( const Fixed &src ) const;
		bool operator<= ( const Fixed &src ) const;
		bool operator== ( const Fixed &src ) const;
		bool operator!= ( const Fixed &src ) const;

		// Overload arythmetic operators
		Fixed operator+ ( const Fixed &src ) const;
		Fixed operator- ( const Fixed &src ) const;
		Fixed operator* ( const Fixed &src ) const;
		Fixed operator/ ( const Fixed &src ) const;

		// Overload increment operators
		// preincrement
		Fixed operator++ ();
		// postincrement
		Fixed operator++ ( int i );
		// predecrement
		Fixed operator-- ();
		// postdecrement
		Fixed operator-- ( int i );

		// Static min/max functions
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );
		static  const Fixed &min( Fixed &a,  Fixed &b );
		static  const Fixed &max( Fixed &a,  Fixed &b );

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
