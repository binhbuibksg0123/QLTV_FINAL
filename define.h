#define MAX_MENU 5
#define DIS_MENUX 30 //Khoang cach giua 2 muc menu
#define DIS_MENUY 30
//****************//
#define WD_WIDTH 1900 //L+R
#define WD_HEIGHT 1000 //U+D
#define OBJ_PER_PAGE 22
#define DELAY_NOTI 1000
//****************//

char MenuChinh[MAX_MENU+1][30] = {"Quan ly dau sach", "Quan ly doc gia", "Muon tra sach", "Thong tin", "Huong dan"};
char Menudausach[][30]={"Them","Xoa","Hieu chinh", "Tim kiem", "Danh muc sach", "Top 10"};
char Menudocgia[][30]={"Them","Xoa","Hieu chinh","Danh sach doc gia","Sach muon qua han","Sach dang muon"};
char Menumuontra[][30]={"Muon sach","Tra sach"};
//
int ViTriKhung[]={500,800,900,400};
int ViTriMucMenu[MAX_MENU+1]={20};
int ViTriMucMenuPhu[7]={0, 40, 80, 120, 160, 200, 240};
int KichThuocMenuPhu[MAX_MENU+1]={200, 225, 180, 180, 120, 200};
int ViTriMucMenuCuoi[5]={220,220,60,400,500,};
int ViTriKhungDauSach[]={0,250,340,430,520,610,700};
int ViTriKhungDocGia[]={0,250,340,430,520,610};

//
char KhungNoiDung[][30]={"Thong tin doc gia","OK","Thoat","Ho","Ten","Trang thai","Phai"};
char KhungDauSach[][30]={"Thong tin dau sach","OK","Thoat","ISBN","Ten sach","So trang","Tac gia","Nam xuat ban","The loai"};
char KhungXoa[][30]={"ISBN","","Danh sach sach","OK","Thoat"};
//
char KhungDocgia[][30]={"Thong tin doc gia","OK","Thoat","Ma the","Ho & ten dem", "Ten", "Trang thai","Phai"};
char Sex[][30] 	= {"Nam", "Nu"};
//
char Success[][50] = {"Them thanh cong!", "Xoa thanh cong!", "Chinh sua thanh cong!", "Save Successfully!"};
char Fail[][50]    = {"Khong duoc de trong!", "Khong tim thay!", "Empty List","Wrong Date!", "Sach da co!", 
					  "Employee Not Found!", "Not Enough Material!","Current quantity: ", "Full List!", "Value must not equal 0!"};
//
int  sizeDanhSachDausach[] 	 = {10, 30, 100, 20, 50, 20, 50};
char danhSachDausach[][30]   = {"STT","ISBN","Ten sach","So trang","Tac gia","Nam xuat ban","The loai"};
char danhSachDanhmucsach[][30] = {"STT", "Ma sach", "Trang thai", "Vi tri"};
int sizeDanhmucsach[] = {20, 40, 60, 80};
//
char checkDS[][30]={"Thong tin dau sach","Xac nhan","Thoat","ISBN","Ten sach","So trang","Tac gia","Nam xuat ban","The loai"};
//DMS
//int ViTriMucMenuDms[] = {20};
int ViTrichuDms[] = {0,550,605,660};
int ViTrimucmenu[] = {0,535,590,645};
char khungdms[][30] = {"Them","Xoa","Sua"};









