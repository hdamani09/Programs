#include<iostream>         //By H.D
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

int main()
{
  int date=0,month=0,year=0,ly=0,result=0;
  string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
  string days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  int monthcode[12]={0,3,3,6,1,4,6,2,5,0,3,5};
  int yearcode[4]={6,4,2,0};
  cout<<"\nEnter the date in the format (dd/mm/yy) :\n";
  scanf("%d/%d/%d",&date,&month,&year);
  if((date>0&&date<=31) && (month>0&&month<=12)){
    result= ((year%100) + date + ((year%100)/4) + monthcode[month-1] - ((year%100)/100) + ((year%100)/400))%7;
    cout<<"\nThe day for: "<<date<<" "<<months[month-1]<<" , "<<year<<" was on a : "<<days[result]<<endl;
  }
  else{
    cout<<"Error in date format";
    exit(-1);
  }
}
