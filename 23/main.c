#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void zadanie(node* root,int a,int b,int* p) {
    int i = 0;
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            if (root->key < a || root->key > b)
                (*p)++;
        }

        zadanie(root->left, a, b,p);
        zadanie(root->right, a, b,p);
      //  return i;
    }
    //return 0;
}
int menu(void){
    int lel;
    int choice;
    printf("enter:\n"
           "1-add\n"
           "2-remove\n"
           "3-zadanie\n"
           "4-print\n"
           "5-end\n");
    scanf("%d",&lel);
    return lel;

}






int main() {
    int choice,p,glub;
    char key;
    char b1,b2,b3;
    node* head=NULL;
    while((choice = menu())!= 5){

        switch (choice) {
            case 1:
                printf("vvedite key uzla\n");
                scanf("%s",&key);
                add(&head,key);
                break;
            case 2:
                printf("vvedite key uzla\n");
                scanf("%s",&key);
                delete(&head,key);
                break;
            case 3:
                printf("vvedite diapazon slitno\n");
                scanf("%c",&b1);
                scanf("%c",&b2);
                scanf("%c",&b3);
                p=0;
                zadanie(head,b2,b3,&p);
                if (p>0)
                    printf("ne vse");
                else
                    printf("vse");
                printf("\n");
           //     glub=glubina(head,0);
            //    printf("%d\n", glub);
             //   p=0;
          //      p=AVL(head);
   /*             if (p!=0)
                    printf("AVL\n");
                else
                    printf("ne AVL\n");*/
                break;
            case 4:
                print(head,0);
                printf("\n");
                break;
        }
    }
    return 0;
}