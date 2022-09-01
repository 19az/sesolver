CC = g++
CFLAGS =
include ../../flags
EXE = sesolver_ut
SRCS = ../rwfile/rwfile.cpp ../sesolver.cpp sesolver_ut.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)

