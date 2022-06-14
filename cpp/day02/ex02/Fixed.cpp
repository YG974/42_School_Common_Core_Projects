#include "Fixed.hpp"
#include <cmath>

int		Fixed::getRawBits ( void ) const
{
	/* std::cout << "getRawBits member function called" << std::endl; */
	return (this->_nb);
}

void	Fixed::setRawBits ( int const raw )
{
	/* std::cout << "setRawBits member function called" << std::endl; */
	this->_nb = raw;
	return ;
}

int		Fixed::toInt ( void ) const
{
	return ( this->_nb >> this->_bits_nb );
}

float	Fixed::toFloat ( void ) const
{
	return ( (float)this->_nb / (float)( 1 << this->_bits_nb ) );
}

// Overload comparison / relational Fixed::operators
bool Fixed::operator> ( const Fixed &src ) const
{
	return ( _nb > src._nb );
}

bool Fixed::operator< ( const Fixed &src ) const
{
	return ( _nb < src._nb );
}

bool Fixed::operator>= ( const Fixed &src ) const
{
	return ( _nb >= src._nb );
}

bool Fixed::operator<= ( const Fixed &src ) const
{
	return ( _nb <= src._nb );
}

bool Fixed::operator== ( const Fixed &src ) const
{
	return ( _nb == src._nb );
}

bool Fixed::operator!= ( const Fixed &src ) const
{
	return ( _nb != src._nb );
}

// Overload arythmetic Fixed::operators
Fixed Fixed::operator+ ( const Fixed &src ) const
{
	return ( _nb + src._nb );
}

Fixed Fixed::operator- ( const Fixed &src ) const
{
	return ( _nb - src._nb );
}

Fixed Fixed::operator* ( const Fixed &src ) const
{
	return ( toFloat() * src.toFloat() );
}

Fixed Fixed::operator/ ( const Fixed &src ) const
{
	return ( toFloat() / src.toFloat() );
}

// Overload increment Fixed::operators
// preincrement
Fixed Fixed::operator++ ()
{
	_nb++;
	return (*this);
}

// postincrement
Fixed Fixed::operator++ ( int i )
{
	(void)i;
	Fixed initial_nb = *this;
	_nb++;
	return (initial_nb);
}

// predecrement
Fixed Fixed::operator-- ()
{
	_nb--;
	return (*this);
}

// postdecrement
Fixed Fixed::operator-- ( int i )
{
	(void)i;
	Fixed initial_nb = *this;
	_nb--;
	return (initial_nb);
}

// Static min/max functions
const Fixed &Fixed::min( const Fixed &a, const Fixed &b )
{
	if ( a._nb < b._nb )
		return ( a );
	return ( b );
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a._nb > b._nb)
		return ( a );
	return ( b );
}

const Fixed &Fixed::min( Fixed &a,  Fixed &b )
{
	if ( a._nb < b._nb )
		return ( a );
	return ( b );
}

const Fixed &Fixed::max( Fixed &a,  Fixed &b )
{
	if (a._nb > b._nb)
		return ( a );
	return ( b );
}

/*
 * Assignation operator
 */
Fixed & Fixed::operator=( Fixed const &src )
{
	/* std::cout << "Assignation operator called." << std::endl; */
	this->_nb = src.getRawBits();
	return (*this);
}

/*
 * Copy Constructor
 */
Fixed::Fixed( const Fixed &source )
{
	/* std::cout << "Copy Constructor called." << std::endl; */
	*this = source;
	return ;
}

/*
 * Float Constructor
 */
Fixed::Fixed( const float nb )
{
	/* std::cout << "Float Constructor called." << std::endl; */

	this->_nb = roundf( nb * ( 1 << this->_bits_nb) );
	return ;
}

/*
 * Int Constructor
 */
Fixed::Fixed( const int nb )
{
	/* std::cout << "Int Constructor called." << std::endl; */

	this->_nb = ( nb << this->_bits_nb);
	return ;
}

/*
 * Default Constructor
 */
Fixed::Fixed()
{
	this->_nb = 0;
	/* std::cout << "Default constructor called." << std::endl; */
	return ;
}

/*
 * Default Destructor
 */
Fixed::~Fixed()
{
	/* std::cout << "Default destructor called" << std::endl; */
	return ;
}

/*
 * std ostream overload operator <<
 */
std::ostream & operator<< (std::ostream & o, Fixed const &src)
{
	/* std::cout << "Overload << operator called." << std::endl; */
	return ( o << src.toFloat() );
}

