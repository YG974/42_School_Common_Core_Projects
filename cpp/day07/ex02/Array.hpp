#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>

template <typename T>
class Array
{

	private:

	T				*_array;
	unsigned int	_len;

	public:

	// Constructor
	// Default
	Array ( void );
	// Init
	Array ( unsigned int n );
	// Copy
	Array ( const Array & src );
	// Assignation
	Array & operator= ( const Array & src );

	// Destructor
	~Array ( void );
	
	// Operator[] / Subscript operator
	T & operator[] (unsigned int index) const;

		class OutRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Operator[Index] -> Index is out of range !");
			}
	};

	// Getter
	unsigned int size ( void ) const;

};

template <typename T>
Array<T>::Array( void ) : _array( NULL ), _len( 0 )
{ return ; }

template <typename T>
Array<T>::Array( unsigned int n ) : _array( new T[n]()), _len( n )
{ return ; }

template <typename T>
Array<T>::Array( const Array & src) : _array( NULL ), _len( src._len )
{
	if ( src._len > 0 )
	{
		this->_array = new T[src._len];
		for ( unsigned int i = 0 ; i < src._len ; i++ )
			this->_array[i] = src._array[i];
	}
	return ;
}

template <typename T>
Array<T> & Array <T>::operator= ( const Array & src )
{
	if ( this->_array != NULL )
		delete [] this->_array;
	this->_len = src._len;
	if ( src._len > 0 )
	{
		this->_array = new T[src._len];
		for ( unsigned int i = 0 ; i < src._len ; i++ )
			this->_array[i] = src._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	delete [] this->_array;
	return ;
}

template <typename T>
T & Array<T>::operator[] (unsigned int index) const
{
	if ( index < 0 || index >= this->_len )
	{
		std::cout << "Array size : " << this->_len << "." << std::endl;
		std::cout << "Index : " << index << "." << std::endl;
		throw Array<T>::OutRangeException();
	}
	else
		return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size ( void ) const
{
	return ( this->_len );
}
