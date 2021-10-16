#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <map>
#define Maxdausach 10000
#define maxN 99999
#define minN 10000
map<int, bool> vis;

using namespace std;
// Cau truc danh muc sach: Danh sach lien ket don.
struct Sach {
	char Masach[20];
	int Trangthai; // 0: cho muon dc; 1: da co nguoi muon; 2: sach da thanh ly
	char Vitri[30];
	Sach() {
		Vitri[0] = '\0';
	}
};
struct nodeSach{//Đây là sách 
	Sach sach;//?????? / đây là data của 1 nodeSach. 
	nodeSach *next;//Testvscode
}; //testvscode
typedef struct nodeSach *pDMS;//testvscode
// day la test
// day la test
struct list{
	pDMS *phead ;
	pDMS *ptail ;
	list(){
		phead = NULL;
		ptail = NULL;
	}

};
typedef struct nodeSach* pDMS;

struct List {
	pDMS First = NULL;
	pDMS Tail = NULL;
	int n = 0;
	void Insert(Sach& news) {
		pDMS tmp = new nodeSach;
		tmp->sach = news;
		if (!(First && Tail)) {
			First = Tail = tmp;
		}
		else {
			Tail->next = tmp;
			Tail = tmp;
		}
		n++;
	}
};


// Cau truc dau sach: Danh sach tuyen tinh.
struct Dausach {
	char ISBN[15];
	char Tensach[25];
	unsigned int Sotrang;
	char Tacgia[25];
	unsigned int Namxb;
	char Theloai[30];
	struct List dms;
	int soluong; // so luong sach moi dau sach
	Dausach() {
		ISBN[0] = '\0';
		Tensach[0] = '\0';
		Tacgia[0] = '\0';
		Theloai[0] = '\0';
		soluong = 0;
	}
};

struct DS_Dausach {
	int n;
	Dausach* nodes[Maxdausach];

	DS_Dausach() {
		n = 0;
	}
	struct Dausach* Search_ISBN(char tmpISBN[15]) {
		for (int i = 0; i < n; i++) {
			if (strcmp(nodes[i]->ISBN, tmpISBN) == 0) {
				return nodes[i];
			}
		}
		return NULL;
	}
	void addsach(int pos, Sach& newsach) {
		struct Dausach* p = nodes[pos];
		char tmp[20];
		string s = to_string(p->dms.n);
		strcpy(tmp, p->ISBN);
 		strcat(tmp, s.c_str());
		strcpy(newsach.Masach, tmp);
		p->dms.Insert(newsach);
	}
}; typedef struct DS_Dausach DSDS;





/*pDMS *p = new pDMS;
DSDS.nodes[stt]->dms->sach;*/

//=== Them dau sach
// insert last
int isFull(DSDS& dsds) {
	return dsds.n == Maxdausach;
}
void Insert(DSDS& dsds, struct Dausach* newnodes) {
	if (isFull(dsds)) {
		dsds.nodes[dsds.n] = newnodes;
		dsds.n++;
	}
	/*int j;
  for(j = dsds.n-1; j >= l; j--)
	  dsds.nodes[j+1] = dsds.nodes[j];
  dsds.nodes[l] = newnodes;
  dsds.n ++;*/
}

int Search_info(DSDS& dsds, struct Dausach* info) {
	for (int i = 0; i < dsds.n; i++) {
		if (strcmp(dsds.nodes[i]->ISBN, info->ISBN) == 0) {
			return i;
		}
	}
	return -1;
}

void DeleteDs(DSDS& dsds, int pos) {
	int j;
	//if(i < 0 || i >= plist.n || plist.n==0) return 0;
	for (j = pos + 1; j < dsds.n; j++)
		dsds.nodes[j - 1] = dsds.nodes[j];
	dsds.n--;

}
void DeleteISBN(DSDS& dsds, char tmpISBN[15]) {
	for (int i = 0; i < dsds.n; i++) {
		if (strcmp(dsds.nodes[i]->ISBN, tmpISBN) == 0) {
			DeleteDs(dsds, i);
			break;
		}
	}
}

// Cau truc muon tra: Danh sach lien ket don.
struct DMY {
	int ngay;
	int thang;
	int nam;
};
struct Muontra {
	char Masach[20];
	DMY Ngaymuon[2];
	DMY Ngaytra[2];
	int Trangthai; // 0: dang muon; 1: da tra; 2: lam mat sach(da thanh ly)	
};
struct NodeMuontra {
	Muontra muontra;
	Muontra* next;
};
// Cau truc doc gia: Cay nhi phan tim kiem.
struct Docgia {
	int Mathe;
	char Ho[30];
	char Ten[20];
	bool Phai; // Nam, Nu.
	int Trangthai; // 0: Khoa, 1: Hoat dong
	NodeMuontra* dsmuon = NULL;
	int soSach;
	void suaDocgia(char* Ho,char* Ten,bool Phai,int status) {
		strcpy(this->Ho, Ho);
		strcpy(this->Ten, Ten);
		this->Phai = Phai;
		this->Trangthai = status;
	}
	void muonSach(DSDS listsach,char masach[20]) {
		if (!Trangthai) {
			cout << "???????????????????" << endl;
		}
		if (soSach == 3) {
			cout << "?????????????????????";
		}

	}
};
struct NodeDocgia {
	Docgia docgia;
	NodeDocgia* left = NULL;
	NodeDocgia* right = NULL;
};
typedef NodeDocgia* node;
struct TreeDocgia {
	node root;
	node addNode(node tmp, Docgia data) {
		if (tmp == NULL) {
			tmp = new NodeDocgia;
			tmp->docgia = data;
			tmp->left = tmp->right = NULL;
		}
		else if (data.Mathe > tmp->docgia.Mathe) {
			tmp->right = addNode(tmp->right, data);
		}
		else {
			tmp->left = addNode(tmp->left, data);
		}
		return tmp;
	}
	node min(node tmp) {
		if (tmp->left == NULL) return tmp;
		else return min(tmp->left);
	}
	node delNode(node tmp, int mathe) {
		node temp;
		if (tmp == NULL) return tmp;
		else if (mathe > tmp->docgia.Mathe) {
			tmp->right = delNode(tmp->right, mathe);
		}
		else if (mathe < tmp->docgia.Mathe) {
			tmp->left = delNode(tmp->left, mathe);
		}
		else {
			if (tmp->left && tmp->right) {
				temp = min(tmp->right);
				tmp->docgia = temp->docgia;
				tmp->right = delNode(tmp->right, tmp->docgia.Mathe);
			}
			else {
				temp = tmp;
				if (tmp->left == NULL) {
					tmp = tmp->right;
				}
				else {
					tmp = tmp->left;
				}
				delete tmp;
			}
		}
		return tmp;
	}
	int sinhMathe() {
		int r;
		bool check = false;
		while(!check){
			do {
				r = minN + rand() % (maxN + 1 - minN);
			} while (vis.find(r) != vis.end());
			vis[r] = true;
			check = true;
		}
		return r;
	}
	void themDocgia(Docgia data) {
		data.Mathe = sinhMathe();
		data.Trangthai = 1;
		data.soSach = 0;
		root = addNode(root, data);
	}
	void xoaDocgia(int mathe) {
		root = delNode(root, mathe);
	}
};
typedef NodeDocgia ptrDocgia;
ptrDocgia* DS_Docgia = NULL;





// DOC & GHI FILE //

void ReadDs(ifstream& file, struct Dausach* p) {
	file.getline(p->ISBN, sizeof(p->ISBN));
	//	file>>p->ISBN;
	file.getline(p->Tensach, sizeof(p->Tensach));
	file >> p->Sotrang;
	file.ignore();
	file.getline(p->Tacgia, sizeof(p->Tacgia));
	file >> p->Namxb;
	file.ignore();
	file.getline(p->Theloai, sizeof(p->Theloai));
}

void WriteDs(ofstream& file, struct Dausach* p) {
	file << p->ISBN << endl;
	file << p->Tensach << endl;
	file << p->Sotrang << endl;
	file << p->Tacgia << endl;
	file << p->Namxb << endl;
	file << p->Theloai << endl;
}


void SaveDs(DSDS& dsds) {
	ofstream fileDs;
	ofstream logs;
	ofstream fileDms;
	fileDs.open("list_dausach.txt", ios::out);
	fileDms.open("list_dms.txt", ios::out);
	logs.open("Logs.txt", ios::out);
	logs << dsds.n;
	for (int i = 0; i < dsds.n; i++) {
		WriteDs(fileDs, dsds.nodes[i]);
		fileDms << dsds.nodes[i]->soluong << endl;
		struct List tmpL = dsds.nodes[i]->dms;
		for (pDMS node = tmpL.First; node != NULL; node = node->next) {
			fileDms << node->sach.Masach << endl;
			fileDms << node->sach.Trangthai << endl;
			fileDms << node->sach.Vitri << endl;
		}
	}
	fileDs.close();
}

void LoadDs(DSDS& dsds, List& l) {
	ifstream fileDs;
	ifstream fileDms;
	ifstream logs;
	fileDs.open("list_dausach.txt", ios::in);
	fileDms.open("list_dms", ios::in);
	logs.open("Logs.txt", ios::in);
	logs >> dsds.n;
	for (int i = 0; i < dsds.n; i++) {
		dsds.nodes[i] = new Dausach;
		ReadDs(fileDs, dsds.nodes[i]);
		//Dms			
		fileDms >> dsds.nodes[i]->soluong;
	}


	fileDs.close();
}
