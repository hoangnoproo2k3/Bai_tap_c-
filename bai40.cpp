/*B�i 40 (TH-CSLT-07): Vi?t c�c CTC th?c hi?n l?n lu?t c�c y�u c?u sau:
1. Nh?p danh s�ch n t�i x? t? b�n ph�m. M?i t�i x? c� c�c th�ng tin sau: M� t�i x?, H? v� t�n, Gi?i t�nh, Nam sinh, Bi?n s? xe, Luong. 
2. In danh s�ch c�c t�i x? l�n m�n h�nh
3. Luu danh s�ch t�i x? v�o file �Taixe.dat�  - File nh? ph�n
4. �?c file �Taixe.dat� v�o m?ng v� hi?n th? danh s�ch t�i x? ra m�n h�nh
5. Tr�ch l?c th�ng tin c?a c�c t�i x? c� gi?i t�nh n? v� luu v�o file �Taixenu.dat�
6. Nh?p t? b�n ph�m m� t�i x?, ch?
6. Nh?p t? b�n ph�m m� t�i x?, ch?nh s?a luong c?a t�i x? d� v� c?p nh?t v�o file. �?c file �Taixe.dat� v� hi?n th? danh s�ch t�i x? sau khi c?p nh?t ra m�n h�nh
Luu �: T? ch?c c�c file du?i d?ng file nh? ph�n.*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
struct taixe
{
 string ten;
 string maxe;
 string gioitinh;
 string biensoxe;
 int namsinh;
 int luong;
};
void nhapds(taixe ds[], int &n)
{
    cout<<"\n--------------------";
    cout<<"\nNhap so tai xe: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"\nNhap ten cua tai xe: ";
        cin.ignore();
        getline(cin, ds[i].ten);
        cout<<"\nNhap ma xe: ";
        getline(cin, ds[i].maxe);
        cout<<"\nNhap gioi tinh: ";
        getline(cin, ds[i].gioitinh);
        cout<<"\nNhap bien so xe: ";
        getline(cin, ds[i].biensoxe);
        cout<<"\nNhap nam sinh: ";
        cin>>ds[i].namsinh;
        cout<<"\nNhap luong: ";
        cin>>ds[i].luong;
    }
}
void intaixe(taixe x)
{
    cout<<"\n"<<setw(20)<<x.ten;
    cout<<setw(15)<<x.maxe;
    cout<<setw(15)<<x.gioitinh;
    cout<<setw(15)<<x.biensoxe;
    cout<<setw(15)<<x.namsinh;
    cout<<setw(15)<<x.luong;
}
void indstaixe(taixe ds[], int &n)
{
    cout<<"\nDanh sach cac tai xe la: ";
    for(int i=0; i<n; i++)
        intaixe(ds[i]);
}
void luufileds(taixe ds[], int&n)
{
    ofstream f;
    f.open("taixe.dat", ios::out|ios::ate|ios::binary);
    for(int i=0; i<n; i++)
        f.write((char *) &ds[i], sizeof(taixe));
    if (!f.good())
    {
        cout<< "\ghi bi loi : "<<endl;
        return;
    }
    cout<< "\ghi thanh cong "<<endl;
    f.close();
}
void docfileds(taixe ds[], int&n)
{
    ifstream f;
    f.open("taixe.dat", ios::in|ios::binary);
    int i=0;
    while(!f.eof())
    {
         f.read((char *) &ds[i], sizeof(taixe));
         i++;
    }
    n=i-1;
    f.close();
    cout<<"\nDoc file thanh cong!";
}
void indstaixenu(taixe ds[],int &n)
{
    cout<<"\nCac tai xe nu la: ";
    for(int i=0; i<n; i++)
    {
        if(ds[i].gioitinh=="nu")
            intaixe(ds[i]);
    }
}
void taixenu(taixe gioitinh(), int &n)
{
    
}
void luufiledsnu(taixe ds[], int&n)
{
    ofstream k;
    k.open("taixenu.dat", ios::out|ios::ate|ios::binary);
    for(int i=0; i<n; i++)
        k.write((char *) &ds[i], sizeof(taixe));
    if (!k.good())
    {
        cout<< "\nghi bi loi : "<<endl;
        return;
    }
    cout<< "\nghi thanh cong "<<endl;
    k.close();
}
void docfiledsnu(taixe ds[], int&n)
{
    ifstream k;
    k.open("taixenu.dat", ios::in|ios::binary);
    int i=0;
    while(!k.eof())
    {
         k.read((char *) &ds[i], sizeof(taixe));
         i++;
    }
    n=i-1;
    k.close();
    cout<<"\nDoc file thanh cong!";
}
int main()
{
    taixe ds[20];
    taixe gioitinh[15];
    int n, chon;
    do
    {
        cout<<"\n------------------------------------";
        cout<<"\n1. Nhap danh sach tai xe ";
        cout<<"\n2. In danh sach tai xe ";
        cout<<"\n3. Luu danh sach tai xe dang nhi phan ";
        cout<<"\n4. Doc danh sach tai xe va hien thi danh sach tai xe ra man hinh ";
        cout<<"\n5. In danh sach tai xe nu va luu, doc file ";
        cout<<"\n6. ";

        cout<<"\n7.  ";
        cout<<"\n0. Dung chuong trinh ";
        cout<<"\nMoi ban chon: ";
        cin>>chon;
        switch(chon)
        {
            case 1 : nhapds(ds, n) ; break;
            case 2 : indstaixe(ds, n) ; break;
            case 3 : luufileds(ds, n);break;
            case 4 : docfileds(ds, n);break;
            case 5 : indstaixenu(ds, n), luufiledsnu(ds, n), docfiledsnu(ds, n)  ;break;
            case 6 : ;break;
            case 7 : ;break;
            case 0 : exit (0);
        }

    } while(chon != 0);

return 0;
}

