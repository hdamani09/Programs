#include<iostream>        //By H.D
using namespace std;
int main()
{
  int size;
  cout<<"Enter the size of matrix: ";             //Take the size of the matrix
  cin>>size;
  cout<<"\nEnter the matrix elements to find its inverse: "<<endl;
  float a[25][25]={0};                            //For matrix upto size 25, initialize a 2X2 array and set Determinant to 0
  float deter=0;
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
  if(size==1)                                     //Calculate the determinant for different matrix sizes, generally for matrix 1X1 and 2X2
    deter=a[0][0];                                //we find the determinant in different ways than in 3X3 and above
  else if(size==2){
    for(i=0;i<size;i++)
      deter = (a[0][0]*a[1][1]) - (a[0][1]*a[1][0]);
  }
  else{
    for(i=0;i<size;i++){
      deter +=(a[0][i]*((a[1][(i+1)%3]*a[2][(i+2)%3]) - (a[1][(i+2)%3]*a[2][(i+1)%3])));
    }
  }
  cout<<"Determinant :"<<endl;
  cout<<deter<<endl;
  if(deter==0)                                    //If determinant is equal to 0 we can't find its inverse since, divide by zero error
    cout<<"Inverse can't be calculated"<<endl;
  else{
    cout<<"Inverse of the matrix:"<<endl;
    if(size==1)
      cout<<1/deter<<endl;                      //Else for different sizes, calculate the respective inverse by their respective
    else if(size==2){                           // formulas. For size 1: Just take the reciprocal of determinant, For Size 2: [{a b},{c d}] is
      cout.precision(2);                    // changed to [{d -b}{-c a}] and for the rest Sizes: Use Adjoint of matrix/determinant
      cout<<a[1][1]/deter<<"\t"<<-a[0][1]/deter<<endl;
      cout<<-a[1][0]/deter<<"\t"<<a[0][0]/deter<<endl;
    }
    else{
      for(i=0;i<size;i++){                      //Make use of .precision with cout before using cout to display the matrix to the precision level
        for(j=0;j<size;j++){
          cout.precision(2);
          cout << ((((a[(i+1)%3][(j+1)%3])*(a[(i+2)%3][(j+2)%3])) - ((a[(i+1)%3][(j+2)%3])*(a[(i+2)%3][(j+1)%3])))/deter) <<"\t";
        }
      cout<<endl;
      }
    }
  }
}
