#include <random_access_iterator.h>

namespace ft
{
	template<class It>
		typename std::iterator_traits<It>::difference_type 
		do_distance(It first, It last, std::input_iterator_tag)
		{
			typename std::iterator_traits<It>::difference_type result = 0;
			while (first != last) {
				++first;
				++result;
			}
			return result;
		}

	template<class It>
		typename std::iterator_traits<It>::difference_type 
		do_distance(It first, It last, std::random_access_iterator_tag)
		{
			return last - first;
		}

	template<class It>
		typename ft::iterator_traits<It>::difference_type 
		do_distance(It first, It last, ft::random_access_iterator_tag<It>)
		{
			return last - first;
		}

/*	template<class It>
		typename ft::iterator_traits<It>::difference_type 
		distance(It first, It last)
		{
			return do_distance(first, last, typename It::iterator_category());
		}*/

	template<class It>
		std::ptrdiff_t distance(It first, It last)
		{
			std::ptrdiff_t result = 0;
			while (first != last) {
				++first;
				++result;
			}
			return result;
		}
}
