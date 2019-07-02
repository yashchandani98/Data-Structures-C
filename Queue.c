#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * front;
struct node * rear;
void insertElement();
void deleteElement();
void displayElement();
int main(){
    int choice=0;
    printf("********Queue Menu Driven Program********\n");
    while(choice!=4)
    {
        printf("Enter your Choice:\n1>Insert\n2>Display\n3>Delete\n4>Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertElement();
            break;
        case 2:
            displayElement();
            break;
        case 3:
            deleteElement();
            break;
        }
    }
    return 0;
}
void insertElement(){
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void deleteElement(){
    struct node *ptr;
        if(front==NULL){
            printf("\nUnderflow!");
        }
        else{
            ptr=front;
            front=front->next;
            ptr->next=NULL;
            free(ptr);
        }
}
void displayElement(){
    struct node *ptr;
    if(front==NULL){
        printf("\nUnderflow!");
    }
    else{
        ptr=front;
        printf("\nPrinting Values:");
        while(ptr!=NULL){
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}