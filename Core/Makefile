
NAME		=	nibbler

LDFLAGS		+=	-ldl
CXXFLAGS	+=	-fPIC

CXX		=	g++

CXXFLAGS        += -W -Wall -Wextra -Werror
CXXFLAGS        += -ldl

SRCDIR		=	./

SRC		=	$(SRCDIR)main.cpp	\
			$(SRCDIR)Core.cpp	\
			$(SRCDIR)DLLoader.cpp	\
			$(SRCDIR)Element.cpp	\
			$(SRCDIR)NibblerError.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)


$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)
clean:
		rm -f $(OBJ) $(OBJ) $(OBJ)

fclean:		clean
		rm -f $(NAME) $(LIB) $(LIB)

re:		fclean all
