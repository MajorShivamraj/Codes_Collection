//Reverse a Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=0,*temp;int count;
void add_node(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data = ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0){
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}
	count++;
}

void display_node(){
	printf("\n\n");struct node *current;
	current=head;
	while(current!=0){
		if(current->next!=0){
			printf("%d --> ",current->data);
		}
		else{
			printf("%d ",current->data);
		}
		current=current->next;
	}
}

void reverse_list(){
	struct node *prevnode=0,*currentnode,*nextnode;
	currentnode=nextnode=head;
	while(nextnode!=0){
		if(head==0){
			printf("The list is empty ");
		}
		else{
			nextnode=currentnode->next;
			currentnode->next=prevnode;
			prevnode=currentnode;
			currentnode=nextnode;
		}
	}
	temp=head;
	head=prevnode;
	printf("List reversed successfully "); 
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

