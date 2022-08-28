CC = g++
CFLAGS =
TARGET = SESolver
SRCS = main.c SESolver.c SESolverUT.c
OBJS = $(SRCS:.c=.o)

.PHONY: all ut clean

all: $(TARGET)

ut: CFLAGS+=-DSEUT -DLEUT

ut: all

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)
 
.c.o:
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)

