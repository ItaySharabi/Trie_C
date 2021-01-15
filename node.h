#ifndef UNTITLED_ISORT_H
#define UNTITLED_ISORT_H
#define WORD 26
typedef enum { FALSE = 0, TRUE = 1 } boolean;
typedef struct node {
	boolean is_word;
	
	char letter;
	long unsigned int count;
	struct node* children[WORD];
} node;
void print_word(node* head,char* c);
void print_word2(node* node, char* c,int level);
void print_word_rev(node* head, char* c);
void print_word_rev2(node* node, char* c, int level);
void chenge(char str[]);

void RemoveChars(char* s);
void free_node(node* n);
void addword(node* head, char* word);
struct node* newNode();
#endif //UNTITLED_ISORT_H