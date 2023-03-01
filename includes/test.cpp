#include <vector.hpp>
#include <vector>
#include <iostream>

#include <type_traits>

int main()
{
    std::vector<int> v(8);// {1, 2, 3, 4, 5, 6, 7, 8};

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v[5] = 6;
    v[6] = 7;

    typedef std::vector<int>::iterator iterator;

    iterator it = v.begin() + 3;
    iterator it2 = v.begin() + 6;

    //std::cout << *it << *it2 << std::endl;

   // v.assign(it, it2);
   
    auto r = v.erase(v.begin(), v.begin() + 3);

    std::cout << "ret: " << r.base() << " vs " << v.begin().base() << std::endl;

    for (auto i = v.begin() ; i < v.end() ; i++ )
        std::cout << *i << std::endl;
        
    std::cout << "---" << std::endl;
    
    if (v.rbegin().base() == v.end() - 1)
   	std::cout << "?" << std::endl;

    for (auto i = v.rbegin() ; i < v.rend() ; i++)
        std::cout << *i << std::endl;

}
