//
// Created by magom on 30.06.2019.
//

#ifndef KANIKULI_TREE_H
#define KANIKULI_TREE_H

#include <stdio.h>
#include <stdlib.h>
struct tree{
    struct tree* left;
    struct tree* right;
    char key;
};

typedef  struct tree node;


void add(node** root, char k);
void delete(node** root, char k);

void print(node *root,int e);
int glubina(node* root,int e);
int max(int a,int b);
int AVL(node* root);
int abs(int a);






#endif //KANIKULI_TREE_H
