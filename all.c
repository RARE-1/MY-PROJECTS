#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i;
struct node{
    int data;
    struct node *next;
};
int count=0;
int choice;
struct node *START=NULL;
void LL(){
    void insert_b();
    void insert_e();
    void insert_sp();
    void delete_b();
    void delete_e();
  //  void delete_sp();
    void view();

    printf("\nEnter 1 for insertion in begining\n");
    printf("Enter 2 for insertion in ending \n");
    printf("Enter 3 for insertion at specific position\n");
    printf("Enter 4 for deletion from begining \n");
    printf("Enter 5 for deletion from ending \n");
    printf("Enter 6 for deletion from specific position\n");
    printf("enter 7 for view LL\n");
    
    while (1)
    {
      printf("Enter the choice");
      scanf("%d",&choice);
      switch (choice)
      {
      case 1:
        insert_b();
        break;
      
      case 2:
        insert_e();
        break;

      case 3:
        insert_sp();
        break;

      case 4:
        delete_b();
        break;

      case 5:
        delete_e();
        break;

      case 6:
        //delete_sp();
        printf("\nFeature comming soon\n");
        break;

      case 7:
        view();
        break;

      case 8:
        exit(0);
        break;

     default:
        printf("\n Enter the valid choice\n");
        break;
      }

    }
}  
    
void insert_b(){
    struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enetr the data part:\n");
    scanf("%d",temp->data);
    temp->next=NULL;
    if (START==NULL)
    {
        START=temp;
    }
    else
    {
        temp->next=START;
        START=temp;
    } 
}
void insert_e()
{
    struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",temp->data);
    temp->next=NULL;
    if (START==NULL)
    {
        START=temp;
    }
    else
    {
        temp=START;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=t;
    }
}
void insert_sp()
{
  struct node *temp,*t;
  int i=1,pos;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",temp->data);
  printf("after which position you want to enter the node?\n");
  if(START==NULL)
  {
    START=temp;
  }
  else if(pos>count){
    printf("enter valid choice\n");
  }
  else{
    temp=START;
    while (i<pos)
    {
      t=t->next;
      i++;
    }
    temp->next=t->next;
    t->next=temp;
    
  }
}
void delete_b()
{
  struct node *t;
  if(START==NULL)
  {
    printf("linked list is empty\n");
    printf("\n");
  }
  else
  {
    t=START;
    START=START->next;
    printf("deleted element:%d\n",t->data);
    free(t);
  }
}
void delete_e()
{
  struct node *t,*temp;
  temp=START;
  while (temp->next!=NULL)
  {
    t=temp;
    temp=temp->next;
  }
  if (temp==START)
  {
    START=NULL;
  }
  else
  {
    t->next=temp->next;
  }
  free(temp);
}
void delete_sp(){
  struct node *t,*temp;
  int pos,i=1;
  printf("enter the pos from where the node is to be deleted:");
  scanf("%d",&pos);
  temp=START;
  while(i<pos-1){
    temp=temp->next;
    i++;
  }
  temp=temp->next;
  temp->next=t->next;
  printf("deleted node =%d",t->data);
  free(t);
}
void view(){
  struct node *t;
  if (START==NULL)
  {
    printf("Bsdk khali ha ab kya hug ke element nikalu\n");
  }
  else
  {
    t=START;
    printf("LL is: ");
    while (t->next!=NULL)
    {
      t=t->next;
      count++;
    }
    printf("%d->",t->data);
  }
  printf("%d->",count);
}
void c_ll(){
  int choice ;
  printf("\nEnter 1 to insert in begining circular linked list");
  printf("\nEnter 2 to insert in ending of circular linked list");
  printf("\nEnter 3 to insert at specific position of circular linked list");
  printf("\nEnter 4 to delete from the begining of circular linked list");
  printf("\nEnter 5 to delete from ending of the circular linked list");
  printf("\nEnter 6 to delete from the specific position from circular linked list");
  printf("\nEnter 7 to view circular linked list");
  printf("\nEnter 8 to exit");

  while (1)
  {
    printf("\nEnter your choice\n");
    scanf("%i",&choice);

    switch (choice)
    {
    case 1:
    c_in_b();
      break;

    case 2:
    c_in_e();
      break;

    case 3:
    c_in_sp();
      break;

    case 4:
    c_del_b();
      break;
    
    case 5:
    c_del_e();
      break;

    case 6:
    c_del_sp();
      break;

    case 7:
    c_view();
      break;

    case 8:
     exit(0);
     break;

    
    default:
    printf("\n\t\t\tYOU NEED AN EYE TEST\n ");
      break;
    }
  }
  
}
void c_in_b(){
  struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enetr the data part:\n");
    scanf("%d",temp->data);
    temp->next=NULL;
    if (START==NULL)
    {
        START=temp;
    }
    else
    {
        temp->next=START;
        START=temp;
        temp->next=START;
    }
  
}
void c_in_e(){
    struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",temp->data);
    temp->next=NULL;
    if (START==NULL)
    {
        START=temp;
        temp->next=START;
    }
    else
    {
        temp=START;
        while (temp->next!=START)
        {
            temp=temp->next;
        }
        temp->next=t;
        temp->next=START;
    }
}
void c_in_sp(){
  struct node *temp,*t;
  int i=1,pos;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",temp->data);
  printf("after which position you want to enter the node?\n");
  if(START==NULL)
  {
    START=temp;
    temp->next=START;
  }
  else if(pos>count){
    printf("enter valid choice\n");
  }
  else{
    temp=START;
    while (i<pos)
    {
      t=t->next;
      i++;
    }
    temp->next=t->next;
    t->next=temp;
  }
}
void c_del_b(){
  struct node *t;
  if(START==NULL)
  {
    printf("linked list is empty\n");
    printf("\n");
  }
  else
  {
    t=START;
    START=START->next;
    printf("deleted element:%d\n",t->data);
    free(t);
  }
}
void c_del_e(){
  struct node *t,*temp;
  temp=START;
  while (temp->next!=START)
  {
    t=temp;
    temp=temp->next;
  }
  if (temp==START)
  {
    START=NULL;
  }
  else
  {
    t->next=temp->next;
    temp->next=START;
  }
  free(temp);
}
void c_del_sp(){
  struct node *t,*temp;
  int pos,i=1;
  printf("enter the pos from where the node is to be deleted:");
  scanf("%d",&pos);
  temp=START;
  while(i<pos-1){
    temp=temp->next;
    i++;
  }
  temp=temp->next;
  temp->next=t->next;
  printf("deleted node =%d",t->data);
  free(t);
}
void c_view(){
  struct node *t;
  if (START==NULL)
  {
    printf("Bsdk khali ha ab kya hug ke element nikalu\n");
  }
  else
  {
    t=START;
    printf("LL is: ");
    while (t->next!=START)
    {
      t=t->next;
      count++;
    }
    printf("%d->",t->data);
  }
}
void main(){
  int choice;
  printf("Enter 1 to operate in singlly linked list");
  printf("\nEnter 2 to operate in circular linked list\n");
  printf("Enter 3 to deal in doublly linked list\n");
  while (1)
  {
    printf("\nEnter your choice\n");
    scanf("%d",&choice);
  
    switch(choice)
    {
    case 1:
      LL();
      break;
    
    case 2:
      c_ll();
      break;

    case 3:
      //printf("Abhi mnn nhi kr rha\n");
      printf("\n\t\tSORRY FOR INCONVENIENCE\n");
      break;
    
    default:
    printf("\nbye bye");
      break;
    }
  }
  
}