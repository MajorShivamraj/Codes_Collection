//Pairwise swap of a Linked list.
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

void swap_paired_nodes(){
	if(head==0 || head->next==0){
		printf("Not enough nodes to swap.");
	}
	else{
		struct node *c1=head,*c2,*l1;
		head=head->next;
		while(c1!=0 && c1->next!=0){
			
			c2=c1->next;
			l1=c2->next;
			c2->next=c1;
			c1->next=l1->next;
			c1=l1;
		}
		printf("Pairs of Numbers have swapped Successfully.");
	}
	
}

int main(){
	int choice;
	while(1){
		printf("--------------------------------------\n");
		printf("1) Add nodes \n");
		printf("2) Display nodes \n");
		printf("3) Swap nodes \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_node();
		}
		else if(choice==2){
			display_node();
		}
		else if(choice==3){
			swap_paired_nodes();
		}
		
		else if(choice==0){
			break;
		}
	}
}

