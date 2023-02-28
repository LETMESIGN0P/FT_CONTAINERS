#pragma once

namespace ft
{
	template <class iterator>
	struct iterator_traits
	{
  		typedef typename iterator::value_type value_type;
  		typedef typename iterator::difference_type difference_type;
  		typedef typename iterator::pointer pointer;
		typedef typename iterator::reference reference;
  		typedef typename iterator::iterator_category iterator_category;
	};
}
