#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void process_command(char* command, t_node** root) {
    if (strncmp(command, "create ", 7) == 0) {
        char* tree_desc = command + 7;
        if (!is_balanced(tree_desc)) {
            printf("invalid\n");
            return;
        }
        char* str = tree_desc;
        t_node* new_root = build_tree(&str);
        if (*str != '\0' || new_root == NULL) { 
            printf("invalid\n");
            free_tree(new_root);
            return;
        }
        *root = new_root;
        printf("Árvore criada com sucesso!\n");
    } 
    else if (strcmp(command, "pre") == 0) {
        if (*root != NULL) {
            printf("Pré Ordem: ");
            pre_order(*root);
            printf("\n");
        } else {
            printf("A árvore ainda não foi criada.\n");
        }
    } 
    else if (strcmp(command, "in") == 0) {
        if (*root != NULL) {
            printf("In Ordem: ");
            in_order(*root);
            printf("\n");
        } else {
            printf("A árvore ainda não foi criada.\n");
        }
    } 
    else if (strcmp(command, "pos") == 0) {
        if (*root != NULL) {
            printf("Pós Ordem: ");
            post_order(*root);
            printf("\n");
        } else {
            printf("A árvore ainda não foi criada.\n");
        }
    } 
    else if (strcmp(command, "height") == 0) {
        if (*root != NULL) {
            int h = height(*root);
            printf("Altura da árvore: %d\n", h);
        } else {
            printf("A árvore ainda não foi criada.\n");
        }
    } 
    else if (strcmp(command, "print") == 0) {
        if (*root != NULL) {
            printf("Árvore:\n");
            print_tree(*root, 0);
        } else {
            printf("A árvore ainda não foi criada.\n");
        }
    } 
    else if (strcmp(command, "exit") == 0) {
        exit(0);
    } else {
        printf("Comando não reconhecido.\n");
    }
}

int main() {
    char command[256];
    t_node* root = NULL;

    while (1) {
        printf("Digite um comando: ");
        if (fgets(command, sizeof(command), stdin) != NULL) {
            command[strcspn(command, "\n")] = '\0';
            process_command(command, &root);
        }
    }

    return 0;
}
