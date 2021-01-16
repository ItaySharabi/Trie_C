#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "node.h"


int main(int argc, char* argv[]) {
	char* r = "r";
	node* head = newNode();
	char c[WORD_SIZE];
	char word[WORD_SIZE];
	while (scanf("%s", word)!= EOF) {
		addWord(head, word);
	}
	if (argv[1] != NULL) {
		if (strcmp(r, argv[1]) == 0) {
			print_words_rev(head, c);
		}
	}
	else {
		print_words(head, c);
	}
	free_node(head);
	return 0;
}