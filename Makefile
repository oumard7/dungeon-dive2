CC = gcc
CFLAGS = -Wall -g

OBJ = main.o roomManip.o commandParser.o stringManip.o

dungeon-dive: $(OBJ)
	$(CC) $(CFLAGS) -o dungeon-dive $(OBJ)

main.o: main.c roomManip.h commandParser.h stringManip.h
	$(CC) $(CFLAGS) -c main.c

roomManip.o: roomManip.c roomManip.h
	$(CC) $(CFLAGS) -c roomManip.c

commandParser.o: commandParser.c commandParser.h
	$(CC) $(CFLAGS) -c commandParser.c

stringManip.o: stringManip.c stringManip.h
	$(CC) $(CFLAGS) -c stringManip.c

clean:
	rm -f *.o dungeon-dive

