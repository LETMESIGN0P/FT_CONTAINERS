#pragma once

#include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{		
		// MEMBER TYPES / VALUES
		
		Container _cntr;
		
		public :

		typedef Container container_type;
		typedef T value_type;
		typedef size_t size_type;
		
		// CONSTRUCTORS / DESTRUCTORS

		explicit stack(const Container &cntr = Container())
		{
			_cntr = cntr;
		}

		~stack()
		{
		}

		// MEMBER FUNCTIONS

		bool empty() const
		{
			return (_cntr.empty());
		}

		size_type size() const
		{
			return (_cntr.size());
		}

		value_type& top()
		{
			return (_cntr.back());
		}

		const value_type& top() const
		{
			return (_cntr.back());
		}

		void push (const value_type& val)
		{
			_cntr.push_back(val);
		}

		void pop()
		{
			_cntr.pop_back();
		}

		// OPERATORS

		template <class T1, class C1>
		friend bool operator== (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		template <class T1, class C1>
		friend bool operator!= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		template <class T1, class C1>
		friend bool operator<= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		template <class T1, class C1>
		friend bool operator>= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		template <class T1, class C1>
		friend bool operator< (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		template <class T1, class C1>
		friend bool operator> (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
		
	};
	
	template <class T1, class C1>
	bool operator== (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	}

	template <class T1, class C1>
	bool operator!= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	}	

	template <class T1, class C1>
	bool operator<= (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	}

	template <class T1, class C1>
	bool operator>= (const stack<T1, C1> &lhs, const stack<T1, C1>& rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	}

	template <class T1, class C1>
	bool operator< (const stack<T1, C1> &lhs, const stack<T1, C1>& rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	template <class T1, class C1>
	bool operator> (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	}
}
