#pragma once

#include <iterator_traits.h>
#include <random_access_iterator.h>

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		// MEMBER TYPES / VALUES

		Iterator _it;

		public :

		typedef Iterator						iterator_type;
		typedef typename iterator_traits<Iterator>::value_type		value_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::pointer		pointer;
		typedef typename iterator_traits<Iterator>::reference		reference;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

		// CONSTRUCTORS / DESTRUCTORS

		explicit reverse_iterator() : _it()
		{
		}

		reverse_iterator(iterator_type const &it) : _it(it)
		{
		}

		template <class T>
 		reverse_iterator<Iterator> (const reverse_iterator<T> &copy)
		{
			*this = copy;
		}

		// MEMBER FUNCTIONS

		iterator_type base() const
		{
			return (_it);
		}

		// OPERTAORS

		template <class T>
 		reverse_iterator<Iterator> &operator=(const reverse_iterator<T> &it)
		{
			_it = it.base();
			return (*this);
		}
		
		reference operator*() const
		{
			Iterator tmp = _it;
			return (*--tmp);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(_it - n));
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(_it - n));
		}

		reverse_iterator &operator++()
		{
			--_it;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--_it;
			return (tmp);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			_it -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(_it + n));
		}

		reverse_iterator &operator--()
		{
			++_it;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++_it;
			return (tmp);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			_it += n;
			return (*this);
		}

		pointer operator->() const
		{
			return (&(operator*()));
		}

		reference operator[](difference_type n) const
		{
			return (*(*this + n));
		}
	};
	
	template <class Iterator>
	bool operator==
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator> 
	bool operator!=
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());	
	}

	template <class Iterator>
	bool operator<=
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());	
	}

	template <class Iterator>
	bool operator>
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator>=
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());	
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+
	(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it.base() - n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-
	(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base - rhs.base());	
	}
}
