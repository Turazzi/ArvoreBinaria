#ifndef TREE_H
#define TREE_H

typedef struct _node {
    char data;
    struct _node* left;
    struct _node* right;
} t_node;

t_node* create_node(char data);
int is_balanced(const char* str);
void free_tree(t_node* node);
t_node* build_tree(char** str);
void pre_order(t_node *node);
void in_order(t_node *node);
void post_order(t_node *node);
int height(t_node* node);
void print_tree(t_node* root, int space);

#endif 
