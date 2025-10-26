//Print the Middle of a given linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=0,*temp,*current;
int count=0;

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

void middle_value(){
	current=head;
	int i=1;
	if(count%2!=0){
		int a=(count/2)+1;
		while(i<a){
			current=current->next;
			i++;			
		}
		printf("\n\nThe Middle element is %d",current->data);
	}
	else if(count%2==0){
		int a=(count/2);
		int b=a+1;
		while(i<a){
			current=current->next;
			i++;
		}
		printf("\n\nThe count was even so has 2 Middle element that are %d and %d",current->data,current->next->data);
	}
}

int main(){
	int choice;
	while(1){
		printf("--------------------------------------\n");
		printf("1) Add nodes \n");
		printf("2) Display nodes \n");
		printf("3) Middle element \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_node();
		}
		else if(choice==2){
			display_node();
		}
		else if(choice==3){
			middle_value();
		}
		
		else if(choice==0){
			break;
		}
	}
	
	
}
