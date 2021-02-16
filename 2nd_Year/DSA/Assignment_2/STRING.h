
long length(char* x)
{
	long i=0;
	while(x[i++]!='\0');
	return --i;
}

char* concat(char* x,char* y,long n)
{
	long i=length(x);
	long j=length(y);
	if(n<i+j+1)
	{
		printf("Insufficient Size! \n");
		return x;
	}
	
	long p;
	for(p=i;p<i+j;p++)
	{
		x[p]=y[p-i];
	}
	x[p]='\0';
	return x;
}

long findPos(char* x,char y)
{
	long i=length(x);
	long j=0;
	for(j=0;j<i;j++)
	{
		if(x[j]==y)
			return j;
	}
	return (long)-1;
}

long findPosRev(char* x,char y)
{
	long i=length(x);
	long j=0;
	for(j=i-1;j>=0;j--)
	{
		if(x[j]==y)
			return i-j-1;
	}
	return -1;
}

char* concatR(char* x,long n)
{
	long i=length(x);
	if(n<2*i+1)
	{
		printf("Insufficient Size! \n");
		return x;
	}
	long j=0;
	for(j=0;j<i;j++)
	{
		x[i+j]=x[i-j-1];
	}
	x[i+j]='\0';
	return x;
	
}

char* concatD(char* x,long n)
{
	long i=length(x);
	if(n<2*i+1)
	{
		printf("Insufficient Size! \n");
		return x;
	}
	long j=0;
	for(j=0;j<i;j++)
	{
		x[i+j]=x[j];
	}
	x[i+j]='\0';
	return x;
}

long compare(char* x,char* y)
{
	long i=length(x);
	long j=length(y);
	if(i!=j)
		return 0;
	for(i=0;i<j;i++)
	{
		if(x[i]!=y[i])
			return 0;
	}
	return 1;
}


long compareWC(char* x,char* y)
{
	long i=length(x);
	long j=length(y);
	if(i!=j)
		return 0;
	for(i=0;i<j;i++)
	{
		long p=x[i];
		long q=y[i];
		if(p>=97 && p<=122)
			p-=32;
		if(q>=97 && q<=122)
			q-=32;
		if(p!=q)
			return 0;
	}
	return 1;
}

char* rev(char* x)
{
	long i=length(x);
	long j=0;
	while(j<i-j)
	{
		char temp=x[j];
		x[j]=x[i-j-1];
		x[i-j-1]=temp;
		j++;
	}
	return x;
}

char* toUpperCase(char* x)
{
	long i=length(x);
	long j=0;
	for(j=0;j<i;j++)
	{
		long p=x[j];
		if(p>=97 && p<=122)
			p-=32;
		x[j]=(char)p;
	}
	return x;
}

char* toLowerCase(char* x)
{
	long i=length(x);
	long j=0;
	for(j=0;j<i;j++)
	{
		long p=x[j];
		if(p>=65 && p<=90)
			p+=32;
		x[j]=(char)p;
	}
	return x;
}

char* toTitleCase(char* x)
{
	long i=length(x);
	long j=0;
	for(j=0;j<i-1;j++)
	{
		if(j==0)
		{
			long p=x[j];
			if(p>=97 && p<=122)
				p-=32;
			x[j]=(char)p;
		}
		if(x[j]==' ' && x[j+1]>='a' && x[j+1]<='z'){
			long p=x[j+1];
			if(p>=97 && p<=122)
				p-=32;
			x[j+1]=(char)p;
		}
		
	}
	return x;
}
char* replace(char* x,char* y,long index)
{
	long i=length(x);
	long j=length(y);
	

	if(index+j>i ||index<0)
	{
		printf("Invalid Operation \n");
		return x;
	}
	long p=index;
	for(p=index;p<index+j;p++)
	{
		x[p]=y[p-index];
	}
	return x;
}

long getPosString(char* x,char* y)
{
	long i=length(x);
	long j=length(y);
	if(i<j ||j==0 || i==0)
		return -1;
	long p=0;
	for(p=0;p<i;p++)
	{
		if(x[p]==y[0])
		{
			
			long pass=1;
			long q=0;
			while(y[q]!='\0')
			{	
				if(p+q>=i)
				{
					return -1;
				}
				if(x[p+q]!=y[q])
				{
					pass=0;
					break;
				}
				q++;
			}
			if(pass==1)
			{	
				
				return p;
			}
		}
	}
	return -1;
}

long isPalindrome(char* x)
{
	long i=length(x);
	long j=0;
	while(j<i-j)
	{
		if(x[j]!=x[i-j-1])
			return 0;
		j++;
	}
	return 1;
}

long countVowels(char* x)
{
	long i=0,j=0;
	while(x[i]!='\0')
	{
		if(x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u' || x[i]=='A' || x[i]=='E' || x[i]=='I' || x[i]=='O' || x[i]=='U'){
	
		j++;
		printf("Vowel %ld %c\n",j,x[i]);
}
			
		i++;
	}
	return j;
}

long* countLW(char* x)
{
	long i=0,wordCount=0,pass=0,pass2=1;
	while(x[i+1]!='\0')
	{
		if(x[i]==' '&& x[i+1]!=' ')
		{
			wordCount++;
			pass=1;
		}
		if(x[i]==' ')
			pass2=0;
			
		i++;
			
	}
	long ans[2];
	ans[0]=i+1;
	if(pass==1 || pass2==1)
		wordCount++;
	ans[1]=wordCount;
	
	printf("%ld %ld \n",ans[0],ans[1]);
	return ans;
}
