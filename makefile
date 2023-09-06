CC = gcc
CCFLAGS = -Wall -g
SDLINCL = SDL/include
SDLLIB = SDL/lib
SDLLIBFLAGS = -lmingw32 -lSDL2 -lSDL2main
bash = git-bash -c

main:	main.c
	${CC} main.c -o main -I${SDLINCL} -L${SDLLIB} ${SDLLIBFLAGS}

clean:
	${bash} "clear"
