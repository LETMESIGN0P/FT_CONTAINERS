#pragma once

#include <Node.h>

namespace ft
{
	template <class T>
	struct bidirectional_iterator_tag
	{
	};


	template <class T>
	class bidirectional_iterator
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

		bidirectional_iterator() :_it(NULL), _pair()
		{
		}
		
		bidirectional_iterator (const bidirectional_iterator &copy)
		{
			this = copy;
		}
		
		bidirectional_iterator (elem_type *copy)
		{
			_it = copy->_it;
			_pair = &(copy->_value);
		}

		~bidirectional_iterator()
		{
		}

		// OPERATORS
		
		
		bidirectional_iterator&		operator=(const bidirectional_iterator &);
		bool				operator==(const bidirectional_iterator &) const;
		bool				operator!=(const bidirectional_iterator &) const;
		reference			operator*() const;
		pointer				operator->() const;
		bidirectional_iterator&		operator++();
		bidirectional_iterator		operator++(int);
		bidirectional_iterator&		operator--();
		bidirectional_iterator		operator--(int);
	};

	template <class T>
	bidirectional_iterator<T> &bidirectional_iterator<T>::operator=(const bidirectional_iterator &rhs)
	{
		_it = rhs._it;
		_pair = rhs._pair;
		return (*this);
	}

	template <class T>
	bool bidirectional_iterator<T>::operator==(const bidirectional_iterator &rhs) const
	{
		return (&_it->value == rhs.operator->());
	}


	template <class T>
	bool bidirectional_iterator<T>::operator!=(const bidirectional_iterator &rhs) const
	{
		return (_it != rhs._it);
	}


	template <class T>
	typename bidirectional_iterator<T>::reference bidirectional_iterator<T>::operator*() const
	{
		return (_it->value);
	}

	template <class T>
	typename bidirectional_iterator<T>::pointer bidirectional_iterator<T>::operator->() const
	{
		return (&_it->value);
	}

	template <class T>
	bidirectional_iterator<T> &bidirectional_iterator<T>::operator++()
	{
		_it = _it->next();
		return (*this);
	}

	template <class T>
	bidirectional_iterator<T> bidirectional_iterator<T>::operator++(int)
	{
		bidirectional_iterator tmp = *this;
		_it = _it->next();
		return (tmp);
	}

	template <class T>
	bidirectional_iterator<T> &bidirectional_iterator<T>::operator--()
	{
		_it = _it->prev();
		return (*this);
	}

	template <class T>
	bidirectional_iterator<T> bidirectional_iterator<T>::operator--(int)
	{
		bidirectional_iterator tmp = *this;
		_it = _it->prev();
		return (tmp);
	}
}
