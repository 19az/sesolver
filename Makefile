CC = g++
CFLAGS =
include ../flags
EXE = sesolver
SRCS = src/main.cpp rwfile/rwfile.cpp src/sesolver.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)
