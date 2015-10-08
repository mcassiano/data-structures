#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *left;
	struct Node *right;
	void *data;
};

struct Tree {
	struct Node *root;
	int size;
};

void tree_init(struct Tree *tree);
int tree_empty(struct Tree *tree);
void tree_insert_recursive(struct Tree *tree, void *data, struct Node *node, int (*comparator) (void *, void *));
void tree_insert(struct Tree *tree, void *data, int (*comparator) (void *, void *));
struct Node* tree_search(struct Tree *tree, void *dataSought, int (*comparator) (void *, struct Node *));
void tree_remove(struct Tree *tree, struct Node *node);
void tree_remove_all(struct Tree *tree);
void tree_traverse_pre_order(struct Tree *tree, struct Node *node, void (*f) (struct Tree *, struct Node *));
void tree_traverse_in_order(struct Tree *tree, struct Node *node, void (*f) (struct Tree *, struct Node *));
void tree_traverse_post_order(struct Tree *tree, struct Node *node, void (*f) (struct Tree *, struct Node *));
