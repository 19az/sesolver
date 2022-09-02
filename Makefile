CC = g++
CFLAGS =
EXE = sesolver
SRCS = main.cpp lib/equations/equations.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXE)

unit_test: 
include flags

unit_test: all

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)
