#pragma once
#include <memory>
#include <iostream>

#include <iterator>
#include <algorithm>
#include <enable_if.h>
#include <compare.h>
#include <reverse_iterator.h>
#include <bidirectional_iterator.h>
#include <const_bidirectional_iterator.h>
#include <pair.h>

namespace ft
{

	template <class Pair, class Compare=std::less<typename Pair::first_type>, class Alloc=std::allocator<Node<Pair> > >
	class tree
	{
		public:

		typedef Pair								value_type;
		typedef typename value_type::first_type					key_type;
		typedef typename value_type::second_type				val_type;
		typedef Compare								compare_type;
		typedef Alloc								allocator_type;
		typedef Node<Pair>							*node_ptr;
		typedef size_t 								size_type;
		typedef ft::bidirectional_iterator<value_type>				iterator;    
		typedef ft::const_bidirectional_iterator<const value_type>		const_iterator;
	        typedef ft::reverse_iterator<iterator>					reverse_iterator;    
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:

		allocator_type	_alloc;	
		compare_type	_compare;
		node_ptr	_root;
		size_type	_size;
		node_ptr	_real_end;
		node_ptr	_maxi;

		public :
			
		tree
		(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _compare(comp), _root(NULL), _size(0), _real_end(), _maxi(NULL)
		{
			_real_end = new_node(ft::pair<key_type, val_type>());
			_real_end->print = 0;
		}        

		~tree()
		{
			if (_root)
				clear_all(_root);
			_root = _destroy_node(_root);
			_destroy_node(_real_end);
		}

		node_ptr	minii() const
		{
			node_ptr	current;

			current = _root;
			while (current != NULL && current->left != NULL)
				current = current->left;
			return (current);
		}

		node_ptr	maxii() const
		{
			node_ptr	current;

			current = _root;
			while (current != NULL && current->right != NULL)
				current = current->right;
			return (current);
		}

		iterator	begin() const
		{
			iterator	it(minii());
			if (_root == NULL)
				return(_real_end);
			return (it);
		}

		iterator	end() const
		{
			return (_real_end);
		}
		
		void	clear()
		{
			if (_root != NULL)
				clear_all(_root);
			_maxi = NULL;
		}

		private :

		node_ptr	new_node(value_type const &val)
		{
			node_ptr node = _alloc.allocate(sizeof(node_ptr));
			_alloc.construct(node, val);
			node->left = NULL;
			node->right = NULL;
			node->daddy= NULL;
			node->end = NULL;
			node->max = _maxi;
			return(node);
		}
		
		void clear_all(node_ptr	&tmp)
		{
			node_ptr	save = 0;
			if (tmp->left)
					clear_all(tmp->left);
			else if (tmp->right)
				clear_all(tmp->right);
			else
			{
				save = tmp->daddy;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, sizeof(node_ptr));
				tmp = NULL;
			}
			if (save != _root)
				clear_all(_root);
			else 
				return;
		}

		node_ptr	_destroy_node(node_ptr node)
		{
			int i =0;
			_size--;
			if (_size == 0)
				_root = NULL;
			if (node != NULL)
			{
				if (node == _maxi)
				 	i = 1;
				if (node == _root)
				 	i = 2;
				_alloc.destroy(node);
				_alloc.deallocate(node, sizeof(node_ptr));
				if (i == 1)
					_maxi = NULL;
				if (i == 2)
					_root = NULL;
				node = NULL;
			}
			return(NULL);
		}
	
    		void	is_new_max(const value_type &val, node_ptr last_add)
    		{
			(void)val;

			if (last_add == NULL)
				return;
    	    		if (_maxi == NULL)
    	    		{
    	       			_maxi = last_add;
    	        		last_add->end = _real_end;
    	        		_real_end->daddy = last_add;
				_real_end->print = 0;
				last_add->max = _maxi;
	    	 	}
    	    		else
    	    		{
    	        		if (_compare(_maxi->val.first, last_add->val.first))
    	        		{
    	            			_maxi->end  = NULL;
    	            			_maxi = last_add;
    	            			_maxi->end = _real_end;
    	            			_real_end->daddy =  _maxi;
					_maxi->max = _maxi;
					last_add->daddy->max = NULL;
    	        		}
    	    		}
			last_add->end = _real_end;
    		}

		void	if_del_max(node_ptr todel,  const key_type &val)
		{
			if (_maxi == _root)
			{
				_maxi->end = NULL;
				if (_size == 1)
				{
					_maxi = NULL;
					return;
				}
					_maxi = _root->left;
				_maxi->end = _real_end;
				_real_end->daddy = _maxi;
				_maxi->max = _maxi;
			}
			if (todel == NULL)
				return;
			if (_compare(_maxi->val.first, val))
					return;
			else if (_compare(val, _maxi->val.first))
				return ;
			else 
			{
				_maxi->end = NULL;
				if (_maxi->left == NULL)
					_maxi = _maxi->daddy;
				else
					_maxi = _maxi->left;
				_maxi->end = _real_end;
				_real_end->daddy = _maxi;
				_maxi->max = _maxi;
				if (todel->daddy)
					todel->daddy->max = NULL;
			}
		}

		// ROTATIONS

		void    choose_rotate(node_ptr current, int factor)
  		{
    	    		if (factor <= -2)
    	    		{
    	        		if (current->right->left != NULL)
    	            			RL_rotate(current, current->right, current->right->left);
    	       			else
    	            			LL_rotate(current, current->right);
    	    		}
    	    		else
    	    		{
    	        		if (current->left->right != NULL)
    	            			LR_rotate(current, current->left, current->left->right);
    	        		else
    	            			RR_rotate(current, current->left);
    	    		}
    		}

		void    balancing(node_ptr current)
	    	{
    			int	left_height;
    	    		int	right_height;
    	    		int	factor;

    			while (current != NULL)
    	    		{
    	   		    	left_height = 0;
    	 		      	right_height = 0;
		    	        if (current->left != NULL)
    		   			left_height = 1 + current->left->height;
    	        		if (current->right != NULL)
    	            			right_height = 1 + current->right->height;
    	        		factor = left_height - right_height;
    	        		if (factor <= -2 || factor >= 2)
    	            		choose_rotate(current, factor);
    	        		current = current->daddy;
    	    		}
    		}

		void	RR_rotate(node_ptr grandpa, node_ptr parent)
		{
			node_ptr	tie;

			tie = grandpa->daddy;
			grandpa->left = parent->right;
			if (parent->right != NULL)
				parent->right->daddy = grandpa;
			parent->right = grandpa;
			parent->daddy = tie;
			grandpa->daddy = parent;
			if (tie == NULL)
			{
				_root = parent;
				update_height(grandpa);
				return ;
			}
			if (tie->left == grandpa)
				tie->left = parent;
			else
				tie->right = parent;
			update_height(grandpa);
		}


		void	LL_rotate(node_ptr grandpa, node_ptr parent)
		{
			node_ptr	tie;

			tie = grandpa->daddy;
			grandpa->right = parent->left;
			if (parent->left != NULL)
				parent->left->daddy = grandpa;
			parent->left = grandpa;
			parent->daddy = tie;
			grandpa->daddy = parent;
			if (tie == NULL)
			{
				_root = parent;
				update_height(grandpa);
				return ;
			}
			if (tie->left == grandpa)
				tie->left = parent;
			else
				tie->right = parent;
			update_height(grandpa);
		}

		void	LR_rotate(node_ptr grandpa, node_ptr parent, node_ptr child)
		{
			node_ptr	tie;
			node_ptr	ltmp;
			node_ptr	rtmp;

			tie = grandpa->daddy;
			ltmp = child->left;
			rtmp = child->right;
			child->left = parent;
			child->right = grandpa;
			parent->daddy = child;
			parent->right = ltmp;
			if (ltmp)
				ltmp->daddy = parent;
			grandpa->daddy = child;
			grandpa->left = rtmp;
			if (rtmp)
				rtmp->daddy = grandpa;
			if (tie == NULL)
			{
				_root = child;
				child->daddy = NULL;
				update_height(grandpa);
				solo_update_height(parent); 
				return ;
			}
			if (tie->left == grandpa)
				tie->left = child;
			else
				tie->right = child;
			child->daddy = tie;
			update_height(grandpa);
			solo_update_height(parent); 
		}	

		void	RL_rotate(node_ptr grandpa, node_ptr parent, node_ptr child)
		{
			node_ptr	tie;
			node_ptr	ltmp;
			node_ptr	rtmp;

			tie = grandpa->daddy;
			ltmp = child->left;
			rtmp = child->right;
			child->left = grandpa;
			child->right = parent;
			parent->daddy = child;
			parent->left = rtmp;
			if (rtmp != NULL)
				rtmp->daddy = parent;
			grandpa->daddy = child;
			grandpa->right = ltmp;
			if (ltmp != NULL)
				ltmp->daddy = grandpa;
			if (tie == NULL)
			{
				_root = child;
				child->daddy = NULL;
				update_height(grandpa);
				solo_update_height(parent);

				return ;
			}
			if (tie->left == grandpa)
				tie->left = child;
			else
				tie->right = child;
			child->daddy = tie;
			update_height(grandpa);
			solo_update_height(parent);

		}


    		void    single_oblitarate(Node<Pair> &current)
 		{
			node_ptr	tmp;
			node_ptr	prev;
			node_ptr	substitute;
			int			direction;

			prev = current.daddy;
			tmp = &current;
			substitute = current.right;
			if (current.left != NULL)
				substitute = current.left;
			if (prev == NULL)
			{
				_root = substitute;
				substitute->daddy =NULL;

				_destroy_node(&current);
				return ;
			}
			direction = 2;
			if (prev->left->val.first == current.val.first)
				direction = 1;
			
			tmp = _destroy_node(tmp);
			if (direction == 1)
				prev->left = substitute;
			else
				prev->right = substitute;
			substitute->daddy = prev;
		}

    		void    complex_oblitarate(Node<Pair> &remove)
    		{
    	    		node_ptr		substitute;
    	    		node_ptr		current;
			value_type		save_val;

    	    		current = &remove;
			current = current->left;
			while (current != NULL)
    	    		{
    	        		substitute = current;
				current = current->right;
    	   		}
    	    		save_val = substitute->val;
			erase(substitute->val.first);
    	    		remove.val = save_val; 
    		}

    		node_ptr	oblitarate(Node<Pair> &current, const int &direction)
    		{
    	    		node_ptr prev;

    			prev = current.daddy;
			
	  		if (current.left == NULL && current.right == NULL)
			{
				if (_size != 1)
					(direction == 1) ? prev->left = NULL : prev->right = NULL;
				_destroy_node(&current);
			}
			else if (current.left != NULL && current.right != NULL)
					complex_oblitarate(current);
			else
					single_oblitarate(current);
			return (NULL);
    		}

		public :

		void add_max()
		{
			node_ptr tmp = _root->mini(_root);
			if (_maxi != NULL)
			{
			while(tmp != _maxi)
			{
				tmp->end = _real_end;
				tmp->max = _maxi;
				tmp = tmp->next();
			}
			_maxi->max = _maxi;
			}
		}

		ft::pair<iterator,bool>  insert (const value_type &val)
		{
			node_ptr	cursor = _root;
			node_ptr	prev = NULL;
			int		var = 0;

			while (cursor)
			{
				prev = cursor;
				if (_compare(val.first, cursor->val.first) && (var = 1))
					cursor = cursor->left;
				else if (_compare(cursor->val.first, val.first) && (var = 2))
					cursor = cursor->right;
				else
					return (ft::make_pair(iterator(cursor), false));
			}
			node_ptr node = new_node(val);
			_size++;
			node->daddy = prev;
			if (var == 1)
				prev->left = node;
			else if (var == 2)
				prev->right = node;
			else
				_root = node;
			is_new_max(val ,node);
			update_height(node->daddy);
			balancing(node->daddy);

			return(ft::make_pair(iterator(node), true));
		}

		void	solo_update_height(node_ptr node)
		{
			node_ptr current;

			current = node;
				if (current == NULL)
					return;
				if (current->left && current->right)
					current->height = 1 + std::max(current->left->height, current->right->height);
				else if(current->left)
					current->height = 1 + current->left->height;
				else if (current->right)
					current->height = 1 + current->right->height;
				else
					current->height = 0;
		}

		inline void	update_height(node_ptr node)
		{
			node_ptr current;
			
			current = node;
			if (current == NULL)
				return;
			while (current != NULL)
			{
				if (current->left && current->right)
					current->height = 1 + std::max(current->left->height, current->right->height);
				else if(current->left)
					current->height = 1 + current->left->height;
				else if (current->right)
					current->height = 1 + current->right->height;
				else
					current->height = 0;
				current = current->daddy;
			}
			return;
		}


		size_type erase (const key_type& val)
		{
			node_ptr    current;
			node_ptr    current_daddy;
		        int         direction;

			current = _root;
        		direction = 0;
        		while (current != NULL)
        		{
            			if (_compare(val, current->val.first) && (direction = 1))
                			current = current->left;
            			else if (_compare(current->val.first, val) && (direction = 2))
                			current = current->right;
            			else
            			{
					current_daddy = current->daddy;
					if_del_max(current_daddy, val);
					//up_height(current->daddy);
	
					current = oblitarate(*current, direction);
					balancing(current_daddy);
					return(1);
				}
			}
			return(0);
		}

		size_type size() const
		{
			return(_size);
		}
		node_ptr 	get_root() const
		{
			return(_root);
		}

		size_type	is_key_here(const key_type &val) const
		{
			node_ptr	cursor = _root;

			while (cursor)
			{
				if (_compare(val, cursor->val.first))
					cursor = cursor->left;
				else if (_compare(cursor->val.first, val))
					cursor = cursor->right;
				else
					return (1);
			}
			return(0);

		}
		iterator	found_key(const key_type &val) const
		{
			node_ptr	cursor = _root;

			while (cursor)
			{
				if (_compare(val, cursor->val.first))
					cursor = cursor->left;
				else if (_compare(cursor->val.first, val))
					cursor = cursor->right;
				else
					return(iterator(cursor));
			}
			return(end());
		}

		size_t	max_size() const
		{
			return _alloc.max_size();
		}
		void	swap(tree &x)
		{

			node_ptr root = x._root;
			node_ptr endi = x._real_end;
			node_ptr maxou = x._maxi;
			size_type i = x._size;

			x._size = _size;
			x._maxi = _maxi;
			x._root = _root;
			x._real_end = _real_end;

			_size = i;
			_maxi = maxou;
			_root = root;
			_real_end = endi;

		}
	};

	template<class Content, class Compare, class Alloc>
	bool operator<(const tree<Content, Compare, Alloc>& lhs,  const tree<Content, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template<class Content, class Compare, class Alloc>
	bool
	operator>(const tree<Content, Compare, Alloc>& lhs,  const tree<Content, Compare, Alloc>& rhs)
	{
		return (lhs < rhs);
	}

	template<class Content, class Compare, class Alloc>
	bool
	operator==(const tree<Content, Compare, Alloc>& lhs, const tree<Content, Compare, Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
}
