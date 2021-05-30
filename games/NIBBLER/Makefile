NAME	= ../lib_arcade_nibbler.so

RM	= rm -f

SRCS	=	../Wall.cpp \
			../Clock.cpp \
			../../core/VectorCalc.cpp \
			./src/Head.cpp \
			./src/Tail.cpp \
			./src/Fruit.cpp \
			./src/Nibbler.cpp \

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
		g++ -g -g3 -c -Wall -fpic $(SRCS)
		g++ -g -g3 -shared -fPIC -o $(NAME) Wall.o Clock.o VectorCalc.o Head.o Tail.o Fruit.o Nibbler.o
		rm -f *.o

clean:
	$(RM) -r *.o

fclean: clean
	$(RM) $(NAME) $(OBJS)
	rm -f *.so

re: fclean all

.PHONY: all clean fclean re
