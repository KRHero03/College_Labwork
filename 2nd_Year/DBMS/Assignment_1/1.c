#include <stdio.h>
int main(){
	printf("File Reading Program\nEnter File Name to Read:-");
	char* name = (char*) malloc(255 * sizeof(char));
	scanf("%[^\n]s",name);
	FILE *ptr = fopen(name,"r");
	if(ptr==NULL){
		printf("File Not Found!\n");
		return 0;
	}
	char c = fgetc(ptr);
	while(c!=EOF){
		printf("%c",c);
		c=fgetc(ptr);
	}
	fclose(ptr);
	
}
