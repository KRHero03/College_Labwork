#include <stdio.h>
int main(){
		char* input = (char*) malloc(255 * sizeof(char)); 
	int id = 0,num;
	printf("File Reading Program\nEnter File Name to Read:-");//char name[255] 
	scanf("%[^\n]s",input);	
	fflush(stdin);	
	printf("Enter Record ID to be deleted:-");
	scanf("%d",&id);
	FILE *iptr = fopen(input,"r");
	if(iptr==NULL){
		printf("The file does not exist!\n");
		return 0;
	}
	int pass=1;
	while (!feof (iptr)){  
    	num = 0;
      	fscanf (iptr, "%d", &num);  
      	if(num==id){
      		pass=0;
      		break;
	  	}
    }
	fclose(iptr);
	if(pass==1){
		printf("Record was not found!\n");
	}else{
		printf("Record has been found!\n");
	}
	
	return 0;
}
