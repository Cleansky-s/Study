#ifndef liner
#define liner
#define InitSize 10
#define MaxSize 10

#include <stdlib.h>

typedef struct {
	int data[MaxSize];
	int length;
}SqList;

typedef struct {
	int* data;
	int Maxsize;
	int length;

}Seqlist;

void initList(SqList& X);
void initList_Dynamic(Seqlist& L);
void IncreseSize(Seqlist& L, int len);
bool ListInsert(SqList& X, int i, int e);
bool ListInsert_Dynamic(Seqlist& L, int i, int e);
bool Delete_Dynamic(Seqlist& L, int i, int& e);
int find_Dynamic(Seqlist L, int e);
#endif // !liner 
