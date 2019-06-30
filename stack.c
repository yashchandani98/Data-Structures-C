#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
struct node{
  int item;
  struct node *next;
};
struct node *head;
int main() {
  int choice=0;
  printf("*****Welcome to the Stack Program *****\n");
  do{
    printf("1->Push\n2->Pop\n3->Peek\n4->Exit\nEnter Choice:");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        exit(0);
    }
  }while(choice>0);
  return 0;
}
void push(){
  int item;
  struct node *ptr;
  printf("Enter Element:");
  scanf("%d",&item);
  ptr =(struct node *) malloc(sizeof(struct node *));
  if(ptr == NULL){
    printf("Couldn't Push the Item");
  }
  else{
    ptr->item=item;
    if(head==NULL){
      ptr->next=NULL;
      head=ptr;
    }
    else{
      ptr->next=head;
      head=ptr;
    }
    printf("Item Pushed\n");
  }
}
void pop(){
  struct node *ptr;
    ptr=head;
    if(head==NULL){
      printf("UnderFlow\n");
    }
    else{
      head=head->next;
      ptr->next=NULL;
      printf("POP Element:%d\n",ptr->item);
      free(ptr);
    }
}
void peek(){
  struct node *ptr;
  if(head==NULL){
    printf("Underflow\n");
  }
  else{
    ptr=head;
    printf("Elements are:\n");
    while(ptr!=NULL){
      printf("%d\n",ptr->item);
      ptr=ptr->next;
    }
  }
}
