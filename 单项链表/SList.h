#pragma once
typedef int SDataType;

typedef struct SListNode {
	SDataType _data;
	struct SListNode* _PNext;
}Node, * PNode;

//����Ľṹ����һ��ͷָ�뱣�������еĵ�һ���ڵ�
typedef struct SList {
	PNode _pHead;//ָ�������еĵ�һ���ڵ�
}SList, * PList;

void SListinit(SList* s);//��ʼ��
PNode BuynewNode(SDataType data);//�����½ڵ�
void PushBack(SList* s, SDataType data);//β��
void PopBack(SList* s);//βɾ
void PushFront(SList* s, SDataType data);//ͷ��
void PopFront(SList* s);//ͷɾ
void SeqListInsert(SDataType data, PNode pos);//��posλ�ò���ֵΪdata��Ԫ��
void SListErase(SList* s, PNode pos);//ɾ��posλ�õ�Ԫ��
PNode SListFind(SList* s, SDataType data);//����ֵΪdata��Ԫ��
void Datadelete(SList* s, SDataType data);//ɾ��ֵΪdata��Ԫ��
int SListSize(SList* s);//��Ԫ�ظ���
int SListEmpty(SList* s);//�п�
void SListClear(SList* s);//�������
void SListDestroy(SList* s);//��������
void SListPrint(SList* s);//��ӡ����
