#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

int comp_str(void *lhs, void *rhs) {
	return strcmp((char *)lhs, (char *)rhs);
}

int comp_search(void *dataSought, struct Node *node) {
	return comp_str((char *)dataSought, (char *)node->data);
}

void print_str(struct Tree *tree, struct Node *node) {
	printf("%s ", (char *)node->data);
}

int main(int argc, char **argv) {

	/* Declare tree */
	struct Tree tree;

	/* Testing tree init */
	printf("Testing tree init... ");
	tree_init(&tree);

	assert(tree.size == 0);
	assert(tree.root == NULL);

	printf("Passed!\n");

	/* Testing tree insertion */
	printf("Testing tree insertion... ");

	tree_insert(&tree, "B", comp_str);
	tree_insert(&tree, "A", comp_str);
	tree_insert(&tree, "C", comp_str);

	assert("B" == (char *)tree.root->data);
	assert("A" == (char *)tree.root->left->data);
	assert("C" == (char *)tree.root->right->data);

	printf("Passed!\n");

	/* Testing traversal */
	printf("Traversing in order: ");
	tree_traverse_in_order(&tree, tree.root, print_str);

	printf("\nTraversing pre order: ");
	tree_traverse_pre_order(&tree, tree.root, print_str);

	printf("\nTraversing post order: ");
	tree_traverse_post_order(&tree, tree.root, print_str);

	/* Testing search */
	printf("\nSearching element 'A'... ");
	struct Node *p = tree_search(&tree, "A", comp_search);
	assert (p != NULL);

	printf("Passed!\n");

	/* Testing removal */
	tree_remove_all(&tree);

	assert(tree.size == 0);
	assert(tree.root == NULL);

	printf("\n%s\n", "All tests passed.");

	return 0;
}