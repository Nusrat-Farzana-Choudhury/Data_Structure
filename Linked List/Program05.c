/*Problem- Create a linked list, delete 1st element & print, then insert the last element & print*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE; //self-referential structure

struct node{
	int id;
	char name[20];
    float cgpa;
	NODE *next;	
};
NODE *head=NULL, *next=NULL, *temp=NULL, *current=NULL;
int num,size,i=1;
void create(){
	/*Dynamic creation of linked list*/
	
	printf("Enter the number of nodes you wanna insert\t: ");
	scanf("%d",&num);
	size=num;
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
		printf("\n");
	}
}
//Printing the list
void show(){
	printf("\nThe status of the linked list\t:\n");
	temp = head;
	while(temp != 0){
		printf("[%d]----->[%d][%s][%.2f]",temp,temp->id,temp->name,temp->cgpa);
		temp = temp->next;
	}
	printf("[0]");
}
//deleting first element:
void delete_at_first(){
	temp=head;
	head=head->next;
	free(temp);	
}

//insertion at last
int insert_at_last(){
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	printf("\nWe have got a node\t\t: %d\n",current);
	temp->next=current;
	printf("Enter the ID in node-%d\t\t: ",size);
	scanf("%d",&current->id);                       //data 1
	printf("Enter the name in node-%d\t: ",size);
	scanf("%s",&current->name);                     //data 2
	printf("Enter the CGPA in node-%d\t: ",size);
	scanf("%f",&current->cgpa);                     //data 3
	current->next=NULL;
}

int main(){
	create();
	show();
	printf("\n\n");
	
	printf("\n------After deleting 1st element:------");
	delete_at_first();
	show();
	printf("\n\n");
	
	printf("\n------Inserting last element------");
	insert_at_last();
	printf("\n\n");
	
	printf("\n------After inserting last element:------");
	show();
	printf("\n\n");
	
	return 0;
}
