#include <stdio.h>
#define MAX 255
struct Book{
	char bookName[255];
	int bookID;
	double bookPrice;
};

void push(struct Book* bookInstance,struct Book* bookArray,int* top){
	
	if(*top==MAX-1){
		printf("Stack Full!\n");
	}else{
		(*top)++;
		bookArray[*top]=*bookInstance;
		printf("Book has been added!\n");
	}

}

struct Book* pop(int* top,struct Book* bookArray){
	if(*top!=-1){
		struct Book* bookInstance=malloc(sizeof(struct Book));	
		*bookInstance=bookArray[*top];
		(*top)--;		
		printf("Deleted Top Most Book!\n");
		return bookInstance;
			
	}else{
		printf("Empty Stack!\n");
	}
}

void peep(int* top,struct Book* bookArray){
	if(*top!=-1)
		printf("Display Top Book\nBook Name:- %s\nBook ID:- %d\nBook Price:- %.3lf\n",(bookArray+*top)->bookName,(bookArray+*top)->bookID,(bookArray+*top)->bookPrice);
	else
		printf("Empty Stack!\n");

}

void getSize(int* top){
	printf("Total Books: %d \n",*top+1);				
}

int main(){
	printf("------------------------------------------\n");
	printf("Assignment 3 - Book Management using Stack\n");
	printf("------------------------------------------\n");
	printf("--------------------\n");
	printf("        Menu    \n");
	printf("1 - Add a Book\n");
	printf("2 - Display Top Book\n");
	printf("3 - Delete Top Book\n");	
	printf("4 - Total Books\n");	
	printf("5 - Exit\n");
	printf("--------------------\n");
	printf("Enter Task:- ");
	int i,top=-1;
	struct Book* bookArray=(struct Book* )malloc(MAX*sizeof(struct Book));
	scanf("%d",&i);
	fflush(stdin);
	while(i!=5){
		switch(i){
			case 1:
				
					printf("Add a Book\nPlease enter a Book's Name:- ");
					struct Book* bookInstance=(struct Book* )malloc(1*sizeof(struct Book));
					scanf(" %[^\n]s",bookInstance->bookName);					
					fflush(stdin);
					printf("Please enter Book ID:- ");
					scanf("%d",&(bookInstance->bookID));						
					fflush(stdin);			
					printf("Please enter Book Price:- ");
					scanf("%lf",&(bookInstance->bookPrice));					
					fflush(stdin);
					push(bookInstance,bookArray,&top);
				
				
				break;
			case 2:
				peep(&top,bookArray);
				break;
			
			case 3:
				printf("");
				struct Book* removedBook=pop(&top,bookArray);				
				break;
			case 4:				
				getSize(&top);
				break;
		}
		printf("Please enter a new task:- ");
		scanf("%d",&i);		
		fflush(stdin);
	}
}
