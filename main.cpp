#include "menu.h"
#include "cautrucdulieu.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	KhoiTaoChuongTrinh();
	DSDS ListDausach;
	pDMS Dms;

	LoadDs(ListDausach);
	Menu(ListDausach, Dms);
	getch();
	return 0;
}





