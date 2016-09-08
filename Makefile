
NAME		=	avm

RM		=	rm -vf

CXX		=	g++

SRC		=	main.cpp 		\
			AvmError.cpp		\
			Calculator.cpp		\
			Lexer.cpp 		\
			Parser.cpp 		\
			Operand.cpp 		\
			OperandCreator.cpp 	\
			Token.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS		+=	-W -Wall -Wextra -Werror

$(NAME):		$(OBJ)
			$(CXX) -o $(NAME) $(SRC)

all:			$(NAME)

clean:
			$(RM) $(OBJ)

fclean:         	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
