#pragma once

#include <vector.h>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{		
		// MEMBER TYPES / VALUES
		
		protected :

		Container c;
		
		public :

		typedef Container	container_type;
		typedef T		value_type;
		typedef size_t		size_type;
		
		// CONSTRUCTORS / DESTRUCTORS

		explicit stack(const Container &cntr = Container())
		{
			c = cntr;
		}

		~stack()
		{
		}

		// MEMBER FUNCTIONS

		bool empty() const
		{
			return (c.empty());
		}

		size_type size() const
		{
			return (c.size());
		}

		value_type& top()
		{
			return (c.back());
		}

		const value_type& top() const
		{
			return (c.back());
		}

		void push (const value_type& val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

		// OPERATORS

		template <class T1, class C1>
		friend bool
		operator== (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
		template <class T1, class C1>
		friend bool
		operator!= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
		template <class T1, class C1>
		friend bool
		operator<= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
		template <class T1, class C1>
		friend bool
		operator>= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
		template <class T1, class C1>
		friend bool
		operator< (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
		template <class T1, class C1>
		friend bool
		operator> (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
	};
	
	template <class T1, class C1>
	bool operator== (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T1, class C1>
	bool operator!= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs.c != rhs.c);
	}	

	template <class T1, class C1>
	bool operator<= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T1, class C1>
	bool operator>= (const stack<T1, C1> &lhs, const stack<T1, C1>& rhs)
	{
		return (lhs.c >= rhs.c);
	}

	template <class T1, class C1>
	bool operator< (const stack<T1, C1> &lhs, const stack<T1, C1>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T1, class C1>
	bool operator> (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs.c > rhs.c);
	}
}
