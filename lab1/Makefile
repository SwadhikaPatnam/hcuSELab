cc := gcc -Wall

all: fileOps student trie stdprcg

fileOps: fileOps.h fileOps.c
	$(cc) -c fileOps.c

student: student.h student.c
	$(cc) -c student.c

trie: trie.h trie.c
	$(cc) -c trie.c

stdprcg: fileOps.o student.o trie.o stdResultPrcgSys.c
	$(cc) fileOps.o student.o trie.o stdResultPrcgSys.c -o stdprcg
		
clean:
	rm -f *.o 
