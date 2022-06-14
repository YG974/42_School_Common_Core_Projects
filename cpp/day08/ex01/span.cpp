#include <exception>
#include <algorithm>
#include <vector>
#include "span.hpp"

/*
 * init Constructor
*/
Span::Span ( unsigned int size ) :  _size ( size )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Span init Constructor called." << std::endl; */
	/* std::cout << "Size : " << this->_size << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

/*
 * Copy Constructor
 */
Span::Span ( Span const & src ) : _container ( src._container ), _size ( src._size )
{
	/* std::cout << "----------------------------------" << std::endl; */
	/* std::cout << "Span copy Constructor called." << std::endl; */
	/* std::cout << "Size : " << this->_size << std::endl; */
	/* std::cout << "----------------------------------" << std::endl; */
	return ;
}

/*
 * Assignement operator
 */
Span&	Span::operator=(const Span& src)
{
	this->_size = src._size;
	this->_container = src._container;

	return (*this);
}



/*
 * Default Destructor
 */
Span::~Span()
{
	std::cout << "Span Destructor called. Span size was "<< this->_size << std::endl;
	return ;
}

// Getters
unsigned int Span::getSize( void ) const
{
	return ( this->_size ) ;
}

void Span::addNumber (unsigned int new_nb)
{
	try
	{
		if (this->_container.size() >= this->getSize())
			throw Span::FullContainerException();
		this->_container.push_back( new_nb );
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	return ;
}

void Span::addNumbers ( void )
{
	try
	{
		if (this->_container.size() >= this->getSize())
			throw Span::FullContainerException();
		while (this->_container.size() < this->getSize())
		{
			this->_container.push_back( rand() % 14200 );
		}
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	return ;
}

void Span::printValues ( void )
{
	std::cout << "Values in container :" << std::endl;
	std::cout << "---------------------" << std::endl;
	for (int i = 0 ; i < (int)this->_container.size() ; i++ )
		std::cout << i << " - \'" << _container[i] << "\'" << std::endl;
}

unsigned int Span::shortestSpan( void )
{
	try
	{
		if ( this->_container.size() < 2 )
			throw Span::EmptyContainerException();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	std::sort ( this->_container.begin(), this->_container.end());

	int min_span = this->_container[1] - this->_container[0] ;
	for ( int i = 0 ; i + 1 < (int)this->getSize() ; i++ )
	{
		if ( (_container[i + 1] - _container[i]) < min_span )
			min_span = _container[i + 1] - _container[i];
	}
	return ( min_span );
}

unsigned int Span::longestSpan( void )
{
	unsigned int max = *std::max_element( _container.begin(), _container.end());
	unsigned int min = *std::min_element( _container.begin(), _container.end());
	try
	{
		if ( this->_container.size() < 2 )
			throw Span::EmptyContainerException();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	return ( max - min );
}
