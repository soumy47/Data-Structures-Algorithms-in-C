    #include <stdio.h>  
    #include <string.h>  
    void toLowercase(char[]);  
    void sortArray(char[]);  
    int main ()  
    {  
        char str1[] = "Grab", str2[] = "Brag";  
        int i, j = 0;  
          
          
        if(strlen(str1) != strlen(str2)){  
            printf("Both the strings are not anagram");  
            return 0;  
        }  
        else {  
          
        toLowercase(str1);  
        toLowercase(str2);  
          
          
        sortArray(str1);  
        sortArray(str2);  
          
        for(i = 0; i < strlen(str1); i++){  
           if(str1[i] != str2[i]){  
               printf("Both the strings are not anagram");  
               return 0;  
           }   
        }     
        printf("Both the strings are anagram");  
        }  
        return 0;  
    }  
    void toLowercase(char a[]){  
                int i;  
                for(i = 0; i < strlen(a)-1; i++){  
                    a[i] = a[i]+32;  
                }      
            }  
     void sortArray(char a[]){  
                int temp = 0,i,j;  
                for(i = 0; i < strlen(a)-1; i++){  
                    for (j = i+1; j < strlen(a); j++){  
                    if(a[i] > a[j]) {  
                        temp = a[i];  
                        a[i] = a[j];  
                        a[j] = temp;         
                        }  
                    }  
                }     
            }  
