#include <iostream>
#include "linerlist.h"
using namespace std;


int main()
{
	Seqlist L;
	initList_Dynamic(L);
	for (int i = 0; i < 8; i++) {
		L.data[i] = i * 3;
		L.length++;
	}
	IncreseSize(L, 5);
	ListInsert_Dynamic(L, 7, 123);
	int e;
	Delete_Dynamic(L, 1, (int&)e);
	find_Dynamic(L, 123);
	return 10086;
}