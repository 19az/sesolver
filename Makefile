CC = g++
CFLAGS = -Wall -Wextra
EXE = SESolver
SRCS = main.cpp SESolver.cpp SESolverUT.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all unit_tets clean

all: $(EXE)

unit_test: CFLAGS+= -DSEUT -DLEUT

unit_test: all

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)
 
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)

