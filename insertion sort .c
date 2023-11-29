#include <stdio.h>
void insertionsort(int a[], int n)   
{  
    int i, j, temp;  
    for (i = 1; i < n; i++)
    {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])  
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    }  
}  

int main()
{
    int a[20],n,i;
    printf("\n how many elements you want to insert: ");
    scanf("%d",&n);
    printf("\n enter values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    printf("\n sorted array is : ");
    for(i=0; i<n; i++)
    {
        printf("\t %d ",a[i]);
    }
    return 0;
}

