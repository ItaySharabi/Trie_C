
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

	n -> word_count = 0; //Set the count field of n.

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

void addWord(node* head,char* word) {
	toLowerCase(word);
	removeSpecialChars(word);
	node* temp = head;
	int i = 0;
	while (i<strlen(word)) {

		if (temp->children[*(word + i) - 97] == NULL) { // Ascii table
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
	
	temp->word_count++;
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
	if(n!=NULL){
		// Remove all allocated memory for n's 
		// Children (26) Recursively.
		for (int i = 1; i < ABC; i++) {
			free_node((n -> children)[i]);
		}
	}
	else
		return;
	free(n);
}

// This method print words from the tree 
// in an alpha-betical order.
// From the head node of the tree, print all words from 'a' to 'z'.
void print_words(node* head,char* c) {

	for (int i = 0; i < ABC; i++) {
		if (head->children[i] != NULL) {
			print_word(head->children[i],c,0);
		}

	}

}

// This method traveles the tree and prints a word every time 
// We reach a node that it's 'is_word' field is true.
void print_word(node* node, char* c,int level) {
	if (level < strlen(c))
		c[level] = '\0';
	strncat(c, &node->letter, 1);
	if (node->is_word == TRUE) {
		printf("%s %ld\n", c, node->word_count); // Print the word and his counter
	}
	
	for (int i = 0; i < ABC; i++) {
		
		if (node->children[i] != NULL) {
			print_word(node->children[i], c,level+1);
		}
	}	
}

// This method prints words from the tree 
// in an opposite alpha-betical order.
// From the head node of the tree, print all words from 'z' to 'a'.
void print_words_rev(node* head, char* c) {

	for (int i = ABC-1; i >= 0; i--) {
		if (head->children[i] != NULL) {
			print_rev(head->children[i], c, 0);
		}
	}
}
// This method traveles the tree in the opposite direction 
// and prints a word every time we reach a node that
// it's 'is_word' field is true.
void print_rev(node* node, char* c, int level) {
	if (level < strlen(c)) {
		c[level] = '\0';
	}
	strncat(c, &node->letter, 1);// Append a char to c.
	if (node->is_word == TRUE) { // If reached a node that has 
		// it's 'is_word' field TRUE - Print the word and its counter.
		printf("%s %ld\n", c, node->word_count);
	}
	
	// Traverse in the opposite direction.
	for (int i = ABC-1; i>=0; i--) {
		if (node->children[i] != NULL) {
			print_rev(node->children[i], c, level + 1);
		}
	}

}
