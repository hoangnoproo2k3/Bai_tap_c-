#include<iostream>
using namespace std;
int main ()
{ int n;
cout << "nhap n: ";
cin >> n;
int s=0;
for(int i=1;i<n;i++)
{ if(n%i==0)
 { s+=i;}}
 if (s==n)
 { cout <<n<< " la so hoan thien";}
 else 
 { cout << n<< " khong phai so hoan thien ";}
 return 0;}
