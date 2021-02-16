long pow(long m,long n){
	long ans=1;
	long i=0;
	for(i=0;i<n;i++){
		ans*=m;
	}
	return ans;

}

long toDecimal(long n){
	long p=0,i=0;
	while(n>0){
		long r=n%10;
		if(r==1 || r==0){
			p+=r*pow(2,i);
			i++;
			n/=10;
		}else{
			
			return -1;
		}
		

	}
	return p;

}
