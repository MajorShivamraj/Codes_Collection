//Merge a linked list into another linked list at alternate positions..
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head1=0,*temp1,*head2=0,*temp2,*head3;
int choice, count1,count2;

void add_node(int a){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data = ");
	scanf("%d",& newnode->data);
	newnode->next=0;
	
// this a helps to add nodes in respective linked list at one go no 2 functions are required..
	if(a==1){
		if(head1==0){
			head1=temp1=newnode;
		}
		else{
			temp1->next=newnode;
			temp1=newnode;
		}
		count1++;
	}
	
	else if(a==2){
		if(head2==0){
			head2=temp2=newnode;
		}
		else{
			temp2->next=newnode;
			temp2=newnode;
		
		}
		count2++;
	}
	printf("\nNode added Successfully to linked list %d\n",a);
}

void display_nodes(int a){
	struct node *current;
	
//helped to display all the 3 linked list saperately..
	if(a==1){
		for(current=head1;current!=0;current=current->next){
			if(current->next==0){
				printf("%d",current->data);
			}
			else{
				printf("%d --> ",current->data);
			}
		}
		printf("\n");
	}
	else if(a==2){
		for(current=head2;current!=0;current=current->next){
			if(current->next==0){
				printf("%d",current->data);
			}
			else{
				printf("%d --> ",current->data);
			}
		}
		printf("\n");
	}
	else if(a==3){
		for(current=head3;current!=0;current=current->next){
			if(current->next==0){
				printf("%d",current->data);
			}
			else{
				printf("%d --> ",current->data);
			}
		}
		printf("\n");
	}
}

void merge_linked_list(){
	struct node *current1,*current2,*l1,*l2;
	current1=head3=head1;
	current2=head2;
	
/*here the code first check the count of both the linked list and on the basis of there count 
like >,=,< we have distinguished our approach , here the linked list are having both different
current1 and current2 and we have l1 and l2 and we just rearrange the next pointer of current1 
and current2
*/
	if(count1==count2){
		while(current1!=0){
			l1=current1->next;
			l2=current2->next;
			current1->next=current2;
			current2->next=l1;
			current1=l1;
			current2=l2;
		}
	}
	else if(count1>count2){
		while(current2!=0){
			l1=current1->next;
			l2=current2->next;
			current1->next=current2;
			current2->next=l1;
			current1=l1;
			current2=l2;
		}
	}
	else{
		while(current1->next!=0){
			l1=current1->next;
			l2=current2->next;
			current1->next=current2;
			current2->next=l1;
			current1=l1;
			current2=l2;
		}
		current1->next=current2;
	}
	printf("\nLinked lists merged Successfully.\n");
}

int main(){
	while(1){
		printf("\n\n----------------------------------\n\n");
		printf("1) Add Nodes for linked list 1\n");
		printf("2) Add Nodes for linked list 2\n");
		printf("3) Display linked lists \n");
		printf("4) Merge Linked List \n");
		printf("0) Exit \n\n Choice = ");
		scanf("%d",&choice);
		if(choice==1 || choice==2){
			add_node(choice);
		}
		else if(choice==3){
			printf("1) Display Linked List 1 \n");
			printf("2) Display Linked List 2 \n");
			printf("3) Display Merged Linked List \n\n choice = ");
			scanf("%d",&choice);
			display_nodes(choice);
		}
		else if(choice==4){
			merge_linked_list();
		}
		else if(choice==0){ 
			break;
		}	
	}
}
