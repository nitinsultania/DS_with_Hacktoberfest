#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr, int l, int r, int item) 
{ 
 	int mid1,mid2;
    	if(r >= l)
     	{ 
       		 int mid1= (l + r)/3;
      		  mid2=2*((l+r)/3);
       		 if (item==*(arr+mid1))  
           		 return mid1; 
        		else if(item==*(arr+mid2)) 
        			    return mid2;
       		 else if (item<*(arr+mid1)) 
        			    return binarySearch(arr, l, mid1-1, item); 
      		 else if(item>(arr+mid1) && item<(arr+mid2))
           		   return binarySearch(arr, mid1+1,mid2-1,item); 
       		 else if(item>*(arr+mid2))
           		 return binarySearch(arr,mid2+1,r,item);
    	} 
	return -1;
} 
int main() 
{ 
    int *arr,n,item,i;
    printf("\nEnter the size of the array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements in sorted manner: ");
    for(i=0;i<n;i++)
     scanf("%d",arr+i);
    printf("Enter the item you want to search: ");
    scanf("%d",&item);
    int result = binarySearch(arr, 0, n - 1, item); 
    if(result==-1)
      printf("Element is not present in array.\n") ;
    else
      printf("Element is present at index %d and at position %d.\n",result,result+1); 
    return 0; 
 }
