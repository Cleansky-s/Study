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
	L.data = (int*)malloc(InitSize * sizeof(int)); //�����ڴ�
	L.Maxsize = InitSize;//����InitSize�������ߴ�
	L.length = 0; //��ʼ������
}

void IncreseSize(Seqlist& L, int len) {
	int* p = L.data; //ָ��L.data����
	L.data = (int*)malloc((L.Maxsize + len) * sizeof(int)); //���·����ڴ�
	for (int i = 0; i < L.length; i++) {   //
		L.data[i]=p[i]; //���������¸���
	}
	L.Maxsize = L.Maxsize + len;
	free(p);
}

bool ListInsert_Dynamic(Seqlist& L, int i, int e) {
	if (i < 1 || i>L.length + 1) { //ȷ���Ƿ񳬳�����
		return false;
	}
	if (L.length >= L.Maxsize) {  //ȷ���Ƿ񳬳���С
		return false;
	}
	for (int j = L.length; j >= i; j--) //�����ڲ������i�������������Ųһλ
		L.data[j] = L.data[j - 1];
		L.data[i - 1] = e; //��Ϊ�����Ǵ��������
		L.length++;//���ӳ���
	return true;
}

bool Delete_Dynamic(Seqlist& L, int i, int& e) {
	if (i < 1 || i>L.length + 1) {//ȷ���Ƿ񳬳�����
		return false;
	}
	if (L.length >= L.Maxsize +1) {//ȷ���Ƿ񳬳���С
		return false;
	} 
	e = NULL;//ȷ��eֵΪNULL
	L.data[i-1] = e;//ɾ��i-1
	return true;
}

int find_Dynamic(Seqlist L, int e) {
	int i = 0; 
	for (int i = 0; i <= InitSize;i++) { //ȷ��Iֵ
		if ((int&)L.data[i] == e) {
			std::cout << "the value is in the list: " << i;//������б��е�˳��
			break;
		}
	}
	return 0;
}