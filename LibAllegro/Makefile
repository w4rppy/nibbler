
NAME	=	LibAllegro.so

CXX	=	g++

SRCDIR	=	./
CORESRC	=	../Core/
CCFLAGS	=	-o

CXXFLAGS	+= -W -Wall -Wextra -Werror
CXXFLAGS	+= -lallegro -fPIC

RM	=	rm -f

SRC	=	$(SRCDIR)LibAllegro.cpp		\
		$(CORESRC)Element.cpp		\

OBJ	=	$(SRC:.cpp=.o)

$(NAME): 	$(OBJ)
		$(CXX) -shared -o $(NAME) $(OBJ) $(CXXFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		@$(RM) $(PATHSRC)*\#*
		$(RM) $(PATHSRC)*~

fclean:		clean
		$(RM) $(NAME)

mrproper:	$(NAME) clean

re:		fclean all

.PHONY:		clean all fclean mrproper re
