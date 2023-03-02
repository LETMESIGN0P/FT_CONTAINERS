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
#include <stdlib.h>

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
		system("g++ -Wall -Wextra -Werror srcs/tests_map.cpp -Iincludes -D TESTED_NAMESPACE=std");
		system("time ./a.out > t1");
		system("g++ -Wall -Wextra -Werror srcs/tests_map.cpp -Iincludes -D TESTED_NAMESPACE=ft");
		system("time ./a.out > t2");
		system("diff t1 t2");
		system("rm a.out");
	}

	else if (!strcmp(av[1],"stack"))
	{
		system("g++ -Wall -Wextra -Werror srcs/tests_map.cpp -Iincludes -D TESTED_NAMESPACE=std");
		system("time ./a.out > t1");
		system("g++ -Wall -Wextra -Werror srcs/tests_map.cpp -Iincludes -D TESTED_NAMESPACE=ft");
		system("time ./a.out > t2");
		system("diff t1 t2");
		system("rm a.out");
	}

	return (0);
}
