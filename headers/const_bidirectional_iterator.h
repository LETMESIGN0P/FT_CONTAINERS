#pragma once

#include <bidirectional_iterator.h>

namespace ft
{
	template <class T>
	class const_bidirectional_iterator
	{
		Node<T> *_it;
		T* 	 _pair;

		public :

		typedef T					value_type;
		typedef T*					pointer;
		typedef T&					reference;
		typedef	std::ptrdiff_t				difference_type;
		typedef bidirectional_iterator_tag<T>		iterator_category;
		typedef bidirectional_iterator<const T>		const_it;
		typedef Node<T>					elem_type;
	
		// CONSTRUCTORS / DESTRUCTORS

		const_bidirectional_iterator() :_it(NULL), _pair()
		{
		}
		
		const_bidirectional_iterator (const const_bidirectional_iterator &copy)
		{
			this = copy;
		}
		
		const_bidirectional_iterator (elem_type *copy)
		{
			_it = copy->_it;
			_pair = &(copy->_value);
		}

		~const_bidirectional_iterator()
		{
		}

		// OPERATORS
		
		const_bidirectional_iterator&	operator=(const const_bidirectional_iterator &);
		bool				operator==(const const_bidirectional_iterator &) const;
		bool				operator!=(const const_bidirectional_iterator &) const;
		reference			operator*() const;
		pointer				operator->() const;
		const_bidirectional_iterator&	operator++();
		const_bidirectional_iterator	operator++(int);
		const_bidirectional_iterator&	operator--();
		const_bidirectional_iterator	operator--(int);

		private :

		friend bool	operator==(const bidirectional_iterator<T> &lhs, const const_bidirectional_iterator &rhs) 
		{
			return (lhs.operator->() == rhs.operator->());
		}
		
		friend bool	operator!=(const bidirectional_iterator<T> &lhs, const const_bidirectional_iterator &rhs) 
		{
			return (lhs._it != rhs._it);
		}
	};

	template <class T>
	const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator=(const const_bidirectional_iterator &rhs)
	{
		_it = rhs._it;
		_pair = rhs._pair;
		return (*this);
	}

	template <class T>
	bool const_bidirectional_iterator<T>::operator==(const const_bidirectional_iterator &rhs) const
	{
		return (&_it->value == rhs.operator->());
	}


	template <class T>
	bool const_bidirectional_iterator<T>::operator!=(const const_bidirectional_iterator &rhs) const
	{
		return (_it != rhs._it);
	}


	template <class T>
	typename const_bidirectional_iterator<T>::reference const_bidirectional_iterator<T>::operator*() const
	{
		return (_it->value);
	}

	template <class T>
	typename const_bidirectional_iterator<T>::pointer const_bidirectional_iterator<T>::operator->() const
	{
		return (&_it->value);
	}

	template <class T>
	const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator++()
	{
		_it = _it->next();
		return (*this);
	}

	template <class T>
	const_bidirectional_iterator<T> const_bidirectional_iterator<T>::operator++(int)
	{
		const_bidirectional_iterator tmp = *this;
		_it = _it->next();
		return (tmp);
	}

	template <class T>
	const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator--()
	{
		_it = _it->prev();
		return (*this);
	}

	template <class T>
	const_bidirectional_iterator<T> const_bidirectional_iterator<T>::operator--(int)
	{
		const_bidirectional_iterator tmp = *this;
		_it = _it->prev();
		return (tmp);
	}
}
