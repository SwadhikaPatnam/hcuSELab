#ifndef TRIE_H
#define TRIE_H

#define SIZE 36
#include <stdbool.h>

typedef struct Trie {	
	struct Trie* child[SIZE]; // 26 (a-z alphabets) + 10 (0-9 numbers)
	bool isEnd;
} Trie;

extern Trie* root;
int getIndex(char c);
Trie* createNode();
int insert(char* rollNo);

#endif
