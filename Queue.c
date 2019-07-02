#include <stdio.h>
#include <conio.h>
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
    printf("Enter your Choice:\n1>Insert\n2>Display\n3>Delete\n4>Exit\n");
    scanf("%d",&choice);
    do{
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
        default:
            printf("\nIncorrect Choice!");
            break;
        }
    }while(choice!=4);
}
void insertElement(){}
void deleteElement(){}
void displayElement(){}