#pragma once

#include "node.h"

namespace ft
{
	struct bidirectional_iterator_tag
	{
	};
	
	template <class T>
	class const_bidirectional_iterator;
	
	template <class T>
		class bidirectional_iterator
		{
			public :
				typedef	T						value_type;
				typedef	T						*pointer;
				typedef	T						&reference;
				typedef	std::ptrdiff_t					difference_type;
				typedef	bidirectional_iterator_tag			iterator_category;
				typedef bidirectional_iterator<const T>			const_it;
				typedef	Node<T>						elem_type;

				elem_type	*_it;
				pointer		_pair;

				// CONSTRUCTORS / DESTRUCTOR

				bidirectional_iterator() : _it(NULL), _pair()
				{
				}

				bidirectional_iterator(const bidirectional_iterator &copy) : _it(copy._it), _pair(copy._pair)
				{
				}

				bidirectional_iterator(elem_type *copy) : _it(copy), _pair(&copy->val)
				{
				}

				~bidirectional_iterator()
				{
				}

				bidirectional_iterator	&operator=(const bidirectional_iterator &copy)
				{
					_it = copy._it;
					_pair = copy._pair;
					return (*this);
				}

				template <class U>
				bidirectional_iterator	&operator=(const const_bidirectional_iterator<U> &copy)
				{
					_it = copy._it;
					_pair = copy._pair;
					return (*this);
				}

				bool	operator==(const bidirectional_iterator &rhs) const
				{	
					return (&_it->val == rhs.operator->());
				}

				bool	operator!=(const bidirectional_iterator &rhs) const
				{
					return (_it != rhs._it);
				}

				reference	operator*() const
				{
					return (_it->val);
				}
			
				pointer			operator->() const
				{
					return (&_it->val);
				}

				bidirectional_iterator	&operator++()
				{
					_it = _it->next();
					return (*this);
				}

				bidirectional_iterator	operator++(int)
				{
					bidirectional_iterator	tmp = *this;
					_it = _it->next();
					return (tmp);
				}

				bidirectional_iterator	&operator--()
				{
					_it = _it->prev();
					return (*this);
				}

				bidirectional_iterator	operator--(int)
				{
					bidirectional_iterator	tmp = *this;
					_it = _it->prev();
					return (tmp);
				}
		};
};
