#include<iostream>        //By H.D
using namespace std;
int main()
{
  int size;
  cout<<"Enter the size of matrix: ";             //Take the size of the matrix
  cin>>size;
  cout<<"\nEnter the matrix elements to find its inverse: "<<endl;
  float a[25][25]={0};                            //For matrix upto size 25, initialize a 2X2 array
  int i=0,j=0;
  for(int i=0;i<size;i++)                         //Take the input for the matrix from the user
    for(int j=0;j<size;j++)
      cin >>a[i][j];
  cout<<"\nThe input matrix is: "<<endl;

  for(i=0;i<size;i++){                             //Displays the matrix
    for(j=0;j<size;j++)
      cout<<a[i][j]<<"\t";
    cout<<endl;
  }
  cout<<"\nThe transpose matrix is: "<<endl;
  for(i=0;i<size;i++){                             //Displays the transpose matrix by reversing the rows and columns that is variables
    for(j=0;j<size;j++)                           // i and j during cout display
      cout<<a[j][i]<<"\t";
    cout<<endl;
  }
}
