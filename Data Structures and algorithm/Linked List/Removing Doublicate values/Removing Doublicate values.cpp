//Remove duplicate elements from sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=0,*temp,*current;
int count;
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


void sort_node(){
	current=head;int arr[count];
	if(head==0){
		printf("No node in the list.\n");
	}
	else if(count==1){
		printf("%d",current->data);
	}
	else{
		struct node *anewnode, *ahead=0, *atemp;
		int i=0,j;
		while(current!=0){
			arr[i]=current->data;
			current=current->next;
			i++;
		}//linked list to array.
		
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(arr[i]>arr[j]){
					int a=arr[i];
					arr[i]=arr[j];
					arr[j]=a;
				}
			}
			anewnode=(struct node *)malloc(sizeof(struct node));
			anewnode->data=arr[i];
			anewnode->next=0;
			if(ahead==0){
				atemp=ahead=anewnode;
			}
			else{
				atemp->next=anewnode;
				atemp=anewnode;
			}
		}
		printf("Nodes Sorted Successfully.\n\n");
		//code for freeing the space of earlier linked list..
		//1-4-2-3-6-5-8
		//1-2-3-4-5-6-8
		temp=head;
		while(temp!=0){
			head=head->next;
			free(temp);
			temp=head;
			printf("Earlier node space free\n");
		}
		head=ahead;
		temp=atemp;
	}
}

void delete_from_position(int i){
	int j=1; struct node *pre;
	temp=head;
	while(j<i){
		pre=temp;
		temp=temp->next;
		j++;
	}
	pre->next=temp->next;
	free(temp);
}


void remove_duplicate(){
	//1-2-3-3-2-4
	//1-2-3-4    
	current=head;struct node *node;
	while(current!=0 && current->next!=0){
		if(current->data==current->next->data){
			node=current->next;
			current->next=node->next;	
			free(node);
			count--;
		}
		else{
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
		printf("3) Sort nodes \n");
		printf("4) Remove Duplicate nodes \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_node();
		}
		else if(choice==2){
			display_node();
		}
		else if(choice==3){
			sort_node();
		}
		else if(choice==4){
			remove_duplicate();
		}
		else if(choice==0){
			break;
		}
	}	
}
