#include <iostream>
#include <stdlib.h>
#define InitSize 10
#define MaxSize 10

typedef struct {
	int *data;
	int Maxsize;
	int length;

}Seqlist;


void initList_Dynamic(Seqlist& L) {
	L.data = (int*)malloc(InitSize * sizeof(int)); //分配内存
	L.Maxsize = InitSize;//根据InitSize分配最大尺寸
	L.length = 0; //初始化长度
}

void IncreseSize(Seqlist& L, int len) {
	int* p = L.data; //指向L.data数据
	L.data = (int*)malloc((L.Maxsize + len) * sizeof(int)); //重新分配内存
	for (int i = 0; i < L.length; i++) {   //
		L.data[i]=p[i]; //将数据重新复制
	}
	L.Maxsize = L.Maxsize + len;
	free(p);
}

bool ListInsert_Dynamic(Seqlist& L, int i, int e) {
	if (i < 1 || i>L.length + 1) { //确认是否超出长度
		return false;
	}
	if (L.length >= L.Maxsize) {  //确认是否超出大小
		return false;
	}
	for (int j = L.length; j >= i; j--) //将大于插入键【i】后的数据往后挪一位
		L.data[j] = L.data[j - 1];
		L.data[i - 1] = e; //因为数组是从零算起的
		L.length++;//增加长度
	return true;
}

bool Delete_Dynamic(Seqlist& L, int i, int& e) {
	if (i < 1 || i>L.length + 1) {//确认是否超出长度
		return false;
	}
	if (L.length >= L.Maxsize +1) {//确认是否超出大小
		return false;
	} 
	e = NULL;//确认e值为NULL
	L.data[i-1] = e;//删除i-1
	return true;
}

int find_Dynamic(Seqlist L, int e) {
	int i = 0; 
	for (int i = 0; i <= InitSize;i++) { //确认I值
		if ((int&)L.data[i] == e) {
			std::cout << "the value is in the list: " << i;//输出线列表中的顺序
			break;
		}
	}
	return 0;
}