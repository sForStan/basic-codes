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