#include <iostream>     //By H.D
#include<conio.h>
using namespace std;

int main()
{
  int a[8];
  int b[8];
  int p1,p2,p3,p4,p5,p6,p7;
  cout<< "Enter the 2X2 matrix elements for Mat A and Mat B: "<<endl;
  for(int i=0;i<8;i++)                      //Strassen's multiplication with time complexity of O(n2)
    cin>>a[i];
  p1=a[0]*(a[5]-a[7]);    
  p2=a[7]*(a[0]+a[1]);
  p3=a[4]*(a[2]+a[3]);
  p4=a[3]*(a[6]-a[4]);
  p5=(a[0]+a[3])*(a[4]+a[7]);
  p6=(a[1]-a[3])*(a[6]+a[7]);
  p7=(a[0]-a[2])*(a[4]+a[5]);
  cout<< "Strassen's multiplication :"<<endl;
  cout<< p6+p5+p4-p2 <<"\t\t"<<p1+p2<<endl;
  cout<< p3+p4<<"\t\t"<< p1+p5-p3-p7<<endl;
  getch();
}
