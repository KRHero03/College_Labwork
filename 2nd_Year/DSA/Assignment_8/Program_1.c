#include <stdio.h>

#include <stdio.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* n;

n root;

void insertElement(n node,int d){
	int val=node->data;
	if(d>val){
		if(node->right==NULL){
			n temp=(n)malloc(sizeof(struct node));
			temp->left=NULL;
			temp->right=NULL;
			temp->data=d;
			node->right=temp;
			printf("%d inserted in Binary Search Tree! \n",d);
			return;
		}else{
			insertElement(node->right,d);
		}
	}else if(d<val){
		if(node->left==NULL){
			n temp=(n)malloc(sizeof(struct node));
			temp->left=NULL;
			temp->right=NULL;
			temp->data=d;
			node->left=temp;
			printf("%d inserted in Binary Search Tree! \n",d);
			return;
		}else{
			insertElement(node->left,d);
		}
	}else{
		printf("%d is already present in the Binary Search Tree! \n",d);
		return;
	}
	
}

void createBST(){
	if(root==NULL){
		printf("Please enter data(-1 to stop):- ");
		int d;
		fflush(stdin);
		scanf("%d",&d);
		while(d!=-1){
			if(root==NULL){
				root=(n)malloc(sizeof(struct node));
				root->left=NULL;
				root->right=NULL;
				root->data=d;
				printf("%d inserted in Binary Search Tree! \n",d);
			}else{
				insertElement(root,d);
			}			
			fflush(stdin);
			scanf("%d",&d);
		}
	}else{
		printf("Binary Search Tree has already been created! \n\n");
	}
}

void searchElementUtil(n node,int d){
	if(node==NULL){
		printf("%d is not present in Binary Search Tree!");
		return;
	}
	int val=node->data;
	if(val==d){
		printf("%d has been found in Binary Search Tree!");
		return;
	}else if(d<val){
		searchElementUtil(node->left,d);		
	}else{		
		searchElementUtil(node->right,d);
	}
	
}

void searchElement(){
	if(root==NULL){
		printf("Binary Search Tree has not been created! \n");
		return;
	}
	printf("Please enter the element that you need to find:- ");
	int t;
	fflush(stdin);
	scanf("%d",&t);
	searchElementUtil(root,t);
}

void preOrderTraversal(n node){
	if(root==NULL){
		printf("Binary Search Tree has not been created! \n");
		return;
	}
	
	if(node==NULL){
		return;
	}
	printf("%d ",node->data);
	preOrderTraversal(node->left);
	preOrderTraversal(node->right);
	
}

void inOrderTraversal(n node){
	if(root==NULL){
		printf("Binary Search Tree has not been created! \n");
		return;
	}
	
	if(node==NULL){
		return;
	}
	inOrderTraversal(node->left);
	printf("%d ",node->data);
	inOrderTraversal(node->right);
	
}

void postOrderTraversal(n node){
	if(root==NULL){
		printf("Binary Search Tree has not been created! \n");
		return;
	}
	
	if(node==NULL){
		return;
	}
	postOrderTraversal(node->left);
	postOrderTraversal(node->right);
	printf("%d ",node->data);
	
}

void findTreeHeight(n node,int i,int *d){
	if(root==NULL){
		printf("Binary Search Tree has not been created! \n");
		return;
	}
	if(node==NULL){
		if((*d)<i){
			*d = i;
		}
		return;
	}
	findTreeHeight(node->left,i+1,d);	
	findTreeHeight(node->right,i+1,d);
}

void clearScreen(){
	system("CLS");
	printf("-------------------------------------------\n");
	printf("       Binary Search Tree Program          \n");
	printf("-------------------------------------------\n");
	printf("				Menu					   \n");
	printf("1. Create Binary Tree\n");
	printf("2. Search Element\n");
	printf("3. Preorder Traversal\n");
	printf("4. Inorder Traversal\n");
	printf("5. Postorder Traversal\n");
	printf("6. Find Tree Height\n");
	printf("7. Clear Screen\n");
	printf("8. Exit\n");
}

int main(){
	root = NULL;
	printf("-------------------------------------------\n");
	printf("       Binary Search Tree Program          \n");
	printf("-------------------------------------------\n");
	printf("				Menu					   \n");
	printf("1. Create Binary Tree\n");
	printf("2. Search Element\n");
	printf("3. Preorder Traversal\n");
	printf("4. Inorder Traversal\n");
	printf("5. Postorder Traversal\n");
	printf("6. Find Tree Height\n");
	printf("7. Clear Screen\n");
	printf("8. Exit\n");
	printf("Select your task:- ");
	int t;
	fflush(stdin);
	scanf("%d",&t);
	while(t!=8){
		switch(t){
			case 1:
				printf("-------------------------------------------\n");
				printf("       Creating Binary Search Tree          \n");
				printf("-------------------------------------------\n");
				createBST();
				break;
			case 2:
				printf("-------------------------------------------\n");
				printf("  Searching Element in Binary Search Tree          \n");
				printf("-------------------------------------------\n");
				searchElement();
				printf("\n\n");
				break;
			case 3:
				printf("-------------------------------------------\n");
				printf("             Pre Order Traversal          \n");
				printf("-------------------------------------------\n");
				printf("\n");
				preOrderTraversal(root);
				printf("\n\n");
				break;
			case 4:
				printf("-------------------------------------------\n");
				printf("              In Order Traversal          \n");
				printf("-------------------------------------------\n");
				printf("\n");
				inOrderTraversal(root);
				printf("\n\n");
				
				break;
			case 5:
				printf("-------------------------------------------\n");
				printf("            Post Order Traversal          \n");
				printf("-------------------------------------------\n");
				printf("\n");
				postOrderTraversal(root);
				printf("\n\n");
				break;
			case 6:
				printf("\n");
				int d=0;
				findTreeHeight(root,0,&d);
				printf("Height of Binary Search Tree:- %d \n\n",d);
				break;
			case 7:
				clearScreen();
				break;
		}		
		printf("Select your task:- ");
		fflush(stdin);
		scanf("%d",&t);
	}
}
