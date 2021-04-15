//cau truc sinh vien
struct sinhvien {
	char* Name;
	int MSSV;
	double Mark;
};

struct Node {
	sinhvien Data;
	Node* pNext;
};

//danh sach
struct List {
	Node* pHead;
	Node* pTail;
};

void KhoiTao(List &L);

//check danh sach empty
int KTempty(List& L);

//in danh sach lien ket
void xuatdanhsach(List L);

//tao node
Node* taonode(sinhvien sv);

//nhap thong tin sinh vien
void nhapThongTin(sinhvien& sv);

//so sanh du lieu
int soSanh(sinhvien a, sinhvien b);

//them sinh vien vao dau danh sach 
void themvaodau(List& L,Node* sv);

//them sinh vien vao cuoi danh sach
void themvaocuoi(List& L,Node* sv);

//nhap thong tin sinh vien va them vao sau node dau tien cua danh sach
void themsauhead(List& L,Node* sv);

//nhap thong tin sinh vien va them vao truoc node cuoi cung cua danh sach
void themsaunodecuoi(List& L,Node* sv);

//ham sinh chuoi ngau nhien
void RandomChuoi(char* &code);


//them 5 Node sinh vien voi thong tin ngau nhien vao danh sach 
void them5NodeNgauNhien(List& L);

//them 10 Node voi thong tin ngau nhien vao danh sach
void them10NodeNgauNhien(List& L);

//xoa node dau tien trong danh sach
void xoaNodeDautien(List& L);

//xoa Node cuoi cung trong danh sach
void xoaNodeCuoiCung(List& L);


/////xoa Node tai vi tri k trong danh sach
//void xoaNodeBatKy(List& L,sinhvien k);

//nhap diem so va xoa nhung sinh vien co diem so vua nhap
void xoaSVcungDiem(List& L);

//xoa cac node trung nhau 
void xoaNodeTrungNhau(List& L);

//dao nguoc danh sach cho tat ca cac Node
List daoNguocCacNode(List& L);

//sap xep Danh sach theo thu tu tang dan diem so 
List sapXepTheoMark(List& L);

//nhap thong tin mot sinh vien va them vao danh sach van giu tinh tang dan diem so
List nhapVaThem(List& L);

//Kiem tra danh sach co chua vong hay khong 
bool KTvong(List& L);

//tim va tra ve danh sach lien ket don chua cac sinh vien ma ho ten bat dau bang 'H'
List DShotenH(List& L);

//nhap va them thong tin sinh vien vao danh sach neu ton tai MSSV thi tien hanh sua thong tin tai vi tri co MSSV do
void CapNhat(List& L);