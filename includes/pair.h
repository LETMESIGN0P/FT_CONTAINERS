#pragma once

namespace ft
{

	template<class T1, class T2>
	struct pair
	{
 		 public:
    		
		typedef T1	first_type;
    		typedef T2	second_type;
    		T1		first;
    		T2		second;
    
		//CONSTRUCTORS / DESTRUCTORS
    
    		pair() : first(), second()
		{
		}
    
    		template<class T, class U> 
    		pair (const pair<T,U>& pr) : first(pr.first), second(pr.second)
		{
		}
    
    		pair (const first_type& a, const second_type& b) : first(a), second(b)
		{
		}
    
    		~pair(){}

		pair& operator= (const pair& pr);
	};

	template <class T1, class T2>
	pair<T1, T2>& pair<T1, T2> ::operator= (const pair& pr)
	{
		first = pr.first;
      		second = pr.second;
      		
		return (*this);
    	}

	// NON-MEMBER FUNCTIONS : OPERATORS / MAKE_PAIR

	template <class T1, class T2>
  	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}

	template <class T1, class T2>
  	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs<lhs);
	}

	template <class T1, class T2>
  	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	}

	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs<rhs));
	}


	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
    		return ( pair<T1,T2>(x,y) );
	}
}
