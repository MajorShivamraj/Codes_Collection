//Doubly linked list  and reversal.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=0,*temp;

void add_node(){
	struct node *newnode, *prev=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data = ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->prev=0;
	if(head==0){
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		newnode->prev=temp;
		temp=newnode;
	}
}

void display_node(){
	struct node *current;
	current=head;
	while(current!=0){
		if(current->next!=0){
			printf("%d <--> ",current->data);
		}
		else{
			printf("%d ",current->data);
		}
		current=current->next;
	}
	printf("\n");
}

void reverse_list(){
	struct node *current;
	current=temp;
	while(current!=0){
		if(current->prev!=0){
			printf("%d <--> ",current->data);
		}
		else{
			printf("%d ",current->data);
		}
		current=current->prev;
	}
	current=head;
	printf("\n");
	
}

int main(){
	int choice;
	while(1){
		printf("--------------------------------------\n");
		printf("1) Add nodes \n");
		printf("2) Display nodes \n");
		printf("3) Reverse nodes \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_node();
		}
		else if(choice==2){
			display_node();
		}
		else if(choice==3){
			reverse_list();
		}
		
		else if(choice==0){
			break;
		}
	}
	
}

