#include<stdio.h>
#include<string.h>
int main()
{  
    char arr[10] = "accba";
    char *left;
    left = arr;

    char *right; 
    right = arr+strlen(arr)-1; 
    
    

    while((left < right)&&(*left == *right))
    {
        left++;
        right--;
    }
    if(*left == *right)
        printf(" shi hui wen zi fu chuan\n");
    else
        printf(" bu shi hui wen zi fu chuan\n");
     
    return 0;
}
