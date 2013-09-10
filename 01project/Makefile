CC = g++
OPT = -O2
LIBS = -lm
DIR = src/

all: raytrace

raytrace: $(DIR)*.cpp Makefile
	$(CC) $(OPT) -g -o raytrace $(DIR)*.cpp $(LIBS)

clean: 
	rm raytrace

