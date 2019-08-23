#pragma once
typedef int SDataType;

typedef struct SListNode {
	SDataType _data;
	struct SListNode* _PNext;
}Node, * PNode;

//链表的结构，给一个头指针保存链表中的第一个节点
typedef struct SList {
	PNode _pHead;//指向链表中的第一个节点
}SList, * PList;

void SListinit(SList* s);//初始化
PNode BuynewNode(SDataType data);//购买新节点
void PushBack(SList* s, SDataType data);//尾插
void PopBack(SList* s);//尾删
void PushFront(SList* s, SDataType data);//头插
void PopFront(SList* s);//头删
void SeqListInsert(SDataType data, PNode pos);//在pos位置插入值为data的元素
void SListErase(SList* s, PNode pos);//删除pos位置的元素
PNode SListFind(SList* s, SDataType data);//查找值为data的元素
void Datadelete(SList* s, SDataType data);//删除值为data的元素
int SListSize(SList* s);//求元素个数
int SListEmpty(SList* s);//判空
void SListClear(SList* s);//清空链表
void SListDestroy(SList* s);//销毁链表
void SListPrint(SList* s);//打印链表
