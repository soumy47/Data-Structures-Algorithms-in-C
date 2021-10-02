#include<stdio.h>
#include<string.h>
 
int i,j,m,n,c[20][20];
char x[20],y[20];
 
int lcs()
{
        m=strlen(x);
        n=strlen(y);
        for(i=0;i<=m;i++)
                        c[i][0]=0;
        for(i=0;i<=n;i++)
                        c[0][i]=0;
                                        
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                if(x[i-1]==y[j-1])
                	c[i][j]=c[i-1][j-1]+1;
                    
                else if(c[i-1][j]>=c[i][j-1])
                	c[i][j]=c[i-1][j];
                    
                else
                	c[i][j]=c[i][j-1];
                   
            }
        return c[m][n];
              
}
int main()
{
                printf("Enter 1st sequence:");
                scanf("%s",x);
                printf("Enter 2nd sequence:");
                scanf("%s",y);
                m=strlen(x);
                n=strlen(y);
                printf("\nThe Longest Common Subsequence is: %d ",lcs());
              
return 0;
}
