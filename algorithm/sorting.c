#include<stdio.h>

int main(){

   int count, temp, i, j, number[30];

   printf("Enter total numbers: ");
   scanf("%d",&count);

   printf("Enter the numbers to be sorted: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);

   
   for(i=0;i<=count-1;i++){
      for(j=0;j<count-i-1;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
