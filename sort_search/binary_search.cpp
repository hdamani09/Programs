#include<iostream>
#include<stdlib.h>
using namespace std;

void binsearch(int *,int,int,int,int);
void binsearch(int *arr,int key,int low,int high){
  while(low<=high){
    int mid = (low+high)/2;
    if(key==arr[mid]){
      cout<<key<<" found at position "<<mid+1;
      exit(0);
    }
    else if(key<arr[mid]){
      high=mid-1;
      binsearch(arr,key,low,high);
    }
    else{
      low=mid+1;
      binsearch(arr,key,mid+1,high);
    }
  }
  return;
}

int main()
{
  int arr1[15]={-34,-24,-5,-1,0,1,10,31,412,529,600,700,800,900,999};
  int key,i=0,length,low=0,option;
  cout<<"The elements of the list are: \n";
  length=sizeof(arr1)/sizeof(arr1[0]);
  for(i=0;i<length;i++){
    cout<<arr1[i]<<" ";
  }
  label1:
  cout<<"\n\nEnter the element to search in the list: ";
  cin>>key;
  binsearch(arr1,key,low,length-1);
  cout<<key<<" not found in the list\n\n";
  cout<<"Do you want to continue searching? Press 1 to continue ";
  cin>>option;
  if(option==1)
  goto label1;
  else
  exit(0);

}
