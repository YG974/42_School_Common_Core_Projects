#include <cstdlib>
#include <iterator>
#include <string>
#include <memory>
#include <iostream>
#include <typeinfo>
#include <locale>
#include <climits>
#include <vector>
#include <stack>
#include <utility>
#include <map>

#ifndef NM
# define NM ft
#endif

#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "utils.hpp"


void    vec_enum(NM::vector<int> &vec)
{
    NM::vector<int>::iterator it;
    NM::vector<int>::iterator it2;

    it = vec.begin();
    it2 = vec.end();
	int i = 0;

    std::cout << std::endl;
    while (it != it2) {
        std::cout << "vector[" << i << "] : " <<*it << std::endl;
        it++;
		i++;
    }
}

void    vec_enum_const(NM::vector<int> &vec)
{
    NM::vector<int>::const_iterator it;
    NM::vector<int>::const_iterator it2;

    it = vec.begin();
    it2 = vec.end();
	int i = 0;

    std::cout << std::endl;
    while (it != it2) {
        std::cout << "vector[" << i << "] : " <<*it << std::endl;
        it++;
		i++;
    }
}
void vector_const_it()
{
	std::cout << "\n--- VECTOR TEST ---\n" << std::endl;
	std::cout << "\n--- CONST ITERATOR ---\n" << std::endl;

	NM::vector<int> myvector;
	NM::vector<int>::const_iterator it;
	NM::vector<int>::const_iterator ot;
	

	std::cout << "------------------------------------" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " default constructor (empty) vec 1" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "vec 1";
	vec_enum_const(myvector);
	std::cout << "----------------" << std::endl;
	std::cout << " insert constructor vec 2" << std::endl;
	std::cout << "----------------" << std::endl;
	NM::vector<int> mine(5, 2);
	std::cout << "vec 2";
	vec_enum_const(mine);
	std::cout << "----------------" << std::endl;
	std::cout << " begin and end value " << std::endl;
	std::cout << "----------------" << std::endl;
	it = mine.begin();
	std::cout << "begin value = " << *it << std::endl;
	it = mine.end();
	it--;
	std::cout << "end value = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " size max_size capacity empty " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "size = " <<mine.size() << std::endl;
	std::cout << "max_size = " << mine.max_size() << std::endl;
	std::cout << "capacity = " << mine.capacity() << std::endl;
	std::cout << " vec 1";
	std::cout << "empty = " << myvector.empty() << std::endl;
	std::cout << " vec 2";
	std::cout << "empty = " << mine.empty() << std::endl;
	mine.push_back(10);
	it = mine.end();
	it--;
	std::cout << "----------------" << std::endl;
	std::cout << " push_back pop_back " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "push_back = " << *it << std::endl;
	std::cout << "capacity = " << mine.capacity() << std::endl;
	mine.pop_back();
	it = mine.end();
	it--;
	std::cout << "pop_back = " << *it << std::endl;
	std::cout << "------------------------------------" <<std::endl;
	mine.resize(15, 6);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "------------------------------------" <<std::endl;
	mine.resize(2, 4);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "------------------------------------" <<std::endl;
	mine.resize(9, 3);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "front = " << mine.front() << std::endl;
	std::cout << "back = " << mine.back() << std::endl;
	std::cout << "------------------------------------" <<std::endl;
	mine.assign(4, 2);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "------------------------------------" <<std::endl;
	myvector.assign(mine.begin(), mine.end());
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " insert iterator constructor vec 3 " << std::endl;
	std::cout << "----------------" << std::endl;
	NM::vector<int> newvec(mine.begin(), mine.end());
	std::cout << "vec 3" ;
	vec_enum_const(newvec);
	mine.push_back(10);
	mine.push_back(9);
	mine.push_back(19);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " copy constructor vec 4 " << std::endl;
	std::cout << "----------------" << std::endl;
	NM::vector<int> v2(mine);
	std::cout << "vec 4" ;
	vec_enum_const(v2);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "insert single" <<std::endl;
	it = myvector.insert(myvector.begin() + 2, (int)4);
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "it      = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "insert multiple" <<std::endl;
	std::cout << "----------------" << std::endl;
	myvector.insert(myvector.begin() + 2, (size_t)3, 4);
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "----------------" << std::endl;
	std::cout << "insert range" <<std::endl;
	std::cout << "----------------" << std::endl;
	mine.insert(mine.begin() + 1, myvector.begin() + 1, myvector.begin() + 4);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "----------------" << std::endl;
	std::cout << "erase single" <<std::endl;
	std::cout << "----------------" << std::endl;
	it = mine.erase(mine.begin() + 1);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "it      = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "erase range" <<std::endl;
	std::cout << "----------------" << std::endl;
	it = mine.erase(mine.begin() + 3, mine.end() );
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "it      = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "swap vec 1 et vec 2" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	myvector.swap(mine);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "----------------" << std::endl;
	std::cout << "ft::swap mine et myvector" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "vec 2" << std::endl;
	vec_enum_const(mine);
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "------------------------------------" <<std::endl;
	NM::swap(mine, myvector);
	std::cout << "vec 2" ;
	vec_enum_const(mine);
	std::cout << "vec 1" ;
	vec_enum_const(myvector);
	std::cout << "----------------" << std::endl;
	std::cout << " Comparison operator" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "< : "<< (myvector <  mine) << std::endl;
	std::cout << "> : "<< (myvector >  mine) << std::endl;
	std::cout << "== : "<< (myvector == mine) << std::endl;
	std::cout << "!= : "<< (myvector != mine) << std::endl;
	std::cout << "------------------------------------" <<std::endl;
	return ;
}

void vector()
{
	std::cout << "\n--- VECTOR TEST ---\n" << std::endl;
	std::cout << "\n--- REGULAR ITERATOR ---\n" << std::endl;

	NM::vector<int> myvector;
	NM::vector<int>::iterator it;
	NM::vector<int>::iterator ot;
	

	std::cout << "------------------------------------" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " default constructor (empty) vec 1" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "vec 1";
	vec_enum(myvector);
	std::cout << "----------------" << std::endl;
	std::cout << " insert constructor vec 2" << std::endl;
	std::cout << "----------------" << std::endl;
	NM::vector<int> mine(5, 2);
	std::cout << "vec 2";
	vec_enum(mine);
	std::cout << "----------------" << std::endl;
	std::cout << " begin and end value " << std::endl;
	std::cout << "----------------" << std::endl;
	it = mine.begin();
	std::cout << "begin value = " << *it << std::endl;
	it = mine.end();
	it--;
	std::cout << "end value = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " size max_size capacity empty " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "size = " <<mine.size() << std::endl;
	std::cout << "max_size = " << mine.max_size() << std::endl;
	std::cout << "capacity = " << mine.capacity() << std::endl;
	std::cout << " vec 1";
	std::cout << "empty = " << myvector.empty() << std::endl;
	std::cout << " vec 2";
	std::cout << "empty = " << mine.empty() << std::endl;
	mine.push_back(10);
	it = mine.end();
	it--;
	std::cout << "----------------" << std::endl;
	std::cout << " push_back pop_back " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "push_back = " << *it << std::endl;
	std::cout << "capacity = " << mine.capacity() << std::endl;
	mine.pop_back();
	it = mine.end();
	it--;
	std::cout << "pop_back = " << *it << std::endl;
	std::cout << "------------------------------------" <<std::endl;
	mine.resize(15, 6);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "------------------------------------" <<std::endl;
	mine.resize(2, 4);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "------------------------------------" <<std::endl;
	mine.resize(9, 3);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "front = " << mine.front() << std::endl;
	std::cout << "back = " << mine.back() << std::endl;
	std::cout << "------------------------------------" <<std::endl;
	mine.assign(4, 2);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "------------------------------------" <<std::endl;
	myvector.assign(mine.begin(), mine.end());
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " insert iterator constructor vec 3 " << std::endl;
	std::cout << "----------------" << std::endl;
	NM::vector<int> newvec(mine.begin(), mine.end());
	std::cout << "vec 3" ;
	vec_enum(newvec);
	mine.push_back(10);
	mine.push_back(9);
	mine.push_back(19);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " copy constructor vec 4 " << std::endl;
	std::cout << "----------------" << std::endl;
	NM::vector<int> v2(mine);
	std::cout << "vec 4" ;
	vec_enum(v2);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "insert single" <<std::endl;
	it = myvector.insert(myvector.begin() + 2, (int)4);
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "it      = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "insert multiple" <<std::endl;
	std::cout << "----------------" << std::endl;
	myvector.insert(myvector.begin() + 2, (size_t)3, 4);
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "----------------" << std::endl;
	std::cout << "insert range" <<std::endl;
	std::cout << "----------------" << std::endl;
	mine.insert(mine.begin() + 1, myvector.begin() + 1, myvector.begin() + 4);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "----------------" << std::endl;
	std::cout << "erase single" <<std::endl;
	std::cout << "----------------" << std::endl;
	it = mine.erase(mine.begin() + 1);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "it      = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "erase range" <<std::endl;
	std::cout << "----------------" << std::endl;
	it = mine.erase(mine.begin() + 3, mine.end() );
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "it      = " << *it << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "swap vec 1 et vec 2" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "vec 1" ;
	vec_enum(myvector);
	myvector.swap(mine);
	std::cout << "------------------------------------" <<std::endl;
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "----------------" << std::endl;
	std::cout << "ft::swap mine et myvector" <<std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "vec 2" << std::endl;
	vec_enum(mine);
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "------------------------------------" <<std::endl;
	NM::swap(mine, myvector);
	std::cout << "vec 2" ;
	vec_enum(mine);
	std::cout << "vec 1" ;
	vec_enum(myvector);
	std::cout << "----------------" << std::endl;
	std::cout << " Comparison operator" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "< : "<< (myvector <  mine) << std::endl;
	std::cout << "> : "<< (myvector >  mine) << std::endl;
	std::cout << "== : "<< (myvector == mine) << std::endl;
	std::cout << "!= : "<< (myvector != mine) << std::endl;
	std::cout << "------------------------------------" <<std::endl;
	return ;
}

void    map_enum(NM::map<std::string, int> &map)
{
    NM::map<std::string, int>::iterator it;
    NM::map<std::string, int>::iterator ite;

    it = map.begin();
    ite = map.end();

    std::cout << std::endl;
    while (it != ite)
	{
        std::cout << "key:'" << it->first << "'  | val:'" << it->second << "'" << std::endl;
        it++;
    }
}

void    map_enum_const(NM::map<std::string, int> &map)
{
    NM::map<std::string, int>::const_iterator it;
    NM::map<std::string, int>::const_iterator ite;

    it = map.begin();
    ite = map.end();

    std::cout << std::endl;
    while (it != ite)
	{
        std::cout << "key:'" << it->first << "'  | val:'" << it->second << "'" << std::endl;
        it++;
    }
}

void map_const (void)
{
	std::cout << "\n--- MAP TEST ---" << std::endl;
	std::cout << "\n--- CONST ITERATOR ---" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "empty map" << std::endl;
	NM::map<std::string, int> mymap;

	std::cout << "empty : " << mymap.empty() << std::endl;
	std::cout << "max size : " << mymap.max_size() << std::endl;
	std::cout << "size : " << mymap.size() << std::endl;
	std::cout << "----------------" << std::endl;
	map_enum_const(mymap);

	std::cout << "----------------" << std::endl;
	std::cout << "Insert 1) 4 values" << std::endl;
	std::cout << "----------------" << std::endl;
	mymap.insert(NM::make_pair("B", 2));
	mymap.insert(NM::make_pair("A", 1));
	mymap.insert(NM::make_pair("C", 3));
	mymap.insert(NM::make_pair("D", 4));
	NM::map<std::string, int>::const_iterator it = mymap.begin();
	NM::map<std::string, int>::const_iterator ite = mymap.end();
	map_enum_const(mymap);

	std::cout << "----------------" << std::endl;
	std::cout << "Insert 2) with redondant key and new keys" << std::endl;
	std::cout << "----------------" << std::endl;

	mymap.insert( NM::make_pair("B", 2));
	mymap.insert( NM::make_pair("E", 5));
	mymap.insert( NM::make_pair("A", 2));
	mymap.insert( NM::make_pair("Z", 26));
	 it = mymap.begin();
	 ite = mymap.end();
	map_enum_const(mymap);
	std::cout << "empty : " << mymap.empty() << std::endl;
	std::cout << "max size : " << mymap.max_size() << std::endl;
	std::cout << "size : " << mymap.size() << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "copy constructor mymap2" << std::endl;
	std::cout << "----------------" << std::endl;

	NM::map<std::string, int> mymap2 = mymap;
	 it = mymap2.begin();
	 ite = mymap2.end();
	map_enum_const(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "clear mymap2 " << std::endl;
	std::cout << "----------------" << std::endl;
	mymap2.clear();
	 it = mymap2.begin();
	 ite = mymap2.end();
	map_enum_const(mymap2);
	std::cout << "----------------" << std::endl;
	std::cout << "swap mymap et mymap2 " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "mymap" << std::endl;
	mymap.swap(mymap2);
	 it = mymap.begin();
	 ite = mymap.end();
	map_enum_const(mymap);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	 it = mymap2.begin();
	 ite = mymap2.end();
	map_enum_const(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	std::cout << "mymap2" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "find A D Y E Z" << std::endl;
	std::cout << "----------------" << std::endl;
	it = mymap2.begin();
	ite = mymap2.end();
	it = mymap2.find("A");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("D");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("Y");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("E");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("Z");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	std::cout << "----------------" << std::endl;
	std::cout << "count A D Y E Z" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "count : " << mymap2.count("A") << std::endl;
	std::cout << "count : " << mymap2.count("D") << std::endl;
	std::cout << "count : " << mymap2.count("Y") << std::endl;
	std::cout << "count : " << mymap2.count("E") << std::endl;
	std::cout << "count : " << mymap2.count("Z") << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "Lower_bound A D J L Y" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("A")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("D")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("J")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("L")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("Y")->first << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "higher_bound A D J L Y" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("A")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("D")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("J")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("L")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("Y")->first << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "operator []" << std::endl;
	std::cout << "----------------" << std::endl;

	mymap2["X"] = 24;
	mymap2["M"] = 14;
	mymap2["A"] = 1;

	map_enum_const(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	std::cout << "mymap2" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " erase begin B M X F" << std::endl;
	std::cout << "----------------" << std::endl;
	mymap2.erase(mymap2.begin());
	mymap2.erase("B");
	mymap2.erase("M");
	mymap2.erase("X");
	mymap2.erase("F");
	map_enum_const(mymap2);
	std::cout << "----------------" << std::endl;
	std::cout << " erase multiple iterators from begin to end" << std::endl;
	std::cout << "----------------" << std::endl;
	it = mymap2.begin();
	it++;
	it++;
	mymap2.erase(mymap2.begin() , mymap2.end() );
	map_enum_const(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;

	return;
}

void map (void)
{
	std::cout << "\n--- MAP TEST ---" << std::endl;
	std::cout << "\n--- REGULAR ITERATOR ---" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "empty map" << std::endl;
	NM::map<std::string, int> mymap;

	std::cout << "empty : " << mymap.empty() << std::endl;
	std::cout << "max size : " << mymap.max_size() << std::endl;
	std::cout << "size : " << mymap.size() << std::endl;
	std::cout << "----------------" << std::endl;
	map_enum(mymap);

	std::cout << "----------------" << std::endl;
	std::cout << "Insert 1) 4 values" << std::endl;
	std::cout << "----------------" << std::endl;
	mymap.insert(NM::make_pair("B", 2));
	mymap.insert(NM::make_pair("A", 1));
	mymap.insert(NM::make_pair("C", 3));
	mymap.insert(NM::make_pair("D", 4));
	NM::map<std::string, int>::iterator it = mymap.begin();
	NM::map<std::string, int>::iterator ite = mymap.end();
	map_enum(mymap);

	std::cout << "----------------" << std::endl;
	std::cout << "Insert 2) with redondant key and new keys" << std::endl;
	std::cout << "----------------" << std::endl;

	mymap.insert(it, NM::make_pair("B", 2));
	mymap.insert(it, NM::make_pair("E", 5));
	mymap.insert(it, NM::make_pair("A", 2));
	mymap.insert(it, NM::make_pair("Z", 26));
	 it = mymap.begin();
	 ite = mymap.end();
	map_enum(mymap);
	std::cout << "empty : " << mymap.empty() << std::endl;
	std::cout << "max size : " << mymap.max_size() << std::endl;
	std::cout << "size : " << mymap.size() << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "copy constructor mymap2" << std::endl;
	std::cout << "----------------" << std::endl;

	NM::map<std::string, int> mymap2 = mymap;
	 it = mymap2.begin();
	 ite = mymap2.end();
	map_enum(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "clear mymap2 " << std::endl;
	std::cout << "----------------" << std::endl;
	mymap2.clear();
	 it = mymap2.begin();
	 ite = mymap2.end();
	map_enum(mymap2);
	std::cout << "----------------" << std::endl;
	std::cout << "swap mymap et mymap2 " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "mymap" << std::endl;
	mymap.swap(mymap2);
	 it = mymap.begin();
	 ite = mymap.end();
	map_enum(mymap);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	 it = mymap2.begin();
	 ite = mymap2.end();
	map_enum(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	std::cout << "mymap2" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "find A D Y E Z" << std::endl;
	std::cout << "----------------" << std::endl;
	it = mymap2.begin();
	ite = mymap2.end();
	it = mymap2.find("A");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("D");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("Y");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("E");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	it = mymap2.find("Z");
	if (it != ite)
		std::cout << "find : " << it->first << "-" << it->second << "\n";
	else
		std::cout << "not found\n";
	std::cout << "----------------" << std::endl;
	std::cout << "count A D Y E Z" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "count : " << mymap2.count("A") << std::endl;
	std::cout << "count : " << mymap2.count("D") << std::endl;
	std::cout << "count : " << mymap2.count("Y") << std::endl;
	std::cout << "count : " << mymap2.count("E") << std::endl;
	std::cout << "count : " << mymap2.count("Z") << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "Lower_bound A D J L Y" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("A")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("D")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("J")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("L")->first << std::endl;
	std::cout << "lower_bound : " << mymap2.lower_bound("Y")->first << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "higher_bound A D J L Y" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("A")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("D")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("J")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("L")->first << std::endl;
	std::cout << "upper_bound : " << mymap2.upper_bound("Y")->first << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "operator []" << std::endl;
	std::cout << "----------------" << std::endl;

	mymap2["X"] = 24;
	mymap2["M"] = 14;
	mymap2["A"] = 1;

	map_enum(mymap2);
	std::cout << "empty : " << mymap2.empty() << std::endl;
	std::cout << "max size : " << mymap2.max_size() << std::endl;
	std::cout << "size : " << mymap2.size() << std::endl;
	std::cout << "mymap2" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " erase begin B M X F" << std::endl;
	std::cout << "----------------" << std::endl;
	mymap2.erase(mymap2.begin());
	mymap2.erase("B");
	mymap2.erase("M");
	mymap2.erase("X");
	mymap2.erase("F");
	map_enum(mymap2);
	std::cout << "----------------" << std::endl;
	std::cout << " erase multiple iterators from begin + 2" << std::endl;
	std::cout << "----------------" << std::endl;
	it = mymap2.begin();
	it++;
	it++;
	mymap2.erase(it, mymap2.end() );
	map_enum(mymap2);
	std::cout << "----------------" << std::endl;
	std::cout << "comparator" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "== : " << (mymap == mymap2) << std::endl;
	std::cout << "!= : " << (mymap != mymap2) << std::endl;
	std::cout << "< : " << (mymap < mymap2) << std::endl;
	std::cout << "> : " << (mymap > mymap2) << std::endl;
	std::cout << ">= : " << (mymap >= mymap2) << std::endl;
	std::cout << "<= : " << (mymap <= mymap2) << std::endl;

	return;
}

void stack( void )
{
	NM::stack<int> mystack;
	std::cout << "\n--- STACK TEST ---" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "empty stack" << std::endl;
	std::cout << "----------------" << std::endl;

	std::cout << "empty : " << mystack.empty() << std::endl;
	std::cout << "size : " << mystack.size() << std::endl;
	std::cout << "----------------" << std::endl;

	std::cout << "----------------" << std::endl;
	std::cout << "pushing values" << std::endl;
	std::cout << "----------------" << std::endl;
	mystack.push(10);
	mystack.push(20);
	mystack.push(30);
	mystack.push(50);
	mystack.push(13);
	mystack.push(93);
	std::cout << "empty : " << mystack.empty() << std::endl;
	std::cout << "size : " << mystack.size() << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " top and pop" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "Top : " << mystack.top() << std::endl;
	mystack.pop();
	std::cout << "Top : " << mystack.top() << std::endl;
	mystack.pop();
	std::cout << "Top : " << mystack.top() << std::endl;
	mystack.pop();
	std::cout << "Top : " << mystack.top() << std::endl;
	mystack.pop();
	std::cout << "Top : " << mystack.top() << std::endl;
	std::cout << "empty : " << mystack.empty() << std::endl;
	std::cout << "size : " << mystack.size() << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " copy and comparators" << std::endl;
	std::cout << "----------------" << std::endl;
	NM::stack<int> mystack2 = mystack;
	std::cout << "== : " << (mystack == mystack2) << std::endl;
	std::cout << "!= : " << (mystack != mystack2) << std::endl;
	std::cout << "< : " << (mystack < mystack2) << std::endl;
	std::cout << "> : " << (mystack > mystack2) << std::endl;
	std::cout << ">= : " << (mystack >= mystack2) << std::endl;
	std::cout << "<= : " << (mystack <= mystack2) << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << " empty stack and compare again" << std::endl;
	std::cout << "----------------" << std::endl;
	mystack.pop();
	mystack.pop();
	std::cout << "== : " << (mystack == mystack2) << std::endl;
	std::cout << "!= : " << (mystack != mystack2) << std::endl;
	std::cout << "< : " << (mystack < mystack2) << std::endl;
	std::cout << "> : " << (mystack > mystack2) << std::endl;
	std::cout << ">= : " << (mystack >= mystack2) << std::endl;
	std::cout << "<= : " << (mystack <= mystack2) << std::endl;


	return;
}

int main ( void )
{
	vector();
	vector_const_it();
	map();
	map_const();
	stack();

	return 1;
}

