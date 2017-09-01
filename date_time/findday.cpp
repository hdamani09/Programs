#include<iostream>         //By H.D
#include<string>
using namespace std;

int main()
{
  int date=0,month=0,year=0,minyear=0,ly=0,result=0;
  string months[12]={"January  ","February ","March    ","April    ","May      ","June     ","July     ","August   ","September","October  ","November ","December "};
  string days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  int monthcode[12]={0,3,3,6,1,4,6,2,5,0,3,5};
  int yearcode[4]={6,4,2,0};
  cout<<"\nEnter the date: ";
  cin>>date;
  cout<<"\nMonth    "<<"\t|\t"<<"Month Number"<<endl;
  cout<<"------------------------------------"<<endl;
  for (int i=0;i<12;i++){
    cout<<months[i]<<"\t|\t"<<i+1<<endl;
  }
  cout<<"\nEnter the 'month number': ";
  cin>>month;
  cout<<"\nEnter the year: ";
  cin>>year;
  minyear= year%100;

  result= minyear + date + (minyear/4) + monthcode[month-1];
  if(year%400>=0 && year%400<100)
    result += yearcode[0];
  else if(year%400>=100 && year%400<200)
    result += yearcode[1];
  else if(year%400>=200 && year%400<300)
    result += yearcode[2];
  else if(year%400>=300 && year%400<400)
    result += yearcode[3];
  result= result%7;
  cout<<"\nThe day for: "<<date<<" "<<months[month-1]<<","<<year<<" was on a : "<<days[result]<<endl;

}
