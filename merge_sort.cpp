#include<iostream>
#define MAX 50
void partition(int arr[],int min,int max);
void merge(int arr[],int min,int max,int mid);
int main()
{
    int A[MAX],n,i;
    std::cout<<"enter the no of elements:";
    std::cin>>n;
    std::cout<<"enter the elements:";
    for(i=0;i<n;i++)
        std::cin>>A[i];
    partition(A,0,n-1);
    std::cout<<"merge sorted array:  ";
    for(i=0;i<n;i++)
        std::cout<<A[i]<<"  ";
    return 0;
}
void partition(int arr[],int min,int max)
{
    int mid;
    if(min<max)
    {mid=(min+max)/2;
    partition(arr,min,mid);
    partition(arr,mid+1,max);
    merge(arr,min,max,mid);
    }
}
void merge(int arr[],int min,int max,int mid)
{
    int j,m,i,temp[MAX],k;
    j=min;
    m=mid+1;
    for(i=min;(j<=mid)&&(m<=max);i++)
    {
        if(arr[j]<arr[m])
        {
            temp[i]=arr[j];
            j++;
        }
        else
        {
            temp[i]=arr[m];
            m++;
        }
    }
    if(j>mid)
        {for(k=m;k<=max;k++)
        {temp[i]=arr[k];
         i++;
        }}
    else
        {for(k=j;j<=mid;k++)
        {temp[i]=arr[k];
         i++;
        }}
    for(k=min;k<=max;k++)
        arr[k]=temp[k];
}
