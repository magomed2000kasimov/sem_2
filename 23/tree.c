//
// Created by magom on 30.06.2019.
//
#include "tree.h"

void print(node *root,int e){
    if (root==NULL)
        return;
    print(root->right,e+1);
    printf("%*s %c\n",4*e, "-", root->key);
    print(root->left,e+1);
}

int max(int a,int b)
{
    if (a>b)
        return a;
    else return b;

}


void add(node** root, char k)
{
    if ((*root)==NULL)
    {
        (*root)=malloc(sizeof(node));
        (*root)->right=NULL;
        (*root)->left=NULL;
        (*root)->key=k;
    }
    else if (k < (*root)->key)
        return add(&(*root)->left, k);
    else
        return add(&(*root)->right, k);
}
int abs(int a)
{
    if (a>0)
        return a;
    else return  -a;
}

int glubina(node* root, int e)
{
    if (root==NULL)
        return e;
    return max(glubina(root->left,e+1),glubina(root->right,e+1));
}

int AVL(node* root)
{
    if (abs(glubina(root->left,0)-glubina(root->right,0))<2)
        return 1;
    else return 0;
}

void delete(node** root, char k) {
    node *repl = NULL,
            *parent = NULL, // родитель искомого узла
            *tmp = *root;
    while ((tmp != NULL) && (tmp->key != k)) {
        parent = tmp;
        if (k < tmp->key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    // если мы не нашли узел, то завершаем выполнение функции
    if (tmp == NULL)
        return;
    // если мы нашли узел и у него есть только левый ребёнок, то
    if (tmp->left != NULL && tmp->right == NULL) {
        if (parent != NULL) {
            if (parent->left == tmp)
                parent->left = tmp->left;
            else
                parent->right = tmp->left;
        } else
        {   free(*root);
            *root = tmp;
        tmp=NULL;}
    } else if (tmp->right != NULL && tmp->left == NULL) {
        if (parent != NULL) {
            if (parent->left == tmp)
                parent->left = tmp->right;
            else
                parent->right = tmp->right;
        } else {
            node* l=*root;
            *root = (*root)->right;
            free(l);
            l=NULL;
        }
    } else if (tmp->left != NULL && tmp->right != NULL) {
        repl = tmp->right;
        if (repl->left == NULL)
            tmp->right = repl->right;
        else {
            while (repl->left != NULL) {
                parent = repl;
                repl = repl->left;
            }

            parent->left = repl->right;
        }

        tmp->key = repl->key;

        free(repl);
        repl = NULL;
        // в противном случае
    } else {
        // если у найденного узла есть родитель
        if (parent != NULL) {
            // и у родителя найденный узел находится слева, то затереть его
            if (parent->left == tmp)
                parent->left = NULL;
                // тоже самое и справа
            else
                parent->right = NULL;
        } else
            (*root) = NULL;

        free(tmp);

        tmp = NULL;
    }

}
