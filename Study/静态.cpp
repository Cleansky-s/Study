#include <iostream>
#include <stdlib.h>
#define InitSize 10
#define MaxSize 10

typedef struct {
	int data[InitSize];
	int length;
}SqList;

void initList(SqList& X) {
	for (int i = 0; i < MaxSize; i++) {
		X.data[i] = 0;
		X.length = 0;
	}
}

bool ListInsert(SqList& X, int i, int e) {
	if (i < 1 || i>X.length + 1)
		return false;
	if (X.length >= InitSize)
		return false;
	for (int j = X.length; j >= i; j--) {
		X.data[j] = X.data[j - 1];
		X.data[i - 1] = e;
		X.length++;
	}
	return true;
}