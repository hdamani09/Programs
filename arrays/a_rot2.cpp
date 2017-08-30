#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
  string a,b;
  int r, i;
  cout<< "\nEnter a string to rotate: " ;
  cin>> a;
  cout<<"Entered string :"<<a;
  cout<< "\nEnter the rotation places: ";
  cin >> r;
  int newIndex = r%a.length();
  if(((a.length()-newIndex)%a.length())==0)       // If a=ABCDEF and rotation is a multiple of length i.e 6 suppose r = 24
    cout<<a<<endl;                                // then (6-(24%6))%6 = 0, display the string as it is without rotation
  else{
    int temp= newIndex, start=0;
    for(i=0;i<a.length();i++){
      if(i<a.length()-newIndex){              // We will start appending the characters of the input string beginning from the
        b.append(1,a[temp++]);                //index position of newIndex to the starting position of the new string and after
      }                                       // that we will append the remaining characters that have been rotated in the else
      else{                                   // part to the end position
        b.append(1,a[start++]);
      }
    }
    cout<< "\nAfter rotating left:  "<<b;
    b.clear();
    cout<<endl;
    start=0;
    temp=a.length()-newIndex;
    for(i=0;i<a.length();i++){

      if(i<newIndex){                      //This is the almost same as rotating left but instead we are rotating right so we
        b.append(1,a[temp++]);             //first append the rotated characters from the end of the input string and then in
      }                                    // the else part we append the initial characters of the input string to the new string
      else{
        b.append(1,a[start++]);
      }
    }
    cout<< "\nAfter rotating right:  "<<b;


  }
  getch();
}
