//Creating a circular linked list with flag

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node Node;
struct node
{
    int flag;
    int data;
    Node *next;
};

Node *head=0,*temp=0,*newnode=0;
int main()
{
	int num;
	printf("How many nodes you wanna insert? : ");
	scanf("%d",&num);
	printf("\n\n");
    
    while(num--)
    {
        newnode=(Node*)malloc(sizeof(Node)); //memory allocation for a node
        newnode->flag=0;
        printf("Enter an integer as he data: ");
        scanf("%d",&newnode->data); //int type data entry in a node
        
    /*Linking list here*/    
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }

    }
    temp->next=head;
    temp->flag=1;         //flag=1 for identifying last node
            //Linking part ended
     
	printf("\n\n");         
	 
    //Printing list
    printf("\n\nThe circular linked list is as below:\n");
    temp=head;
    while(temp->flag!=1) //this loop will continue till the 2nd last node
    {
        printf("[%d] [%d] [%d]-->",temp->flag,temp->data,temp->next);
        temp=temp->next;
    }
       printf("[%d] [%d] [%d]-->",temp->flag,temp->data,temp->next); //as the list is circular there's an arrow at the end.

   printf("\n\n");
   return 0;
}
