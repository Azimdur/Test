NAME	=	yolo

SRC	=	main.cpp \
		SafeQueue.cpp \
		Consumer.cpp \
		Producer.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-std=c++11 -fpermissive

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ -o $(NAME) $(OBJ) -lpthread

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
