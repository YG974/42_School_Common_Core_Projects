#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>

class Base
{
	public :
		virtual ~Base ( void );
};

Base::~Base ( void )
{
	std::cout << "Base destructor called." << std::endl;
	return ;
}

class A : public Base { };
class B : public Base { };
class C : public Base { };

Base * generate(void)
{
	int index = rand() % 3;

	if (index == 0)
		return ( new A );
	if (index == 1)
		return ( new B );
	if (index == 2)
		return ( new C );
	std::cout << "Random number generation failed" << std::endl;
	return (NULL);
}

void identify(Base* p)
{
	Base	*tmp;

	if ( (tmp = dynamic_cast<A*>(p)) != NULL )
		std::cout << "A" << std::endl;
	else if ( (tmp = dynamic_cast<B*>(p)) != NULL )
		std::cout << "B" << std::endl;
	else if ( (tmp = dynamic_cast<C*>(p)) != NULL )
		std::cout << "C" << std::endl;
	return ;
}

void identify(Base& p)
{
	try
	{
		A	&x = dynamic_cast<A&>(p);
		(void)x;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		(void)e;
	}
	try
	{
		B	&x = dynamic_cast<B&>(p);
		(void)x;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception &e)
	{
		(void)e;
	}
	try
	{
		C	&x = dynamic_cast<C&>(p);
		(void)x;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
		(void)e;
	}
}

int main ( void )
{
	std::cout << "---From pointers without random---" << std::endl;

	A	a;
	B	b;
	C	c;

	identify(&a);
	identify(&b);
	identify(&c);

	std::cout << std::endl;
	std::cout << "---From references without random---" << std::endl;

	A &refa = a;
	B &refb = b;
	C &refc = c;

	identify(refa);
	identify(refb);
	identify(refc);

	std::cout << std::endl;
	std::cout << "--- RANDOM ---" << std::endl;
	
	Base	*random[10];

	for ( int i = 0 ; i < 10  ; i++ )
		random[i] = generate();
	for ( int i = 0 ; i < 10 ; i++ )
	{
		std::cout << i + 1 << " - ";
		identify(random[i]);
	}
	std::cout << std::endl;
	std::cout << "---Destructors---" << std::endl;
	for ( int i = 0 ; i < 10  ; i++ )
		delete random[i];

	return (0);
}
