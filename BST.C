#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *lchild;
    struct tree *rchild;
}*t,*temp;

int element;
struct tree *create(struct tree *t,int element)
{
    t=(struct tree*)malloc(sizeof(struct tree));
    t->data=element;
    t->lchild=NULL;
    t->rchild=NULL;
    return t;
}
struct tree *insert(struct tree *t,int element)
{
    if(t==NULL)
    {
        t=(struct tree*)malloc(sizeof(struct tree));
        t->data=element;
        t->lchild=NULL;
        t->rchild=NULL;
        return t;
    }
    else
    {
        if(element<t->data)
        {
            t->lchild=insert(t->lchild,element);
        }
        else
        {
            if(element>t->data)
            {
               t->rchild=insert(t->rchild,element); 
            }
            else{
                if(element==t->data)
                   printf("element already present");
            }
            return t;
        }
    }
}
void *search(struct tree *t,int element)
{
   if(t==NULL)
   {
       return NULL;
   }
   else
   {
         if(element<t->data)
             search(t->lchild,element);
         else if(element>t->data)
             search(t->rchild,element);
         else
         {
             printf("Element found!!");
             return t;
         }
    }
             
}
struct tree *findmin(struct tree *t)
{
    if(t==NULL)
        return NULL;
    else
       if(t->lchild==NULL)
          return t;
    else
        return (findmin(t->lchild));
}
struct tree *del(struct tree *t,int element)
{   
    int c=0;
    if(t==NULL)
    {
       printf("NO elements!!");
       c=1;
    }
    else if(element<t->data)
       t->lchild=del(t->lchild,element);
    else if(element>t->data)
         t->rchild=del(t->rchild,element);
    else
    {
    
           if(t->rchild==NULL)
           {
               struct tree *temp=t->lchild;
               free(t);
               return(temp);
           }
           if(t->lchild==NULL)
           {
               struct tree *temp=t->rchild;
               free(t);
               return(temp);
           }
           temp=findmin(t->rchild);
           t->data=temp->data;
           t->rchild=del(t->rchild,temp->data);
    }
    if(c==0)
    
       printf("Element deleted successfully");
    return(t);
}   


struct tree *findmax(struct tree *t)
{
    if(t==NULL)
       return NULL;
    else
        if(t->rchild==NULL)
           return t;
    else 
        return (findmax(t->rchild));
}
void inorder(struct tree *t)
{
    if(t==NULL)
    {
        return;
    }
    else{
        
      inorder(t->lchild);
      printf("%d",t->data);
      inorder(t->rchild);
    }
}
void preorder(struct tree *t)
{
    if(t==NULL)
    {
        return;
    }
    else{
        printf("%d",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void postorder(struct tree *t)
{
    if(t==NULL)
    {
        return;
    }
    else{
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d",t->data);
    }
}
int main()
{   int ch;
    do
    {
      
      printf("BINARY SEARCH TREE");
      printf("\n1.create\n2.insert\n3.search\n4.findmin\n5.findmax\n6.inorder\n7.preorder\n8.postorder\n9.delete\n10.exit");
      printf("\nEnter your choice : ");
      scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nenter the data \n");
            scanf("%d",&element);
            t=create(t,element);
            inorder(t);
            break;
        case 2:
            printf("\nenter the data \n");
            scanf("%d",&element);
            t=insert(t,element);
            inorder(t);
            break;
        case 3:
            printf("\nenter the element to search\n");
            scanf("%d",&element);
            temp=search(temp,element);
            if(t->data==element)
              printf("\nthe element %d is ",element);
            else
              printf("data not found");
            break;
        case 4:
            temp=findmin(t);
            printf("\n max value is %d ",temp->data);
            break;
        case 5:
            temp=findmax(t);
            printf("\n min value is %d ", temp->data);
            break;
        case 6:
            inorder(t);
            break;
        case 7:
            preorder(t);
            break;
        case 8:
            postorder(t);
            break;
        case 9:
             printf("\nenter the element to delete\n");
             scanf("%d",&element);
             temp=del(temp,element);
             break;
        case 10:
            exit(0);
            break;
        default:
            printf("invalid choice");
        
            
    }
}while(ch!=10);
    printf("thank you :) ");
    return 0;
}
