CXXFLAGS:=(shell pkg-config --cflags sdl2) $(CXXFLAGS) -lm
LDLIBS:=$(shell pkg-config --libs sdl2) $(LDLIBS) -lm

all: hilbert dragon

hilbert: hilbert.o turtle.o

dragon: dragon.o turtle.o

