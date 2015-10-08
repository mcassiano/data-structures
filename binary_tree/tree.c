#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void tree_init(struct Tree *tree) {
	tree->root = NULL;
	tree->size = 0;
}

int tree_empty(struct Tree *tree) {
    return (tree->root == NULL);
}

void tree_insert_recursive(struct Tree *tree, void *data, struct Node *node, int (*comparator) (void *, void *)) {
    
    if (node == NULL)
        return;

    int comparison = comparator(data, node->data);

    if (comparison == 0) {
    	tree->size -= 1;
    	return;
    }
    
    /* If the result from the comparison is greater than
        zero, look to the right */
    
    else if (comparison > 0) {
        
        if (node->right == NULL) {
            node->right = (struct Node *) malloc(sizeof(struct Node));

            node->right->left = NULL;
            node->right->right = NULL;
            node->right->data = data;

            return;
        }
        
        tree_insert_recursive(tree, data, node->right, comparator);
    }
    
    else {
        
        if (node->left == NULL) {
            node->left = (struct Node *) malloc(sizeof(struct Node));

            node->left->left = NULL;
            node->left->right = NULL;
            node->left->data = data;

            return;
        }
        
        tree_insert_recursive(tree, data, node->left, comparator);
    }
    
}


void tree_insert(struct Tree *tree, void *data, int (*comparator) (void *, void *)) {

	if (tree == NULL)
        return;
    
    else if (tree_empty(tree)) {
        tree->root = (struct Node *) malloc(sizeof(struct Node));
        tree->root->left = NULL;
        tree->root->right = NULL;
        tree->root->data = data;
    }
    
    else
        tree_insert_recursive(tree, data, tree->root, comparator);
    
    tree->size += 1;
}

struct Node* tree_search(struct Tree *tree, void *dataSought, int (*comparator) (void *, struct Node *)) {

    struct Node *node = tree->root;
    struct Node *sought = NULL;

    while (node != NULL) {

        int comparison = comparator(dataSought, node);

        if (comparison == 0) {
            sought = node;
            node = NULL;
        }

        else if (comparison < 0)
            node = node->left;

        else
            node = node->right;

    }

    return sought;

}

void tree_traverse_in_order(struct Tree* tree, struct Node *node, void (*f)(struct Tree *, struct Node *)) {
    
    if (node == NULL)
        return;
    
    if (node->left)
        tree_traverse_in_order(tree, node->left, f);
    
    f(tree, node);
    
    if (node->right)
        tree_traverse_in_order(tree, node->right, f);
    
}

void tree_remove(struct Tree *tree, struct Node *node) {
    
    if (node != NULL) {
        
        if (node->left) {
            tree_remove(tree, node->left);
            node->left = NULL;
        }
        
        if (node->right) {
            tree_remove(tree, node->right);
            node->right = NULL;
        }
        
        free(node);
        tree->size -= 1;
    }
}

void tree_remove_all(struct Tree *tree) {
    tree_remove(tree, tree->root);
    tree->size = 0;
    tree->root = NULL;
}

