#pragma once

#include <iterator_traits.h>

namespace ft
{
	template <class T>
	struct random_access_iterator_tag
	{
	};

	template <class T>
	class random_access_iterator
	{
		// MEMBER TYPES / VALUES

		T*	_it;

		public :

		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag<T> iterator_category;

		// MEMBER FUNCTIONS
		
		pointer base() const
		{
			return (_it);
		}

		// CONSTRUCTORS / DESTRUCTORS

		random_access_iterator()
		{
			_it = 0;
		}

		random_access_iterator(pointer ptr)
		{
			_it = ptr;
		}

		random_access_iterator(const random_access_iterator &copy)
		{
			_it = copy._it;
		}

		~random_access_iterator()
		{
		}

		// OPERATORS

		random_access_iterator &operator=(const random_access_iterator &rhs)
		{
			if (this != &rhs)
				_it = rhs._it;
			return (*this);
		}

		pointer operator->() const
		{
			return (_it);
		}

		reference operator*() const
		{
			return (*_it);
		}

		operator random_access_iterator<const T>() const
		{
			return (random_access_iterator<const T>(_it));
		}

		random_access_iterator &operator++()
		{
			++_it;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			++_it;
			return (tmp);
		}

		random_access_iterator &operator--()
		{
			--_it;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			--_it;
			return (tmp);
		}

		random_access_iterator operator+(const difference_type n) const
		{
			return (random_access_iterator(_it + n));
		}

		difference_type operator-(const random_access_iterator<T> &rhs) const
		{
			return (_it - rhs.operator->());
		}
		
		random_access_iterator operator-(const difference_type n) const
		{
			return (random_access_iterator(_it - n));
		}

		random_access_iterator &operator+=(difference_type n)
		{
			_it += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_it -= n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return (_it[n]);
		}
	};
		
		template <class T>
		bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template <class T, class T2>
		bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
			return (lhs.base() == rhs.base());
		}
		
		template <class T>
		bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

		template <class T>
		bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
			return (lhs.base() < rhs.base());
		}

		template <class T>
		bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
			return (lhs.base() > rhs.base());
		}

		template <class T>
		bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
			return (lhs.base() <= rhs.base());
		}

		template <class T>
		bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
			return (lhs.base() >= rhs.base());
		}
		/////////////////////////
		
		template <class T, class T2>
		bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

		template <class T, class T2>
		bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
			return (lhs.base() < rhs.base());
		}

		template <class T, class T2>
		bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
			return (lhs.base() > rhs.base());
		}

		template <class T, class T2>
		bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
			return (lhs.base() <= rhs.base());
		}

		template <class T, class T2>
		bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
			return (lhs.base() >= rhs.base());
		}

		template <class T>
		random_access_iterator<T> 
		operator+(const typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &rhs)
		{
			return (rhs.base() + n);
		}

		template <class T, class T2>
		typename random_access_iterator<T>::difference_type
		operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T2> &rhs)
		{
    			return (lhs.base() - rhs.base());
		}

		template <class T>
		typename random_access_iterator<T>::difference_type 
		operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
		{
    			return (lhs.base() - rhs.base());
		}
}
