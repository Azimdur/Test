NAME	=	yolo

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-std=c++11

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ -o $(NAME) $(OBJ) -lpthread

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
