#include <stdio.h>
struct task{
	int id;
	struct task* next;
	struct task* prev;
};
typedef struct task task;
task* cur;
int i=1;

void findCurrentTask(){
	printf("Current Task ID:- %d \n",cur->id);
}

void doTask(){
	task* temp=(task*)malloc(sizeof(task));
	temp->next=NULL;
	temp->prev=cur;
	temp->id = i;
	cur->next=temp;
	cur=cur->next;
	i++;
	printf("New Task Done!\n");
}

void undo(){
	if(cur->prev!=NULL){
		cur=cur->prev;
		printf("Undo action Done! \n");
	}else{
		printf("No previous task! \n");
	}
}

void redo(){
	if(cur->next!=NULL){
		cur=cur->next;
		printf("Redo action Done! \n");
	}else{
		printf("No next task! \n");
	}
}
void clearScreen(){
	system("CLS");
	printf("-----------------------------------------------\n");
	printf("         Assignment 6 - Question 5\n");
	printf("-----------------------------------------------\n");
	printf("1. Find Current Task\n");
	printf("2. Do Task\n");
	printf("3. Redo\n");
	printf("4. Undo\n");
	printf("5. Clear Screen\n");
	printf("6. Exit\n");
}

int main(){
	cur=(task*)malloc(sizeof(task));
	cur->next=NULL;
	cur->prev=NULL;
	cur->id=0;
	printf("-----------------------------------------------\n");
	printf("         Assignment 6 - Question 5\n");
	printf("-----------------------------------------------\n");
	printf("1. Find Current Task\n");
	printf("2. Do Task\n");
	printf("3. Redo\n");
	printf("4. Undo\n");
	printf("5. Clear Screen\n");
	printf("6. Exit\n");
	printf("Enter your choice:- ");
	int t;
	fflush(stdin);
	scanf("%d",&t);
	while(t!=6){
		switch(t){
			case 1:
				findCurrentTask();
				break;
			case 2:
				doTask();
				break;
			case 3:
				redo();
				break;
			case 4:
				undo();
				break;
			case 5:
				clearScreen();
				break;
		}			
		printf("\nEnter your choice:- ");
		fflush(stdin);
		scanf("%d",&t);
	}
}
