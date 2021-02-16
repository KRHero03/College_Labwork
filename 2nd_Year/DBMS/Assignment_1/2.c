#include <stdio.h>
int main(){
	printf("File Reading Program\nEnter File Name to write:-");
	char* name = (char*) malloc(255 * sizeof(char)); //char name[255] 
	scanf("%[^\n]s",name);
	FILE *ptr = fopen(name,"w");
	if(ptr==NULL){
		printf("File Not Found!\n");
		return 0;
	}
	printf("Enter data(Press TAB to end):-\n");
	fflush(stdin);
	char* data = (char*) malloc(10000* sizeof(char));
	scanf("%[^\t]s",data);
	fprintf(ptr,"%s",data);
	printf("Data has been copied to designated File %s! \n",name);
	fclose(ptr);
}
