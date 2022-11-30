/*Problem- Create a Doubly linked list which can take character as input. After creation, write a code which can delete any (not only 1st or last) element from that 
linked list. Finally print all elements. To create a linked list, using a loop is mandatory.*/

/*Nusrat Farzana Choudhury
  ID: 221-35-990
  Sec-B*/

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

typedef struct node Node; //self-referential structure

struct node {
    Node *prev; //previous pointer
    char ch;    //data part
    Node *next; //next pointer
};

int main() {
	
	system("cls");
	system("color B0");
    Node *head = NULL, *current = NULL, *temp = NULL, *temp2= NULL; 
    int num, position,size;
              //taking variables
    
    printf("How many nodes do you wanna insert?\t: ");
    scanf("%d",&num);
    size=num;
    printf("\n\n");
    
    /*start making linked list*/
    
    while(num--){ //this loop will continue till the end of input
   
        current = (Node *)malloc(sizeof(Node)); //memory allocation for a node
		printf("We have got node\t\t\t\t: %d\n", current);

        /*taking character as inputs of those variables in node*/
        printf("Enter a character as a data of linked list\t: ");
        scanf(" %c", &current->ch);
        fflush(stdin);
        current->prev = NULL;
        current->next = NULL;

        /*linking list here*/
        if(head == NULL) {
            head = temp = current;
        }
        else {
            temp->prev = temp2;
            temp->next = current;
            temp2 = temp;
            temp = current;
        }
    }
        temp->prev = temp2;
    
    /*printing the list*/
    printf("\nStatus of linked list:\n");
    temp = head;
    printf("[%d]--->[%d][%c]", temp, temp->prev, temp->ch);
    temp=temp->next;    
    while(temp != NULL) {
    	printf("[%d]<--->[%d][%c]", temp, temp->prev, temp->ch);
        temp = temp->next;      
    }
    printf("[0]");
    printf("\n\n");
    
    /*Deletion at any position*/
    printf("Enter the position of node you wanna delete\t: ");
    scanf("%d",&position);
    
    if(position==1){ //delete at first
    	temp=head;
    	head=head->next;
    	head->prev= NULL;
    	free(temp);
	}
	
	else if(position==size){ //delete at last
		temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
    		temp2=temp->prev;
			temp2->next=NULL;
			free(temp);
	}
	else{ //delete at any intermidiate position
		temp=head;
		position=position-1;
		while(position--){
			temp=temp->next;
		}
		temp2=temp->prev;
		temp2->next=temp->next;
		temp->next->prev=temp2;
		free(temp);
	}
		
	/*printing the list after deletion*/
    printf("\nStatus of linked list after deletion:\n");
    temp = head;
    printf("[%d]--->[%d][%c]", temp, temp->prev, temp->ch);
    temp=temp->next;    
    while(temp != NULL) {
    	printf("[%d]<--->[%d][%c]", temp, temp->prev, temp->ch);
        temp = temp->next;      
    }
    printf("[0]");
    printf("\n\n");
	

    return 0;
}
