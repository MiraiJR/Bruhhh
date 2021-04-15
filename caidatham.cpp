#include <iostream>
#include "thuvien.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

//MiraiJR

//khoi tao danh sach lien ket
void KhoiTao(List &L)
{
	L.pHead = NULL;
}

//kiem tra 
int KTempty(List& L)
{
	if (L.pHead == NULL)
	{
		return 1;
	}
}
//tao node moi
Node* taonode(sinhvien sv)
{
	Node* a = new Node;
	a->Data = sv;
	a->pNext = NULL;

	return a;
}

//xuat danh sach sinh vien
void xuatdanhsach(List L)
{
	Node* p = L.pHead;
	while (p != NULL)
	{
		cout <<"Ho ten: "<< p->Data.Name << "\t\t MSSV: "<< p->Data.MSSV<<"\t\t Diem: "<<p->Data.Mark<<endl;
		p = p->pNext;
	}
}

//nhap thong tin sinh vien
void nhapThongTin(sinhvien& sv)
{
	char a[100];
	cout << "Ho va ten: ";
	cin.get(a, 100);
	cin.ignore();
	sv.Name = new char[strlen(a) + 1];
	strcpy_s(sv.Name, strlen(a) + 1, a);
	cout << "MSSV: ";
	cin >> sv.MSSV;
	cout << "Diem: ";
	cin >> sv.Mark;
}

//so sanh du lieu
int soSanh(sinhvien a, sinhvien b)
{
	if (a.Mark == b.Mark && a.MSSV == a.MSSV && strcmp(a.Name, b.Name) == 0)
	{
		return 1;
	}
}

//them vao dau
void themvaodau(List& L,Node* sv)
{
	/*Node* sv;
	sinhvien a1;
	nhapThongTin(a1);
	sv = taonode(a1);*/
	if (KTempty(L)==1)
	{
		L.pHead = sv;
	}
	else
	{
		sv->pNext = L.pHead;
		L.pHead = sv;
	}
}

//them vao cuoi
void themvaocuoi(List& L,Node* sv)
{
	/*Node* sv;
	cin.ignore();
	sinhvien a1;
	nhapThongTin(a1);
	sv = taonode(a1);*/
	if (KTempty(L) == 1)
	{
		L.pHead = sv;
	}
	else
	{
		Node* p = L.pHead;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = sv;
	}
}

//nhap thong tin sinh vien va them vao sau node dau tien cua danh sach
void themsauhead(List& L,Node* sv)
{
	/*Node* sv;
	cin.ignore();
	sinhvien a1;
	nhapThongTin(a1);
	sv = taonode(a1);*/
	if (KTempty(L) == 1)
	{
		L.pHead = sv;
	}
	else
	{
		sv->pNext = L.pHead->pNext;
		L.pHead->pNext = sv;
	}
}

//nhap thong tin sinh vien va them vao truoc node cuoi cung cua danh sach
void themsaunodecuoi(List& L,Node* sv)
{
	Node* p = L.pHead;
	if (KTempty(L) == 1)
	{
		L.pHead = sv;
	}
	else
	{
		while (p ->pNext!=NULL)
		{
			p = p->pNext;
		}
		sv->pNext = p->pNext;
		p->pNext = sv;
	}
}

//ham sinh chuoi ngau nhien
void RandomChuoi(char* &code)
{
	const char* box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz";
	int boxLength = strlen(box);
	int x = rand() %9 + 2;
	code = new char[x];
	for (int i = 0; i < x; i++)
	{
		code[i] = box[rand() % boxLength];
	}
	code[x] = '\0';
}

//them 5 Node sinh vien voi thong tin ngau nhien vao danh sach 
void them5NodeNgauNhien(List& L)
{
	for (int i = 0; i < 5; i++)
	{
		sinhvien sv;
		RandomChuoi(sv.Name);
		sv.Mark = rand() % 11;
		sv.MSSV = rand();
		themvaodau(L,taonode(sv));
	}
}

//xoa Node dau tien trong danh sach
void xoaNodeDautien(List& L)
{
	if (KTempty(L) == 1)
	{
		cout << "Khong co du lieu de xoa" << endl;
	}
	else
	{
		Node* temp = L.pHead;
		L.pHead = L.pHead->pNext;
		delete[]temp;
	}
}

//xoa Node cuoi cung trong danh sach
void xoaNodeCuoiCung(List& L)
{
	if (KTempty(L) == 1)
	{
		cout << "Khong co du lieu de xoa" << endl;
	}
	else
	{
		Node* temp = L.pHead;
		while ( temp->pNext->pNext != NULL)
		{
			temp = temp->pNext;
		}
		Node* p = temp->pNext;
		temp->pNext = NULL;
		delete[] p;
		/*cout << temp->Data.Name << endl;*/
	}
}

//them 10 Node voi thong tin ngau nhien vao danh sach
void them10NodeNgauNhien(List& L)
{
	for (int i = 0; i < 10; i++)
	{
		sinhvien sv;
		RandomChuoi(sv.Name);
		sv.Mark = rand() % 11;
		sv.MSSV = rand();
		themvaodau(L, taonode(sv));
	}
}


//xoa node tai vi tri k trong danh sach
void xoaNodeBatKy(List& L,sinhvien k)
{
	Node* p = L.pHead;
	if (KTempty(L) == 1)
	{
		cout << "Khong co du lieu de xoa" << endl;
	}
	else
	{
		Node* q = NULL;
		while (p != NULL)
		{
			if (soSanh(p->Data, k) == 1)
			{
				//cout << "1" << endl;
				break;
			}
			q = p;
			p = p->pNext;
		}
		cout << q->Data.Name << endl;
		cout << p->Data.Name << endl;
		if (p->pNext == NULL)
		{
			xoaNodeCuoiCung(L);
		}
		else
		{
			q->pNext = p->pNext;
			delete[]p;
		}
	}
}

//nhap diem so va xoa nhung sinh vien co diem so vua nhap
void xoaSVcungDiem(List& L)
{
	double n;
	cout << "Nhap diem so: ";
	cin >> n;
	List T;
	KhoiTao(T);
Again:
	Node* p = L.pHead;
	while (p != NULL)
	{
		if (p->Data.Mark != n)
		{
			sinhvien sv;
			sv.Mark = p->Data.Mark;
			sv.MSSV = p->Data.MSSV;
			sv.Name = p->Data.Name;
			themvaodau(T, taonode(sv));
		}
		p = p->pNext;
	}
	xuatdanhsach(T);
}

//xoa cac node trung nhau 
void xoaNodeTrungNhau(List& L)
{
	List T;
	KhoiTao(T);
	Node* p = L.pHead;
	while (p != NULL)
	{
		int x = 0;
		Node* q = p->pNext;
		while (q != NULL )
		{
			if (soSanh(p->Data,q->Data)==1)
			{
				x = 1;
				cout << x << endl;
				break;
			}
			q = q->pNext;
		}
		if (x == 0 )
		{
			sinhvien sv;
			sv.Mark = p->Data.Mark;
			sv.MSSV = p->Data.MSSV;
			sv.Name = p->Data.Name;
			themvaodau(T, taonode(sv));
		}
		p = p->pNext;
	}
	xuatdanhsach(T);
}


//dao nguoc danh sach cho tat ca cac Node
List daoNguocCacNode(List& L)
{
	Node* p = L.pHead;
	List T;
	KhoiTao(T);
	while (p != NULL)
	{
		sinhvien sv;
		sv.Mark = p->Data.Mark;
		sv.MSSV = p->Data.MSSV;
		sv.Name = p->Data.Name;
		themvaodau(T, taonode(sv));
		p = p->pNext;
	}
	return T;
}



//sap xep Danh sach theo thu tu tang dan diem so 
List sapXepTheoMark(List& L)
{
	if (KTempty(L) == 1)
	{
		cout << "Khong co du lieu de thuc hien" << endl;
	}
	else {
		Node* p = L.pHead;
		while (p != NULL)
		{
			Node* q = p->pNext;
			while (q != NULL)
			{
				if (p->Data.Mark > q->Data.Mark)
				{
					sinhvien temp = q->Data;
					q->Data = p->Data;
					p->Data = temp;
				}
				q = q->pNext;
			}
			p = p->pNext;
		}
		return L;
	}
}

//nhap thong tin mot sinh vien va them vao danh sach van giu tinh tang dan diem so
List nhapVaThem(List& L)
{
	sinhvien sv;
	nhapThongTin(sv);
	themvaocuoi(L, taonode(sv));
	sapXepTheoMark(L);
	return L;
}

//Kiem tra danh sach co chua vong hay khong 
bool KTvong(List& L)
{
	if (KTempty(L) == 1)
	{
		return false;
	}
	else
	{
		Node* p = L.pHead;
		Node* q = L.pHead;
		while (true)
		{
			p = p->pNext;
			if (q->pNext != NULL)
			{
				q = q->pNext->pNext;
			}
			else
			{
				return false;
			}
			if (q == NULL || p == NULL)
			{
				return false;
			}
			if(q=p)
			{
				return true;
			}
		}
	}
	
}


//tim va tra ve danh sach lien ket don chua cac sinh vien ma ho ten bat dau bang 'H'
List DShotenH(List& L)
{
	List T;
	KhoiTao(T);
	Node* p = L.pHead;
	int x = 0;
	while (p != NULL)
	{
		if (p->Data.Name[0] == 'H' || p->Data.Name[0] == 'h')
		{
			x = 1;
			sinhvien sv;
			sv.Mark = p->Data.Mark;
			sv.MSSV = p->Data.MSSV;
			sv.Name = p->Data.Name;
			themvaodau(T, taonode(sv));
		}
		p = p->pNext;
	}
	/*if (x == 0)
	{
		cout << "Khong co ho ten sinh vien nao bat dau bang 'H' va 'h' trong danh sach" << endl;
		return;
	}
	else
	{
		return T;
	}*/
	return T;
}



//nhap va them thong tin sinh vien vao danh sach neu ton tai MSSV thi tien hanh sua thong tin tai vi tri co MSSV do
void CapNhat(List& L)
{
	sinhvien sv;
	cin.ignore();
	nhapThongTin(sv);
	Node* p = L.pHead;
	while (p != NULL)
	{
		
		if (p->Data.MSSV == sv.MSSV)
		{
			p->Data = taonode(sv)->Data;
		}
		p = p->pNext;
	}
}
