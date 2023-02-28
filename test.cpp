#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.insert(vec.end(), vec.begin(), vec.end());
	//vec.insert(std::vector<int>::iterator(NULL), vec.begin(), vec.end());
	std::cout << vec.capacity() << std::endl;
	return 0;
}
