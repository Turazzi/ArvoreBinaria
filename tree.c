#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

t_node* create_node(char data) {
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int is_balanced(const char* str) {
    int balance = 0;
    while (*str) {
        if (*str == '(') balance++;
        if (*str == ')') balance--;
        if (balance < 0) return 0;  
        str++;
    }
    return balance == 0;
}

void free_tree(t_node* node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

t_node* build_tree(char** str) {
    if (**str == '\0') return NULL;

    if (**str == '(') (*str)++;

    if (**str == ')') {
        (*str)++;
        return NULL;
    }

    t_node* root = create_node(**str);
    (*str)++;

    if (**str == '(' || **str == ',') {
        if (**str == ',') (*str)++;
        root->left = build_tree(str);
        if (root->left == NULL && **str != ',') { 
            free(root);
            return NULL;
        }
        if (**str != ',' && **str != ')') {
            free_tree(root);
            return NULL;
        }
    }

    if (**str == ',' || **str == '(') {
        if (**str == ',') (*str)++;
        root->right = build_tree(str);
        if (root->right == NULL && **str != ')') {  
            free_tree(root);
            return NULL;
        }
        if (**str != ')') {
            free_tree(root);
            return NULL;
        }
    }

    if (**str == ')') (*str)++;

    return root;
}

void pre_order(t_node *node) {
    if (node != NULL) {
        printf("%c ", node->data);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%c ", node->data);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->data);
    }
}

int height(t_node* node) {
    if (node == NULL) return -1;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void print_tree(t_node* root, int space) {
    if (root == NULL) return;

    space += 4;

    print_tree(root->right, space);

    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);

    print_tree(root->left, space);
}
