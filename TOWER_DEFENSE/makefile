CC = gcc
OBJ = bin/Tower.o bin/Object.o bin/Graphisme.o bin/Sound.o
CFLAGS = -ansi -pedantic -Wall -g
LDFLAGS = -lMLV -lm
EXEC = Tower.exe

$(EXEC): src/Main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

bin/%.o: src/%.c include/Config.h include/Object.h
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)


bin/Object.o : src/Object.c

bin/Tower.o : src/Tower.c include/Tower.h

bin/Graphisme.o : src/Graphisme.c include/Graphisme.h include/Tower.h


bin/Sound.o : src/Sound.c include/Sound.h 


clean:
	rm $(EXEC)

uninstall:
	rm bin/*.o