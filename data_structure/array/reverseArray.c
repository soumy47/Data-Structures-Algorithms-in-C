int main()
{
	//code
	int n;
	printf("\n How many Elements you want to Enter: ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
	    printf(" Enter Element [%d] - ", i);
	    scanf("%d",&a[i]);
	}
	    
	for(int i=0,j=n-1;i<j;i++,j--)
	{
	    int temp=a[i];
	    a[i]=a[j];
	    a[j]=temp;
	}
	printf("\n Revered array: ");
	for(int i=0;i<n;i++)
	{
	    printf("%d ",a[i]);
	}
	printf("\n");

	 return 0;
}
//Giving proper message to user is a Good Practice.
//Good Going Keep it up...
