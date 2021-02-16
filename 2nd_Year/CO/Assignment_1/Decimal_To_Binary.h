long toBinary(long n){
	long p=0;
	long i=1;
	while(n>0){
		long r=n%2;
		p+=r*i;
		i*=10;
		n/=2;

	}
	return p;

}

