#include <stdio.h>
long* getAnswer(long a[],long n){
    long ans[2];
    long maximum=a[0];
    long minimum=a[0];
    long i=0;
    for(i=0;i<n;i++){
        if(a[i]>maximum)
            maximum=a[i];
	if(a[i]<minimum)
            minimum=a[i];
    }
    ans[0]=maximum;    
    ans[1]=minimum;
    return ans;
}

int main(){
    long n;
    printf("Please enter the number of elements in Array:-");
    scanf("%ld",&n);
    if(n<=0){
        printf("Invalid Array Size\n");
    }else{
        long a[n];
        long i=0;
        printf("Please enter the elements in Array:-");
        for(i=0;i<n;i++){
            scanf("%ld",&a[i]);
        }
        long* ans= getAnswer(a,n);
        printf("Maximum Value:- %ld \nMinimum Value:- %ld \n",ans[0],ans[1]);       
    }        

}
