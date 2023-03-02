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

		reverse_iterator() : _it()
		{
		}

		explicit reverse_iterator(iterator_type const &it) : _it(it)
		{
		}

		template <class Iter>
 		reverse_iterator<Iterator> (const reverse_iterator<Iter> &copy)
		{
			*this = copy;
		}
		
		~reverse_iterator()
		{
		}

		// MEMBER FUNCTIONS

		iterator_type base() const
		{
			return (_it);
		}

		// OPERTATORS

		template <class T>
 		reverse_iterator<Iterator> &operator=(const reverse_iterator<T> &it)
		{
			_it = it.base();
			return (*this);
		}
		
		reference operator*() const
		{
			Iterator tmp = _it;
			return (*(--tmp));
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
    		
	template <class A, class B>
	bool operator<=(const reverse_iterator<A> &_x, const reverse_iterator<B> &_y)
    	{
        	return (_x.base() >= (_y.base()));
    	}

        template <class A, class B>
	bool operator==(const reverse_iterator<A> &lhs, const reverse_iterator<B> &rhs)
    	{
        	return lhs.base()== (rhs.base());
   	}
        
	template <class A>
	bool operator==(const reverse_iterator<A> &lhs, const reverse_iterator<A> &rhs)
    	{
        	return lhs.base()== (rhs.base());
    	}

 	template <class A, class B>
	bool operator!=(const reverse_iterator<A> &lhs, const reverse_iterator<B> &rhs)
    	{
        	return lhs.base()!= (rhs.base());
    	}
 	template <class A>
	bool operator!=(const reverse_iterator<A> &lhs, const reverse_iterator<A> &rhs)
    	{
        	return lhs.base()!= (rhs.base());
    	}

	template <class A, class B>
	bool operator>(const reverse_iterator<A> &_x, const reverse_iterator<B> &_y)
    	{
        	return _x.base() < (_y.base());
    	}

	template <class A>
	bool operator>(const reverse_iterator<A> &_x, const reverse_iterator<A> &_y)
    	{
        	return _x.base() < (_y.base());
    	}
	
	template <class A>
	bool operator<=(const reverse_iterator<A> &_x, const reverse_iterator<A> &_y)
    	{
        	return (_x.base() >= (_y.base()));
    	}

	template <class A, class B>
	bool operator<(const reverse_iterator<A> &_x, const reverse_iterator<B> &_y)
   	{
        	return _x.base() > (_y.base());
    	}

	template <class A>
	bool operator<(const reverse_iterator<A> &_x, const reverse_iterator<A> &_y)
    	{
        	return _x.base() > (_y.base());
    	}
	
	template <class A, class B>
	bool operator>=(const reverse_iterator<A> &_x, const reverse_iterator<B> &_y)
    	{
        	return (_x.base() <= (_y.base()));
    	}

    	template <class A>
	bool operator>=(const reverse_iterator<A> &_x, const reverse_iterator<A> &_y)
    	{
        	return (_x.base() <= (_y.base()));
    	}
	
	template <class Iterator>
	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return reverse_iterator<Iterator>(it.base() - n);
	}

    	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}
