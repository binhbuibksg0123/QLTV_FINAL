#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#define Maxdausach 10000
using namespace std;
// Cau truc danh muc sach: Danh sach lien ket don.
struct Sach{
	char Masach[20];
	int Trangthai; // 0: cho muon dc; 1: da co nguoi muon; 2: sach da thanh ly
	char Vitri[30];
	Sach(){
		Vitri[0]='\0';
	}
};
struct nodeSach{
	Sach sach;
	nodeSach *next;		
}; 
typedef struct nodeSach *pDMS;

struct List{
	pDMS First=NULL;
		
	void Insert_first(Sach &news){
		pDMS p = new nodeSach;
		p->sach=news;
		p->next=First;
		First=p;	
	}
	
	int rdMS(int pos){
		int s;
		s = rand() % (57-48+1)+48;
		return s;
	}
};
typedef struct List list;


 
// Cau truc dau sach: Danh sach tuyen tinh.
struct Dausach{
	char ISBN[15];
	char Tensach[25];
	unsigned int Sotrang;
	char Tacgia[25];
	unsigned int Namxb;
	char Theloai[30];
	nodeSach *dms=NULL;
	
	struct List listsach;
	int soluong; // so luong sach moi dau sach
	Dausach(){
		ISBN[0]='\0';
		Tensach[0]='\0';
		Tacgia[0]='\0';
		Theloai[0]='\0';
		soluong = 0;
	}
		
};		

struct DS_Dausach{
	int n;
	Dausach *nodes[Maxdausach];	
	
	DS_Dausach(){
		n=0;
	}
	struct Dausach* Search_ISBN(char tmpISBN[15]){
		for(int i=0; i<n; i++){
			if(strcmp(nodes[i]->ISBN, tmpISBN) == 0){
				return nodes[i];
			}
		}
		return NULL;
	}
	
	void addsach(int pos, Sach &newsach){
		struct Dausach *p = nodes[pos];
		p->listsach.Insert_first(newsach);
	}
	
}; typedef struct DS_Dausach DSDS;





/*pDMS *p = new pDMS;
DSDS.nodes[stt]->dms->sach;*/

//=== Them dau sach
// insert last
void Insert(DSDS &dsds, struct Dausach *newnodes){
	  	dsds.nodes[dsds.n]=newnodes;
	  	dsds.n++;
		  /*int j;
		for(j = dsds.n-1; j >= l; j--)
			dsds.nodes[j+1] = dsds.nodes[j];
		dsds.nodes[l] = newnodes;
		dsds.n ++;*/
}

int Search_info(DSDS &dsds, struct Dausach *info){
	for(int i = 0; i<dsds.n; i++){
		if (strcmp(dsds.nodes[i]->ISBN, info->ISBN)==0){                                
			return i;
		}
	}
	return -1;
}

int isFull(DSDS &dsds){
	for(int i=0; i<dsds.n; i++){
		return dsds.n==Maxdausach;
	}
}

void DeleteDs(DSDS &dsds, int pos){
	int j;
	//if(i < 0 || i >= plist.n || plist.n==0) return 0;
	for(j = pos+1;  j< dsds.n ; j++)
		dsds.nodes[j-1] = dsds.nodes[j];
	dsds.n--;

}
void DeleteISBN(DSDS &dsds, char tmpISBN[15]){
	for(int i=0; i<dsds.n; i++){
		if(strcmp(dsds.nodes[i]->ISBN, tmpISBN) == 0){
			DeleteDs(dsds,i);
			break;
		}
	}
}

// Cau truc muon tra: Danh sach lien ket don.
struct DMY{
	int ngay;
	int thang;
	int nam;
};
struct Muontra{
	char Masach[20];
	DMY Ngaymuon[2];
	DMY Ngaytra[2];
	int Trangthai; // 0: dang muon; 1: da tra; 2: lam mat sach(da thanh ly)	
};
struct NodeMuontra{
	Muontra muontra;
	Muontra *next;
};
// Cau truc doc gia: Cay nhi phan tim kiem.
struct Docgia{
	int Mathe;
	char Ho[30];
	char Ten[20];
	bool Phai; // Nam, Nu.
	int Trangthai; // 0: Khoa, 1: Hoat dong
};
struct NodeDocgia{
	Docgia docgia;
	NodeMuontra *dsmuon=NULL;
	NodeDocgia *left=NULL;
	NodeDocgia *right=NULL;
};
typedef NodeDocgia ptrDocgia;
	ptrDocgia *DS_Docgia=NULL;





// DOC & GHI FILE //

void ReadDs(ifstream &file, struct Dausach *p){
	file.getline(p->ISBN,sizeof(p->ISBN));
//	file>>p->ISBN;
	file.getline(p->Tensach, sizeof(p->Tensach));
	file>>p->Sotrang;
	file.ignore();
	file.getline(p->Tacgia, sizeof(p->Tacgia));
	file>>p->Namxb;	
	file.ignore();
	file.getline(p->Theloai, sizeof(p->Theloai));	
}

void WriteDs(ofstream &file, struct Dausach *p){
	file<<p->ISBN<<endl;
	file<<p->Tensach<<endl;
	file<<p->Sotrang<<endl;
	file<<p->Tacgia<<endl;
	file<<p->Namxb<<endl;
	file<<p->Theloai<<endl;
}

void WriteDms(ofstream &file, struct Sach *p){
	file<<p->Masach<<endl;
	file<<p->Trangthai<<endl;
	file<<p->Vitri<<endl;
}

void ReadDms(ifstream &file,  struct Sach p){
//	file>>q.soluong;
	file>>p.Masach;
	file>>p.Trangthai;
	file.ignore();
	file.getline(p.Vitri, sizeof(p.Vitri));
	
}

void SaveDs(DSDS &dsds){
	ofstream fileDs;
	ofstream logs;
	ofstream fileDms;
	fileDs.open("list_dausach.txt", ios::out);
	fileDms.open("list_dms.txt", ios::out);
	logs.open("Logs.txt", ios::out);
	logs<<dsds.n;
	for(int i=0; i<dsds.n; i++){
		WriteDs(fileDs, dsds.nodes[i]);
		fileDms<<dsds.nodes[i]->soluong<<endl;
		 struct List tmpL = dsds.nodes[i]->listsach;
		for(pDMS node=tmpL.First; node != NULL; node = node->next){
//				WriteDms(fileDms, node);
				fileDms<<node->sach.Masach<<endl;
				fileDms<<node->sach.Trangthai<<endl;
				fileDms<<node->sach.Vitri<<endl;
		}
	}
	fileDs.close();
}

void LoadDs(DSDS &dsds){
	Sach *tmp;
	ifstream fileDs;
	ifstream fileDms;
	ifstream logs;
	fileDs.open("list_dausach.txt", ios::in);
	fileDms.open("list_dms", ios::in);
	logs.open("Logs.txt",ios::in);
	logs>>dsds.n;
	for(int i=0; i<dsds.n; i++){
		dsds.nodes[i] = new Dausach;
		ReadDs(fileDs, dsds.nodes[i]);				
	}
/*	while(!fileDms.eof()){
		struct Sach sach;
		ReadDms(fileDms,sach);
		pDMS *p = Khoitaonodesach(sach);
		Insert_last(l, p);
	}*/
	fileDs.close();
}















