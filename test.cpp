#include "includes/vector.h"
#include <vector>

int main()
{
	std::vector<int> v(3,0);
	std::vector<int>::iterator i = 1 + v.begin();
	return 0;
}
