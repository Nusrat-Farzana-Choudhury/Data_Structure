/*Problem- Create a singly linked list to store data for ID, name & CGPA of a student in a node (user should be able to input the number of nodes & data).*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE; //self-referential structure

struct node{
	int id;
	char name[20];
    float cgpa;
	NODE *next;	
};

int main(){
	/*Dynamic creation of linked list*/
	
	NODE *head=NULL, *next=NULL, *temp=NULL, *current=NULL;
	int num, i=1;
	
	printf("Enter the number of nodes you wanna insert\t: ");
	scanf("%d",&num);
	printf("\n\n");
	
	while(num--){
		current= (NODE*)malloc(sizeof(NODE));           //memory allocation for a node
		printf("We have got a node\t\t: %d\n",current);
		printf("Enter the ID in node-%d\t\t: ",i);
		scanf("%d",&current->id);                       //data 1
		printf("Enter the name in node-%d\t: ",i);
		scanf("%s",&current->name);                     //data 2
		printf("Enter the CGPA in node-%d\t: ",i);
		scanf("%f",&current->cgpa);                     //data 3
		i++;                                            //updating counter of node 
		fflush(stdin);
		current->next=NULL;
		
		/*Linking nodes here*/
		if(head==NULL){
			head=temp=current;                         //identifying head of the node
		}
		else{
			temp->next=current;
			temp=current;
		}
		printf("\n\n");
	}
	
	/*Printing the list*/
	printf("The status of the linked list\t:\n");
	temp = head;
	while(temp != 0){
		printf("[%d]----->[%d][%s][%.2f]",temp,temp->id,temp->name,temp->cgpa);
		temp = temp->next;
	}
	printf("[0]");
	
	return 0;
}
