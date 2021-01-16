
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


node* newNode() {
	// Dynamically allocate memory for a node.
	// Allocation failed meaning n got the memory 0 or NULL.
	node* n = (node*)malloc(sizeof(node)); 
	if (n == NULL)
		printf("Memory allocation failed!");

	n -> count = 0; //Set the count field of n.

	int i = 0;
	while (i < ABC) { // Set all children of node as NULL's
		n -> children[i++] = NULL;
	}

	return n;
}

// This method turnes every upper-case letter from char str[]
// into a lower-case letter.
void toLowerCase(char str []){
	for (int i = 0; *(str + i)!='\0'; i++) {
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) = *(str + i) + 32; 
	}
}

void addword(node* head,char* word) {
	toLowerCase(word);
	removeSpecialChars(word);
	node* temp = head;
	int i = 0;
	while (i<strlen(word)) {

		if (temp->children[*(word + i) - 97] == NULL) {
			temp->children[*(word + i) - 97] = newNode();
			temp = temp->children[*(word + i) - 97];
			temp->letter = *(word + i);
			
			i++;

			
		}
		else{
			temp = temp->children[*(word + i) - 97];
			i++;
		}

	}
	
	temp->count++;
	temp->is_word = TRUE;
}

// This method removes all chars which are 
// NOT 'a' through 'z' in lowercase letters.
void removeSpecialChars(char* s)
{
	int i = 0, len = strlen(s);

	int write = 0;
	while (i < len)
	{
		if (s[i]>='a' && s[i]<='z')
		{
			s[write++] = s[i];
		}

		i++;
	}

	s[write] = '\0';
}
void free_node(node* n) {
	
	if (n == NULL) {
		return;
	}
	else {
		// Remove all allocated memory for n's 
		// Children (26) Recursively.
		for (int i = 1; i < ABC; i++) {
			free_node((n -> children)[i]);
		}
	}
	
	free(n);
	// return;
}
void print_word(node* head,char* c) {
	
	for (int i = 0; i < ABC; i++) {
		if (head->children[i] != NULL) {
			int level=1;
			print_word2(head->children[i],c,level);
		}

	}

}
void print_word2(node* node, char* c,int level) {
	if (level <= strlen(c))
		c[level-1] = '\0';
	strncat(c, &node->letter, 1);
	if (node->is_word == TRUE) {
		printf("%s\t%ld\n", c, node->count);
		
	}
	
	for (int i = 0; i < ABC; i++) {
		
		if (node->children[i] != NULL) {
		print_word2(node->children[i], c,level+1);

		}
		

	}
	

}


void print_word_rev(node* head, char* c) {

	for (int i = ABC-1; i >= 0; i--) {
		if (head->children[i] != NULL) {
			int level = 1;
			print_word_rev2(head->children[i], c, level);
		}

	}

}
void print_word_rev2(node* node, char* c, int level) {
	if (level <= strlen(c)) {
		c[level - 1] = '\0';
	}
	strncat(c, &node->letter, 1);
	if (node->is_word == TRUE) {
		printf("%s\t%ld\n", c, node->count);

	}

	for (int i = ABC-1; i>=0; i--) {

		if (node->children[i] != NULL) {
			print_word_rev2(node->children[i], c, level + 1);

		}


	}

}