#include <asm-generic/errno.h>
#include <cstdio>
#include <iostream>
#include <colormod.h>
#include <iterator>
#include <string>
#include <cstring>
#include <stack>
#include <map>
#include <map>
#include <stdio.h>

#include <map.h>
//#include <map.h>
//#include <stack.h>

bool check_state(const ft::map<int> &ft_map, const std::map<int> &stl_map, std::string test)
{
	bool ok = true;
	bool constructor = (test.find("constructor") != std::string::npos);

	if (ft_map.size() != stl_map.size())
	{
		if (constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "size()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_map.max_size() != stl_map.max_size())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "max_size()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_map.capacity() != stl_map.capacity())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "capacity()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_map.empty() != stl_map.empty())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "empty()" << FG_DEF << " function";
		ok = false;	
	}
	if (stl_map.size() && ft_map.front() != stl_map.front())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "front()" << FG_DEF << " function";
		ok = false;
	}
	if (stl_map.size() && ft_map.back() != stl_map.back())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "back()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_map.get_allocator() != stl_map.get_allocator())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "get_allocator()" << FG_DEF << " function";
		ok = false;
	}

	if (!ok)
		std::cout << std::endl;
	return (ok);
}

bool v_check_content(ft::map<int> &ft_map, std::map<int> &stl_map, std::string const &test)
{
	bool ok = true;
	bool constructor = (test.find("constructor") != std::string::npos);

	int n = stl_map.size();
	while (n--)
	{
		if (ft_map[n] != stl_map[n])
		{
			std::cout << std::endl << "content was incorrect at index" << FG_YEL << " [" << n << "]" << FG_DEF << " : expected " << FG_YEL << stl_map[n] << FG_DEF << ", got " << FG_MAG << ft_map[n] << FG_DEF;


			ok = false;
		}
		ft_map[n] = n;
		stl_map[n] = n;
	}

	if (!ok)
		std::cout << std::endl;

	n = stl_map.size();

	if (n && ft_map.at(0) != stl_map.at(0))
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "at()" << FG_DEF << " function";
		ok = false;
	}
	if (n && *ft_map.begin() != *stl_map.begin())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "begin()" << FG_DEF << " function";
		ok = false;
	}

	if (n && *(ft_map.end() - 1) != *(stl_map.end() - 1))
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "end()" << FG_DEF << " function";
		ok = false;
	}
	if (n && *ft_map.rbegin() != *stl_map.rbegin())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "rbegin()" << FG_DEF << " function";
		ok = false;
	}
	if (n && *ft_map.rend().base() != *stl_map.rend().base())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "rend()" << FG_DEF << " function";
		ok = false;
	}

	if (!ok)
		std::cout << std::endl;

	return (ok);
}

bool v_test ()
{
	bool state, content, ok = true;

	std::cout << FG_YEL << "- DEFAULT CONSTRUCTOR " << FG_DEF;

	ft::map<int> ft_map_def;
	std::map<int> stl_map_def;

	state = v_check_state(ft_map_def, stl_map_def, "default constructor");
	content = v_check_content(ft_map_def, stl_map_def, "default constructor");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	std::cout << FG_YEL << "- PARAMETRIC CONSTRUCTOR (size_t, const &value_type) " << FG_DEF;

	ft::map<int> ft_map(4, 2);
	std::map<int> stl_map(4, 2);
	state = v_check_state(ft_map, stl_map, "parametric constructor (size_t, const &value_type)");
	content = v_check_content(ft_map, stl_map, "parametric constructor (size_t, const &value_type)");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	std::cout << FG_YEL << "- PARAMETRIC CONSTRUCTOR (InputIterator, InputIterator) " << FG_DEF;

	ft::map<int> ft_map_par2(ft_map.begin(), ft_map.end());
	std::map<int> stl_map_par2(stl_map.begin(), stl_map.end());
	state = v_check_state(ft_map_par2, stl_map_par2, "parametric constructor (InputIterator, InputIterator)");
	content = v_check_content(ft_map_par2, stl_map_par2, "parametric constructor (size_t, const &value_type)");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	std::cout << FG_YEL << "- COPY CONSTRUCTOR (InputIterator, InputIterator) " << FG_DEF;

	ft::map<int> ft_map_cpy(ft_map.begin(), ft_map.end());
	std::map<int> stl_map_cpy(stl_map.begin(), stl_map.end());
	state = v_check_state(ft_map_cpy, stl_map_cpy, "copy constructor");
	content = v_check_content(ft_map_cpy, stl_map_cpy, "copy constructor");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// CONST INSTANCE

	const ft::map<int> ft_map_const(ft_map);
	const ft::map<int> ft_map_const2(ft_map_const);
	const std::map<int> stl_map_const(stl_map);

	std::cout << FG_YEL << "- CONST INSTANCE " << FG_DEF;

	// IF COMPARISON IMPOSSIBLE -> OVERLOAD TYPE OPERATOR IN RANDOM_ACCESS_ITERATOR TO ALLOW FOR IMPLICIT CONVERSION BEETWEEN CONST AND NON-CONST
	if (ft_map_const.begin() != ft_map.begin())
	{
		;
	}

	state = v_check_state_const(ft_map_const, stl_map_const);
	content = v_check_content_const(ft_map_const, stl_map_const);

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	// OPERATORS
	
	std::cout << FG_YEL << "- OPERATORS " << FG_DEF;

	if (!(ft_map_const == ft_map_const2) || ft_map == ft_map_def)
	{
		state = false;
		std::cout << std::endl << std::endl << "the operator " << FG_MAG << "==" << FG_DEF << " is broken";
	}
	if (ft_map_const != ft_map_const2 || !(ft_map != ft_map_def))
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "!=" << FG_DEF << " is broken";
	}
	if (ft_map_const > ft_map_const2 || !(ft_map > ft_map_def))
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << ">" << FG_DEF << " is broken";
	}
	if (ft_map_const2 < ft_map_const || !(ft_map_def < ft_map))
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "<" << FG_DEF << " is broken";
	}
	if (!(ft_map_const >= ft_map_const2) || ft_map_def >= ft_map)
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << ">=" << FG_DEF << " is broken";
	}
	if (!(ft_map_const2 >= ft_map_const) || ft_map_def <= ft_map)
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "<=" << FG_DEF << " is broken";
	}
	if (!(ft_map_const2 >= ft_map_const) || ft_map_def <= ft_map)
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "<=" << FG_DEF << " is broken";
	}
	if (ft_map[0] != stl_map[0])
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "[]" << FG_DEF << " is broken";
	}
	if (ft_map_const[0] != stl_map[0])
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "[] const" << FG_DEF << " is broken";
	}

	ft::map<int> eq;
	eq = ft_map;
	
	if (ft_map != eq || ft_map.size() != eq.size() || ft_map.max_size() || ft_map.capacity() != eq.capacity() || ft_map.empty() != eq.empty() || \
		ft_map.front() != eq.front() || ft_map.back() != eq.back() || ft_map.get_allocator() != eq.get_allocator())
	{
		if (state)
			std::cout << std::endl; 
		state = false;
		std::cout << std::endl << "the operator " << FG_MAG << "=" << FG_DEF << " is broken";
	}

	if (state)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << std::endl << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	
	std::cout << std::endl;	

	// RESIZE()

	std::cout << FG_YEL << "- Testing " << "resize() :" << FG_DEF << std::endl;

	ft_map.resize(20, 1);
	stl_map.resize(20, 1);
	ft_map.resize(0);
	stl_map.resize(0);
	ft_map.resize(5);
	stl_map.resize(5);

	state = v_check_state(ft_map, stl_map, "resize()");
	content = v_check_content(ft_map, stl_map, "resize()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// RESERVE()

	std::cout << FG_YEL << "- Testing " << "reserve() :" << FG_DEF << std::endl;

	ft_map.reserve(0);
	stl_map.reserve(0);
	ft_map.reserve(6);
	stl_map.reserve(6);
	
	state = v_check_state(ft_map, stl_map, "reserve()");
	content = v_check_content(ft_map, stl_map, "reserve()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// ASSIGN (size_t, value_type)
	
	std::cout << FG_YEL << "- Testing " << "assign (size_type, const &value_type) :" << FG_DEF << std::endl;

	ft_map.assign(0, 3);
	stl_map.assign(0, 3);
	ft_map.assign(2, 4);
	stl_map.assign(2, 4);
	ft_map.assign(stl_map.capacity() + 1, 3);
	stl_map.assign(stl_map.capacity() + 1, 3);
	ft_map.assign(2, 4);
	stl_map.assign(2, 4);
	
	state = v_check_state(ft_map, stl_map, "assign()");
	content = v_check_content(ft_map, stl_map, "assign()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// ASSIGN (InputIterator, InputIterator)
	
	std::cout << FG_YEL << "- Testing " << "assign (InputIterator, InputIterator) :" << FG_DEF << std::endl;

	ft_map.assign(ft_map.begin(), ft_map.begin());
	stl_map.assign(stl_map.begin(), stl_map.begin());
	ft_map.assign(ft_map.begin(), ft_map.begin() + 1);
	stl_map.assign(stl_map.begin(), stl_map.begin() + 1);
	ft_map.assign(stl_map.capacity() + 1, 3);
	stl_map.assign(stl_map.capacity() + 1, 3);
	ft_map.assign(ft_map.begin(), ft_map.end());
	stl_map.assign(stl_map.begin(), stl_map.end());

	state = v_check_state(ft_map, stl_map, "assign()");
	content = v_check_content(ft_map, stl_map, "assign()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	//if (ft_map.assign(1, 2))
	//	std::cout << FG_MAG << "enable_if" << FG_DEF << " failure" << std::endl;

	std::cout << std::endl;

	// CLEAR()

	std::cout << FG_YEL << "- Testing " << "clear() :" << FG_DEF << std::endl;

	ft_map.clear();
	stl_map.clear();

	state = v_check_state(ft_map, stl_map, "clear()");
	content = v_check_content(ft_map, stl_map, "clear()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// PUSH_BACK()
	
	std::cout << FG_YEL << "- Testing " << "push_back() :" << FG_DEF << std::endl;

	ft_map.push_back(6);
	stl_map.push_back(6);
	ft_map.push_back(6);
	stl_map.push_back(6);
	ft_map.push_back(7);
	stl_map.push_back(7);

	state = v_check_state(ft_map, stl_map, "push_back()");
	content = v_check_content(ft_map, stl_map, "push_back()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// POP_BACK()

	std::cout << FG_YEL << "- Testing " << "pop_back() :" << FG_DEF << std::endl;

	ft_map.pop_back();
	stl_map.pop_back();

	state = v_check_state(ft_map, stl_map, "pop_back()");
	content = v_check_content(ft_map, stl_map, "pop_back()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	while (stl_map.size())
	{
		ft_map.pop_back();
		stl_map.pop_back();
	}

	std::cout << std::endl;

	// INSERT (iterator, const &value_type)

	std::cout << FG_YEL << "- Testing " << "insert (iterator, const &value_type) :" << FG_DEF << std::endl;

	ft_map.insert(ft_map.begin(), 5);
	stl_map.insert(stl_map.begin(), 5);
	ft_map.insert(ft_map.end(), 5);
	stl_map.insert(stl_map.end(), 5);
	ft_map.insert(ft_map.begin() + 1, 5);
	stl_map.insert(stl_map.begin() + 1, 5);

	state = v_check_state(ft_map, stl_map, "insert()");
	content = v_check_content(ft_map, stl_map, "insert()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// INSERT (iterator, size_type, const &value_type)

	std::cout << FG_YEL << "- Testing " << "insert (iterator, size_type, const &value_type) :" << FG_DEF << std::endl;

	ft_map.insert(ft_map.begin(), 2, 3);
	stl_map.insert(stl_map.begin(), 2, 3);

	state = v_check_state(ft_map, stl_map, "insert()");
	content = v_check_content(ft_map, stl_map, "insert()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// INSERT (iterator, InputIterator, InputIterator)

	std::cout << FG_YEL << "- Testing " << "insert (iterator, InputIterator, InputIterator) :" << FG_DEF << std::endl;

	ft_map.insert(ft_map.begin(), ft_map.begin(), ft_map.begin());
	stl_map.insert(stl_map.begin(), stl_map.begin(), stl_map.begin());
	ft_map.insert(ft_map.begin() + 1, ft_map.begin(), ft_map.begin() + 1);
	stl_map.insert(stl_map.begin() + 1, stl_map.begin(), stl_map.begin() + 1);
	ft_map.insert(ft_map.end(), ft_map.begin(), ft_map.begin() + 2);
	stl_map.insert(stl_map.end(), stl_map.begin(), stl_map.begin() + 2);
	ft_map.insert(ft_map.end(), ft_map.begin(), ft_map.end());
	stl_map.insert(stl_map.end(), stl_map.begin(), stl_map.end());

	state = v_check_state(ft_map, stl_map, "insert()");
	content = v_check_content(ft_map, stl_map, "insert()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	//if (ft_map.assign(1, 2))
	//	std::cout << FG_MAG << "enable_if" << FG_DEF << " failure" << std::endl;
	
	std::cout << std::endl;
	
	ft_map.clear();
	stl_map.clear();

	for (int i = 0; i < 10; i++)
	{
		ft_map.push_back(i);
		stl_map.push_back(i);
	}

	// ERASE (iterator)

	std::cout << FG_YEL << "- Testing " << "erase (iterator) :" << FG_DEF << std::endl;

	size_t ft_ret_index;
	size_t stl_ret_index;

	ft_ret_index = ft_map.erase(ft_map.begin()) - ft_map.begin();
	stl_ret_index = stl_map.erase(stl_map.begin()) - stl_map.begin();

	if (ft_ret_index != stl_ret_index)
		std::cout << std::endl << FG_YEL << "test 1" << FG_DEF << " : wrong return value : expected index " << FG_YEL << "[" << stl_ret_index << "]" << FG_DEF << ", got iterator to index " << FG_MAG << "[" << ft_ret_index << "]" << FG_DEF << std::endl;
	
	ft_ret_index = ft_map.erase(ft_map.begin() + 1) - ft_map.begin();
	stl_ret_index = stl_map.erase(stl_map.begin() + 1) - stl_map.begin();
	
	if (ft_ret_index != stl_ret_index)
		std::cout << std::endl << FG_YEL << "test 2" << FG_DEF << " : wrong return value : expected index " << FG_YEL << "[" << stl_ret_index << "]" << FG_DEF << ", got iterator to index " << FG_MAG << "[" << ft_ret_index << "]" << FG_DEF << std::endl;

	state = v_check_state(ft_map, stl_map, "erase()");
	content = v_check_content(ft_map, stl_map, "erase()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// ERASE (iterator, iterator)

	ft_map.erase(ft_map.begin(), ft_map.begin() + 1);
	stl_map.erase(stl_map.begin(), stl_map.begin() + 1);
	ft_map.erase(ft_map.begin(), ft_map.begin() + 2);
	stl_map.erase(stl_map.begin(), stl_map.begin() + 2);

	std::cout << FG_YEL << "- Testing " << "erase (iterator, iterator) :" << FG_DEF << std::endl;

	state = v_check_state(ft_map, stl_map, "erase()");
	content = v_check_content(ft_map, stl_map, "erase()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// SWAP()

	ft::map<int>ft_swap(3,2);
	std::map<int>stl_swap(3,2);
	ft_map.swap(ft_swap);
	stl_map.swap(stl_swap);

	std::cout << FG_YEL << "- Testing " << "swap() :" << FG_DEF << std::endl;

	state = v_check_state(ft_map, stl_map, "swap()");
	content = v_check_content(ft_map, stl_map, "swap()");

	if (state)
		std::cout << std::endl << "state " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << std::endl << "state " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}
	if (content)
		std::cout << "content " << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << "content " << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	return (ok);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	if (!strcmp(av[1], "map"))
	{
		std::cout << FG_YEL << "~==[ TESTS VECTOR ]==~" << FG_DEF << std::endl << std::endl << std::endl;

		bool ok = v_test();

		std::cout << std::endl << FG_YEL << "~==[ VERDICT : " << FG_DEF;
		if (ok)
			std::cout << FG_BLUE << "OK" << FG_DEF;
		else
			std::cout << FG_MAG << "KO" << FG_DEF;
		std::cout << FG_YEL << " ]==~" << FG_DEF << std::endl;
	}

	else if (!strcmp(av[1], "map"))
	{

	}

	else if (!strcmp(av[1],"stack"))
	{

	}

	return (0);
} 
