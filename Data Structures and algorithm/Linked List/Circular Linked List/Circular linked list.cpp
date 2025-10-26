#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*temp;
void add_node(){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data = ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0){
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
		temp->next=head;
	}
	
	
}

void display_list(){
	struct node *current;int rounds=-1;
	current=head;
	while(current!=0){
		if(rounds==2){
			break;
		}
		else{
			if(current==head){
				rounds++;
				
			}
			printf("%d --> ",current->data);
			current=current->next;
		}
	}
}

int main(){
	int choice;
	while(1){
		printf("\n\n--------------------------------------\n");
		printf("1) Add nodes \n");
		printf("2) Display nodes \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_node();
		}
		else if(choice==2){
			display_list();
		}
		
		else if(choice==0){
			break;
		}
	}
}
