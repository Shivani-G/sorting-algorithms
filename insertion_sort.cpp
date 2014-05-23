#include<iostream>
int main()
{
int n,i,A[20],d,temp;
std::cout<<"enter the no of elements:";
std::cin>>n;
std::cout<<"enter the elements:";
for(i=0;i<n;i++)
std::cin>>A[i];
for(i=1;i<=n-1;i++)
{d=i;
while(d>0 && A[d]<A[d-1])
{
temp=A[d];
A[d]=A[d-1];
A[d-1]=temp;
d--;
}
}
std::cout<<"sorted array:/n";
for(i=0;i<n;i++)
std::cout<<A[i]<<" ";
}
