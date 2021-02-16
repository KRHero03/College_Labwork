#include <stdio.h>
long* getAnswer(long a[],long n){
	long ans[2];
	long max1,max2,min1,min2;
	long i=0;
	if(a[0]>a[1]){
		max1=a[0];
		max2=a[1];
		min1=a[0];
		min2=a[1];
	}else{
		max1=a[1];
		max2=a[0];
		min1=a[1];
		min2=a[0];
	}	
	
	for(i=0;i<n;i++){
		if(a[i]>max1){
			max2=max1;
			max1=a[i];
		}else if(a[i] >max2 && a[i]<max1){
			max2=a[i];
		}
		if(a[i]<min1){
			min2=min1;
			min1=a[i];
		}else if(a[i] <min2 && a[i]>min1){
			min2=a[i];
		}
	}
	ans[0]=max2;
	ans[1]=min2;
	return ans;
}

int main(){
    long n;
    printf("Please enter the number of elements in Array:-");
    scanf("%ld",&n);
    if(n<=1){
        printf("Invalid Array Size for getting second Maximum or Minimum value!\n");
    }else{
        long a[n];
        long i=0;
        printf("Please enter the elements in Array:-");
        for(i=0;i<n;i++){
            scanf("%ld",&a[i]);
        }
        long* ans=getAnswer(a,n);
        printf("Second Maximum Value:- %ld \nSecond Minimum Value:- %ld\n",ans[0],ans[1]);       
    }        

}
