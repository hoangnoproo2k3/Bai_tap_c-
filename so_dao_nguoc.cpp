#include <iostream>
using namespace std;
#include<cmath>
int main()
{ int n;
  cout << "nhap n: ";
 cin >> n;
 int temp=n;
 int dem =0;
 //xem n c� bao nhi�u chu s�
   while (temp!=0)
   { 	temp/=10;
     dem++;}
     //t�ch c�c chu s� ra v� t�nh nguoc lai
     int x=0;
     temp=n;
     dem--;
     while(temp!=0)
     {
     	x=x+(temp%10)*pow(10,dem);
     	dem--;
     	temp=temp/10;}
 if(x==n)
 { cout<< n<< " la so dao nguoc";}
 else 
 { cout <<n<< "khong phai so dao nguoc";}
 return 0;
 }
