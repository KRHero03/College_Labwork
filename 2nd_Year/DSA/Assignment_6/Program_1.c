#include <stdio.h>
#include <string.h>
struct node{
	char name[255];
	int rollNo;
	double cgpa;
	struct node* next;
	struct node* prev;
};

struct node* first;

void createLinkedList(){
	if(first->next==NULL){
		printf("------------------------------------------------\n");
		printf("        Creating Doubly Linked List\n");
		printf("------------------------------------------------\n");

		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		temp->prev=NULL;
		fflush(stdin);
		printf("Please enter Name:- ");
		scanf("%[^\n]s",temp->name);
		fflush(stdin);
		printf("Please enter Roll No.:- ");
		scanf("%d",&(temp->rollNo));
		fflush(stdin);
		printf("Please enter CGPA:- ");
		scanf("%lf",&(temp->cgpa));

		first->next = temp;

		printf("Doubly Linked List has been created! \n");

	}else{
		printf("Doubly Linked List has already been created!\n");
	}
}

void insertElement(){
	if(first->next!=NULL){
		printf("------------------------------------------------\n");
		printf("    Inserting Element in Doubly Linked List\n");
		printf("------------------------------------------------\n");
		int occ=0,pos=0;
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		temp->prev=NULL;
		fflush(stdin);
		printf("Please enter Name:- ");
		scanf("%[^\n]s",(temp->name));
		fflush(stdin);
		printf("Please enter Roll No.:- ");
		scanf("%d",&(temp->rollNo));
		fflush(stdin);
		printf("Please enter CGPA:- ");
		scanf("%lf",&(temp->cgpa));
		fflush(stdin);
		printf("Please enter Index for Insertion( 0 - First , -1 - Last):- ");
		scanf("%d",&occ);
		if(occ==0){
			(first->next)->prev = temp;
			temp->next = first->next;
			first->next = temp;
			printf("Record inserted at front!\n");
			return;
		}
		else if(occ==-1){
			struct node* cur=first;
			while(cur->next!=NULL){
				cur = cur->next;
			}
			temp->prev = cur;
			cur->next = temp;
			printf("Record inserted at last!\n");
			return;
		}else{
			pos = 0;
			struct node* cur=first;			
			while(cur->next!=NULL && pos!=occ){
				cur = cur->next;
				pos++;
			}
			if(pos==occ){
				temp->next = (cur->next);
				(cur->next)->prev=temp;
				temp->prev = cur;
				cur->next = temp;				
				printf("Record inserted at Index %d!\n",occ);
				return;
			}else{
				temp->prev = cur;
				cur->next = temp;
				printf("Record appended due to Index not found!\n");
				return;
			}
		}		
		

		printf("Element has been inserted in  Linked List! \n");

	}else{
		printf("Doubly Linked List has not been created!\n");
	}
}

void searchByRoll(){
	int roll=0,occ=0,pos=0;
    printf("Please enter Roll No. :- ");
    fflush(stdin);
    scanf("%d",&roll);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* cur=first;
	pos=0;
    while(cur->next!=NULL){
        if((cur->next)->rollNo==roll){
            temp=cur;  
			pos++; 
			if(pos==1){
				printf("Record Found:- \n");
        		printf("------------------------------------------------\n");
			}
			printf("Roll No.:- %d\n",(temp->next)->rollNo);
    		printf("Name:- %s \n",&((temp->next)->name));
    		printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
    		printf("------------------------------------------------\n");
			
			            
        }
        cur=cur->next;
    }
    if(pos==0){
    	printf("Record not Found!\n");
    	return;
	}
}

void searchByName(){
	int pos=0;
	char nameTemp[255];
	fflush(stdin);
	printf("Please enter Name:- ");
	scanf("%[^\n]s",nameTemp);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* cur=first;
	pos=0;
    while(cur->next!=NULL){
        if(strcmp((cur->next)->name,nameTemp)==0){
            temp=cur;  
			pos++; 
			if(pos==1){
				printf("Record Found:- \n");
        		printf("------------------------------------------------\n");
			}
			printf("Roll No.:- %d\n",(temp->next)->rollNo);
    		printf("Name:- %s \n",&((temp->next)->name));
    		printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
    		printf("------------------------------------------------\n");
			
			            
        }
        cur=cur->next;
    }
    if(pos==0){
    	printf("Record not Found!\n");
    	return;
	}
	
}

void searchByIndex(){
	int roll=0,occ=0,pos=0;
    printf("Please enter Index( 0 - First , -1 - Last):- ");
    fflush(stdin);
    scanf("%d",&occ);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* cur=first->next;
    
    if(occ==0){
    	printf("Record Found:- \n");
        printf("------------------------------------------------\n");
        printf("Roll No.:- %d\n",(first->next)->rollNo);
        printf("Name:- %s\n",&((first->next)->name));
        printf("CGPA:- %.2lf \n",(first->next)->cgpa);
        printf("------------------------------------------------\n");
	}
	else if(occ==-1){
    	pos=0;
    	temp=cur;
    	if((first->next) -> next ==NULL){
    		printf("Record Found:- \n");
	        printf("------------------------------------------------\n");
	        printf("Roll No.:- %d\n",(first->next)->rollNo);
	        printf("Name:- %s\n",&((first->next)->name));
	        printf("CGPA:- %.2lf \n",(first->next)->cgpa);
	        printf("------------------------------------------------\n");
		}
        while(cur->next!=NULL){
            temp=cur;  
			pos++;    
            cur=cur->next;
        }
        char y;
        if(pos==0){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
		}        
	}else{
		pos=0;
		temp = cur;
        while(cur->next!=NULL && pos!=occ){
            temp=cur;  
			pos++; 
            cur=cur->next;
        }
        char y;
        if(pos!=occ){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
		}
	}
}

void searchElement(){
	if(first->next==NULL){
		printf("Doubly Linked List has not been created!\n");
    }else{

		printf("------------------------------------------------\n");
		printf("  Searching Element in Doubly Linked List\n");
		printf("------------------------------------------------\n");
		printf("Search By:- \n1. Roll No.\n2. Name \n3.Index (0 - First, -1 - Last) \nPlease select your mode:- ");
		int type=0;
		fflush(stdin);
        scanf("%d",&type);
        switch(type){
            case 1:
                searchByRoll();
                break;
            case 2:
                searchByName();
                break;
            case 3:
                searchByIndex();
                break;
            default:
                printf("Invalid Search Type Selected!\n");
        }
    }
}

void deleteByRoll(){
    int roll=0,occ=0,pos=0;
    printf("Please enter Roll No. :- ");
    fflush(stdin);
    scanf("%d",&roll);
    printf("Please enter Occurence( 1 - First , -1 - Last):- ");
    fflush(stdin);
    scanf("%d",&occ);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* cur=first->next;
	if(occ==-1){
    	pos=0;
    	if((first->next)->rollNo==roll){
    		temp=first;
    		pos++;
		}
        while(cur->next!=NULL){
            if((cur->next)->rollNo==roll){
                temp=cur;  
				pos++;              
            }
            cur=cur->next;
        }
        char y;
        if(pos==0){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
			printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	temp->next=(temp->next)->next;        	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}        
	}else{
		pos=0;
    	if((first->next)->rollNo==roll){
    		temp=first;
    		pos++;
		}
        while(cur->next!=NULL && pos!=occ){
            if((cur->next)->rollNo==roll){
                temp=cur;  
				pos++; 
				            
            }
            cur=cur->next;
        }
        char y;
        if(pos!=occ){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
			printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	temp->next=(temp->next)->next;        	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}
	}

}

void deleteByName(){
	int occ=0,pos=0;
	char nameTemp[255];
	fflush(stdin);
	printf("Please enter Name:- ");
	scanf("%[^\n]s",nameTemp);
    printf("Please enter Occurence( 1 - First , -1 - Last):- ");
    fflush(stdin);
    scanf("%d",&occ);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* cur=first->next;
    
	if(occ==-1){
    	pos=0;
    	if(strcmp((first->next)->name,nameTemp)==0){
    		temp=first;
    		pos++;
		}
        while(cur->next!=NULL){
            if(strcmp((cur->next)->name,nameTemp)==0){
                temp=cur;  
				pos++;              
            }
            cur=cur->next;
        }
        char y;
        if(pos==0){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
			printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	temp->next=(temp->next)->next;        	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}        
	}else{
		pos=0;
    	if(strcmp((first->next)->name,nameTemp)==0){
    		temp=first;
    		pos++;
		}
        while(cur->next!=NULL && pos!=occ){
            if(strcmp((cur->next)->name,nameTemp)==0){
                temp=cur;  
				pos++; 
				            
            }
            cur=cur->next;
        }
        char y;
        if(pos!=occ){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
			printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	temp->next=(temp->next)->next;        	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}
	}
}

void deleteByIndex(){
	int roll=0,occ=0,pos=0;
    printf("Please enter Index( 0 - First , -1 - Last):- ");
    fflush(stdin);
    scanf("%d",&occ);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* cur=first->next;
    
    if(occ==0){
    	printf("Record Found:- \n");
        printf("------------------------------------------------\n");
        printf("Roll No.:- %d\n",(first->next)->rollNo);
        printf("Name:- %s\n",&((first->next)->name));
        printf("CGPA:- %.2lf \n",(first->next)->cgpa);
        printf("------------------------------------------------\n");
        char y;
        printf("Are you sure you want to delete it(Y/N)? :-");
        fflush(stdin);
        scanf("%c",&y);
        if(y=='y'||y=='Y'){
        	first->next=(first->next)->next;                	
            printf("Element Deleted! \n");
            return;
        }else{
        	
            printf("Deletion Aborted! \n");
            return;
		}
	}
	else if(occ==-1){
    	pos=0;
    	temp=cur;
    	if((first->next) -> next ==NULL){
    		printf("Record Found:- \n");
	        printf("------------------------------------------------\n");
	        printf("Roll No.:- %d\n",(first->next)->rollNo);
	        printf("Name:- %s\n",&((first->next)->name));
	        printf("CGPA:- %.2lf \n",(first->next)->cgpa);
	        printf("------------------------------------------------\n");
	        char y;
	        printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	first->next=(first->next)->next;                	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}
        while(cur->next!=NULL){
            temp=cur;  
			pos++;    
            cur=cur->next;
        }
        char y;
        if(pos==0){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
			printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	temp->next=(temp->next)->next;        	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}        
	}else{
		pos=0;
		temp = cur;
        while(cur->next!=NULL && pos!=occ){
            temp=cur;  
			pos++; 
            cur=cur->next;
        }
        char y;
        if(pos!=occ){
        	printf("Record not Found!\n");
        	return;
		}else{
			printf("Record Found:- \n");
            printf("------------------------------------------------\n");
            printf("Roll No.:- %d\n",(temp->next)->rollNo);
            printf("Name:- %s \n",&((temp->next)->name));
            printf("CGPA:- %.2lf \n",(temp->next)->cgpa);
            printf("------------------------------------------------\n");
			printf("Are you sure you want to delete it(Y/N)? :-");
	        fflush(stdin);
	        scanf("%c",&y);
	        if(y=='y'||y=='Y'){
	        	(temp->next)->prev = temp;
	        	temp->next=(temp->next)->next;        	
	            printf("Element Deleted! \n");
	            return;
	        }else{
	        	
	            printf("Deletion Aborted! \n");
	            return;
			}
		}
	}
}

void deleteElement(){
    if(first->next==NULL){
		printf("Doubly Linked List has not been created!\n");
    }else{

		printf("------------------------------------------------\n");
		printf("  Deleting Element in Doubly Linked List\n");
		printf("------------------------------------------------\n");
		printf("Delete By:- \n1. Roll No.\n2. Name \n3.Index (0 - First, -1 - Last) \nPlease select your mode:- ");
		int type=0;
		fflush(stdin);
        scanf("%d",&type);
        switch(type){
            case 1:
                deleteByRoll();
                break;
            case 2:
                deleteByName();
                break;
            case 3:
                deleteByIndex();
                break;
            default:
                printf("Invalid Delete Type Selected!\n");
        }
    }
}



void displayLinkedList(){
	if(first->next!=NULL){
		printf("------------------------------------------------\n");
		printf("        Displaying Doubly Linked List\n");
		printf("------------------------------------------------\n");
		struct node* cur=first->next;
		while(cur!=NULL){
			printf("Roll No.:- %d\n",cur->rollNo);
			printf("Name:- %s\n",&(cur->name));
			printf("CGPA:- %.2lf \n",cur->cgpa);
            printf("------------------------------------------------\n");
			cur=cur->next;
		}
	}else{
		printf("Doubly Linked List has not been created! \n");
	}
}

void deleteLinkedList(){	
	char y;
	printf("------------------------------------------------\n");
	printf("        Deleting Doubly Linked List\n");
	printf("------------------------------------------------\n");
	printf("Are  you sure you want to delete the  Linked List(Y/N)? :- ");
	fflush(stdin);
    scanf("%c",&y);
    if(y=='y'||y=='Y'){
    	first->next=NULL;
		        	
        printf("Doubly Linked List has been deleted! \n");
        return;
    }else{
    	
        printf("Deletion Aborted! \n");
        return;
	}
}

void reverseDLL(){
	if(first->next==NULL){
		printf("Doubly Linked List has not been created! \n");
	}else{
		struct node* cur=first->next;
		while(cur->next!=NULL){
			struct node* temp = cur->next;
			cur->next=cur->prev;
			cur->prev=temp;
			printf("%d \n",cur->rollNo);
			cur=temp;
		}
		cur->next=cur->prev;
		cur->prev=NULL;
		first->next=cur;
		printf("Doubly Linked List reversed!\n");
		
	}
}

void clearScreen(){
	system("cls");
	printf("------------------------------------------------\n");
	printf("     Doubly Linked List Program\n");
	printf("------------------------------------------------\n");
	printf("                     Menu\n");
	printf("1. Create Linked List\n");
	printf("2. Insert Element in Doubly Linked List\n");
	printf("3. Delete Element in Doubly Linked List\n");
	printf("4. Search Element in Doubly Linked List\n");
	printf("5. Display  Doubly Linked List\n");
	printf("6. Delete  Doubly Linked List\n");
	printf("7. Clear Screen\n");
	printf("8. Reverse Doubly Linked List\n");
	printf("9. Exit\n");
}

int main(){
	first = malloc(sizeof(struct node));
	first->next = NULL;
	first->prev = NULL;
	printf("------------------------------------------------\n");
	printf("     Doubly Linked List Program\n");
	printf("------------------------------------------------\n");
	printf("                     Menu\n");
	printf("1. Create Linked List\n");
	printf("2. Insert Element in Doubly Linked List\n");
	printf("3. Delete Element in Doubly Linked List\n");
	printf("4. Search Element in Doubly Linked List\n");
	printf("5. Display  Doubly Linked List\n");
	printf("6. Delete  Doubly Linked List\n");
	printf("7. Clear Screen\n");
	printf("8. Reverse Doubly Linked List\n");
	printf("9. Exit\n");

	int flag=1;
	printf("Please enter task:- ");
	fflush(stdin);
	scanf("%d",&flag);
	while(flag!=9){
		switch(flag){
			case 1:
				createLinkedList();
				break;
			case 2:
				insertElement();
				break;
			case 3:
				deleteElement();
				break;
			case 4:
				searchElement();
				break;
			case 5:
				displayLinkedList();
				break;
			case 6:
				deleteLinkedList();
				break;
			case 7:
				clearScreen();
				break;
			case 8:
				reverseDLL();
				break;

		}
		printf("Please enter task:- ");
		fflush(stdin);
		scanf("%d",&flag);

	}

}
