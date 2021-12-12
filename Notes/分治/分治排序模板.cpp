#include <stdio.h>
 
void MergeSortedArr(int arr[], int begin , int mid , int end, int tmpArr[])
{
    int lBegin = begin; 
    int lEnd   = mid;   
    int rBegin = mid + 1;
    int rEnd   = end;
    int k = 0;  
    while( lBegin <= lEnd && rBegin <= rEnd) 
    {
        if(arr[lBegin] <= arr[rBegin])
        {
            tmpArr[k++] = arr[lBegin++];
        }else
        {
            tmpArr[k++] = arr[rBegin++];    
            //ÄæĞò¶ÔÔõÃ´Ğ´£¿£¿£¿£¿£¿ 
        }
            
     }
    while(lBegin <= lEnd)
     {
        tmpArr[k++] = arr[lBegin++];    
     }
       
    while(rBegin <= rEnd)
    {
        tmpArr[k++] = arr[rBegin++];    
    }
     
    for(int i = 0; i < k; i++)
    {
        arr[begin + i] = tmpArr[i]; 
    }
}
  
void MegerSort(int arr[], int begin , int end, int tmpArr[])
{
	if( begin < end)
 	{
  		int mid = (begin + end) /2;
    	MegerSort(arr, begin , mid , tmpArr) ; 
     	MegerSort(arr, mid + 1, end, tmpArr); 
      	MergeSortedArr(arr, begin , mid, end, tmpArr); 
     }
}
int a[200000];
int a_temp[200000];
int main()
{
    int n; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    MegerSort(a, 0, n - 1, a_temp);
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", *(a + i));
    }
    return 0;
}