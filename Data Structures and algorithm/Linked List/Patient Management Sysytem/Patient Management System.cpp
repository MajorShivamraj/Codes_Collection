//Patient management system using linked list.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
struct node{
	int id,age,level;
	char name[50];
	bool visited;
	struct node *next;
};

struct node *head,*temp,*current;
int count=0;

//code to add a newnode....
void add_patient(){
	printf("\n--------------------------------------\n");
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Patient ID = ");
	scanf("%d",& newnode->id);
	printf("Enter Patient Name = ");
	scanf("%s",&newnode->name);
	printf("Enter Patient Age = ");
	scanf("%d",& newnode->age);
	
	newnode->visited=false;
	printf("Enter Patient Disease Level\n");
	printf("1) Low \n");
	printf("2) Medium \n");
	printf("3) High \n choice = ");
	scanf("%d",& newnode->level);
	if(newnode->level!=1 && newnode->level!=2 && newnode->level!=3 ){
		printf("Invalid Entry. \n");
	}
	else{
		newnode->next=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		count++;
		printf("\n\n Patient Added Successfully. \n");
	}	
}

//code to display Patient...
void display_patient(){
	printf("\n--------------------------------------\n");
	struct node *current;
	current=head;
	if(head==0){
		printf("No Patient Available.");
	}
	else{
		current=head;
		while(current!=0){
			printf("\n");
			printf("Patient ID = %d \n",current->id);
			printf("Patient Name = %s \n",current->name);
			printf("Patient Age = %d \n",current->age);
			printf("Patient Disease Level = %d \n",current->level);
			printf("%s",current->visited?"true":"false");
			current=current->next;
			printf("\n\n");
		}
	}
	printf("Patients Displayed Successfully.\n");
}

//code to search Patient...
void search_patient(){
	int id;
	printf("\n\n--------------------------------------\n");
	if(head==0){
		printf("No Patient Available.");
	}
	else{
		printf("Enter Patient ID = ");
		scanf("%d",&id);
		temp=head;
		while(temp->id!=id){
			temp=temp->next;
			if(temp==0){
				printf("Patient with ID %d not found",id);
				break;
			}
		}
		
		printf("\n");
		printf("Patient ID = %d \n",temp->id);
		printf("Patient Name = %s \n",temp->name);
		printf("Patient Age = %d \n",temp->age);
		printf("Patient Disease Level = %d \n",temp->level);
		printf("Patient Searched Successfully .\n");
	}	
}


void delete_from_begning(){
	temp=head;
	head=temp->next;
	free(temp);
}

void delete_from_end(){
	temp=head;
	struct node *pre;
	while(temp->next!=0){
		pre=temp;
		temp=temp->next;
	}
	pre->next=0;
	free(temp);
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

//code to delete Patient...
void delete_patient(){
	int id; int i=1;
	printf("\n--------------------------------------\n");
	if(head==0){
		printf("No Patient Available. ");
	}
	else{
		printf("Enter Patient ID = ");
		scanf("%d",&id);
		temp=head;
		
		while(temp->id!=id){
			temp=temp->next;
			i++;
		}
		if(i==1 && count==1){
			head=0;
			free(temp);
		}
		else{
			if(i==1){
				delete_from_begning();
			}
			else if(i==count){
				delete_from_end();
			}
			else if(i!=1 && i!=count){
				delete_from_position(i);
			}
		}
		count--;
		printf("Patient Deleted Successfully.\n");
	}	
}

//code to sort Patient...
void sort_patient(){
	int arr[count];//count is as per the number of nodes added increamented everytime when a new node is added.
	current=head;
	if(head==0){
		printf("No node in the list.\n");
	}
	//below prints just the data of single node, no need to traverse...
	else if(count==1){
		printf("\n");
		printf("Patient ID = %d \n",current->id);
		printf("Patient Name = %s \n",current->name);
		printf("Patient Age = %d \n",current->age);
		printf("Patient Disease Level = %d \n",current->level);
	}
	else{
		struct node *anewnode,*ahead=0,*atemp,*current;
		int i=0;
		while(current!=0){
			arr[i]=current->age;
			current=current->next;
			i++;
		}//converting linked list to array.
		
		//below is the code to sort the data 
		//1-4-2-3-6-5-8
		//1-2-3-4-5-6-8
		for(i=0;i<count;i++){
			for(int j=i+1;j<count;j++){
				if(arr[i]>arr[j]){
					int a=arr[i];
					arr[i]=arr[j];
					arr[j]=a;
				}
			} //this for loop is to check any smaller number then arr[i]..
			
			current=head;
			while(current!=0){
				//here the linked list is traversed to see the nodes that match the Patient data..
				
				//below line checks if the node is visited with a boolean value..
				if(current->visited==true){
					continue;
				}
				//if not visited then it checks for that node and copy in new linked list...
				else{
					if(current->age==arr[i]){
						struct node *anewnode;
						anewnode=(struct node *)malloc(sizeof(struct node));
						strcpy(anewnode->name,current->name);
						anewnode->id=current->id;
						anewnode->age=current->age;
						anewnode->level=current->level;
						anewnode->next=0;
						if(ahead==0){
							ahead=atemp=anewnode;
						}
						else{
							atemp->next=anewnode;
							atemp=anewnode;
						}
						current->visited=true;//here the code marks the node as visited true so that they dont visit the same node next time..
					}
					
				}
				current=current->next;
			}	
		}
		printf("Nodes Sorted Successfully.\n");
		
		//code to free the earlier linked list nodes space.
		temp=head;
		while(temp!=0){
			head=head->next;
			free(temp);
			temp=head;
			printf("Earlier node space free\n");
		}
		head=ahead;
		temp=atemp;
		//this is done to reinitialize the head and temp so that they can be again used to display the data and also add a newnode and again see the sorted Patients...
	}
	
}

int main(){
	struct node*head=0;
	int choice;
	while(1){
		printf("--------------------------------------\n");
		printf("1) Add Patient \n");
		printf("2) Display Patient \n");
		printf("3) Search Patient \n");
		printf("4) Delete Patient \n");
		printf("5) Sort Patient \n");
		printf("0) Exit \n\n choice = ");
		scanf("%d",&choice);
		
		if(choice==1){
			add_patient();
		}
		else if(choice==2){
			display_patient();
		}
		else if(choice==3){
			search_patient();
		}
		else if(choice==4){
			delete_patient();
		}
		else if(choice==5){
			sort_patient();
		}
		else if(choice==0){
			break;
		}
	}
}
