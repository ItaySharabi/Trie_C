#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"node.h"





int main(int argc, char* argv[]) {
	char* r = "r";
	node* head = newNode();
	char c[100];
	char word[100];
	
	while (scanf("%s", word) != EOF) {
		addword(head, word);
	}
	if (argv[1] != NULL) {
		if (strcmp(r, argv[1]) == 0) {
			print_word_rev(head, c);
		}
	}
	else {
		print_word(head, c);
	}
	/*if (strcmp(r, argv[1]) == 0) {
		for (int i = 2; i < argc; i++) {
			addword(head, argv[i]);
			
		}
		print_word_rev(head, c);
	}
	else {
		for (int i = 1; i < argc; i++) {
			addword(head, argv[i]);
			
		}
		print_word(head, c);
	}*/

	free_node(head);
	return 0;
}