/*vi?t c�c ch??ng tr�nh con th?c hi?n c�c c�ng vi?c sau:
o	nh?p 1 danh s�ch n (0<n<100) th� sinh tham d? v�ng s? lo?i ch??ng tr�nh vietnam idol g?m c�c th�ng tin: (s? b�o danh, h? t�n, gi?i t�nh, t�n ti?t m?c d? thi, k?t qu? (??t/kh�ng ??t c� th? k� hi?u l� 'd' v� 'kd')
o	hi?n danh s�ch th� sinh ra m�n h�nh v?i ??y ?? c�c th�ng tin (s? b�o danh, h? t�n, gi?i t�nh, t�n ti?t m?c, k?t qu?)
o	t�m danh s�ch c�c ti?t m?c tr�ng t�n v� hi?n th�ng tin c�c ti?t m?c ra m�n h�nh (v?i ??y ?? c�c th�ng tin: s? b�o danh, h? t�n, gi?i t�nh, t�n ti?t m?c d? thi)
o	ghi v�o t?p "ketqua.dat" (d??i d?ng nh? ph�n) danh s�ch c�c th� sinh ??t v�ng d? thi.
o	s?p x?p danh s�ch th� sinh c� t�n c?a th� sinh theo th? t? alphabet (a-z)
Vi?t ch??ng tr�nh ch�nh ?? g?i c�c ch??ng tr�nh con tr�n theo tr?t t? ???c vi?t nh? tr�n. N?u c� th? t? ch?c ch??ng tr�nh th�ng qua menu th� s? l� m?t ?i?m c?ng.*/
#include<iostream>
#include<string.h>
#include <stdio.h>
#include<fstream>
#include<iomanip>
using namespace std;

struct thisinh 
{
	int sbd;
	char hoten[50];
	char gt[20];
	char tentm[50];
	char kq[10];	
};
void nhap( thisinh &ts)
{
	cout<<"nhap vao so bao danh: ";
	cin>>ts.sbd;
	fflush(stdin);
	cout<<"nhap vao ho ten: ";
	gets( ts.hoten);
	cout<<"nhap vao gioi tinh: ";
	gets(ts.gt);
	cout<<"nhap vao ten tiet muc du thi: ";
	gets(ts.tentm);
	cout<<"nhap vao ket qua: ";
	gets(ts.kq);
	
}
void xuat(thisinh ts)
{ cout<<setw(5)<<" "<<"HOTEN"<<setw(10)<<" "<<"GT"<<setw(5)<<" "<<"TIETMUC"<<setw(15)<<" "<<"KQ"<<endl;
	cout<<setw(5)<<" "<<ts.hoten<<setw(10)<<" "<<ts.gt<<setw(5)<<" "<<ts.tentm<<setw(15)<<" "<<ts.kq<<endl;
}
void nhapdsts( thisinh ds[], int &n)
{
	for( int i=0;i<n;i++)
	{cout<<"Nhap vao thi sinh thu "<<i<<endl;
	nhap(ds[i]);
	}
}
void xuatdsts( thisinh ds[], int n)
{ cout<<setw(5)<<"STT"<<setw(5)<<" "<<"HOTEN"<<setw(10)<<" "<<"GT"<<setw(5)<<" "<<"TIETMUC"<<setw(15)<<" "<<"KQ"<<endl;
 	for( int i=0; i<n;i++)
	{
		cout<<setw(5)<<i+1<<setw(5)<<" "<<ds[i].hoten<<setw(10)<<" "<<ds[i].gt<<setw(5)<<" "<<ds[i].tentm<<setw(15)<<" "<<ds[i].kq<<endl;
	}
}
void trungten( thisinh ds[], int n)
{
	for( int i=0;i<n;i++)
	{for( int j=i+1;j<n;j++)
	{
		if( strcmp(ds[i].tentm,ds[j].tentm)==0)
		{ xuat(ds[i]);
		xuat(ds[j]);
		}
	}
	}
}
void luufile(thisinh ds[], int n)
{
	ofstream f;
	f.open("ketqua.dat",ios::out|ios::binary);
	for( int i=0; i<n;i++)
	{
		if( ds[i].kq=="dat")
		{
			cout<<left<<setw(5)<<" "<<ds[i].hoten<<setw(10)<<" "<<ds[i].gt<<setw(5)<<" "<<ds[i].tentm<<setw(15)<<" "<<ds[i].kq<<endl;
		
	f.write((char*)&ds[i], sizeof(ds[i]));}
	}
	f.close();
}

void sapxep(thisinh ds[], int n)
{	char tmp[50];
	for( int i=0; i<n;i++)
	{
		for( int j=1;j<n;j++)
		if(strcmp(ds[j-1].hoten,ds[j].hoten)>0)
			{
		        strcpy(tmp, ds[j-1].hoten);
		        strcpy(ds[j-1].hoten, ds[j].hoten);
		        strcpy(ds[j].hoten, tmp);
      		}

	}
}

int main()
{
	thisinh ds[100];
	int n;
	cout<<"Nhap vao so luong thi sinh: ";
	cin>>n;
	nhapdsts(ds,n);
	xuatdsts(ds,n);
	/*trungten(ds,n);
	luufile(f,ds,n);
	sapxep(ds,n);
	xuatdsts(ds,n);*/
	//xuatdsts(ds,n);
	luufile(ds,n);
	return 0;
}
