CC = g++
CFLAGS = -D NDEBUG
EXE = sesolver
SOURCES = main.cpp
INCLUDES_DIR = lib
include $(INCLUDES_DIR)/equations/Makefile

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJECTS)
