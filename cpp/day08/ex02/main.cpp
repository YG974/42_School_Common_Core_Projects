#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>
#include <list>
#include <deque>
#include <stack>

#include "mutantstack.hpp"

int main()
{
	std::cout << "\n--- Main from the subject ---\n" << std::endl;


	/* test push */
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack top" << std::endl;
	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mstack size" << std::endl;
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...] mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;

	--it;

	std::cout << "Print values with iterators" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;

		++it;
		std::stack<int> s(mstack);
	}

	std::cout << "\n--- const iterator with one new value ---\n" << std::endl;
	mstack.push(12);
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();

	++cit;

	--cit;

	while (cit != cite)
	{
		std::cout << *cit << std::endl;

		++cit;
		std::stack<int> s(mstack);
	}
	return 0;
}
