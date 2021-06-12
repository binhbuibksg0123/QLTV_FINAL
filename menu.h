#include <graphics.h>
#include "define.h"
#include "colors.h"
#include "cautrucdulieu.h"
#include "nhaplieu.h"
using namespace std;

//***************//
void KhoiTaoChuongTrinh();
void Guild();
void TaoManHinhLamViec();
void VeMenu();
void VeMenuPhu(int sttMenuChinh, char menu[][30]);
void InThongTin(int x, int y,char *s);
void noti(char khungNoiDung[]);
void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen);
void infoText(int x, int y, char noiDung[],char info[],int MauChu);
void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu);
void veKhung1(int x, int y, char noiDung[], bool daChon);
void NoiBatMuc(int sttMenuChinh, int sttMenuPhu, char menu[][30], int HL_COLOR, int C_SIZE);
void VeKhungthemDausach(char KhungNoiDung[][30],DS_Dausach *listtmp,struct Dausach *tmp, int Mcase);
void VeKhungxoaDausach();
void VeKhungthemDocgia(char KhungNoiDung[][30], int Mcase);
void DanhMucsach(DSDS &ListDausach, List &l);

//***************//
//MENU
void Menu(DSDS &ListDausach, pDMS &Dms);
void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc);
void addDausach(struct DS_Dausach &ListDausach);
void XoaDausach(struct DS_Dausach &ListDausach);
void chinhSuaDausach(struct DS_Dausach &ListDausach);
void ChonMenuPhu(int sttMenuChinh, DSDS &ListDausach, List &l);
void addDocgia();
void Dausach(struct DS_Dausach &ListDausach, List &l);
void Docgia();
void Muontra();
void Huongdan();
void Thongtin();
//**************//
//Ham ve thanh cong cu 
void VeMenu(){
	// Ve nen menu chinh
	setbkcolor(MAU_NEN);
	cleardevice();
	setfillstyle(SOLID_FILL, MAU_MENU);
	
	// Ve cac muc menu chinh
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);	
	for (int i = 0; i < MAX_MENU; i++){
		outtextxy(ViTriMucMenu[i], 15, MenuChinh[i]);
		ViTriMucMenu[i+1] = ViTriMucMenu[i] + textwidth(MenuChinh[i]) + DIS_MENUX;
	}
}

void TaoManHinhLamViec(){
	VeMenu();
	NoiBatMuc(0, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
}

void KhoiTaoChuongTrinh(){
	initwindow(1920, 1080);
	TaoManHinhLamViec();
	//Guild();
}



void NoiBatMuc(int sttMenuChinh, int sttMenuPhu, char menu[][30], int HL_COLOR, int C_SIZE){
	// * Ve cac muc duoc chon
	setbkcolor(HL_COLOR);
	setfillstyle(SOLID_FILL, HL_COLOR);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);
	
	// Highlight muc menu chinh
	if (sttMenuPhu == 0){
		bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 5, ViTriMucMenu[sttMenuChinh+1]-DIS_MENUX/2, 45);
		outtextxy(ViTriMucMenu[sttMenuChinh], 10, menu[sttMenuChinh]);
		
	}
	//Higlight muc menu phu
	else{
		bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 
		50+ViTriMucMenuPhu[sttMenuPhu-1], 
		ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2+KichThuocMenuPhu[sttMenuChinh], 
		50+ViTriMucMenuPhu[sttMenuPhu]);
		outtextxy(ViTriMucMenu[sttMenuChinh], 45+ViTriMucMenuPhu[sttMenuPhu-1]+DIS_MENUY/2, menu[sttMenuPhu-1]);
	}	
}

void Menu(DSDS &ListDausach, List &l){
	// Thao tac trong menu chinh
	int chiMuc = 0;
	NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
	while(1)	{
		if(kbhit())	{
			VeMenu();
			char key = getch();
			if (key == 0) {
				char cNext = getch();
				switch(cNext){
					case KEY_LEFT: {
						chiMuc--;
						break;
					}
					case KEY_RIGHT: {
						chiMuc++;
						break;
					}
					case KEY_F9: {
						SaveDs(ListDausach);
						noti(Success[3]);
						delay(1000);
						VeMenu();
						break;
					}
				}
				if (chiMuc == MAX_MENU)
					chiMuc = 0;
				if (chiMuc < 0)
					chiMuc = MAX_MENU-1;
			}
			else if (key == '\r'){
				VeMenu();
				ChonMenuPhu(chiMuc,ListDausach,l);
			}
			NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
		}
	}
}

void VeMenuPhu(int sttMenuChinh, char menu[][30]){
	int MAX;	//so luong muc trong menu phu
	switch(sttMenuChinh){
		case 0: {
			MAX = 6;
			break;
		}
		case 1: {
			MAX = 6;
			break;
		}
		case 2: {
			MAX = 2;
			break;
		}		
	}
	setbkcolor(HIGHTLIGHTS);
	setfillstyle(SOLID_FILL, HIGHTLIGHTS);
	setusercharsize(1, 2, 1, 2);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);
	
	// in nen menu phu
	bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 
	50, 
	ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2+KichThuocMenuPhu[sttMenuChinh], 
	70+ViTriMucMenuCuoi[sttMenuChinh]);
	
	// in cac muc menu phu
	for (int i = 0; i < MAX; i++){
		outtextxy(ViTriMucMenu[sttMenuChinh], 45+ViTriMucMenuPhu[i]+DIS_MENUY/2, menu[i]);
	}
}

void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc){
	// Thao tac trong menu phu
	chonMuc = 1;
	NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
	while(1){
		if(kbhit()){
			VeMenuPhu(viTriMenuPhu, menu);
			char key = getch();
			if(key == 0){
				char cNext = getch();
				switch(cNext){
					case KEY_UP:{
						chonMuc--;
						break;
					}
					case KEY_DOWN: {
						chonMuc++;
						break;
					}
					default:{
							VeMenu();
							chonMuc = -1;
							return;
						}
				}
				if (chonMuc > MAXMENU)
					chonMuc = 1;
				if (chonMuc < 1)
					chonMuc = MAXMENU;
			}
			else if (key == '\r'){
				return VeMenu();
			}
			else if (key == 27){
				chonMuc = -1;
				VeMenu();
				return;
			}
			NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
		}
	}
}

void ChonMenuPhu(int sttMenuChinh, DSDS &ListDausach, List &l){
	switch(sttMenuChinh){
		case 0:	return Dausach(ListDausach,l);
		case 1: return Docgia();
		case 2:	return Muontra();
		case 3:	return Thongtin();
		case 4:	return Huongdan();
		default : return;
	}
}

void About(){
	MessageBox(NULL, 
	"Quan ly thu vien\n"
	"Sinh vien:\n"
	"Do Huy Hoang-N19DCCN063 \n"
	"Tham Ngoc Anh-N19DCCN012 \n",
	"About", MB_APPLMODAL | MB_ICONINFORMATION);
}

void Guild(){
	MessageBox(NULL, 
	"Di chuyen		: Cac phim mui ten.\n"
	"Chon		: Enter.\n"
	"Exit		: ESC.\n"
	"Luu		: F9.\n"
	"Chuyen trang	: PageUp, PageDown.\n",
	"Huong dan", MB_APPLMODAL | MB_ICONINFORMATION);
}

void noti(char khungNoiDung[]){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 100;
	int W = 250;
	setusercharsize(2, 1, 2, 1);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	
	/*setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, D);*/
	
	/*setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);*/
	
	//in thong bao
	setcolor(WHITE);
	setbkcolor(MAU_MENU);
	outtextxy(L+canLeGiua(khungNoiDung, W), U+(H-textheight(khungNoiDung))/2, khungNoiDung);
}

void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen){	
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noti);
	Sleep(DELAY_NOTI);
	setfillstyle(SOLID_FILL, mauNen);
	bar(x, y, x + textwidth(noti), y + textheight(noti));
}

void Dausach(DSDS &ListDausach, List &l){
	int thaotac;
	VeMenuPhu(0,Menudausach);
	MenuPhu(0,Menudausach,6,thaotac);
	switch(thaotac){
		case 1:{
			return addDausach(ListDausach);
			break;
		}
		case 2:{
			return XoaDausach(ListDausach);
			break;
		}
		case 3:{
			return chinhSuaDausach(ListDausach);
			break;
		}
		case 5:{
			DanhMucsach(ListDausach, l);
			break;
		}
	}
}

void Docgia(){
	int thaotac;
	VeMenuPhu(1,Menudocgia);
	MenuPhu(1,Menudocgia,6,thaotac);
	switch(thaotac){
		case 1: {
			return addDocgia();
		}
	}
}

void Muontra(){
	int thaotac;
	VeMenuPhu(2,Menumuontra);
	MenuPhu(2,Menumuontra,2,thaotac);
}

void Huongdan(){
	Guild();
}

void Thongtin(){
	About();
}

void InThongTin(int x, int y, char *s){
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x, y, s);
}		
				
void infoText(int x, int y, char noiDung[],char info[],int MauChu){
	setbkcolor(NEN_TEXT);
	setcolor(MauChu);
	outtextxy(x, y, noiDung);
	int dis = 175;	
	outtextxy(x+dis-1, y, info);
}

void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu){
	setbkcolor(NEN_KHUNG);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 575;
	int dis = 160;
	
	setfillstyle(SOLID_FILL, NEN_TEXT);
	bar(x+dis, y-H+5, x+W, y+H+10);
	if (daChon)
		setcolor(WHITE);
	else
		setcolor(BLACK);
	 //highligh vien ngoai neu da chon	 
	rectangle(x+dis, y-H+5, x+W, y+H+10);	
}

void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset, int n){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	// In info khung
	/*setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);*/
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	/*setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);*/
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, WD_WIDTH/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[n+1]);
	} else{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[n+1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);						//center line
	
}

void VeKhungthemDausach(char KhungNoiDung[][30], DSDS &listtmp, struct Dausach *tmp, bool &selected){
	selected = false;
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(KhungDauSach[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(KhungDauSach[2]))/2;
	int midTextH = (kichThuocNut - textheight(KhungDauSach[1]))/2 + textheight(KhungDauSach[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, KhungDauSach[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, KhungDauSach[2]);
	// 
	int pos=1;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		if (i == 1){
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 1, NEN_KHUNG, WHITE);
			
		} else{
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
		}
	}
		/*char tmpnxb[5];
		char tmpst[8];*/
	struct DetailDS{
	char tmpnxb[5];
	char tmpst[8];
	DetailDS(){
		tmpnxb[0] = '\0';
		tmpst[0] = '\0';
	}
	};
DetailDS tmpDS;	
	//===== Chon vi tri ======//
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 0)
					pos = 7;
				if (pos > 7){
						pos = 1;
				}
			}
			else if (key == '\r'){
				if (pos <= 6)  //enter xuong o moi
					pos++;
//				else
//					return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			
			for (int i = 1; i <= Soluongkhung; i++){
				veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_TEXT, WHITE);
			}
				
			
				
			/*strcpy(tmpDS.tmpst, toChars(tmp->Sotrang));
			strcpy(tmpDS.tmpnamxb, toChars(tmp->Namxb));*/
				
				
			setbkcolor(NEN_TEXT);
				InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
				InThongTin(830, ViTriKhungDauSach[2], tmp->Tensach);
				InThongTin(830, ViTriKhungDauSach[3], tmpDS.tmpst);
				InThongTin(830, ViTriKhungDauSach[4], tmp->Tacgia);
				InThongTin(830, ViTriKhungDauSach[5], tmpDS.tmpnxb);
				InThongTin(830, ViTriKhungDauSach[6], tmp->Theloai);
				
				
			//===di chuyen trong menu===//
			switch(pos){
				case 1:{
						veKhung(650, 250, KhungDauSach[3], 1, NEN_TEXT, WHITE);
						Nhap(830,250,-1, key, tmp->ISBN,14);
						break;
					}
				case 2:{
						veKhung(650, 340, KhungDauSach[4], 1, NEN_TEXT, WHITE);
						Nhap(830,340,2, key, tmp->Tensach, 24);
						break;
					}
				case 3:{
						veKhung(650, 430, KhungDauSach[5], 1, NEN_TEXT, WHITE);
						Nhap(830,430,0, key, tmpDS.tmpst,7);
						break;
					}
				case 4:{
						veKhung(650, 520, KhungDauSach[6], 1, NEN_TEXT, WHITE);
						Nhap(830,520,2, key, tmp->Tacgia,27);
						break;
					}
				case 5:{
						veKhung(650, 610, KhungDauSach[7], 1, NEN_TEXT, WHITE);
						Nhap(830,610,0, key, tmpDS.tmpnxb,4);
						break;
				}
				case 6:{
						veKhung(650, 700, KhungDauSach[8], 1, NEN_TEXT, WHITE);
						Nhap(830,700,2, key, tmp->Theloai,24);
						break;
				}
				case 7:	{
						// Them dau sach
					
						bool buttonL = 1;
						veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit())	{
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
									//return;
									if (buttonL == 1){
											
										if(strlen(tmp->ISBN)!=0 && strlen(tmpDS.tmpnxb)!=0 && strlen(tmpDS.tmpst)!=0 && strlen(tmp->Tacgia)!=0 && strlen(tmp->Tensach)!=0 && strlen(tmp->Theloai)!=0)
										{
											selected = true;
											tmp->Namxb = ChangeCharToNum(tmpDS.tmpnxb);
											tmp->Sotrang = ChangeCharToNum(tmpDS.tmpst);
											return;
										}
										else{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									return;
								}
								veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
							}
						}
					}
				}
			}
		}
}

void addDausach(struct DS_Dausach &ListDausach){
	bool entered = false;
	do{
		struct Dausach *tmpD = new struct Dausach;
		VeKhungthemDausach(KhungDauSach,ListDausach, tmpD,entered);
		if(entered){
			if (isFull(ListDausach)){
				ThongBao(1150, 165, Fail[8], GREEN, MAU_MENU);
			}
			else{
				if (Search_info(ListDausach,tmpD)==-1){
					Insert(ListDausach,tmpD);
					ThongBao(1150, 165, Success[0], GREEN, MAU_MENU);
				} else {
					ThongBao(1200, 165, Fail[4],LIGHTRED, MAU_MENU);
				}
			}	
		}
	}while(entered);
	VeMenu();
	
	
}

void showPage(int x, int y, int page, int limit){
	//  Page: page / limit
	setcolor(MAU_TEXT_KHUNG);
	setbkcolor(MAU_NEN);
	outtextxy(x, y, "Trang: ");
	x += textwidth("Trang: ");
	
	outtextxy(x, y, toChars(page));
	x += textwidth(toChars(page));
	
	outtextxy(x, y, " / ");
	x += textwidth(" / ");	
	
	outtextxy(x, y, toChars(limit));
}

void  VeKhungxoaDausach(char khungNoiDung[][30], DSDS &listtmp, bool &list, char *findID, bool &selected){
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
		
	// Kich thuoc khung
	int L =	470;
	int U = 300;
	int R =	1430;
	int D =	515;
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,(L+R)/2,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(470, 300, KhungXoa[0]);

			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
/*	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(470, 300, khungNoiDung[0]);*/
	
	//
	//Ve cac khung ban dau===
	selected = false;
	bool choice = 1;
	bool chooseL = 1; 
	int posR = 1;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[2]);
	setcolor(WHITE);
	
	
	rectangle(L+14, ViTriKhung[3]-21, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+textheight(khungNoiDung[0]));
	// ve khung chon id
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-20, WD_WIDTH/2, ViTriKhung[3]+20+textheight(khungNoiDung[0]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0])); // khung nhap
	
	// ve khung chon list
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	
	// 2 nut check and exit
	outtextxy(L+midText1, D+12-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH+12, khungNoiDung[4]);
	//make ur choice
	
	findID[0] = '\0';
	while(1)
	{
		InThongTin(L+35+2*textwidth(khungNoiDung[0]),ViTriKhung[3],findID);
		if(kbhit())
		{
			char keyR = getch();
			if(keyR==0)
			{
				char ckeyR = getch();
				switch(ckeyR)
				{
					case KEY_LEFT:
					{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_RIGHT:
					{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_UP:
					{
						if(posR == 1)
						{
							posR = 2;
							chooseL = true;
							break;
						}
						else
						{
							posR = 1;
							//choice = true;
							break;
						}		
					}
					case KEY_DOWN:
					{
						if(posR == 1)
						{
							posR = 2;
							chooseL = true;
							break;
						}
						else
						{
							posR = 1;
							//choice = true;
							break;
						}	
					}	
				}
			}
			if(keyR == '\r')
			{
				if(posR == 1)
				{
					posR = 2;
					chooseL = 1;
				}
				else
				{
					if(chooseL)
					{
						if(choice == 1)
						{
							list = false;
							selected = true;
							return;
						}
						else
						{
							list = true;
							selected = true;
							return;
						}
					}
					else
					{
						VeMenu();
						return;
					}
				}
			}
			if(keyR == 27)
			{
				VeMenu();
				return;
			}
			// hien thi
			if(posR == 1)	//ID/list
			{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				if(choice)
				{
					// ID
					setbkcolor(NEN_KHUNG);
					bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
					bar (L+15, ViTriKhung[3]-20,WD_WIDTH/2 , ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					Nhap(L+35+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
				}
				else
				{
					// list
					setbkcolor(NEN_KHUNG);
					bar (L+15, ViTriKhung[3]-20,WD_WIDTH/2 , ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-20, WD_WIDTH/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);
				}
				
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (L, D-kichThuocNut, WD_WIDTH/2, D);
				bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
				setbkcolor(NEN_KHUNG);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				setcolor(WHITE);
				outtextxy(L+midText1, D-midTextH+12, khungNoiDung[3]);
				outtextxy(WD_WIDTH/2+midText2, D-midTextH+12, khungNoiDung[4]);
			}
			else	//check/exit
			{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(chooseL) //check
				{	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH+12, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH+12, khungNoiDung[4]);
				}
				else	//exit
				{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH+12, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH+12, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			}		
		}
	}
}

void inDausach(struct Dausach *ds, int posX, int posY){
	char tmpst[8];
	char tmpnxb[5];
	strcpy(tmpst,toChars(ds->Sotrang));
	strcpy(tmpnxb,toChars(ds->Namxb));
	// in ISBN
	outtextxy(posX + canLeGiua(ds->ISBN, textwidth(danhSachDausach[1])+sizeDanhSachDausach[1]*2), posY, ds->ISBN);
	posX += textwidth(danhSachDausach[1]) + sizeDanhSachDausach[1]*2;
	
	// in ten sach
	outtextxy(posX + 10, posY, ds->Tensach);
	posX += textwidth(KhungDauSach[2]) + sizeDanhSachDausach[2]*2;
	
	// in so trang
	outtextxy(posX + 80, posY, tmpst);
	posX += textwidth(KhungDauSach[3]) + sizeDanhSachDausach[3]*2;
	// in tac gia
	outtextxy(posX + 100, posY, ds->Tacgia);
	posX += textwidth(KhungDauSach[4]) + sizeDanhSachDausach[3]*2;
	// in nxb
	outtextxy(posX + 195, posY, tmpnxb);
	posX += textwidth(KhungDauSach[5]) + sizeDanhSachDausach[3]*2;
	// in the loai
	outtextxy(posX + 215, posY, ds->Theloai);
	posX += textwidth(KhungDauSach[6]) + sizeDanhSachDausach[3]*2;
}

void inTrangDausach(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	350;
	int U = 100;
	int R =	1510;
	int D =	870;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 22; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = dsds.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		inDausach(dsds.nodes[i], disW, dis);
		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}

void chonTuDanhSach(DSDS &dsds, int &stt, int &startPage, bool &selected){	
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(dsds.n*1.0/OBJ_PER_PAGE); // lam tron so 
	if (limitPage == 0){
		noti(Fail[2]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W=1160;
		int U = 100;
		int L =	350;
		
		int x = 350, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		/*int L =	350;
		int U = 100;
		int R =	1510;
		int D =	895;*/
				
		inTrangDausach(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
		showPage(1450, 900, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDausach(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1450, 900, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDausach(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1450, 900, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), dsds.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > dsds.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					VeMenu();
					return;
				}
				else if (key == '\r'){
					selected = true;
					return;
				}
			}
		}
	}
}

void DanhsachxoaDausach(DSDS &dsds){
	//sortEmp(ListEmployees.nodeListEmp, 0, ListEmployees.n-1);
	
	int removePos = 0;
	int page = 1;
	bool select;
	while(1){
		chonTuDanhSach(dsds, removePos, page, select);
		if(select){
			DeleteDs(dsds,removePos);
		}
		else{
			break;
		}
	}
	VeMenu();
}
	
void XoaIsbn(DSDS &dsds, char khungNoiDung[][30], int H, int W, struct Dausach *Info){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	/*int H = 450;
	int W = 600;*/
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);
	//
	//Ve cac khung ban dau===
	int pos=1;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
	}
	
	
	//info
	char tmpst[8];
	char tmpnxb[5];
	strcpy(tmpst,toChars(Info->Sotrang));
	strcpy(tmpnxb,toChars(Info->Namxb));
	
	InThongTin(830, ViTriKhungDauSach[1], Info->ISBN);
	InThongTin(830, ViTriKhungDauSach[2], Info->Tensach);
	InThongTin(830, ViTriKhungDauSach[3], tmpst);
	InThongTin(830, ViTriKhungDauSach[4], Info->Tacgia);
	InThongTin(830, ViTriKhungDauSach[5], tmpnxb);
	InThongTin(830, ViTriKhungDauSach[6], Info->Theloai);
	bool buttonL = 1;
	veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
	while(1){
		if(kbhit()){
			char key = getch();
			if(key==0){
				char ckey = getch();
				switch(ckey){
					case KEY_LEFT:{
						buttonL ^= 1;
						break;
					}
					case KEY_RIGHT:	{
						buttonL ^= 1;
						break;
					}
				}
			}
			else if(key == '\r'){
				if(buttonL){
					DeleteISBN(dsds,Info->ISBN);
					ThongBao(1150, 165, Success[1], GREEN, MAU_MENU);
				}
				VeMenu();
				return;
			}
			else if(key==27){
		 		VeMenu();
			 	return;
			}
			veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
		}
	}
}

void XoaDausach(struct DS_Dausach &ListDausach){
	bool entered = false;
	do
	{
		bool chooseList = false;
		char tmpISBN[15];
		VeKhungxoaDausach(KhungXoa, ListDausach, chooseList, tmpISBN, entered);
		if (entered){
			if (chooseList){
				return DanhsachxoaDausach(ListDausach);
			}
			else{
				struct Dausach *tmp;
				tmp = ListDausach.Search_ISBN(tmpISBN);
				if(tmp == NULL){
					//loi ko ton tai
					ThongBao(1180, 310, Fail[1], LIGHTRED, MAU_MENU);
				}
				else{	
					XoaIsbn(ListDausach, checkDS, 450, 600, tmp);
				}
			}
		}
	}while(entered);
}

void chinhThongTinDS(char khungNoiDung[][30], DSDS &listtmp, struct Dausach *tmp, bool &selected){
	selected = false;
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(KhungDauSach[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(KhungDauSach[2]))/2;
	int midTextH = (kichThuocNut - textheight(KhungDauSach[1]))/2 + textheight(KhungDauSach[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, KhungDauSach[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, KhungDauSach[2]);
	// 
	int pos=2;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		if (i == 1){
//			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 1, NEN_KHUNG, WHITE);
				setbkcolor(NEN_KHUNG);
				setcolor(WHITE);
				outtextxy(650, 250, KhungDauSach[3]);
				int H = textheight(KhungDauSach[3]);
				int W = 575;
				int dis = 160;
				
				setfillstyle(SOLID_FILL, NEN_TEXT);
				bar(650+dis, 255-H, 650+W, 260+H);
					setcolor(BLACK);
				 //highligh vien ngoai neu da chon	 
				rectangle(650+dis, 255-H, 650+W, 260+H);
			
		} else {
			if (i==2){
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 1, NEN_KHUNG, WHITE);
			} else {
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
			}
		
		}
	}
//	in thong tin
			
			char tMpst[8];
			char tMpnxb[5];
				
			strcpy(tMpst,toChars(tmp->Sotrang));
			strcpy(tMpnxb,toChars(tmp->Namxb));	

			InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
			InThongTin(830, ViTriKhungDauSach[2], tmp->Tensach);
			InThongTin(830, ViTriKhungDauSach[3], tMpst);
			InThongTin(830, ViTriKhungDauSach[4], tmp->Tacgia);
			InThongTin(830, ViTriKhungDauSach[5], tMpnxb);
			InThongTin(830, ViTriKhungDauSach[6], tmp->Theloai);		
	//===== Chon vi tri ======//
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 1)
					pos = 7;
				if (pos > 7){
						pos = 2;
				}
			}
			else if (key == '\r'){
				if (pos <= 6)  //enter xuong o moi
					pos++;
//				else
//					return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			
			for (int i = 1; i <= Soluongkhung; i++){
				veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_TEXT, WHITE);
			}
			setbkcolor(NEN_TEXT);
				
				/*strcpy(tmpDS.tMpst,toChars(tmp->Sotrang));
				strcpy(tmpDS.tMpnxb,toChars(tmp->Namxb));*/
														
				InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
				InThongTin(830, ViTriKhungDauSach[2], tmp->Tensach);
				InThongTin(830, ViTriKhungDauSach[3], tMpst);
				InThongTin(830, ViTriKhungDauSach[4], tmp->Tacgia);
				InThongTin(830, ViTriKhungDauSach[5], tMpnxb);
				InThongTin(830, ViTriKhungDauSach[6], tmp->Theloai);
			//===di chuyen trong menu===//
			switch(pos){
				
				case 1:{
						veKhung(650, 250, KhungDauSach[3], 1, NEN_TEXT, WHITE);
						Nhap(830,250,-1, key, tmp->ISBN,14);
						break;
					}
				case 2:{
						veKhung(650, 340, KhungDauSach[4], 1, NEN_TEXT, WHITE);
						Nhap(830,340,2, key, tmp->Tensach, 24);
						break;
					}
				case 3:{
						veKhung(650, 430, KhungDauSach[5], 1, NEN_TEXT, WHITE);
						Nhap(830,430,0, key, tMpst,7);
						break;
					}
				case 4:{
						veKhung(650, 520, KhungDauSach[6], 1, NEN_TEXT, WHITE);
						Nhap(830,520,2, key, tmp->Tacgia,24);
						break;
					}
				case 5:{
						veKhung(650, 610, KhungDauSach[7], 1, NEN_TEXT, WHITE);
						Nhap(830,610,0, key, tMpnxb,4);
						break;
				}
				case 6:{
						veKhung(650, 700, KhungDauSach[8], 1, NEN_TEXT, WHITE);
						Nhap(830,700,2, key, tmp->Theloai,24);
						break;
				}
				case 7:	{
						// Them dau sach
						bool buttonL = 1;
						veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
						while(1)
						{
							if(kbhit())
							{
								char key5 = getch();
								char c5Next;
								if (key5 == 0)
								{
									c5Next = getch();
									switch(c5Next)
									{
										case KEY_UP:
											{
												pos--;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:
											{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:
											{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r')
								{
									//return;
									if (buttonL == 1)
									{
										if(strlen(tmp->ISBN)!=0 && strlen(tMpnxb)!=0 && strlen(tMpst)!=0 && strlen(tmp->Tacgia)!=0 && strlen(tmp->Tensach)!=0 && strlen(tmp->Theloai)!=0)
										{
											selected = true;
											tmp->Namxb = ChangeCharToNum(tMpnxb);
											tmp->Sotrang = ChangeCharToNum(tMpst);
											return;
										}
										else
										{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else
									{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27)
								{
									VeMenu();
									return;
								}
								veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
							}
						}
					}
				}
			}
		}
}

void danhSachchinhthongtinDs(DSDS &dsds){
	//tao mang 1 chieu
//	sortEmp(ListEmployees.nodeListEmp, 0, ListEmployees.n-1);
	
	int choosePos = 0;
	int page = 1;
	bool select;
	while(1){
		chonTuDanhSach(dsds, choosePos, page, select);
		if(select){
			struct Dausach *tmpD;
			tmpD = dsds.nodes[choosePos];
			
			char tmpst[8];
			char tmpnxb[5];
			strcpy(tmpst,toChars(tmpD->Sotrang));
			strcpy(tmpnxb,toChars(tmpD->Namxb));	
			
			struct Dausach recoverD;
			
			char tmpstD[8];
			char tmpnxbD[5];
			strcpy(tmpstD,toChars(tmpD->Sotrang));
			strcpy(tmpnxbD,toChars(tmpD->Namxb));
			
			strcpy(recoverD.ISBN, tmpD->ISBN);
			strcpy(recoverD.Tensach, tmpD->Tensach);
			strcpy(tmpstD, toChars(tmpD->Sotrang));
			strcpy(recoverD.Tacgia, tmpD->Tacgia);
			strcpy(tmpnxbD, toChars(tmpD->Namxb));
			strcpy(recoverD.Theloai, tmpD->Theloai);
			
			
			bool saved = false;
			chinhThongTinDS(KhungDauSach, dsds,tmpD, saved);
			if (!saved){
				//
				char tmpst[8];
				char tmpnxb[5];
				strcpy(tmpst,toChars(tmpD->Sotrang));
				strcpy(tmpnxb,toChars(tmpD->Namxb));
				
				char tmpstD[8];
				char tmpnxbD[5];
				strcpy(tmpstD,toChars(tmpD->Sotrang));
				strcpy(tmpnxbD,toChars(tmpD->Namxb));
				
				strcpy(tmpD->ISBN, recoverD.ISBN);
				strcpy(tmpD->Tensach, recoverD.Tensach);
				strcpy(tmpstD, tmpst);
				strcpy(tmpD->Tacgia, recoverD.Tacgia);
				strcpy(tmpnxbD, tmpnxb);
				strcpy(tmpD->Theloai, recoverD.Theloai);
			}
			else{
				ThongBao(1140, 165, Success[2], GREEN, MAU_MENU);
				
			}
		}
		else{
			break;
		}
	}
	VeMenu();
}

void chinhSuaDausach(DSDS &ListDausach){
	bool entered = false;
	do{
		bool chooseList = false;
		char tmpISBN[15];
		VeKhungxoaDausach(KhungXoa, ListDausach, chooseList, tmpISBN, entered);
		if (entered){
			if (chooseList){
				return danhSachchinhthongtinDs(ListDausach);
			}
			else{
				struct Dausach *tmpD;
				tmpD = ListDausach.Search_ISBN(tmpISBN);
				if(tmpD == NULL){
					//loi ko ton tai
					ThongBao(1180, 310, Fail[1], LIGHTRED, MAU_MENU);
				}
				else{	
					
					char tmpst[8];
					char tmpnxb[5];
					strcpy(tmpst,toChars(tmpD->Sotrang));
					strcpy(tmpnxb,toChars(tmpD->Namxb));
					
					char tmpstD[8];
					char tmpnxbD[5];
					strcpy(tmpstD,toChars(tmpD->Sotrang));
					strcpy(tmpnxbD,toChars(tmpD->Namxb));
				
					// tao bien de khoi phuc
					struct Dausach recoverD;
					strcpy(recoverD.ISBN, tmpD->ISBN);
					strcpy(recoverD.Tensach, tmpD->Tensach);
					strcpy(tmpstD, tmpst);
					strcpy(recoverD.Tacgia, tmpD->Tacgia);
					strcpy(tmpnxbD, tmpnxb);
					strcpy(recoverD.Theloai, tmpD->Theloai);
					
					bool saved = false;
					chinhThongTinDS(KhungDauSach, ListDausach, tmpD, saved);
					if (!saved){
						char tmpnxb[5];
						strcpy(tmpst,toChars(tmpD->Sotrang));
						strcpy(tmpnxb,toChars(tmpD->Namxb));
						
						char tmpstD[8];
						char tmpnxbD[5];
						strcpy(tmpstD,toChars(tmpD->Sotrang));
						strcpy(tmpnxbD,toChars(tmpD->Namxb));
						
						strcpy(tmpD->ISBN, recoverD.ISBN);
						strcpy(tmpD->Tensach, recoverD.Tensach);
						strcpy(tmpst,tmpstD);
						strcpy(tmpD->Tacgia, recoverD.Tacgia);
						strcpy(tmpnxb, tmpnxbD);
						strcpy(tmpD->Theloai, recoverD.Theloai);
						
					}
					else{
						ThongBao(1140, 165, Success[2], GREEN, MAU_MENU);
					}
				}
			}
			VeMenu();
		}
	}while(entered);
}

//======Danh muc sach=======//

void chondanhMucsach(DSDS &ListDausach, pDMS &Dms);
void VeMenudms(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start);
void MenuDms(DSDS &dsds, char menu[][30], int MAXMENU, int &chonMuc);
// bang ben trai
void inTrangDms(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start){ 
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	20;
	int U = 100;
	int R =	1180;
	int D =	870;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 22; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = dsds.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		inDausach(dsds.nodes[i], disW, dis);		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}
// in danh sach
void Vekhungdanhmucsach(DSDS &dsds, int &stt, int &startPage, bool &selected){
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(dsds.n*1.0/OBJ_PER_PAGE); // lam tron so 
	if (limitPage == 0){
		noti(Fail[2]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W=1160;
		int U = 100;
		int L =	350;
		
		int x = 20, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		/*int L =	350;
		int U = 100;
		int R =	1510;
		int D =	895;*/
				
		inTrangDms(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
		showPage(1040, 880, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDms(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1040, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDms(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1040, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), dsds.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > dsds.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					VeMenu();
					break;
				}
				else if (key == '\r'){
					selected = true;
					
					return;
				}
			}
		}
	}
}

void veKhungNut1(char khungNoiDung[][30], bool Left, bool reset, int n){
int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L =	1245;
	int U = 150;
	int R =	1820;
	int D =	750;
	
	int H = 450;
	int W = 600;
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	// In info khung
	/*setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);*/
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	/*setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);*/
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, (L+R)/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	} else{
		bar ((L+R)/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,(L+R)/2,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);					//center line
	
}

void VekhungnhapSach(DSDS &dsds,int apos, List &l){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	
	int L = 1200;
	int U = 471;
	int R = 1890;
	int D = 870;
	
	setfillstyle(SOLID_FILL,NEN_KHUNG);
	bar(L,U,R,D);
	
	
	// Vi trí 2 nut cuoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (1245, 750-kichThuocNut, 1820, 750);
	
	int midText1 = (575/2 - textwidth(KhungDauSach[1]))/2;
	int midText2 = (575/2 - textwidth(KhungDauSach[2]))/2;
	int midTextH = (kichThuocNut - textheight(KhungDauSach[1]))/2 + textheight(KhungDauSach[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	setbkcolor(NEN_KHUNG);
	outtextxy(1245+midText1, 750-midTextH, KhungDauSach[1]);
	outtextxy((3065/2)+midText2, 750-midTextH, KhungDauSach[2]);
	setcolor(BLACK);
	rectangle(1245,750-kichThuocNut,(3065)/2,750);
	rectangle((3065)/2,750-kichThuocNut,1820,750);
	int tmp;
	int pos=2;
	for(int i=1; i<=3; i++){
		if(i==2){
			veKhung(1245,ViTrichuDms[i],danhSachDanhmucsach[i],1,NEN_TEXT,WHITE);
		} else {
			veKhung(1245,ViTrichuDms[i],danhSachDanhmucsach[i],0,NEN_TEXT,WHITE);
		}
	}
	Sach tmpD;
	strcpy(tmpD.Masach,toChars(l.rdMS(2)));
	// Di chuyen trong menu
	while(1){	
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 1)
					pos = 4;
				if (pos > 4){
						pos = 2;
				}
			}
			else if (key == '\r'){
				if (pos <= 4)  //enter xuong o moi
					pos++;
//				else
//					return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			for(int i=1; i<=3; i++){
				veKhung(1245,ViTrichuDms[i],danhSachDanhmucsach[i],0,NEN_TEXT,WHITE);
			}
			
			char tmptt[5];	
					
			strcpy(tmptt,toChars(tmpD.Trangthai));
												
			InThongTin(1425,550,tmpD.Masach);
			InThongTin(1425,605,tmptt);
			InThongTin(1425,660,tmpD.Vitri);
			switch(pos){
				case 1:{
					veKhung(1245,550,danhSachDanhmucsach[1],1,NEN_TEXT,WHITE);
					InThongTin(1425,550,tmpD.Masach);
					break;
				}
				case 2:{
					veKhung(1245,605,danhSachDanhmucsach[2],1,NEN_TEXT,WHITE);
					Nhap(1425,605,2,key,tmptt,5);
					break;
				}
				case 3:{
					veKhung(1245,660,danhSachDanhmucsach[3],1,NEN_TEXT,WHITE);
					Nhap(1425,660,2,key,tmpD.Vitri,29);
					break;
				}
				case 4:{
						// Them sach
					
						bool buttonL = 1;
						veKhungNut1(KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit()){
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut1(KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut1( KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){	
//									return;
									if (buttonL == 1){
										if(strlen(tmpD.Masach)!=0 && strlen(tmpD.Vitri)!=0){ 
											//
											dsds.addsach(apos, tmpD);
											dsds.nodes[apos]->soluong++;
											ThongBao(1500,500,Success[0],GREEN,NEN_KHUNG);
											return;
										}
										else
										{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									
									else{	
//										chondanhMucsach(dsds, Dms);
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									return;
								}
								veKhungNut1( KhungNoiDung, buttonL, 0,1);
							}
						}			
					}
				}				
			}
		}
	}

void BatMuc(int sttmenu, char menu[][30], int HL_COLOR, int C_SIZE){
	// * Ve cac muc duoc chon
	setbkcolor(HL_COLOR);
	setfillstyle(SOLID_FILL, HL_COLOR);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 3);
	
	// Highlight muc menu 
	bar(1440,ViTrimucmenu[sttmenu], 1680, 55+ViTrimucmenu[sttmenu]);
	rectangle(1440,ViTrimucmenu[sttmenu], 1680, 55+ViTrimucmenu[sttmenu]);
	
	outtextxy(1535, ViTrichuDms[sttmenu], menu[sttmenu-1]);
	settextstyle(COMPLEX_FONT, 0, 2);
	}

void VeMenudms(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 3; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	//tinh kich thuoc khung
	int L =	1200;
	int U = 100;
	int R =	1890;
	int D =	870;

	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 4; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D/2+36);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 10; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	settextstyle(COMPLEX_FONT,0,3);
	for(int i=0; i<3; i++){
		outtextxy(1535, ViTrichuDms[i+1], khungdms[i]);
		setcolor(BLACK);
		rectangle(1440,ViTrimucmenu[i+1], 1680, 55+ViTrimucmenu[i+1]);
		setcolor(WHITE);
	}
	settextstyle(COMPLEX_FONT,0,2);
	// in thong tin
	/*setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = dsds.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		inDausach(dsds.nodes[i], disW, dis);
		
		dis += h+5;
	}*/
	
}

void MenuDms(DSDS &dsds, char menu[][30], int MAXMENU, int &chonMuc){
	chonMuc = 1;
	bool select;
	int removePos = 0;
	int page = 1;
	BatMuc(1,menu, HL_MENU_PHU, 2);
	while(1){
		if(kbhit()){
			VeMenudms(dsds,danhSachDanhmucsach,sizeDanhmucsach,1);
			char key = getch();
			if(key == 0){
				char cNext = getch();
				switch(cNext){
					case KEY_UP:{
						chonMuc--;
						break;
					}
					case KEY_DOWN: {
						chonMuc++;
						break;
					}
					default:{
							VeMenu();
							chonMuc = -1;
							return;
						}
				}
				if (chonMuc > 3)
					chonMuc = 1;
				if (chonMuc < 1)
					chonMuc = 3;
			}
			else if (key == '\r'){
				return VeMenudms(dsds,danhSachDanhmucsach,sizeDanhmucsach,1);
			}
			else if (key == 27){
				chonMuc = -1;
				VeMenudms(dsds,danhSachDanhmucsach,sizeDanhmucsach,1);
				return;
			}
			BatMuc(chonMuc, menu, HL_MENU_PHU, 2);
		}
	}
}

/*void addDms(DSDS &dsds, pDMS &Dms){
	bool entered=false;
	do{
		Sach tmpD;
		
		VekhungnhapSach(dsds,tmpD,entered);
		if(entered){
//			InsertDms_last(First,tmpD);
			
//			chondanhMucsach(dsds,Dms);
			break;
		} else {
			break;
		}
	}while(entered);
	VeMenu();
}*/

/*void chondanhMucsach(DSDS &ListDausach,int &pos, List &l){
	int thaotac;
	VeMenudms(ListDausach,danhSachDanhmucsach,sizeDanhmucsach,1);
	MenuDms(ListDausach,khungdms,3,thaotac);
	switch(thaotac){
		case 1:{
			return VekhungnhapSach(ListDausach, pos, l); //addDms(ListDausach, Dms); // test fix?
			break;
		}
		
	}		
}*/

void DanhMucsach(DSDS &ListDausach, List &l){
	bool select;
	int addPos = 0;
	int page = 1;
	while(1){
		Vekhungdanhmucsach(ListDausach,addPos,page,select);
		VeMenudms(ListDausach,danhSachDanhmucsach,sizeDanhmucsach,1);
		if(select){
//			chondanhMucsach(ListDausach,addPos, l);
			VekhungnhapSach(ListDausach, addPos, l);
		}else{
			break;
		}
		
	} 
	VeMenu();
}

//========Doc gia========//
void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu){
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 275;
	int rad = H/2-2;
	int dis1 = 180;
	int dis2 = 320;
	outtextxy(x+dis2+H, y, noiDungMucChon[1]);
	outtextxy(x+dis1+H, y, noiDungMucChon[0]);
	setfillstyle(SOLID_FILL, GREEN);
	
	if (chonTrai){
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, GREEN);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	else{
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, GREEN);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	
	setfillstyle(SOLID_FILL, TEXTBOX);
}

void VeKhungthemDocgia(char khungNoiDung[][30], int ViTriKhung[]){
//	selected = false;
	int soLuongKhung = 5;
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	//khung
	rectangle(L-1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			if (i == 1) // 650
				veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
			else
				veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else{
			veMuc2Chon(650, ViTriKhung[i], khungNoiDung[7], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
	
	int pos = 1;
	bool seX;
	int fst = seX;			//SEX
	/*char ID[5];
	char firstName[30];
	char lastName[20];
	char sex[5];*/
	//in thong tin
	/*InThongTin(560, ViTriKhung[1], ID);
	InThongTin(560, ViTriKhung[2], firstName);
	InThongTin(560, ViTriKhung[3], lastName);
	veMuc2Chon(380, 380, khungNoiDung[6], Sex, sex, NEN_KHUNG, WHITE);*/
	while(1)
	{
		if(kbhit())
		{
			char key = getch();
			char cNext;
			if (key == 0)
			{
				cNext = getch();
				switch(cNext)
				{
					case KEY_UP:
						{
							pos--;
							break;
						}
					case KEY_DOWN:
						{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 0)
					pos = 6;
				if (pos > 6)
					pos = 1;
			}
			else if (key == '\r')
			{
				if (pos <= 5)
					pos++;
			}
			else if (key == 27)
			{
				//VeMenu();
				return;
			}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 5; i++)
			{
				if (i != 5)
					veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
				else
					veMuc2Chon(650, ViTriKhung[5], khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
				setcolor(WHITE);
			}
			/*setbkcolor(NEN_TEXT);
			InThongTin(560, ViTriKhung[1], ID);
			InThongTin(560, ViTriKhung[2], firstName);
			InThongTin(560, ViTriKhung[3], lastName);*/
			switch(pos)
			{
				case 1:
					{
						veKhung(650, 250, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
//						Nhap(560, 200, -1, key, ID, 10);
						break;
					}
				case 2:
					{
						veKhung(650, 340, khungNoiDung[4], 1, NEN_KHUNG, WHITE);
//						Nhap(560, 260, 1, key, firstName, 25);
						break;
					}
				case 3:
					{
						veKhung(650, 430, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
//						Nhap(560, 320, 1, key, lastName, 25);
						break;
					}
				case 4:{
					veKhung(650, 520, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
					break;
				}
				case 5:
					{
						veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
						while(1)
						{
							if (kbhit())
							{
								char key4 = getch();
								if (key4 == 0)
								{
									char c4Next = getch();
									switch(c4Next)
									{
										case KEY_LEFT:
											{
												fst++;
												break;
											}
										case KEY_RIGHT:
											{
												fst--;
												break;
											}
										case KEY_UP:
											{
												pos--;
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												goto cpos;
											}
									}
								}
								else if (key4 == '\r')
								{
									pos++;
									goto cpos;
									break;
								}
								else if (key4 == 27)
								{
									return;
								}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
//								sex = fst;
							}
						}
						break;
					}
				case 6:
					{
						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
						while(1)
						{
							if(kbhit())
							{
								char key5 = getch();
								char c5Next;
								if (key5 == 0)
								{
									c5Next = getch();
									switch(c5Next)
									{
										case KEY_UP:
											{
												pos--;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:
											{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:
											{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r')
								{
									return;
									/*if (buttonL == 1)
									{
										if(strlen(tmpE->ID) != 0 && strlen(tmpE->firstName) != 0 && strlen(tmpE->lastName) != 0)
										{
											selected = true;
											return;
										}
										else
										{
											ThongBao(780, 130, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else
									{
										VeMenu();
										return;
									}*/
								}
								else if (key5 == 27)
								{
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
							}
						}
					}
			}
		}
	}
}

void addDocgia(){
	bool selected = false;
	
		VeKhungthemDocgia(KhungDocgia,ViTriKhungDocGia);		
	
}














