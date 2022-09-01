CC = g++
CFLAGS =
include ../flags
EXE = sesolver
SRCS = main.cpp rwfile/rwfile.cpp sesolver.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)
