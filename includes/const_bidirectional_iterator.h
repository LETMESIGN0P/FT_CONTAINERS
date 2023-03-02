#pragma once

#include <bidirectional_iterator.h>

namespace ft
{
	template <class T>
		class const_bidirectional_iterator
		{
			public :
				typedef	T							value_type;
				typedef	T*							pointer;
				typedef	T&							reference;
				typedef std::ptrdiff_t						difference_type;
				typedef	ft::bidirectional_iterator_tag				iterator_category;
				typedef const_bidirectional_iterator<const T>			const_it;
				typedef	Node<T>							elem_type;

				elem_type	*_it;
				pointer		_pair;

				// CONSTRUCTORS / DESTRUCTOR

				const_bidirectional_iterator() : _it(NULL), _pair()
				{
				}

				const_bidirectional_iterator(const const_bidirectional_iterator &copy) : _it(copy._it), _pair(copy._pair)
				{
				}

				const_bidirectional_iterator(const ft::bidirectional_iterator<T> &copy) : _it(copy._it), _pair(copy._pair)
				{
				}

				const_bidirectional_iterator(elem_type *copy) : _it(copy), _pair(&copy->val)
				{
				}

				~const_bidirectional_iterator()
				{
				}

				const_bidirectional_iterator	&operator=(const const_bidirectional_iterator &copy)
				{
					_it = copy._it;
					_pair = copy._pair;
					return (*this);
				}

				bool	operator==(const const_bidirectional_iterator &rhs) const
				{	
					return (&_it->val == rhs.operator->());
				}

				bool	operator!=(const const_bidirectional_iterator &rhs) const
				{
					return (_it != rhs._it);
				}

				reference	operator*() const
				{
					return (_it->val);
				}
			
				pointer		operator->() const
				{
					return (&_it->val);
				}

				const_bidirectional_iterator	&operator++()
				{
					_it = _it->next();
					return (*this);
				}

				const_bidirectional_iterator	operator++(int)
				{
					const_bidirectional_iterator	tmp = *this;
					_it = _it->next();
					return (tmp);
				}

				const_bidirectional_iterator	&operator--()
				{
					_it = _it->prev();
					return (*this);
				}

				const_bidirectional_iterator	operator--(int)
				{
					const_bidirectional_iterator	tmp = *this;
					_it = _it->prev();
					return (tmp);
				}
		};
};
