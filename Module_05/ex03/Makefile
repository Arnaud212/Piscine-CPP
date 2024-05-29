SRCS	= 	main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

CXX		= c++

NAME	= a.out

OBJS	= ${SRCS:.cpp=.o}

RM		= rm -f

all:	${NAME}

$(NAME): ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

n:	all clean

.PHONY: all clean fclean re n
