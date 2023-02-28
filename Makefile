NAME		=	test

SRC		=	main.cpp \
			tests_vector.cpp
			#tests_map.cpp \
			#tests_stack.cpp

INC		=	stack.h \
			vector.h \
			map.h \
			avl_tree.h \
			iterator_traits.h \
			random_access_iterator.h \
			reverse_iterator.h \
			compare.h \
			enable_if.h \
			colormod.h \
			tests_containers.h \

OBJS		=	${addprefix objs/,${notdir ${SRC:.cpp=.o}}}

CC		=	g++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

RM		=	rm -f

all:
			@mkdir -p objs
			${MAKE} ${NAME}

objs/%.o:		sources/%.cpp ${addprefix headers/,${INC}}
			${CC} ${CFLAGS} -c $< -o $@ -I headers

${NAME}:		${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean:
			@${RM} ${OBJS}
			@rm -rf objs

fclean:			clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:			clean fclean re all
