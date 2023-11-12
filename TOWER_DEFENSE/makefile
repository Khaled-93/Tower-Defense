CC = gcc
OBJ = bin/Tower.o
CFLAGS = -ansi -pedantic -Wall -g
LDFLAGS = -lMLV -lm
EXEC = Tower.exe

$(EXEC): src/Main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

bin/%.o: src/%.c include/Tower.h
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

bin/Tower.o : src/Tower.c


clean:
	rm $(EXEC)

uninstall:
	rm bin/*.o