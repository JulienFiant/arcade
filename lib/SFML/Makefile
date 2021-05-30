NAME	= ../lib_arcade_sfml.so

RM	= rm -f

SRCS	=	./src/SFML.cpp \
		../../games/Clock.cpp \

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
		g++ -g -g3 -c -Wall -fpic $(SRCS)
		g++ -g -g3 -shared -fPIC -o $(NAME) SFML.o Clock.o
		rm -f *.o

clean:
	$(RM) -r *.o

fclean: clean
	$(RM) $(NAME) $(OBJS)
	rm -f *.so

re: fclean all

.PHONY: all clean fclean re
