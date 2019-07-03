#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Math.h>
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node node2;
struct node *root=NULL;
int count=0;
int temp=0;
void insertNode();
void postorder(node2 *tree);
void preorder(node2 *tree);
void inorder(node2 *tree);
node2 *node(node2 *tree, int data);
int main(){
    int choice=0;
    printf("\n*****Welcome to Binary Tree Program*****");
    do
    {
        printf("\nEnter your Choice:\n1>Insert\n2>Inorder Traversal\n3>Preorder Traversal\n4>Postorder Traversal\n5>Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertNode();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        }
    }while(choice!=5);
}
void insertNode(){
    int item;
    printf("\nEnter Data(Enter -1 to stop):");
    scanf("%d",&item);
    while(item!=-1){
        root = node(root,item);
        scanf("%d",&item);
    }
}
node2* node(struct node *tree, int data){
    if(tree==NULL){
        tree = (node2 *)malloc(sizeof(node2));
        tree->data=data;
        tree->lchild=NULL;
        tree->rchild = NULL;
        count++;
    }
    else{
        if(count%2==0){
            tree->rchild = node(tree->rchild, data);
        }
        else{
            tree->lchild = node(tree->lchild, data);
        }
    }
    return tree;
}
void inorder(node2* tree){
    if(tree!=NULL){
        inorder(tree->lchild);
        printf("\n%d",tree->data);
        inorder(tree->rchild);
    }
}
void preorder(node2 *tree){
    if (tree != NULL){
        printf("\n%d", tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}
void postorder(node2 *tree){
    if (tree != NULL){
        postorder(tree->lchild);
        postorder(tree->rchild);
        printf("\n%d", tree->data);
    }
}