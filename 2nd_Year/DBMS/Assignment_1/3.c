#include <stdio.h>
int main(){
	printf("File Reading Program\nEnter File Name to Read:-");
	char* input = (char*) malloc(255 * sizeof(char)); //char name[255] 
	scanf("%[^\n]s",input);	
	fflush(stdin);
	printf("Enter File Name where %s's data is to be copied:-",input);
	char* output = (char*) malloc(255 * sizeof(char)); //char name[255] 
	scanf("%[^\n]s",output);
	FILE *iptr = fopen(input,"r");
	FILE *optr = fopen(output,"w");	
	char c = fgetc(iptr);
	while(c!=EOF){
		fprintf(optr,"%c",c);
		c=fgetc(iptr);
	}
	printf("Data has been copied from %s to %s!\n",input,output);
	fclose(iptr);
	fclose(optr);
}
