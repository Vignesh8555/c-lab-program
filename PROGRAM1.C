#include<stdio.h>
#include<conio.h>
void swap(int*a ,int*b){
     int temp=*a;
     *a =*b;
     *b =temp;

}
int partition(int arr[],int low,int high)
{
  int pivot= arr[high];
  int i = (low -1);
  int j;
  for(j=low;j<=high-1;j++)
  {
     if(arr[j]<pivot){
	i++;
	swap(&arr[i],&arr[j]);
     }
  }
  swap(&arr[i+1],&arr[high]);
  return(i+1);
}

void quicksort(int arr[],int low,int high)
{
 if(low  < high){
    int pi =partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
   }
}
void printarray(int arr[], int size)
{
    int i;
    for(i=0;i<size;i++)
      printf("%d ",arr[i]);
    printf("\n");
}
void main()
{
  int n,i;
  int arr[100];
  clrscr();
  printf("enter the number of elements:");
  scanf("%d",&n);


  printf("enter the elements:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  quicksort(arr,0,n-1);
  printf("sorted array:");
  printarray(arr,n);
  getch();


  }