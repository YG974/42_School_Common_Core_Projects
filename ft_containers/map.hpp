/* ************************************************************************** */
/* ygeslin                                                                    */
/* MAP.HPP                                                                 */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

/* #include <memory> */
#include <cstddef>	//for ptrdiff_t
#include <iterator>
#include <iostream>
#include <map>
#include <memory>
/* #include <utility> */
#include "utils.hpp"
#include "iterators.hpp"

/* https://www.programiz.com/dsa/binary-search-tree */
namespace ft
{

/*----------------------------------------------------------------------------*/
/* PAIR                                                                       */
/*----------------------------------------------------------------------------*/
	/* page 358 norme iso */

	template <class T1, class T2>
		struct pair
		{
			public :
				typedef T1		first_type;
				typedef T2		second_type;

				T1				first;
				T2				second;

				//default constructor
				pair()
					/* : first( 0 ), second( 0 ) {}; */
					: first(  ), second(  ) {};

				// 2 param constructor
				pair(const T1& x, const T2& y)
					: first( ( x ) ), second( ( y ) ) {};

				// 1 pair param constructor
				template<class U, class V>
					pair(const pair< U, V > &p)
					/* : first( ( x ) ), second( ( y ) ) {}; */
					: first( p.first ), second( p.second ) {};

				// assignation operator
				pair& operator= (const pair& pr)
				{
					first = pr.first;
					second = pr.second;
					return (*this);
				}
				
						 // Key getter
						 const T1 & key ( void ) const
						 { return ( first ); }

						 const T1 & val ( void ) const
						 { return ( second ); }

		};

	/* Pair overload operators */
	/* https://cplusplus.com/reference/utility/pair/operators/ */

	/* == */
	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	/* != */
	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }

	/* < */
	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || 
			( !( rhs.first < lhs.first ) && lhs.second<rhs.second ); }

	/* <= */
	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }

	/* > */
	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs<lhs; }

	/* >= */
	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }

	/* make_pair */
	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{ return ( pair<T1,T2>(x,y) ); }

	/* utility page 361 norme iso */
	/* template <class Arg, class Result> */
	/* 	struct unary_function */ 
	/* 	{ */
	/* 		typedef Arg    argument_type; */
	/* 		typedef Result result_type; */
	/* 	}; */

	/* template <class Arg1, class Arg2, class Result> */
	/* 	struct binary_function */
	/* 	{ */
	/* 		typedef Arg1	 	first_argument_type; */
	/* 		typedef Arg2	 	second_argument_type; */
	/* 		typedef Result		result_type; */
	/* 	}; */


	/* norme iso */ 
	/* page 490 */
	/* https://cplusplus.com/reference/map/map/?kw=map */

template <class Key, class T, class Compare = std::less< Key >,
		 class Allocator = std::allocator<pair<const Key, T> > >
			 class map
			 {
				 typedef pair<const Key, T>			paire;

/*----------------------------------------------------------------------------*/
/* NODE                                                                       */
/*----------------------------------------------------------------------------*/
				 /* template <typename T> */
				 struct node
				 {
					 public:
						 paire						data;

						 int						end;
						 node						*left;
						 node						*right;
						 node						*parent;

					 public :
						 /* constructor */
						 node (paire data) :
							 data(data), end(0),left(0), right(0), parent (0) { };

						 node (paire data, int end, node *left, node *right, node *parent) :
							 data(data), end(end),left(left), right(right), parent (parent) { };

						 // Key getter
						 const Key & key ( void )
						 { return ( data.first ); }

						 // Value getter
						 T & val ( void )
						 { return ( data.second ); }

						 node *min ( void )
						 {
							 node *tmp = &(*this);
						 	while (tmp && tmp->left != 0)
						 		tmp = tmp->left;
						 	return (tmp);
						 }

						 node *max ( void )
						 {
							 node *tmp = &(*this);
						 	/* while (tmp && tmp->right && tmp->end != 1) */
							 /* if (tmp->end == 1) */
								 /* return ++tmp; */
						 	while (tmp && tmp->right != 0 && tmp->right->end != 1)
						 	/* while (tmp && tmp->right != 0 && tmp->end != 1) */
						 		tmp = tmp->right;
						 	return (tmp);
						 }

				 }; //node class

					 /* node *node_min (node *node) */
					 /* { */
						 /* while (node && node->left) */
							 /* node = node->left; */
						 /* return (node); */
					 /* } */

					 /* node *node_max (node *node) */
					 /* { */
						 /* while (node && node->right) */
							 /* node = node->right; */
						 /* return (node); */
					 /* } */
	/* MAP ITERATOR */

		class bi : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef paire					value_type;
			typedef value_type&				reference;
			typedef value_type const &		const_reference;
			typedef value_type*				pointer;
			typedef std::ptrdiff_t			difference_type;
			typedef std::size_t				size_type;
			typedef node					node_type;
			typedef node*					node_ptr;

		protected :
			node_ptr				_node;

		public :
			// 
			// constructor 0 param
			bi ( void ) { return ; };

			// constructor 1 node param
			bi ( node_ptr rhs)
			{
				_node = rhs;
				return ;
			}

			// constructor copy
			bi ( bi const & rhs  )
			{
				*this = rhs;
				return ;
			}

			// assignment constructor
			bi & operator=( bi const & rhs )
			{
				_node = rhs._node ;
				return (*this);
			}

			// destructor 
			virtual ~bi ( void ) { return ; }

			/* ++it */
			bi & operator ++ ( void )
			{
				/* if ( (_node->right) && _node->right->end == 0) */
				if (_node->right)// && _node->right->end == 0)
					_node = (_node->right)->min();
				else if (_node->parent)
				{
					node *tmp = _node;
					_node = _node->parent;
					while ( _node && tmp == _node->right )
					{
						tmp = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/* it++ */
			bi operator ++ (int)
			{
				bi tmp = (*this);
				operator++();
				return ( tmp );
			}

			/* --it */
			bi & operator -- ( void )
			{
				if (_node->left)
					_node = (_node->left)->max();
				else if (_node->parent)
				{
					node *tmp = _node;
					_node = _node->parent;
					while ( _node && tmp == _node->left )
					{
						tmp = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/* it-- */
			bi operator -- (int)
			{
				bi tmp = (*this);
				operator--();
				return ( tmp );
			}

			reference operator * ( void ) const
			{ return reference(_node->data); }

			pointer operator -> ( void ) const
			{ return pointer(&_node->data); }

			/* == */
			bool operator == ( bi const & rhs ) const
			{ return (_node == rhs._node ); }

			/* != */
			bool operator != ( bi const & rhs ) const
			{ return (_node != rhs._node ); }

			template <class, class, class, class>
			friend class map;

			template <class, class>
			friend class map_iterator;

						 /* node* node_min (node* nd) */
						 /* { */
						 /* 	if (nd == 0) */
						 /* 		return (0); */
						 /* 	while (nd && nd->left != 0) */
						 /* 		nd = nd->left; */
						 /* 	return (nd); */
						 /* } */

						 /* node *node_max (node *nd) */
						 /* { */
						 /* 	if (nd == 0) */
						 /* 		return (0); */
						 /* 	while (nd && nd->right != 0) */
						 /* 		nd = nd->right; */
						 /* 	return (nd); */
						 /* } */

	}; // bi class bi = bidirectionnal iterator

	// prevoir overloads de comparaison
		class cbi : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef const paire					value_type;
			typedef value_type&				reference;
			typedef value_type const &		const_reference;
			typedef value_type*				pointer;
			typedef std::ptrdiff_t			difference_type;
			typedef std::size_t				size_type;
			typedef node					node_type;
			typedef node*					node_ptr;

		protected :
			node_ptr				_node;

		public :
			// 
			// constructor 0 param
			cbi ( void ) { return ; };

			// constructor 1 node param
			cbi ( node_ptr rhs)
			{
				_node = rhs;
				return ;
			}

			// constructor from non const iterator
			cbi ( const bi &rhs)
			{
				_node = rhs._node;
				return ;
			}

			// constructor copy
			cbi ( cbi const & rhs  )
			{
				*this = rhs;
				return ;
			}

			// assignment constructor
			cbi & operator=( cbi const & rhs )
			{
				_node = rhs._node ;
				return (*this);
			}

			// destructor 
			virtual ~cbi ( void ) { return ; }

			/* To build a const Iterator from a regular iterator */
			/* operator cbi ( void ) */ 
			/* { */
			/* 	return  const cbi  ( _node ) ; */
			/* } */

			/* ++it */
			cbi & operator ++ ( void )
			{
				/* if ( (_node->right) && _node->right->end == 0) */ 
				if (_node->right)
					_node = (_node->right)->min();
				else if (_node->parent)
				{
					node *tmp = _node;
					_node = _node->parent;
					while ( _node && tmp == _node->right )
					{
						tmp = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/* it++ */
			cbi operator ++ (int)
			{
				cbi tmp = (*this);
				operator++();
				return ( tmp );
			}

			/* --it */
			cbi & operator -- ( void )
			{
				if (_node->left)
					_node = (_node->left)->max();
				else if (_node->parent)
				{
					node *tmp = _node;
					_node = _node->parent;
					while ( _node && tmp == _node->left )
					{
						tmp = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/* it-- */
			cbi operator -- (int)
			{
				cbi tmp = (*this);
				operator--();
				return ( tmp );
			}

			reference operator * ( void ) const
			{ return reference(_node->data); }

			pointer operator -> ( void ) const
			{ return pointer(&_node->data); }

			/* == */
			bool operator == ( cbi const & rhs ) const
			{ return (_node == rhs._node ); }

			/* != */
			bool operator != ( cbi const & rhs ) const
			{ return (_node != rhs._node ); }

			template <class, class, class, class>
			friend class map;

			template <class, class>
			friend class map_iterator;
	};

/*----------------------------------------------------------------------------*/
/* MAP                                                                        */
/*----------------------------------------------------------------------------*/

				 public :
					 // types:
					 typedef Key									key_type;
					 typedef T										mapped_type;
					 typedef pair<const Key, T>						value_type;
					 typedef Compare								key_compare;
					 typedef typename Allocator::template rebind<node>::other	allocator_type;
					 /* typedef Allocator								allocator_type; */
					 typedef typename Allocator::reference			reference;
					 typedef typename Allocator::const_reference	const_reference;
					 typedef typename Allocator::pointer			pointer;
					 typedef typename Allocator::const_pointer		const_pointer;
					 typedef ptrdiff_t								difference_type;
					 typedef size_t									size_type;

					 typedef node									node_type;
					 typedef node_type*								node_ptr;

					 //Iterators
					 typedef bi					iterator;
					 typedef cbi					const_iterator;
					 typedef ft::reverse_iterator<iterator>				reverse_iterator;
					 typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

					 class value_compare : public std::binary_function<value_type,value_type,bool>
				 {
					 friend class map;

					 protected :
					 Compare comp;
					 value_compare(Compare c) : comp(c) {}

					 public:
					 bool operator()(const value_type& x, const value_type& y) const
					 { return comp(x.first, y.first); };
				 }; // value_compare class

				 private :
					 allocator_type				_alloc;

					 // compare
					 key_compare							_cmp;

					 // size
					 size_type								_size;

					 // Nodes
					 node_ptr								_root;
					 node_ptr								_end;
					 
					 node_ptr _new_node(const value_type & value)
					 {
						 node_ptr node = _alloc.allocate(1);
						 _alloc.construct(node, value );
						 node->left  = 0;
						 node->right  = 0;
						 node->parent  = 0;
						 node->end  = 0;
						 return ( node );
					 }

				 public :
					 // 23.3.1.1 construct/copy/destroy:
					 explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
						 : _alloc ( alloc ), _cmp ( comp ), _size ( 0 ), _root ( 0 ), _end ( 0 )
					 { 
						 return ; }

					 template <class InputIterator>
						 map(InputIterator first, InputIterator last,
								 const Compare& comp = Compare(), const Allocator& alloc = Allocator())
						 : _alloc ( alloc ), _cmp ( comp ), _size ( 0 ), _root ( 0 ), _end ( 0 )
						 {
							 insert( first, last );
							 return ;
						 }

					 map(const map<Key,T,Compare,Allocator>& x)
						 :  _size ( 0 ), _root ( 0 ), _end ( 0 )
					 {
						 (*this) = x;
						 return ;
					 }

					 /* destructor */
					 ~map()
					 {
						 clear();
						 if (_root)
							 _alloc.deallocate(_root, _size);
						 if (_end)
							 _alloc.deallocate(_end, 1);
					 }

					 map<Key,T,Compare,Allocator>&
						 operator=(const map<Key,T,Compare,Allocator>& x)
						 {
							 clear();
							 _cmp = x._cmp;
							 _alloc = x._alloc;
							 insert ( x.begin(), x.end() );
							 return (*this);
						 }

					  /* iterators: */

					 // begin
					 iterator begin()
					 { return  iterator (  _root->min()  ) ; }
					 /* { return  iterator (  node_min(_root)) ; } */

					 const_iterator begin()const
					 /* { return const_iterator ( node_min( _root) ); } */
					 { return  const_iterator (  _root->min() ) ; }

					 // end
					 iterator end()
					 { 
							 return (_end);
							 /* return iterator(_end->right); */
							 /* return iterator ( (_root->max())) ; */
						 	/* if (!_root || !size()) */
								/* return iterator(_root->ma()); */
							/* return iterator(_root->max()->right); */
							 /* return iterator ( (_root->max())->right ) ; */
					 }

					 const_iterator end()const
					 {
							 return (_end);
						 	/* if (!_root || !size()) */
								/* return const_iterator(_root->max()); */
							/* return const_iterator(_root->max()->right); */
							/* return ( const_iterator ((_root->max())) ); */
							/* return ( const_iterator (_root->max())->right); */
					 }

					 // rbegin
					 reverse_iterator rbegin()
					 /* { return reverse_iterator (_end->min()); } */
					 /* { return reverse_iterator (_end->max()); } */
					 { return reverse_iterator (_end); }
					 /* { return reverse_iterator (node_max(_end)); } */

					 const_reverse_iterator rbegin() const
					 /* { return const_reverse_iterator (_end->min()); } */
					 /* { return const_reverse_iterator (_end->max()); } */
					 { return const_reverse_iterator (_end); }
					 /* { return const_reverse_iterator (node_max(_end)); } */

					 // rend
					 reverse_iterator rend()
					 { return reverse_iterator (begin()); }

					 const_reverse_iterator rend() const
					 { return const_reverse_iterator (begin()); }

					 /* capacity: */

					 // empty
					 bool empty()const
					 { return  (_size < 1) ; }

					 // size
					 size_type size() const
					 { return ( _size ); }

					 // max_size
					 size_type max_size() const
					 { return ( _alloc.max_size()); }

					 /* element access: */
					 /* https://www.cplusplus.com/reference/map/map/operator[]/ */
					 T& operator[](const key_type& k)
					 {
						 return ((*((this->insert(pair<const Key, T>(k,mapped_type()))).first)).second);
					 }

					 void _set_end( void )
					 {
						 node_ptr tmp = _root->max();
						 /* if (_end) */
							 /* if (_end->parent) */
								 /* _end->parent->right = 0; */

						 if (!_end)
						 {
							 _end = _alloc.allocate(1);
							 _end->right = NULL;
							 _end->left = NULL;
							 // flag to identify sentinel node
							 _end->end = 1;
						 }
						 tmp->right = _end;
						 _end->parent = tmp;
					 }

					 // private insert node function
					 node_ptr _insert(node_ptr node, value_type val)
					 {
						 // more detailed function
						 if (!_root )//|| !node || node == _end)
						 {
							 node = _new_node(val);
							 _root = node;
							 _size++;
						 }
						 else if ( !node || node == _end)
						 {
							 node = _new_node(val);
							 _size++;
							 if (node == _end)
								 node->end = 0;
						 }

						 // initialize the new node before inserting it
						 /* if (!_root || !node || node == _end) */
						 /* { */
							 /* node = _new_node(val); */

							 /* // initialize root node */
							 /* if (!_root) */
								 /* _root = node; */

							 /* _size++; */
						 /* } */
						 // if key to insert is lower than actual node go left
						 else if (key_comp()(val.first, node->key()))
						 {
							 node->left = _insert(node->left, val);
							 node->left->parent = node;
							 node->end = 0;
						 }
						 // if key to insert is higher than actual node go right
						 else
						 {
							 node->right = _insert(node->right, val);
							 node->right->parent = node;
							 node->end = 0;
						 }
						 //move the sentinel node
						 _set_end();
						 return node;

					 }

					 // modifiers:
					 // insert 1
					 pair<iterator, bool> insert(const value_type& val)
					 {
						 pair<iterator, bool>	ret;

						 if (count(val.first))
							 ret.second = false;
						 else
						 {
							 _root = _insert(_root, val);
							 ret.second = true;
						 }
						 ret.first = find(val.first);

						 return ret;
					 }

					 // insert 2
					 iterator insert(iterator position, const value_type& x)
					 { 
						 (void)position;
						 return  iterator(insert(x).first);
					 }

					 // insert 3
					 template <class InputIterator>
						 void insert(InputIterator first, InputIterator last)
						 {
							 while (first != last)
								 insert(*first++);
							 return ;
						 }

					 // private delete node function
					 node_ptr _delete(node_ptr node, value_type val)
					 {
						 node_ptr tmp = 0;
						 // if map empty or end of the map
						 /* if (node->right != _end) */
						/* if ( node == _end ) */
						if (!node || node == _end )
						/* if (!node)// || node == _end ) */
							 return 0;
						 // looking for the node to delete
						 else if (key_comp()(val.first, node->data.first))
						 {
							 node->end = 0;
							 node->left = _delete(node->left, val);
						 }
						 else if (key_comp()(node->key(), val.first))
						 {
							 node->end = 0;
							 node->right = _delete(node->right, val);
						 }
						 // if found
						 else
						 {
							 node->end = 0;
							 // case 1 : no children
							 if ( !node->left && !node->right)
							 {
							 	_alloc.destroy(node);
								return 0;
							 }
							 // case 2 : one children
							 else if (  !node->left && (tmp = node->right) )
							 {
								 tmp->parent = node->parent;
							 	_alloc.destroy(node);
								return tmp;
							 }
							 else if ( !node->right && (tmp = node->left) )
							 {
								 tmp->parent = node->parent;
							 	_alloc.destroy(node);
								return tmp;
							 }
							 // case 3 : 2 children
							 tmp = (node->right)->min();
							 _alloc.destroy(node);
							 _alloc.construct(node, tmp->data);
							 node->right = _delete(node->right, tmp->data);
						 }
						 return node;
					 }


					 void erase(iterator position)
					 {
						 	/* this->erase(position++, position); */
						 if ( empty() )
							 return ;
						 --_size;
						 _root = _delete(_root, value_type(position->first, position->second));
						 _set_end();
						 return ;
					 }

					 size_type erase(const key_type& k)
					 {
						 if (!count(k))
							 return 0;
						 erase(find(k));
						 _set_end();
						 return 1;
						 /* iterator pos = find(x); */
						 /* if (!count(x) || !_root) */
							 /* return 0; */
						 /* --_size; */
						 /* _root = _delete(_root, value_type(x, find(x)->second)); */
						 /* _set_end(); */
						 /* return 1; */
					 }

					 void erase(iterator first, iterator last)
					 {
						 while (first != last )//&& first->end != 1)
						 /* while (first != last && first->end != 1) */
						 {
							 _size--;
							 _root = _delete(_root, value_type(first->first, first->second));
							 first++;
						 _set_end();
						 }
					 }

					 void swap (map& x)
					 {
						 map tmp;

						 // if we use copy constructor instead of copy of map
						 // tmp._alloc = _alloc, its unvalid the iterators
						 tmp._alloc = _alloc;
						 tmp._cmp = _cmp;
						 tmp._end = _end;
						 tmp._root = _root;
						 tmp._size = _size;

						 _alloc = x._alloc;
						 _cmp = x._cmp;
						 _end = x._end;
						 _root = x._root;
						 _size = x._size;

						 x._alloc = tmp._alloc;
						 x._cmp = tmp._cmp;
						 x._end = tmp._end;
						 x._root = tmp._root;
						 x._size = tmp._size;

					 }

					 void clear()
					 {
						 	for (size_type i = 0; i < _size; i++)
								_alloc.destroy(_root);
							_size = 0;
							_root = NULL;
							_end = NULL;

							return ;
					 }

					  /* observers: */

					 // key_comp
					 key_compare key_comp()const
					 { return ( key_compare () ); }

					 // value_comp
					 value_compare value_comp() const
					 { return ( value_compare( key_compare() ) ) ; }

					 // 23.3.1.3 map operations:
					 iterator find(const key_type& x)
					 {
						 iterator	ite = end();
						 iterator	it = begin();

						 for (; it != ite; it++)
						 {
							 if ( (*it).key() == x)
								 return (it);
						 }
						 /* return (++it); */
						 /* return (it); */
						 /* return ( ++ite ); */
						 return ( ite );
					 }

					 const_iterator find(const key_type& x) const
					 {
						 const_iterator	ite = end();
						 const_iterator	it = begin();

						 for (; it != ite; it++)
						 {
							 if ( (*it).key() == x )
								 return (it);
						 }
						 /* return (++it); */
						 /* return (it); */
						 /* return ( ++ite ); */
						 return ( ite );
					 }

					 size_type count(const key_type& x) const
					 {
						 if ( _root == 0 )
							 return ( 0 );
						 for (const_iterator it = begin() ; it != end() ; it++ )
							 if ( (*it).key() == x)
								 return ( 1 );
						 return ( 0 );
					 }

					 iterator       lower_bound(const key_type& x)
					 {
						 iterator it = begin();
						 for ( ; it != end() ; it++ )
							 if ( !_cmp( it->first, x) )
								 return (it);
						 return ( it );
					 }

					 const_iterator lower_bound(const key_type& x) const
					 {
						 const_iterator it = begin();
						 for ( ; it != end() ; it++ )
							 if ( !_cmp( it->first, x) )
								 return (it);
						 return ( it );
					 }

					 iterator       upper_bound(const key_type& x)
					 {
						 iterator it = begin();
						 for ( ; it != end() ; it++ )
							 if ( _cmp( x, it->first ) )
								 return (it);
						 return ( it );
					 }

					 const_iterator upper_bound(const key_type& x) const
					 {
						 const_iterator it = begin();
						 for ( ; it != end() ; it++ )
							 if ( _cmp( x, it->first ) )
								 return (it);
						 return ( it );
					 }

					 pair<iterator,iterator>
						 equal_range(const key_type& x)
						 {
							 return make_pair(lower_bound(x), upper_bound(x));
						 }

					 pair<const_iterator,const_iterator>
						 equal_range(const key_type& x) const
					 {
							 return make_pair(lower_bound(x), upper_bound(x));
					 }

}; // Map class

template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      return false;
    ++first1; ++first2;
  }
  return true;
}
	template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 itl, InputIterator1 itle, InputIterator2 itr, InputIterator2 itre)
{
	while (itl != itle)
	{
		if (itr == itre || *itr != *itl)
			return (false);
		++itl, ++itr;
	}

	return (itr == itre);
}
	template <class T>
	bool equal (T & a, T & b)
	{
		return (a == b);
	}

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs)
{ 
	// return ( ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
		typename map<Key, T, Compare, Allocator>::const_iterator	it = lhs.begin();
		typename map<Key, T, Compare, Allocator>::const_iterator	ite = lhs.end();
		typename map<Key, T, Compare, Allocator>::const_iterator	it2 = rhs.begin();

		while (it != ite && it2 != rhs.end()) // cas particulier lié a end()
		{
			if (it->first != it2->first || it->second != it2->second)
				return (false);
			it++;
			it2++;
		}
	/* std::cout << "test" << std::endl; */
		return (it == ite && it2 == rhs.end());
	return (equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end() )) ;
}

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>&rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>&rhs)
{ 
	return (lhs.size() < rhs.size());
	/* return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end() )) ; */
}

template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>&rhs)
{
	return ( lhs.size() > rhs.size());
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>&rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>&rhs)
{
	return (!(lhs > rhs));
}

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key,T,Compare,Allocator>& lhs, map<Key,T,Compare,Allocator>&rhs)
{
	lhs.swap(rhs);
}



} // ft namespace

/* USEFULL */
#endif
