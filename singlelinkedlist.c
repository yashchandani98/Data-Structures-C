#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
void begininginsert(int);
struct node *head;
int main(){
  int choice,data;
  do{
      printf("Enter Data:");
      scanf("%d",&data);
      begininginsert(data);
      printf("Would you like to insert more Data? 1/0:");
      scanf("%d",&choice);
  }while(choice==1);
}
void begininginsert(int data){
  struct node *ptr;
  ptr = (struct node *) malloc(sizeof(struct node *));
  if(ptr==NULL){
    printf("OverFlow\n");
  }
  else{
    ptr->data=data;
    ptr->next=head;
    head=ptr;
  }
}
void endinsert(int data){
  struct node *ptr;
  struct node *temp;
  ptr = (struct node *) malloc(sizeof(struct node *));
  if(ptr==NULL){
    printf("OverFlow\n");
  }
  else{
    if(head== NULL){
      ptr->data=data;
      ptr->next=NULL;
      head=ptr;
    }
    else{
      temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=ptr;
      ptr->next=NULL;
    }
  }
}
void specificnode(int data,int nodeno){
  struct node *ptr;
  struct node *temp;
  struct node *temp2;
  ptr = (struct node *) malloc(sizeof(struct node *));
  if(ptr==NULL){
    printf("OverFlow\n");
  }
  else{
    temp=head;
    for(int i=0;i<nodeno;i++){
      temp2=temp;
      temp=temp->next;
      if(temp==NULL)
      return;
    }
    ptr->data=data;
    temp2->next=ptr;
    ptr->next=temp;
  }
}
int beginingdelete(){
  struct node *ptr;
  if(head==NULL){
    printf("Underflow");
    return 0;
  }
  ptr=head;
  head=head->next;
  free(ptr);
  return 0;
}
int lastdelete(){
  struct node *ptr;
  struct node *ptr2;
  if(head==NULL){
    printf("Underflow");
    return 0;
  }
  if(head->next==NULL){
    free(head);
    return 0;
  }
  ptr=head;
  while(ptr->next!=NULL){
    ptr2=ptr;
    ptr=ptr->next;
  }
  ptr2->next=NULL;
  free(ptr);
  return 0;
}
int specificdelete(int nodenumber){
  struct node *ptr;
  struct node *ptr2;
  if(head==NULL){
    printf("Underflow");
    return 0;
  }
  if(head->next==NULL){
    free(head);
    return 0;
  }
  ptr=head;
  for(int i=0;i<nodenumber;i++){
    ptr2=ptr;
    ptr=ptr->next;
    if(i==nodenumber){
      ptr2->next=ptr->next;
      free(ptr);
    }
  }
  return 0;
}
