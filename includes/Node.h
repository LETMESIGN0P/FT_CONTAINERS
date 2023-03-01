#pragma once

#include <pair.h>

namespace ft
{
	template <class Pair>
		class Node
		{
			// MEMBER TYPES / ATTRIBUTES

			public :

			typedef Pair	value_type;
			typedef size_t	size_type;
			Node		*_left;
			Node		*_right;
			Node		*_parent;
			Node		*_end;
			Node		*_max;
			bool		_print;
			size_t		_height;
			value_type	_value;

			// CONSTRUCTORS

			Node ()
			{
				_left = NULL;
				_right = NULL;
				_parent = NULL;
				_end = NULL;
				_max = NULL;
				_print = 1;
				_height = 0;
				_value = 0;
			}

			Node (const value_type &value)
			{
				_left = NULL;
				_right = NULL;
				_parent = NULL;
				_end = NULL;
				_max = NULL;
				_print = 1;
				_height = 0;
				_value = value;		
			}

			// MEMBER FUNCTIONS

			Node *min(Node *search) const
			{
				if (!search->_left)
					return (search);

				while (search->_left)
					search = search->_left;
				return (search);
			}

			Node *max(Node *search) const
			{
				if (!search->_right)
					return (search);

				while (search->_right)
					search = search->_right;
				return (search);
			}

			Node *next(Node *search)
			{
				Node *tmp = this;

				if (tmp == _max)
					return (_end);

				if (tmp->_right)
					return (min(tmp->_right));
				Node *tmp_parent = tmp->_parent;
				while (tmp_parent && tmp == tmp_parent->_right)
				{
					tmp = tmp_parent;
					tmp_parent = tmp_parent->_parent;
				}
				return (tmp_parent);
			}

			Node *prev()
			{
				Node *tmp = this;

				if (tmp->left != NULL)
					return (min(tmp->_left));
				Node *tmp_parent = tmp->_parent;
				while (tmp_parent && tmp == tmp_parent->_left)
				{
					tmp = tmp_parent;
					tmp_parent = tmp_parent->_parent;
				}
				return (tmp_parent);
			}

			size_type size(Node *n) const
			{
				if (!n)
					return (NULL);
				Node *tmp;
				tmp = min(n);
				size_type size = 0;
				while (tmp != NULL && tmp != _end)
				{
					tmp = tmp->next();
					size++;
				}
				return (size);
			}
		};
}
