# Compiler for Linux
CC_LINUX := gcc

# Compiler for Windows
CC_WINDOWS := x86_64-w64-mingw32-gcc

# Compiler flags
CFLAGS := -Wall -Wextra -std=c99 -I./raylib/include

# Linker flags
LDFLAGS := -L./raylib/lib

# Libraries to link against
LDLIBS := -Wl,-Bstatic -lraylib -Wl,-Bdynamic -lm -lpthread -ldl -lrt

# Source files
SRCS := main.c

# Object files
OBJS := $(SRCS:.c=.o)

# Executable name for Linux
TARGET_LINUX := game

# Executable name for Windows
TARGET_WINDOWS := game.exe

# Default target platform
PLATFORM ?= linux

.PHONY: all clean

ifeq ($(PLATFORM),linux)
    CC := $(CC_LINUX)
    TARGET := $(TARGET_LINUX)
else
    CC := $(CC_WINDOWS)
    TARGET := $(TARGET_WINDOWS)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
