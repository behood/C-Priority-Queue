# --Macro Definitions--
CC = gcc -g
CFLAGS =  -ansi -pedantic-errors -Wall -fstack-protector-all -Werror

# --ALL Flag --
all: public01.x public02.x public03.x public04.x public05.x public06.x \
	public07.x public08.x public09.x public10.x public11.x public12.x  \
	public13.x public14.x public15.x \
	student01.x student02.x student03.x student04.x

# --Linking Tests--
#public tests begin
public01.x: public01.o prio-q.o
	$(CC) public01.o prio-q.o -o public01.x

public02.x: public02.o prio-q.o
	$(CC) public02.o prio-q.o -o public02.x

public03.x: public03.o prio-q.o memory-checking.o
	$(CC) public03.o prio-q.o memory-checking.o -o public03.x

public04.x: public04.o prio-q.o memory-checking.o
	$(CC) public04.o prio-q.o memory-checking.o -o public04.x

public05.x: public05.o prio-q.o memory-checking.o
	$(CC) public05.o prio-q.o memory-checking.o -o public05.x

public06.x: public06.o prio-q.o memory-checking.o
	$(CC) public06.o prio-q.o memory-checking.o -o public06.x

public07.x: public07.o prio-q.o memory-checking.o
	$(CC) public07.o prio-q.o memory-checking.o -o public07.x

public08.x: public08.o prio-q.o memory-checking.o compare-name-lists.o
	$(CC) public08.o prio-q.o memory-checking.o compare-name-lists.o -o public08.x

public09.x: public09.o prio-q.o memory-checking.o
	$(CC) public09.o prio-q.o memory-checking.o -o public09.x

public10.x: public10.o prio-q.o memory-checking.o compare-name-lists.o
	$(CC) public10.o prio-q.o memory-checking.o compare-name-lists.o -o public10.x

public11.x: public11.o prio-q.o memory-checking.o
	$(CC) public11.o prio-q.o memory-checking.o -o public11.x

public12.x: public12.o prio-q.o memory-checking.o compare-name-lists.o
	$(CC) public12.o prio-q.o memory-checking.o compare-name-lists.o -o public12.x

public13.x: public13.o prio-q.o
	$(CC) public13.o prio-q.o -o public13.x

public14.x: public14.o prio-q.o compare-name-lists.o
	$(CC) public14.o prio-q.o compare-name-lists.o -o public14.x

public15.x: public15.o prio-q.o
	$(CC) public15.o prio-q.o -o public15.x

#student tests begin
student01.x: student01.o prio-q.o
	$(CC) student01.o prio-q.o -o student01.x

student02.x: student02.o prio-q.o
	$(CC) student02.o prio-q.o -o student02.x

student03.x: student03.o prio-q.o
	$(CC) student03.o prio-q.o -o student03.x

student04.x: student04.o prio-q.o
	$(CC) student04.o prio-q.o -o student04.x


#--UPPER LEVEL OBJECTS:--
prio-q.o: prio-q.c
	$(CC) $(CFLAGS) -c prio-q.c

#public tests begin
public01.o: public01.c prio-q.c 
	$(CC) $(CFLAGS) -c public01.c

public02.o: public02.c prio-q.c 
	$(CC) $(CFLAGS) -c public02.c

public03.o: public03.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public03.c

public04.o: public04.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public04.c

public05.o: public05.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public05.c

public06.o: public06.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public06.c

public07.o: public07.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public07.c

public08.o: public08.c prio-q.c memory-checking.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public08.c

public09.o: public09.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public09.c

public10.o: public10.c prio-q.c memory-checking.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public10.c

public11.o: public11.c prio-q.c memory-checking.h
	$(CC) $(CFLAGS) -c public11.c

public12.o: public12.c prio-q.c memory-checking.h compare-name-lists.h
	$(CC) $(CFLAGS) -c public12.c

public13.o: public13.c prio-q.c 
	$(CC) $(CFLAGS) -c public13.c

public14.o: public14.c prio-q.c compare-name-lists.h
	$(CC) $(CFLAGS) -c public14.c

public15.o: public15.c prio-q.c 
	$(CC) $(CFLAGS) -c public15.c

#student tests begin
student01.o: student01.c prio-q.c 
	$(CC) $(CFLAGS) -c student01.c

student02.o: student02.c prio-q.c 
	$(CC) $(CFLAGS) -c student02.c

student03.o: student03.c prio-q.c 
	$(CC) $(CFLAGS) -c student03.c

student04.o: student04.c prio-q.c 
	$(CC) $(CFLAGS) -c student04.c


#HEADER FILE
prio-q.h: prio-q-datastructure.h
	touch prio-q-datastructure.h


# Clean Code
clean:
	rm -f *.x prio-q.o public*.o private*.o