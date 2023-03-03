NAME		=	test

SRCS		=	main.cpp \
			tests_vector.cpp

INC		=	stack.h \
			vector.h \
			distance.h \
			map.h \
			tree.h \
			node.h \
			pair.h \
			iterator_traits.h \
			random_access_iterator.h \
			reverse_iterator.h \
			compare.h \
			enable_if.h \
			colormod.h \
			tests_containers.h \

OBJS		=	${addprefix objs/,${notdir ${SRCS:.cpp=.o}}}

CC		=	g++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

RM		=	rm -f

all:
			@mkdir -p objs
			${MAKE} ${NAME}

objs/%.o:		srcs/%.cpp ${addprefix includes/,${INC}}
			${CC} ${CFLAGS} -c $< -o $@ -I includes

${NAME}:		${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean:
			@${RM} ${OBJS}
			@rm -rf objs srcs/t1 srcs/t2 srcs/a.out

fclean:			clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:			clean fclean re all
