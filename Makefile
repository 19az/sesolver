CC = g++
CFLAGS =
include ../flags
EXE = sesolver
SRCS = main.cpp rwfile/rwfile.cpp sesolver.cpp
OBJS = $(SRCS:.cpp=.o)

EXE_UT = sesolver_ut
SRCS_UT = rwfile/rwfile.cpp sesolver.cpp unit_test/sesolver_ut.cpp
OBJS_UT = $(SRCS_UT:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

unit_test: $(EXE_UT)

$(EXE_UT): $(OBJS_UT)
	$(CC) -o $(EXE_UT) $(OBJS_UT) $(CFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)
	rm -rf $(EXE_UT) $(OBJS_UT)

