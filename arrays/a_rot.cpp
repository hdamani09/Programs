#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
  string a;
  int r,r2,i;
  cout<< "\nEnter a string to rotate: " ;
  cin>> a;
  cout<<"Entered string :"<<a;
  cout<< "\nEnter the rotation places: ";
  cin >> r;
  string b=a;
  r2 = r;
  if(((a.length()-(r%a.length()))%a.length())==0) // If a=ABCDEF and rotation is a multiple of length i.e 6 suppose r = 24
    cout<< "\nAfter rotating left/right "<<a<<endl;         // then (6-(24%6))%6 = 0, display the string as it is without rotation
  else{
    while(r--){
      char temp=a[0];                             //Store the first character of string A i.e 'A' in temp
      for(i=0;i<a.length()-1;i++)                 //Run loop to swap the remaining elements from the right to the left
        a[i]=a[i+1];                              //so the string ABCDEF changes to BCDEFF
      a[i]=temp;                                  //Replace the rightmost element with the temp value i.e A hence BCDEFA
    }
    cout<<"\nAfter rotating left: "<<a<<endl;
    while(r2--){
      char temp=b[b.length()-1];                 //Store the last character of string A i.e 'F' in temp
      for(i=b.length()-1;i>0;i--)                 //Run decreasing loop to swap the remaining elements from the left to the right
        b[i]=b[i-1];                              //so the string ABCDEF changes to AABCDE
      b[0]=temp;                                  //Replace the leftmost element with the temp value i.e F hence FABCDE
    }
    cout<<"\nAfter rotating right: "<<b<<endl;
  }
  getch();
}
