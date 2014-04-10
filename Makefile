CXXFLAGS:=(shell pkg-config --cflags sdl2) $(CXXFLAGS) -lm
LDLIBS:=$(shell pkg-config --libs sdl2) $(LDLIBS) -lm

all: main hilbert dragon koch snowflake

hilbert: main
	ln -s main hilbert

dragon: main
	ln -s main dragon

koch: main
	ln -s main koch

snowflake: main
	ln -s main snowflake

main: turtle.o hilbert.o dragon.o koch.o snowflake.o

clean:
	rm *.o
