#include <asm-generic/errno.h>
#include <cstdio>
#include <iostream>
#include <colormod.h>
#include <iterator>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <map>

#include <vector.h>
#include <tests_containers.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	if (!strcmp(av[1], "vector"))
	{
		std::cout << FG_YEL << "~==[ TESTS VECTOR ]==~" << FG_DEF << std::endl << std::endl << std::endl;

		bool ok = v_test();

		std::cout << std::endl << FG_YEL << "~==[ VERDICT : " << FG_DEF;
		if (ok)
			std::cout << FG_BLUE << "OK" << FG_DEF;
		else
			std::cout << FG_MAG << "KO" << FG_DEF;
		std::cout << FG_YEL << " ]==~" << FG_DEF << std::endl;
	}

	else if (!strcmp(av[1], "map"))
	{
		std::cout << FG_YEL << "~==[ TESTS MAP ]==~" << FG_DEF << std::endl << std::endl << std::endl;

		bool ok = v_test();

		std::cout << std::endl << FG_YEL << "~==[ VERDICT : " << FG_DEF;
		if (ok)
			std::cout << FG_BLUE << "OK" << FG_DEF;
		else
			std::cout << FG_MAG << "KO" << FG_DEF;
		std::cout << FG_YEL << " ]==~" << FG_DEF << std::endl;

	}

	else if (!strcmp(av[1],"stack"))
	{
		std::cout << FG_YEL << "~==[ TESTS STACK ]==~" << FG_DEF << std::endl << std::endl << std::endl;

		bool ok = v_test();

		std::cout << std::endl << FG_YEL << "~==[ VERDICT : " << FG_DEF;
		if (ok)
			std::cout << FG_BLUE << "OK" << FG_DEF;
		else
			std::cout << FG_MAG << "KO" << FG_DEF;
		std::cout << FG_YEL << " ]==~" << FG_DEF << std::endl;

	}

	return (0);
} 

