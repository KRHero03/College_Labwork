#include <stdio.h>
#include <string.h>
int main(){
	
	char* input = (char*) malloc(255 * sizeof(char)); 
	int id = 0,num;
	printf("File Reading Program\nEnter File Name to Read:-");//char name[255] 
	scanf("%[^\n]s",input);	
	fflush(stdin);	
	printf("Enter Record ID to be deleted:-");
	scanf("%d",&id);
	FILE *iptr = fopen(input,"r");
	FILE *tptr = fopen("t.temp","w");
	if(iptr==NULL){
		printf("The file does not exist!\n");
		return 0;
	}
	while (!feof (iptr)){  
    	num = 0;
      	fscanf (iptr, "%d", &num);  
      	if(num!=id && num!=0){
      		fprintf(tptr,"%d\n",num);
	  	}
    }
	fclose(iptr);
	fclose(tptr);	
	remove(input);
	rename("t.temp",input);
	printf("Process Complete! \n",id,input);
	return 0;
}
