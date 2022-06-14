#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <cfloat>
#include <list>

#include "span.hpp"

int main()
{
	std::cout << "\n--- Main from the subject ---\n" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest Span :" << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span :" << sp.longestSpan() << std::endl;

	std::cout << "\n--- My main 10 integers ---\n" << std::endl;
	Span x = Span(10);
	x.addNumber(14);
	x.addNumber(4);
	x.addNumber(3);
	x.addNumbers();
	x.printValues();

	std::cout << "Shortest Span :" << x.shortestSpan() << std::endl;
	std::cout << "Longest Span :" << x.longestSpan() << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "Try to add number 3" << std::endl;
	std::cout << "--------------------" << std::endl;
	x.addNumber(3);

	std::cout << "\n--- My main 14 200 integers ---\n" << std::endl;
	Span y = Span(14200);
	y.addNumbers();
	y.printValues();
	std::cout << "Shortest Span :" << y.shortestSpan() << std::endl;
	std::cout << "Longest Span :" << y.longestSpan() << std::endl;

}
