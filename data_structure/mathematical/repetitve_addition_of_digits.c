#include<stdio.h>
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    long long int n;
	    scanf("%lld",&n);
	    
	    if(n==0)
	    {
	        printf("0\n");
	    }
	    else{
	        
	        if(n%9 == 0)
	        {
	            printf("9\n");
	        }
	        else {
	            printf("%d\n",(n%9));
	        }
	        
	        
	        
	    }
	    
	}
	return 0;
}
