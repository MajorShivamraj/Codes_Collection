//Nth node from end of linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*temp,*current;
int count=0;
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
	printf("\n\n");
}

void nth_node(int x){
	int pos,i=1;
	pos=(count-x);
	current=head;
	if(head==0){
		printf("The list is empty ");
	}
	else if(pos<0){
		printf("The position is not valid from end ");
	}
	else{
		while(i<pos+1){
		 	current=current->next;
		 	i++;
		}
		printf("The %d element from end is %d \n\n",x,current->data);
	}
}

int main(){
	int choice;
	while(1){
		printf("--------------------------------------\n");
		printf("1) Add nodes \n");
		printf("2) Display nodes \n");
		printf("3) Nth Element from end \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_node();
		}
		else if(choice==2){
			display_node();
		}
		else if(choice==3){
			int x;
			printf("Enter the nth element from end = ");
			scanf("%d",&x);
			nth_node(x);
		}
		
		else if(choice==0){
			break;
		}
	}
}



