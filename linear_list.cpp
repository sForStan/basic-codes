#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 1000
#define OK 1
#define OVERFLOW  -2
#define TURE 1
#define FALSE 0
#define ERROR 0
#define INFEASBLE -1

typedef int Status;
typedef char ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}SqList;
//���Ա�ĳ�ʼ��
Status InitList_Sq(SqList &L)
{
	L.elem = new ElemType[MAXSIZE];//Ϊ˳������ռ�
	if (!L.elem) exit(OVERFLOW);//�������ʧ��
	L.length = 0;//�ձ���Ϊ0
	return OK;
};
//�������Ա�L
void DestroyList(SqList& L)
{
	if (L.elem) delete L.elem;
}
//������Ա�L
void ClearList(SqList& L)
{
	L.length = 0;
}
//�����Ա���
int GetLength(SqList& L)
{
	return (L.length);
}
//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList& L)
{
	if (L.length == 0)
		return 1;
	else return 0;
}
//���Ա��ȡֵ������λ��i��ȡ��Ӧλ�õ�����Ԫ�أ�
int GetElem(SqList L, int i,ElemType &e)
{
	if (i<1 ||i>L.length)return ERROR;//�ж�i��ֵ�Ƿ������������ERROR
	e = L.elem[i - 1];//��i��Ԫ�ش����ŵ�i��Ԫ��
	return OK;
}
//˳���İ�ֵ����
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length ;i++)//����L������ֵΪe��Ԫ��
		if (L.elem[i] == e)
			return i + 1;//���ҳɹ��������
			return 0;//����ʧ�ܷ���0
}//ƽ�����ҳ��� ��N+1��/2
//˳���Ĳ��� 
//������м䣬��ǰ���ڵ�i��λ���ϲ����½ڵ�e��ʹ����Ϊn�����Ա��ȱ�Ϊn+1
Status ListInsert_Sq(SqList& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L.length)return ERROR;//�ж�i��ֵ�Ƿ������������ERROR
	if (L.length==MAXSIZE)return ERROR;//��ǰ����ռ�����
	for (j = L.length - 1; j >= i-1; j--)//����n��Ԫ�أ����һ��Ԫ�ؽǱ���n-1��Ҫ�����λ����i-1
	{
		L.elem[j + 1] = L.elem[j];//����λ�ü�֮���Ԫ�غ���
		L.elem[i - 1] = e;	//����Ԫ��e�����i��λ��
		L.length++;//����1
		return OK;
	}
	//����λ�ú��ƶ������ĺ��ǣ�n+1��
	//����λ��Ϊi���ƶ�����Ϊn+1-i��
	//�ۼ���������ԣ�n+1���ֿ��ܣ�����������Ϊn/2
	//��������㷨���Ӷ�ΪO(n)
}
//���Ա��ɾ��
//ɾ�����Ա�L�е�i��λ�õ�Ԫ����e����
Status ListDelete_Sq(SqList& L, int i)
{
	int j;
	if (i<1 || i>L.length)return ERROR;//�ж�i��ֵ�Ƿ������������ERROR
	for (j = i; j < L.length - 1; j++)//�߼����±��1��i��λ�����������±��i+1
	{
		L.elem[j - 1] = L.elem[j];//��ɾԪ��֮���Ԫ��ǰ��
		L.length--;//����-1
	}
	//����λ�ö�ɾ������N�ֿ���
	//λ�ú��ƶ������ĺ�ΪN����i��Ԫ����Ҫ�ƶ���n-i����
	//�ƶ�������Ϊ��n-1��/2
	//����㷨�ĸ��Ӷ�ΪO(n)
}
/*
������ֻ��һ��ָ����
˫�������������ָ����
ѭ��������β��ӵ�����

ͷָ�룺��ָ�������е�һ������ָ��
ͷ��㣺����Ԫ���֮ǰ�����һ�����
��Ԫ��㣺�����д����һ��Ԫ��a1�Ľ��

��α�ʾ�ձ�
��ͷ���ʱ��ͷָ��Ϊ��ʱΪ�ձ�
��ͷ�ڵ�ʱ��ͷ�ڵ�ָ����Ϊ��Ϊ�ձ�

ͷ������������װʲô��
����ν

������ص�
1���������е�λ���������
2��ֻ��ͨ��ͷָ���������

*/
//�����ʼ��
typedef struct Lnode 
{
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

// �ж������Ƿ�Ϊ��
//�ձ���������Ԫ�أ�ͷָ���ͷ�����Ȼ��
int ListEmpty(LinkList L)
{
	if (L->next)
		return 0;
	else
		return 1 ;
}
//�����������
//��ͷָ�뿪ʼ�������ͷ����н��
Status DestroyList_L(LinkList &L)
{
	Lnode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
}
//�������
//������Ȼ���ڣ���Ϊ������
//�����ͷ����н�㣬����ͷ���ָ��������Ϊ��
Status ClearList(LinkList& L)
{
	Lnode* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
		q = p->next;
	}		
	L->next = NULL;
	return OK;
}
//������ı�
//����Ԫ��㿪ʼ�����μ������н��
int ListLength_L(LinkList L)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
}
//��Ҫ����
//p=Lָ��ͷ���
//s=L->nextָ����Ԫ�ڵ�
//p=p->nextָ����һ�����

//ȡֵ-ȡ�������е�i��Ԫ�ص�ֵ
Status GetElem(LinkList L, int i, ElemType& e)
{
	Lnode* p;
	int j = 1;
	p = L->next;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)//��n��Ԫ�ز�����
		return ERROR;
	e = p->data;
	return OK;
}
//������Ĳ���
//��ֵ����--����ָ�����ݻ�ȡ���������ڵ�λ�ã���ַ��
//�ӵ�һ����㿪ʼ������e�Ƚϣ��ҵ� �򷵻أ�û�ҵ�����0���߷��ؿ�
Lnode* LocateElem_L(LinkList L, ElemType e)
{
	int j;
	Lnode* p;
	p = L->next;
	while (p&&p->data!=e)
	{
		p = p->next;
		return p;	
	}
}
//��ֵ����-�������ݻ�ȡ�����ݵ�λ�����
int LocateElem(LinkList L, ElemType e)
{
	Lnode* p;;
	p = L->next;
	int j = 1;
	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p)return j;
	else return 0;
}
//����-�ڵ�i�����ǰ����ֵΪe���½��
//�ҵ��ڣ�i-1������㴢��λ�� p������һ��������Ϊe���½��s
//�����½�� �½���ָ����ָ��ai��a��i-1����ָ����ָ���½��
Status InsertList(LinkList& L, int i, ElemType e)
{
	Lnode* s;
	Lnode* p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	//�쳣�ж�
	if (!p || i < 0)
		return ERROR;
	s = new Lnode;
	s->data = e;//�����½��s
	s->next = p->next;//�����S����L����
	p->next = s;
}
//ɾ��--ɾ����i�����
//�ҵ���i-1����㣬����Ҫɾ���ĵ�i������ֵ����ָ��ָ��ڣ�i+1�������
//�ͷ�ɾ�����Ŀռ�
Status ListDelete_L(LinkList& L, int i, ElemType& e)
{
	int j = 0;
	Lnode* p,*q;
	p = L;
	while (p->next&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 0)
		return ERROR;
	q = p->next;//��ʱ���汻ɾ���ĵ�ַ
	p->next = q->next;//�ı�ɾ�����ǰ�����ĵ�ַ�Ա��ͷ�
	e = q->data;//����ɾ�����Ŀ�����
	delete p;
	return OK;
}
//������Ľ�����ͷ�巨--Ԫ�ز�������ͷ����Ҳ��ǰ�巨
//����һ���������½�����β�������ǰ��
void CreatListHead(LinkList& L, int n)
{
	Lnode* p;
	L = new Lnode;
	p = new Lnode;
	L->next = NULL;
		
	for (int i = n; i > 0; i--)
	{
		scanf_s("%d",&( p->data));
		p->next = L->next;//���뵽��ͷ
		L->next = p;
	}
}
//β�巨
void CreatListR(LinkList& L, int n)
{
	Lnode* r, * p;
	p = new Lnode;
	L = new Lnode;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &(p->data));
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
//ѭ��������һ��ͷβ��ӵ������������һ������ָ����ָ��ͷ��㣩
//���������γ�һ����
//����ѭ��������û��NULLָ�룬���漰��������ʱ������ֹ����Ϊ�ж����Ƿ����ͷָ��
//��βָ���ѭ������ϲ�
//Tb��ͷ���ӵ�Ta��β���ͷ�Tbͷ���
LinkList Connect(LinkList Ta, LinkList Tb)
{
	Lnode* p;
	p = Ta->next;
	Ta->next = Tb->next->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}
 //˫����double link list��
//˫����Ķ���
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode,*DuLinkList;
//˫������Ĳ���
void ListInsertDuL(DuLinkList& L, int i, ElemType e)
{
	DuLNode *s,*p;
	if (!(p = GetElem(L, i,e)))
		return 0;
	s = new DuLNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->piror = s;
	return OK;
}
//˫�������ɾ��
void ListDeleteDul(DuLinkList& L, int i, ElemType& e)
{
	DuLNode* p;
	if (!(p = GetElemP(L, i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}
//���Ա�ĺϲ�
