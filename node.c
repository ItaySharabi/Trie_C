
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"node.h"




node* newNode() {
	node* t = (node*)malloc(sizeof(node));
	if (t == NULL)
		printf("malloc not work try again");

	t->count = 0;
	for (int i = 0; i < WORD; i++)
		t->children[i] = NULL;

	return t;

	
}

void chenge(char str []){

	for (int i = 0; str[i]!='\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}


}

void addword(node* head,char* word) {
	chenge(word);
	RemoveChars(word);
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
void RemoveChars(char* s)
{
	int writer = 0, reader = 0;

	while (s[reader])
	{
		if (s[reader]>='a' && s[reader]<='z')
		{
			s[writer++] = s[reader];
		}

		reader++;
	}

	s[writer] = 0;
}
void free_node(node* n) {
	
	if (n == NULL) {
		return;
	}
	else {
		for (int i = 0; i < WORD; ++i) {
			free_node((n->children)[i]);
		}
	}
	free(n);
	return;
}
void print_word(node* head,char* c) {
	
	for (int i = 0; i < WORD; i++) {
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
	
	for (int i = 0; i < WORD; i++) {
		
		if (node->children[i] != NULL) {
		print_word2(node->children[i], c,level+1);

		}
		

	}
	

}


void print_word_rev(node* head, char* c) {

	for (int i = WORD-1; i >= 0; i--) {
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

	for (int i = WORD-1; i>=0; i--) {

		if (node->children[i] != NULL) {
			print_word_rev2(node->children[i], c, level + 1);

		}


	}

}