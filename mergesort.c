#include<stdio.h>
void mergesort(int a[],int start,int end);
void merge(int a[],int start,int mid,int end);
int main()
{
    int a[20],i,n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    printf("Enter the element of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("sorted array:\n");
    for(i=0;i<n;i++){
        printf(" %d",a[i]);
    }
    return 0;
}
void mergesort(int a[],int start,int end){
    int mid;
    if(start<end){
        mid=(start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
void merge(int a[],int start,int mid,int end){
    int b[20];
    int i,j,k;
    i=start;
    j=mid+1;
    k=start;
    while(i>=start&&j<=end){
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
   if(i>mid){
       while(j<=end){
           b[k]=a[j];
           j++;
           k++;
           
       }
       }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }   
   for(i=start;i<=end;i++){
       a[i]=b[i];
   }
}

