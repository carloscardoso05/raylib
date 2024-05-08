CC=gcc
# CC=x86_64-w64-mingw32-gcc
CLIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CFLAGS=-o

all: .game

.game: .build game.c
	$(CC) $(CFLAGS) build/game game.c $(CLIBS)

.build:
	make clean
	- mkdir build

run: all
	build/game

clean:
	rm -fr build