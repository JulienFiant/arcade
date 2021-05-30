NAME	= ../lib_arcade_pacman.so

RM	= rm -f

SRCS	=	../Wall.cpp \
			../Clock.cpp \
			../../core/VectorCalc.cpp \
			./src/Pacman.cpp \
			./src/PacGumSmall.cpp \
			./src/PacGumSpecial.cpp \
			./src/pac.cpp \
			./src/blinky.cpp \
			./src/clyde.cpp \
			./src/inky.cpp	\
			./src/pinky.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
		g++ -g -g3 -c -Wall -fpic $(SRCS)
		g++ -g -g3 -shared -fPIC -o $(NAME) Wall.o Clock.o VectorCalc.o Pacman.o PacGumSmall.o PacGumSpecial.o pac.o blinky.o clyde.o inky.o pinky.o
		rm -f *.o

clean:
	$(RM) -r *.o

fclean: clean
	$(RM) $(NAME) $(OBJS)
	rm -f *.so

re: fclean all

.PHONY: all clean fclean re
