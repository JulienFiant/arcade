NAME	= ../arcade

RM	= rm -f

SRCS	=	./Main.cpp \
			./Event.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
		g++ -g -g3 -c -Wall -fpic $(SRCS)
		g++ -g -g3 -o $(NAME) $(SRCS) -ldl -lsfml-graphics -lsfml-window -lsfml-system -lncurses
		rm -f *.o

clean:
	$(RM) -r *.o

fclean: clean
	$(RM) $(NAME) $(OBJS)
	rm -f *.so

re: fclean all

.PHONY: all clean fclean re
