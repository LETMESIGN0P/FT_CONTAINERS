#include <asm-generic/errno.h>
#include <cstdio>
#include <iostream>
#include <colormod.h>
#include <iterator>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
#include <stdio.h>

#include <vector.h>
//#include <map.h>
//#include <stack.h>

bool v_check_state_const(const ft::vector<int> &ft_vec, const std::vector<int> &stl_vec)
{
	bool ok = true;

	if (ft_vec.size() != stl_vec.size())
	{
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "size()" << FG_DEF;
		ok = false;
	}
	if (ft_vec.max_size() != stl_vec.max_size())
	{
		if (ok)
			std::cout << std::endl;
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "max_size()" << FG_DEF;
		ok = false;
	}
	if (ft_vec.capacity() != stl_vec.capacity())
	{
		if (ok)
			std::cout << std::endl;
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "capacity()" << FG_DEF;
		ok = false;
	}
	if (ft_vec.empty() != stl_vec.empty())
	{
		if (ok)
			std::cout << std::endl;
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "empty()" << FG_DEF;
		ok = false;	
	}
	if (stl_vec.size() && ft_vec.front() != stl_vec.front())
	{
		if (ok)
			std::cout << std::endl;
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "front()" << FG_DEF;
		ok = false;
	}
	if (stl_vec.size() && ft_vec.back() != stl_vec.back())
	{
		if (ok)
			std::cout << std::endl;
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "back()" << FG_DEF;
		ok = false;
	}
	if (ft_vec.get_allocator() != stl_vec.get_allocator())
	{
		if (ok)
			std::cout << std::endl;
		std::cout << std::endl << "function's return value is fucked : " << FG_MAG << "get_allocator()" << FG_DEF;
		ok = false;
	}

	if (!ok)
		std::cout << std::endl;
	return (ok);
}

bool v_check_content_const (const ft::vector<int> &ft_vec, const std::vector<int> &stl_vec)
{
	bool ok = true;

	int n = stl_vec.size();
	while (n--)
	{
		if (ft_vec[n] != stl_vec[n])
		{
			std::cout << std::endl << "content was incorrect at index" << FG_YEL << " [" << n << "]" << FG_DEF << " : expected " << FG_YEL << stl_vec[n] << FG_DEF << ", got " << FG_MAG << ft_vec[n] << FG_DEF;
			ok = false;
		}
	}

	if (!ok)
		std::cout << std::endl;

	n = stl_vec.size();

	if (n && ft_vec.at(0) != stl_vec.at(0))
	{
		std::cout << std::endl;
		if (!ok)
			std::cout << std::endl;

		std::cout <<"function's return value is fucked : " << FG_MAG << "at()" << FG_DEF << std::endl;
		ok = false;
	}
	if (n && *ft_vec.begin() != *stl_vec.begin())
	{
		if (ok)
			std::cout << std::endl;
		std::cout <<"function's return value is fucked : " << FG_MAG << "begin()" << FG_DEF << std::endl;
		ok = false;
	}

	if (n && *(ft_vec.end() - 1) != *(stl_vec.end() - 1))
	{
		if (ok)
			std::cout << std::endl;
		std::cout <<"function's return value is fucked : " << FG_MAG << "end()" << FG_DEF << std::endl;
		ok = false;
	}
	if (n && *ft_vec.rbegin() != *stl_vec.rbegin())
	{
		if (ok)
			std::cout << std::endl;
		std::cout <<"function's return value is fucked : " << FG_MAG << "rbegin()" << FG_DEF << std::endl;
		ok = false;
	}
	if (n && *ft_vec.rend().base() != *stl_vec.rend().base())
	{
		if (ok)
			std::cout << std::endl;
		std::cout <<"function's return value is fucked : " << FG_MAG << "rend()" << FG_DEF << std::endl;
		ok = false;
	}

	if (!ok)
		std::cout << std::endl;

	return (ok);
}

bool v_check_state(ft::vector<int> &ft_vec, std::vector<int> &stl_vec, std::string test)
{
	bool ok = true;
	bool constructor = (test.find("constructor") != std::string::npos);

	if (ft_vec.size() != stl_vec.size())
	{
		if (constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "size()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_vec.max_size() != stl_vec.max_size())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "max_size()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_vec.capacity() != stl_vec.capacity())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "capacity()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_vec.empty() != stl_vec.empty())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "empty()" << FG_DEF << " function";
		ok = false;	
	}
	if (stl_vec.size() && ft_vec.front() != stl_vec.front())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "front()" << FG_DEF << " function";
		ok = false;
	}
	if (stl_vec.size() && ft_vec.back() != stl_vec.back())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "back()" << FG_DEF << " function";
		ok = false;
	}
	if (ft_vec.get_allocator() != stl_vec.get_allocator())
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

bool v_check_content(ft::vector<int> &ft_vec, std::vector<int> &stl_vec, std::string const &test)
{
	bool ok = true;
	bool constructor = (test.find("constructor") != std::string::npos);

	int n = stl_vec.size();

	while (n--)
	{
		if (ft_vec[n] != stl_vec[n])
		{
			std::cout << std::endl << "content was incorrect at index" << FG_YEL << " [" << n << "]" << FG_DEF << " : expected " << FG_YEL << stl_vec[n] << FG_DEF << ", got " << FG_MAG << ft_vec[n] << FG_DEF;

			ok = false;
		}
		ft_vec[n] = n;
		stl_vec[n] = n;
	}


	if (!ok)
		std::cout << std::endl;

	n = stl_vec.size();

	if (n && ft_vec.at(0) != stl_vec.at(0))
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "at()" << FG_DEF << " function";
		ok = false;
	}
	if (n && *ft_vec.begin() != *stl_vec.begin())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "begin()" << FG_DEF << " function";
		ok = false;
	}

	if (n && *(ft_vec.end() - 1) != *(stl_vec.end() - 1))
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "end()" << FG_DEF << " function";
		ok = false;
	}
	if (n && *ft_vec.rbegin() != *stl_vec.rbegin())
	{
		if (ok && constructor)
			std::cout << std::endl;

		std::cout << std::endl << "calls to " << FG_YEL << test << FG_DEF << " fucked up the return value of the " << FG_MAG << "rbegin()" << FG_DEF << " function";
		ok = false;
	}
	if (n && *ft_vec.rend().base() != *stl_vec.rend().base())
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

	ft::vector<int> ft_vec_def;
	std::vector<int> stl_vec_def;

	state = v_check_state(ft_vec_def, stl_vec_def, "default constructor");
	content = v_check_content(ft_vec_def, stl_vec_def, "default constructor");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	std::cout << FG_YEL << "- PARAMETRIC CONSTRUCTOR (size_t, const &value_type) " << FG_DEF;

	ft::vector<int> ft_vec(4, 2);
	std::vector<int> stl_vec(4, 2);
	state = v_check_state(ft_vec, stl_vec, "parametric constructor (size_t, const &value_type)");
	content = v_check_content(ft_vec, stl_vec, "parametric constructor (size_t, const &value_type)");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	std::cout << FG_YEL << "- PARAMETRIC CONSTRUCTOR (InputIterator, InputIterator) " << FG_DEF;

	ft::vector<int> ft_vec_par2(ft_vec.begin(), ft_vec.end());
	std::vector<int> stl_vec_par2(stl_vec.begin(), stl_vec.end());
	state = v_check_state(ft_vec_par2, stl_vec_par2, "parametric constructor (InputIterator, InputIterator)");
	content = v_check_content(ft_vec_par2, stl_vec_par2, "parametric constructor (size_t, const &value_type)");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	std::cout << FG_YEL << "- COPY CONSTRUCTOR (InputIterator, InputIterator) " << FG_DEF;

	ft::vector<int> ft_vec_cpy(ft_vec.begin(), ft_vec.end());
	std::vector<int> stl_vec_cpy(stl_vec.begin(), stl_vec.end());
	state = v_check_state(ft_vec_cpy, stl_vec_cpy, "copy constructor");
	content = v_check_content(ft_vec_cpy, stl_vec_cpy, "copy constructor");

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl;
		ok = false;
	}

	std::cout << std::endl;

	// CONST INSTANCE

	const ft::vector<int> ft_vec_const(ft_vec);
	const ft::vector<int> ft_vec_const2(ft_vec_const);
	const std::vector<int> stl_vec_const(stl_vec);

	std::cout << FG_YEL << "- CONST INSTANCE " << FG_DEF;

	// IF COMPARISON IMPOSSIBLE -> OVERLOAD TYPE OPERATOR IN RANDOM_ACCESS_ITERATOR TO ALLOW FOR IMPLICIT CONVERSION BEETWEEN CONST AND NON-CONST
	if (ft_vec_const.begin() != ft_vec.begin())
	{
		;
	}

	state = v_check_state_const(ft_vec_const, stl_vec_const);
	content = v_check_content_const(ft_vec_const, stl_vec_const);

	if (state && content)
		std::cout << FG_BLUE << "OK" << FG_DEF << std::endl;
	else
	{
		std::cout << FG_MAG << "KO" << FG_DEF << std::endl << std::endl;
		ok = false;
	}

	// OPERATORS
	
	std::cout << FG_YEL << "- OPERATORS " << FG_DEF;

	if (!(ft_vec_const == ft_vec_const2) || ft_vec == ft_vec_def)
	{
		state = false;
		std::cout << std::endl << std::endl << "the operator " << FG_MAG << "==" << FG_DEF << " is broken";
	}
	if (ft_vec_const != ft_vec_const2 || !(ft_vec != ft_vec_def))
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "!=" << FG_DEF << " is broken";
	}
	if (ft_vec_const > ft_vec_const2 || !(ft_vec > ft_vec_def))
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << ">" << FG_DEF << " is broken";
	}
	if (ft_vec_const2 < ft_vec_const || !(ft_vec_def < ft_vec))
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "<" << FG_DEF << " is broken";
	}
	if (!(ft_vec_const >= ft_vec_const2) || ft_vec_def >= ft_vec)
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << ">=" << FG_DEF << " is broken";
	}
	if (!(ft_vec_const2 >= ft_vec_const) || ft_vec_def <= ft_vec)
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "<=" << FG_DEF << " is broken";
	}
	if (!(ft_vec_const2 >= ft_vec_const) || ft_vec_def <= ft_vec)
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "<=" << FG_DEF << " is broken";
	}
	if (ft_vec[0] != stl_vec[0])
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "[]" << FG_DEF << " is broken";
	}
	if (ft_vec_const[0] != stl_vec[0])
	{
		if (state)
			std::cout << std::endl;
		state = false;
		std::cout  << std::endl<< "the operator " << FG_MAG << "[] const" << FG_DEF << " is broken";
	}

	ft::vector<int> eq;
	eq = ft_vec;
	
	if (ft_vec != eq || ft_vec.size() != eq.size() || ft_vec.max_size() || ft_vec.capacity() != eq.capacity() || ft_vec.empty() != eq.empty() || \
		ft_vec.front() != eq.front() || ft_vec.back() != eq.back() || ft_vec.get_allocator() != eq.get_allocator())
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

	ft_vec.resize(20, 1);
	stl_vec.resize(20, 1);
	ft_vec.resize(0);
	stl_vec.resize(0);
	ft_vec.resize(5);
	stl_vec.resize(5);

	state = v_check_state(ft_vec, stl_vec, "resize()");
	content = v_check_content(ft_vec, stl_vec, "resize()");

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

	ft_vec.reserve(0);
	stl_vec.reserve(0);
	ft_vec.reserve(6);
	stl_vec.reserve(6);
	
	state = v_check_state(ft_vec, stl_vec, "reserve()");
	content = v_check_content(ft_vec, stl_vec, "reserve()");

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

	ft_vec.assign(0, 3);
	stl_vec.assign(0, 3);
	ft_vec.assign(2, 4);
	stl_vec.assign(2, 4);
	ft_vec.assign(stl_vec.capacity() + 1, 3);
	stl_vec.assign(stl_vec.capacity() + 1, 3);
	ft_vec.assign(2, 4);
	stl_vec.assign(2, 4);
	
	state = v_check_state(ft_vec, stl_vec, "assign()");
	content = v_check_content(ft_vec, stl_vec, "assign()");

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

	ft_vec.assign(ft_vec.begin(), ft_vec.begin());
	stl_vec.assign(stl_vec.begin(), stl_vec.begin());
	ft_vec.assign(ft_vec.begin(), ft_vec.begin() + 1);
	stl_vec.assign(stl_vec.begin(), stl_vec.begin() + 1);
	ft_vec.assign(stl_vec.capacity() + 1, 3);
	stl_vec.assign(stl_vec.capacity() + 1, 3);
	ft_vec.assign(ft_vec.begin(), ft_vec.end());
	stl_vec.assign(stl_vec.begin(), stl_vec.end());

	state = v_check_state(ft_vec, stl_vec, "assign()");
	content = v_check_content(ft_vec, stl_vec, "assign()");

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

	//if (ft_vec.assign(1, 2))
	//	std::cout << FG_MAG << "enable_if" << FG_DEF << " failure" << std::endl;

	std::cout << std::endl;

	// CLEAR()

	std::cout << FG_YEL << "- Testing " << "clear() :" << FG_DEF << std::endl;

	ft_vec.clear();
	stl_vec.clear();

	state = v_check_state(ft_vec, stl_vec, "clear()");
	content = v_check_content(ft_vec, stl_vec, "clear()");

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

	ft_vec.push_back(6);
	stl_vec.push_back(6);
	ft_vec.push_back(6);
	stl_vec.push_back(6);
	ft_vec.push_back(7);
	stl_vec.push_back(7);

	state = v_check_state(ft_vec, stl_vec, "push_back()");
	content = v_check_content(ft_vec, stl_vec, "push_back()");

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

	ft_vec.pop_back();
	stl_vec.pop_back();

	state = v_check_state(ft_vec, stl_vec, "pop_back()");
	content = v_check_content(ft_vec, stl_vec, "pop_back()");

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

	while (stl_vec.size())
	{
		ft_vec.pop_back();
		stl_vec.pop_back();
	}

	std::cout << std::endl;

	// INSERT (iterator, const &value_type)

	std::cout << FG_YEL << "- Testing " << "insert (iterator, const &value_type) :" << FG_DEF << std::endl;

	ft_vec.insert(ft_vec.begin(), 5);
	stl_vec.insert(stl_vec.begin(), 5);
	ft_vec.insert(ft_vec.end(), 5);
	stl_vec.insert(stl_vec.end(), 5);
	ft_vec.insert(ft_vec.begin() + 1, 5);
	stl_vec.insert(stl_vec.begin() + 1, 5);

	state = v_check_state(ft_vec, stl_vec, "insert()");
	content = v_check_content(ft_vec, stl_vec, "insert()");

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

	ft_vec.insert(ft_vec.begin(), 2, 3);
	stl_vec.insert(stl_vec.begin(), 2, 3);

	ft::vector<int> t;
	t.push_back(1);
	t.push_back(1);
	t.push_back(1);
	t.insert(t.end(), t.begin(), t.end());
	//t.insert(ft::vector<int>::iterator(NULL), stl_vec.begin(), stl_vec.end());

	state = v_check_state(ft_vec, stl_vec, "insert()");
	content = v_check_content(ft_vec, stl_vec, "insert()");

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

	ft_vec.insert(ft_vec.begin(), ft_vec.begin(), ft_vec.begin());
	stl_vec.insert(stl_vec.begin(), stl_vec.begin(), stl_vec.begin());
	ft_vec.insert(ft_vec.begin() + 1, ft_vec.begin(), ft_vec.begin() + 1);
	stl_vec.insert(stl_vec.begin() + 1, stl_vec.begin(), stl_vec.begin() + 1);
	ft_vec.insert(ft_vec.end(), ft_vec.begin(), ft_vec.begin() + 2);
	stl_vec.insert(stl_vec.end(), stl_vec.begin(), stl_vec.begin() + 2);
	ft_vec.insert(ft_vec.end(), ft_vec.begin(), ft_vec.end());
	stl_vec.insert(stl_vec.end(), stl_vec.begin(), stl_vec.end());
	//ft_vec.insert(ft::vector<int>::iterator(NULL), ft_vec.begin(), ft_vec.end());
	//stl_vec.insert(std::vector<int>::iterator(NULL), stl_vec.begin(), stl_vec.end());

	//state = v_check_state(ft_vec, stl_vec, "insert()");
	//content = v_check_content(ft_vec, stl_vec, "insert()");

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

	//if (ft_vec.assign(1, 2))
	//	std::cout << FG_MAG << "enable_if" << FG_DEF << " failure" << std::endl;
	
	std::cout << std::endl;
	
	ft_vec.clear();
	stl_vec.clear();

	for (int i = 0; i < 10; i++)
	{
		ft_vec.push_back(i);
		stl_vec.push_back(i);
	}

	// ERASE (iterator)

	std::cout << FG_YEL << "- Testing " << "erase (iterator) :" << FG_DEF << std::endl;

	size_t ft_ret_index;
	size_t stl_ret_index;

	ft_ret_index = ft_vec.erase(ft_vec.begin()) - ft_vec.begin();
	stl_ret_index = stl_vec.erase(stl_vec.begin()) - stl_vec.begin();

	if (ft_ret_index != stl_ret_index)
		std::cout << std::endl << FG_YEL << "test 1" << FG_DEF << " : wrong return value : expected index " << FG_YEL << "[" << stl_ret_index << "]" << FG_DEF << ", got iterator to index " << FG_MAG << "[" << ft_ret_index << "]" << FG_DEF << std::endl;
	
	ft_ret_index = ft_vec.erase(ft_vec.begin() + 1) - ft_vec.begin();
	stl_ret_index = stl_vec.erase(stl_vec.begin() + 1) - stl_vec.begin();
	
	if (ft_ret_index != stl_ret_index)
		std::cout << std::endl << FG_YEL << "test 2" << FG_DEF << " : wrong return value : expected index " << FG_YEL << "[" << stl_ret_index << "]" << FG_DEF << ", got iterator to index " << FG_MAG << "[" << ft_ret_index << "]" << FG_DEF << std::endl;

	state = v_check_state(ft_vec, stl_vec, "erase()");
	content = v_check_content(ft_vec, stl_vec, "erase()");

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

	ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 1);
	stl_vec.erase(stl_vec.begin(), stl_vec.begin() + 1);
	ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 2);
	stl_vec.erase(stl_vec.begin(), stl_vec.begin() + 2);

	std::cout << FG_YEL << "- Testing " << "erase (iterator, iterator) :" << FG_DEF << std::endl;

	state = v_check_state(ft_vec, stl_vec, "erase()");
	content = v_check_content(ft_vec, stl_vec, "erase()");

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

	ft::vector<int>ft_swap(3,2);
	std::vector<int>stl_swap(3,2);
	ft_vec.swap(ft_swap);
	stl_vec.swap(stl_swap);

	std::cout << FG_YEL << "- Testing " << "swap() :" << FG_DEF << std::endl;

	state = v_check_state(ft_vec, stl_vec, "swap()");
	content = v_check_content(ft_vec, stl_vec, "swap()");

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
