/* ************************************************************************** */
/* ygeslin                                                                    */
/* STACK.HPP                                                                 */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

/* #include <memory> */
#include <cstddef>	//for ptrdiff_t
#include <iterator>
#include <iostream>
#include <map>
#include <memory>
#include "vector.hpp"
/* #include <utility> */
/* #include "utils.hpp" */
/* #include "iterators.hpp" */

namespace ft
{

	template <class T, class Container = ft::vector<T> >
		class stack {
			public:
				typedef typename Container::value_type value_type;
				typedef typename Container::size_type size_type;
				typedef          Container container_type;
			protected:
				Container c;
			public:
				explicit stack(const Container& c = Container())
					: c( c ) {}

				bool      empty() const { return c.empty(); }
				size_type size()  const { return c.size(); }
				value_type&       top() { return c.back(); }
				const value_type& top() const { return c.back(); }
				void push(const value_type& x) { c.push_back(x); }
				void pop() { c.pop_back(); }

				friend bool operator ==(const stack &lhs, const stack &rhs)
				{ return (lhs.c == rhs.c); };
				friend bool operator !=(const stack &lhs, const stack &rhs)
				{ return (lhs.c != rhs.c); };

				template <class T2, class Container2>
					friend bool operator== (const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);

				template <class T2, class Container2>
					friend bool operator!= (const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);

				template <class T2, class Container2>
					friend bool operator< (const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);

				template <class T2, class Container2>
					friend bool operator<= (const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);

				template <class T2, class Container2>
					friend bool operator> (const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);

				template <class T2, class Container2>
					friend bool operator>= (const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);
		};


	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c > rhs.c;
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c <= rhs.c;
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c >= rhs.c;
	}


} // ft namespace

#endif
