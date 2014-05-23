#include<iostream>
#include<stdlib.h>
#define MAX 50
int invct;

void Sort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main()
    {
    int merge[MAX],i,n;
    invct=0;
    std::cout<<"Enter the total number of elements: ";
    std::cin>>n;
    std::cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
         std::cin>>merge[i];
    partition(merge,0,n-1);
    std::cout<<"After merge sorting elements are: ";
    for(i=0;i<n;i++){
         std::cout<<merge[i]<<"  ";
    }
    std::cout<<"no of inverions: "<<invct;
    return 0;
}

void partition(int arr[],int low,int high){

    int mid,size;

    if(low<high){
         mid=(low+high)/2;
         size=high-low+1;
         if(size<=10)
         {Sort(arr,low,mid,high);return;}
         else
         {partition(arr,low,mid);
         partition(arr,mid+1,high);
         Sort(arr,low,mid,high);
         }
}
}

void Sort(int arr[],int low,int mid,int high)

    int i,m,k,size = high -low + 1;
    if(size<=10)
    {
        for(i=low+1;i<=high;i++)
        {
            k=i;
            while(arr[k]<arr[k-1] && k>low)
            {
                m=arr[k];
                arr[k]=arr[k-1];
                arr[k-1]=m;
                k--;
                invct++;

            }
        }
        }
    else
    {
    int *temp = (int*)malloc(sizeof(int)*size*1LL),l;    
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high))
     {
         if(arr[l]<=arr[m])
             {temp[i++]=arr[l++];}
         else{
             temp[i++]=arr[m++];
             invct+=m-i;
         }

     }

    if(l>mid){
         for(k=m;k<=high;k++)
             temp[i++]=arr[k];
    }
    else{
         for(k=l;k<=mid;k++)
             temp[i++]=arr[k];
    }

    for(k=low;k<=high;k++)
         arr[k]=temp[k];

}
}

