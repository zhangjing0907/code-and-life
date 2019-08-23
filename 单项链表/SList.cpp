#include "SList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

//初始化
void SListinit(SList* s) {
	assert(s);
	s->_pHead = NULL;
}
//购买节点
PNode BuynewNode(SDataType data) {
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_PNext = NULL;
	return pNewNode;
}
//尾插
void PushBack(SList* s, SDataType data) {
	assert(s);
	PNode pNewNode = BuynewNode(data);
	if (s->_pHead == NULL) {
		s->_pHead = pNewNode;
	}
	else {
		PNode pcur = s->_pHead;
		while (pcur->_PNext) {
			pcur = pcur->_PNext;
		}
		pcur->_PNext = pNewNode;
	}
}
//尾删
void PopBack(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {
		return;
	}
	else if (s->_pHead->_PNext == NULL) {
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {
		PNode pcur = s->_pHead->_PNext;
		PNode ppur = s->_pHead;
		while (pcur->_PNext) {
			pcur = pcur->_PNext;
			ppur = ppur->_PNext;
		}
		free(pcur);
		ppur->_PNext = NULL;
	}
}
//头插
void PushFront(SList* s, SDataType data) {
	assert(s);
	PNode pNewNode = BuynewNode(data);
	if (s->_pHead == NULL) {
		s->_pHead = pNewNode;
	}
	pNewNode->_PNext = s->_pHead;
	s->_pHead = pNewNode;
}
//头删
void PopFront(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {
		return;
	}
	else if (s->_pHead->_PNext == NULL) {
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {
		PNode pcur = s->_pHead;
		s->_pHead = pcur->_PNext;
		free(pcur);
	}
}
//在pos位置插入
void SeqListInsert(SDataType data, PNode pos) {
	if (pos == NULL) {
		return;
	}
	else {
		PNode pNewNode = BuynewNode(data);
		pNewNode->_PNext = pos->_PNext;
		pos->_PNext = pNewNode;
	}
}
//删除pos位置的节点
void SListErase(SList* s, PNode pos) {
	assert(s);
	if (pos == NULL) {
		return;
	}
	if (pos == s->_pHead) {
		PNode pcur = s->_pHead;
		s->_pHead = pcur->_PNext;
		free(s->_pHead);
	}
	else {
		PNode ppur = s->_pHead;
		while (ppur->_PNext != pos) {
			ppur = ppur->_PNext;
		}
		ppur->_PNext = pos->_PNext;
		free(pos);
	}
}
//寻找值为data的元素
PNode SListFind(SList* s, SDataType data) {
	assert(s);
	PNode pcur = s->_pHead;
	while (pcur) {
		if (pcur->_data == data) {
			return pcur;
		}
		pcur = pcur->_PNext;
	}
}

//删除值为data的元素
void Datadelete(SList* s,SDataType data) {	
	assert(s);
	PNode pcur = s->_pHead->_PNext;
	PNode ppur = s->_pHead;
	if (s->_pHead == NULL) {
		return;
	}	
	while (ppur == SListFind(s, data)) {
		s->_pHead = ppur->_PNext;
		free(ppur);
		ppur = ppur->_PNext;
		pcur = pcur->_PNext;
	}
	while(pcur->_PNext) {
		if (pcur == SListFind(s, data)) {
			ppur->_PNext = pcur->_PNext;
			free(pcur);
			pcur = ppur->_PNext;			
		}
		else {
			ppur = pcur;
			pcur = pcur->_PNext;		
		}
	}
}

//计算有效节点
int SListSize(SList* s) {
	assert(s);
	PNode pcur = s->_pHead;
	int count = 0;
	while (pcur) {
		count++;
		pcur = pcur->_PNext;
	}
	return count;
}
//判空
int SListEmpty(SList* s) {
	if (s->_pHead == NULL) {
		return -1;
	}
	return 0;
}
//清空链表
void SListClear(SList* s) {
	if (s->_pHead == NULL) {
		return;
	}
	else if (s->_pHead->_PNext == NULL) {
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {
		PNode pcur = s->_pHead->_PNext;
		PNode ppur = s->_pHead;
		while (pcur->_PNext) {
			ppur->_PNext = pcur->_PNext;
			free(pcur);
		}
		free(s->_pHead);
		s->_pHead = NULL;
		free(pcur);
	}
}
//销毁链表
void SListDestroy(SList* s) {//销毁链表
	assert(s);
	if (s->_pHead == NULL) {
		free(s->_pHead);
		return;
	}
	while (s->_pHead) {
		PNode Tmp = s->_pHead->_PNext;
		free(s->_pHead);
		s->_pHead = Tmp;
	}
}
//打印链表
void SListPrint(SList* s) {
	assert(s);
	PNode pcur = s->_pHead;
	while (pcur) {
		printf("%d ", pcur->_data);
		pcur = pcur->_PNext;
	}
	printf("\n");
}

void main() {
	SList s;
	SListinit(&s);
	PushBack(&s, 1);
	PushBack(&s, 2);
	PushBack(&s, 4);
	PushBack(&s, 5);
	SListPrint(&s);
	PushBack(&s, 6);
	SListPrint(&s);
	PopBack(&s);
	SListPrint(&s);
	PushFront(&s, 0);
	SListPrint(&s);
	Datadelete(&s, 4);
	SListPrint(&s);
	Datadelete(&s, 0);
	SListPrint(&s);
	SListDestroy(&s);
	//TestSList();
	return;
}