/*Vi?t c�c chuong trinh con th?c hi?n c�ng vi?c sau :
-nh?p m?t danh s�ch c�c th�nh vi�n trong clb �m nh?c g?m c�c th�ng tin: h? t�n, gi?i t�nh(k� hi?u 0 l� n? 1 l� nam), tu?i nh?c c? s? d?ng cho d?n khi h? t�n th�nh vi�n nh?p l� d?u "*" th� d?ng vi?c nh?p .
- hi?n danh s�ch th�nh vi�n clb �m nh?c ra m�n h�nh
-chuy?n c�c th�nh vi�n s? d?ng nh?c c? l� tr?ng l�n d?u danh s�ch
-ghi l� t?p "casy.dat" (d?ng t?p nh? ph�n) c�c th�nh vi�n trong clb c� gi?i t�nh 0 v� nh?c c? s?u d?ng l� "h�t"
-hi?n th? danh s�ch c�c th�nh vi�n c� tu?i tr�n 20 v?i d?y d? c�c th�ng tin
Vi?t chuong tr�nh ch�nh d? g?i c�c chuong tr�nh con theo tr?t t? dc vi?t nhu tr�n. N?u c� th? t? ch�c theo ctr menu th� s? l� m?t di?m c?ng.
*/
#include<bits/stdc++.h>
using namespace std;
int n=0;
struct CLB
{
    string Ho_ten;
    char Gioi_tinh;
    int tuoi;
    string nhac_cu;
} ds[100];
void nhapdsnv()
{
    while(true)
    {
        string s;
        cout << "Nhap du lieu nhan vien thu "<< n+1 << endl;
        cout << "Nhap ten nhan vien:";
        fflush(stdin);
        getline(cin,s);
        if (s=="*")
        {
            break;
        }
        ds[n].Ho_ten=s;
        cout << "Nhap gioi tinh(0:nu, 1:nam): ";
        cin>> ds[n].Gioi_tinh;
        cout << "Nhap tuoi: ";
        cin>>ds[n].tuoi;
        cout << "Nhap nhac cu: ";
        cin.ignore();
        getline (cin,ds[n].nhac_cu);
        n++;
    }
    cout << endl;
}
void intv(CLB x)
{
    cout << endl<< setw(20)<<x.Ho_ten;
    if(x.Gioi_tinh=='0')
    {
        cout<<setw(10)<< " Nu ";
    }
    else if (x.Gioi_tinh=='1')
    {
        cout <<setw(10)<< " Nam ";
    }
    cout <<setw(15)<<x.tuoi
         <<setw(18)<<x.nhac_cu;
}
void indstv()
{
    cout <<setw(20)<< "  Ho Ten  "<<setw(10)<< "  Gioi tinh  "<< setw(10)<< "  Tuoi  "<<setw(20)<< "  Nhac cu  "<<endl;
    for (int i=0; i<n; i++)
    {
        intv(ds[i]);
        cout << endl;
    }
    cout <<endl;
}
void sapxepds()
{
    CLB tg;
    for (int i=0; i<n; i++)
    {
        if (ds[i].nhac_cu=="Trong")
        {
            tg=ds[i];
            ds[i]=ds[i-1];
            ds[i-1]=tg;
        }
    }
    cout << "\ndanh sach thanh vien voi sap xep nguoi su dung nhac cu Trong len dau!\n";
    indstv();

}
void casy()
{
    for (int i=0; i<n; i++)
    {
        if (ds[i].Gioi_tinh=='0' && ds[i].nhac_cu=="hat")
        {
            intv(ds[i]);
            cout << endl;
        }
    }
    ofstream a;
    a.open("casy.dat",ios::out|ios::ate| ios::binary);
    a.write((char *)ds, sizeof(CLB)*n);
    a.close();
}
//void luudanhsachfile()
//{
//
//    ofstream a;
//    a.open("casy.dat",ios::out| ios::binary);
//    a.write((char *)ds, sizeof(CLB)*n);
//    a.close();
//}
void hienthitv()
{
    cout << "\nDanh sach thanh vien tren 20 tuoi trong CLB!\n";
    for (int i=0; i<n; i++)
    {
        if (ds[i].tuoi>20)
        {
            intv(ds[i]);
        }
    }
    cout <<endl;

}
int main()
{
    int chon;
    do
    {
        cout << "\n------------------------------------------------MENU--------------------------------------------------\n";
        cout << "\n1.Nhap Danh sach thanh vien CLB am nhac."
             << "\n2.Hien danh sach thong tin thanh vien CLB am nhac. "
             << "\n3.Chuyen cac thanh vien su dung trong len dau."
             << "\n4.Ghi ten tep la casy.dat cac thanh vien trong cau lac bo co gioi tinh nu va su dung nhac cu la hat"
             << "\n5.Hien thi thong tin thanh vien co do tuoi 20 tro len"
             << "\n0.Thoat!\n";
        cout << "_________________________________________************************_________________________________________";
        cout << "\nMoi chon: ";
        cin>> chon;
        switch(chon)
        {
        case 1:
            nhapdsnv();
            break;
        case 2:
            indstv();
            break;
        case 3:
            sapxepds();
            break;
        case 4:
        {
            casy();
           // luudanhsachfile();
        }
        break;
        case 5:
            hienthitv();
            break;
        case 0:
            exit(0);

        }
        system("pause");
        system("cls");

    }
    while (n!=0);


    return 0;
}

