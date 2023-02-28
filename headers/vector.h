#pragma once

#include <asm-generic/errno.h>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <random_access_iterator.h>
#include <reverse_iterator.h>
#include <compare.h>
#include <enable_if.h>


namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		// MEMBER TYPES / VALUES

		Alloc				_alloc;
		typename Alloc::pointer		_begin;
		typename Alloc::pointer		_end;
		typename Alloc::pointer		_storage_end;

		public :

		typedef	T							value_type;
		typedef Alloc							allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference				const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer				const_pointer;
		typedef random_access_iterator<value_type>			iterator;
		typedef random_access_iterator<const value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t							size_type;

		// CONSTRUCTORS / DESTRUCTORS

		explicit vector (const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_begin = NULL;
			_end = NULL;
			_storage_end = NULL;
		}
	
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_begin = NULL;
			_end = NULL;
			_storage_end = NULL;
			assign(n, val);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_begin = NULL;
			_end = NULL;
			_storage_end = NULL;
			assign(first, last);
		}

		vector (const vector& x)
		{
			_alloc = allocator_type();
			_begin = NULL;
			_end = NULL;
			_storage_end = NULL;
	
			*this = x;	
		}

		~vector()
		{
			if (_begin)
				destroy_block(_begin, size());
		}

		// MEMBER FUNCTIONS

		private :

		void construct_block(pointer start, size_t n, const value_type value)
		{
			while (start && n--)
				_alloc.construct(start++, value);
		}

		void clear_block(pointer start, size_type n)
		{
			while (n-- && start < _storage_end)
				_alloc.destroy(start++);
		}


		void destroy_block(pointer start, size_t n)
		{
			clear_block(start, n);
			if (n)
				_alloc.deallocate(start, n);
		}

		void expand (size_t n)
		{
			size_type s = size();
			pointer begin_old = _begin;
			_begin = _alloc.allocate(n);

			size_type i = -1;
			while (++i != s)
				_alloc.construct(_begin + i, *(begin_old++));
			_end = _begin + s;
			destroy_block(begin_old - s, capacity());
			_storage_end = _begin + n;
		}

		public :
 

		size_type size() const
		{
			return (static_cast<size_type>(_end - _begin));
		}

		size_type max_size() const
		{
			return (std::numeric_limits<difference_type>::max() / sizeof(T));
		}

		void resize (size_type n, value_type value = value_type())
		{
			if (n == size())
				return;
			if (n < size())
			{
				_end -= size() - n;
				clear_block(_end, size() - n);
			}
			else if (n > size())
			{
				if (n > capacity())
					expand(n);
				construct_block(_end, n - size(), value);
				_end += n - size();
			}
		}

		size_type capacity() const
		{
			return (static_cast<size_type>(_storage_end - _begin));
		}

		bool empty() const
		{
			return (_begin == _end);
		}

		void reserve (size_type n)
		{
			if (n > capacity())
				expand(n);
		}

		reference at (size_type n)
		{
			if (n >= size())
				throw (std::out_of_range("vector"));
			return (_begin[n]);
		}

		const_reference at (size_type n) const
		{
			if (n >= size())
				throw (std::out_of_range("vector"));
			return (_begin[n]);
		}

		reference front()
		{
			return (*_begin);
		}

		const_reference front() const
		{
			return (*_begin);
		}

		reference back()
		{
			return (*(_end - 1));
		}

		const_reference back() const
		{
			return (*(_end - 1));
		}

		void assign (size_type n, const value_type& value)
		{
			if (n)
			{
				reserve(n);
				_end = _begin + n;
				clear_block(_begin, size());
				construct_block(_begin, n, value);
			}
			else
				_end = _begin;
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type assign (InputIterator first, InputIterator last)
		{
			size_type n = last - first;
			if (n)
			{
				reserve(n);
				_end = _begin + n;
				clear_block(_begin, size());

				for (size_t i = 0; i < n; i++)
					_alloc.construct(_begin + i, *(first++));
			}
			else
				_end = _begin;
		}


		void push_back (const value_type &value)
		{
			size_type c = capacity();
			if (c && size() + 1 > c)
				expand(c * 2);
			else if (size() + 1 > c)
				expand(1);
			_alloc.construct(_end, value);
			_end++;
		}

		void pop_back()
		{
			if (size())
			{
				clear_block(_end - 1, 1);
				_end--;
			}
		}

		iterator insert (iterator position, const value_type& value)
		{
			size_type index;

			index = position - begin();
			insert(position, 1, value);
			return (begin() + index);
		}

		void insert (iterator position, size_type n, const value_type& value)
		{
			if (capacity() < size() + n)
			{
				if (!capacity())
					reserve(n);
				else
				{
					if (capacity() * 2 < capacity() + n)
						reserve(capacity() * 2 + n);
					else
						reserve(capacity() * 2);
				}
			}

			if (position.base() == NULL)
				position = begin();

			pointer new_end = _end + n;
			size_type j = size() - (position - begin());

			for (size_type i = 1; i <= j; i++)
				_alloc.construct(new_end - i, *(_end - i));
			
			_end = new_end;
			clear_block(_begin + (position - begin()), n);
			
			while (n--)
				_alloc.construct(_begin + (position++ - begin()), value);
		}


		template <class InputIterator>
		typename enable_if<!ft::is_integral<InputIterator>::value, void>::type insert (iterator position, InputIterator first, InputIterator last)
		{
			size_type n = last - first;
			
			if (capacity() < size() + n)
			{
				if (!capacity())
					reserve(n);
				else
				{
					if (capacity() * 2 < capacity() + n)
						reserve(capacity() * 2 + n);
					else
						reserve(capacity() * 2);
				}
			}

			if (position.base() == NULL)
				position = begin();

			pointer new_end = _end + n;
			size_type j = size() - (position - begin());

			for (size_type i = 1; i <= j; i++)
				_alloc.construct(new_end - i, *(_end - i));

			_end = new_end;
			clear_block(_begin + (position - begin()), n);

			while (n--)
				_alloc.construct(_begin + (position++ - begin()), *(first++));
		}

		iterator erase (iterator position)
		{
			return (erase(position, position + 1));
		}

		iterator erase (iterator first, iterator last)
		{
			size_type n = last - first;
			if (last - first)
			{
				pointer start = _begin + (first - begin());
				size_type i = end() - first;
				while (i--)
				{
					*(start) = *(start + n);
					start++;
				}
				clear_block(_end - n, n);
				_end -= n;
			}
			return (first);
		}

		void swap (vector& x)
		{
			pointer tmp_b = _begin;
			pointer tmp_e = _end;
			pointer tmp_se = _storage_end;

			_begin = x._begin;
			_end = x._end;
			_storage_end = x._storage_end;

			x._begin = tmp_b;
			x._end = tmp_e;
			x._storage_end = tmp_se;
		}

		void clear()
		{
			clear_block(_begin, size());
			_end = _begin;
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		// ITERATORS

		iterator begin()
		{
			return (iterator(_begin));
		}

		const_iterator begin() const
		{
			return (const_iterator(_begin));
		}

		iterator end()
		{
			return (iterator(_end));
		}

		const_iterator end() const
		{
			return (const_iterator(_end));
		}
		
		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end - 1));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_end - 1));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(_begin));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_begin));
		}

		// OPERATORS
	
		vector& operator= (const vector& x)
		{
			clear();
			if (capacity() > x.capacity())
				insert(begin(), x.begin(), x.end());
			else
				assign(x.begin(), x.end());
			return (*this);
		}

		reference operator[] (size_type n)
		{
			if (n >= size())
				throw (std::out_of_range("vector"));
			return (_begin[n]);
		}

		const_reference operator[] (size_type n) const
		{
			if (n >= size())
				throw (std::out_of_range("vector"));
			return (_begin[n]);
		}
	};

	template <class T, class Alloc> 
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc> 
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc> 
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc> 
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc> 
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}
