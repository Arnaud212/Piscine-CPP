SRCS	= 	test.cpp \
			Account.cpp 

CFLAGS	= -Wall -Werror -Wextra -std=c++98

CC		= c++

NAME	= diary

OBJS	= ${SRCS:.cpp=.o}

RM		= rm -f

all:	${NAME}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re