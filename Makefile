CC = gcc
CFLAGS = -O3

EXECUTABLE = matrix_multiplication

all: $(EXECUTABLE)

$(EXECUTABLE): cscript.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) cscript.c

clean:
	rm -f $(EXECUTABLE)
