#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int power;
    int coeff;
    struct node *next;
}*p,*q,*r;

struct node *create(struct node *head,struct node *newnode);
void display(struct node *head);
void add();


void main()
{
    int n1,n2,i;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    
    printf("Addion of polynomial");
    printf("\nEnter the no of terms in fisrt polynomial : ");
    scanf("%d",&n1);
    printf("\nEnter the coeff and power of 1st polynomial : ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&ptr->coeff);
        scanf("%d",&ptr->power);
        ptr->next=NULL;
        p=create(p,ptr);
    }
        //display(p);
    printf("\nEnter the no of terms in 2nd polynomial : ");
    scanf("%d",&n2);
    printf("\nEnter the coeff and power of 2nd polynomial :  ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&ptr->coeff);
        scanf("%d",&ptr->power);
        ptr->next=NULL;
        q=create(q,ptr);
    }
    display(q);
    add(); 
    printf("\nThe result is : ");
    display(r);
    display(r);
    getch();
}
struct node *create(struct node *head,struct node *newnode)
{   
    if(head==NULL)
    {
        head=newnode;
        return (head);
    } 
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
    
            temp=temp->next;
        temp->next=newnode;
        
        return (head);
    }
}
void add()
{    
    struct node *newnode,*ptr1,*ptr2;
    ptr1=p;
    ptr2=q;
    
  while(ptr1!=NULL||ptr2!=NULL)
  {  
    newnode=(struct node*)malloc(sizeof(struct node));
    if(ptr1->power==ptr2->power)
    {
      newnode->coeff=ptr1->coeff+ptr2->coeff;
      newnode->power=ptr1->power;
      newnode->next=NULL;
        r=create(r,newnode);
      ptr1=ptr1->next;
      ptr2=ptr2->next;
    }
    else if(ptr1->power>ptr2->power)
    {
        newnode->coeff=ptr1->coeff;
        newnode->power=ptr1->power;
        newnode->next=NULL;
         r=create(r,newnode);
        ptr1=ptr1->next;
    }
    else
    {
      newnode->coeff=ptr2->coeff;
      newnode->power=ptr2->power;
      newnode->next=NULL;
         r=create(r,newnode);
      ptr2=ptr2->next;
    }
  }
  if(ptr1!=NULL)
  {
      while(ptr1!=NULL)
      {
         newnode->coeff=ptr1->coeff;
         newnode->power=ptr1->power;
         newnode->next=NULL;
           r=create(r,newnode);
         ptr1=ptr1->next;
      }
  }
  if(ptr2!=NULL)
  {
      while(ptr2!=NULL)
      {
          newnode->coeff=ptr2->coeff;
          newnode->power=ptr2->power;
          newnode->next=NULL;
            r=create(r,newnode);
          ptr2=ptr2->next;
      }
  }
    
}    
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("No elements ");
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            printf("\n%dx^%d",temp->coeff,temp->power);
            printf("+");
            temp=temp->next;
        }
        printf("\n%dx^%d",temp->coeff,temp->power);
    }
}
