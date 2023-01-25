CC=gcc
CFLAGS=-ggdb -Wall -std=c18

test : tryGeom
	./tryGeom
	
checkMem : tryGeom
	valgrind --leak-check=full --show-leak-kinds=all ./tryGeom
	
tryGeom : tryGeom.c coord.c coord.h line.c line.h
	${CC} ${CFLAGS} -o tryGeom coord.c line.c tryGeom.c -lm
	
clean:
	rm tryGeom