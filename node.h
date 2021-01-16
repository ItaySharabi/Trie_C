#ifndef UNTITLED_ISORT_H
#define UNTITLED_ISORT_H
#define ABC 26
#define WORD_SIZE 100
typedef enum { FALSE = 0, TRUE = 1 } boolean;
typedef struct node {
	boolean is_word;
	
	char letter;
	long unsigned int word_count;
	struct node* children[ABC];
} node;
void print_words(node* head,char* c);
void print_word(node* node, char* c,int level);
void print_words_rev(node* head, char* c);
void print_rev(node* node, char* c, int level);
void toLowerCase(char str[]);

void removeSpecialChars(char* s);
void free_node(node* n);
void addWord(node* head, char* word);
struct node* newNode();
#endif //UNTITLED_ISORT_H