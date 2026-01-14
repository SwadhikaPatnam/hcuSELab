#include "trie.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getIndex(char c) {
	if (c >= '0' && c <= '9')
		return 26 + (c - '0');
	c = tolower(c);
	return c - 'a';
}

Trie* createNode() {
	Trie* node = calloc(1,sizeof(Trie));
	return node;
}

int insert(char* rollNo) {
	Trie* curr = root;
	for (int i = 0; rollNo[i] != '\0'; i++) {
		int idx = getIndex(rollNo[i]);
		
		// invalid character non alphanumeric 
		if (idx < 0 || idx >= SIZE)
			return 1;
			
		if (curr->child[idx] == NULL)
			curr->child[idx] = createNode();
		curr = curr->child[idx];
	}
	
	// duplicate
	if (curr->isEnd)
	        return 1;
	curr->isEnd = 1;
	return 0;
}


