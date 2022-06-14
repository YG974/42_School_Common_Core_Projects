#include "Fixed.hpp"

int		Fixed::getRawBits ( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb);
}

void	Fixed::setRawBits ( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw;
	return ;
}

/*
 * Assignation operator
 */
Fixed & Fixed::operator=( Fixed const &src )
{
	std::cout << "Assignation operator called." << std::endl;
	this->_nb = src.getRawBits();
	return (*this);
}

/*
 * Copy Constructor
 */
Fixed::Fixed( const Fixed &source )
{
	std::cout << "Copy Constructor called." << std::endl;
	this->_nb = source.getRawBits();
	return ;
}

/*
 * Init Constructor
 */
Fixed::Fixed( int nb ) : _nb ( nb )
{
	std::cout << "Fixed init Constructor called. nb = ";
	std::cout << this->_nb << "." << std::endl;
	return ;
}


/*
 * Default Constructor
 */
Fixed::Fixed()
{
	this->_nb = 0;
	std::cout << "Default constructor called." << std::endl;
	return ;
}

/*
 * Default Destructor
 */
Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

