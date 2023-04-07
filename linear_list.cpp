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
//线性表的初始化
Status InitList_Sq(SqList &L)
{
	L.elem = new ElemType[MAXSIZE];//为顺序表分配空间
	if (!L.elem) exit(OVERFLOW);//储存分配失败
	L.length = 0;//空表长度为0
	return OK;
};
//销毁线性表L
void DestroyList(SqList& L)
{
	if (L.elem) delete L.elem;
}
//清空线性表L
void ClearList(SqList& L)
{
	L.length = 0;
}
//求线性表长度
int GetLength(SqList& L)
{
	return (L.length);
}
//判断线性表L是否为空
int IsEmpty(SqList& L)
{
	if (L.length == 0)
		return 1;
	else return 0;
}
//线性表的取值（根据位置i获取相应位置的数据元素）
int GetElem(SqList L, int i,ElemType &e)
{
	if (i<1 ||i>L.length)return ERROR;//判断i数值是否合理，不合理返回ERROR
	e = L.elem[i - 1];//第i个元素储存着第i个元素
	return OK;
}
//顺序表的按值查找
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length ;i++)//遍历L查找数值为e的元素
		if (L.elem[i] == e)
			return i + 1;//查找成功返回序号
			return 0;//查找失败返回0
}//平均查找长度 （N+1）/2
//顺序表的插入 
//（最后，中间，最前）在第i个位置上插入新节点e，使长度为n的线性表长度变为n+1
Status ListInsert_Sq(SqList& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L.length)return ERROR;//判断i数值是否合理，不合理返回ERROR
	if (L.length==MAXSIZE)return ERROR;//当前储存空间已满
	for (j = L.length - 1; j >= i-1; j--)//存了n个元素，最后一个元素角标是n-1，要插入的位置是i-1
	{
		L.elem[j + 1] = L.elem[j];//插入位置及之后的元素后移
		L.elem[i - 1] = e;	//将新元素e放入第i个位置
		L.length++;//表长加1
		return OK;
	}
	//插入位置和移动次数的和是（n+1）
	//插入位置为i，移动次数为n+1-i；
	//累加起来后除以（n+1）种可能，最后求得期望为n/2
	//所以这个算法复杂度为O(n)
}
//线性表的删除
//删除线性表L中第i个位置的元素用e返回
Status ListDelete_Sq(SqList& L, int i)
{
	int j;
	if (i<1 || i>L.length)return ERROR;//判断i数值是否合理，不合理返回ERROR
	for (j = i; j < L.length - 1; j++)//逻辑比下标大1，i的位置上是数组下标的i+1
	{
		L.elem[j - 1] = L.elem[j];//被删元素之后的元素前移
		L.length--;//表长度-1
	}
	//各个位置都删除共有N种可能
	//位置和移动次数的和为N，第i个元素需要移动（n-i）次
	//移动的期望为（n-1）/2
	//这个算法的复杂度为O(n)
}
/*
单链表：只有一个指针域
双链表：结点有两个指针域
循环链表：首尾相接的链表

头指针：是指向链表中第一个结点的指针
头结点：在首元结点之前附设的一个结点
首元结点：链表中储存第一个元素a1的结点

如何表示空表？
无头结点时，头指针为空时为空表
有头节点时，头节点指针域为空为空表

头结点的数据域内装什么？
无所谓

链表的特点
1）储存器中的位置是任意的
2）只能通过头指针进入链表

*/
//链表初始化
typedef struct Lnode 
{
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

// 判断链表是否为空
//空表：链表中无元素，头指针和头结点仍然在
int ListEmpty(LinkList L)
{
	if (L->next)
		return 0;
	else
		return 1 ;
}
//单链表的销毁
//从头指针开始，依次释放所有结点
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
//清空链表
//链表仍然存在，成为空链表
//依次释放所有结点，并将头结点指针域设置为空
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
//求单链表的表长
//从首元结点开始，依次计数所有结点
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
//重要操作
//p=L指向头结点
//s=L->next指向首元节点
//p=p->next指向下一个结点

//取值-取单链表中第i个元素的值
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
	if (!p || j > i)//第n个元素不存在
		return ERROR;
	e = p->data;
	return OK;
}
//单链表的查找
//按值查找--根据指定数据获取该数据所在的位置（地址）
//从第一个结点开始依次与e比较，找到 则返回，没找到返回0或者返回空
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
//按值查找-根据数据获取该数据的位置序号
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
//插入-在第i个结点前插入值为e的新结点
//找到第（i-1）个结点储存位置 p，生成一个数据域为e的新结点s
//插入新结点 新结点的指针域指向ai，a（i-1）的指针域指向新结点
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
	//异常判断
	if (!p || i < 0)
		return ERROR;
	s = new Lnode;
	s->data = e;//生成新结点s
	s->next = p->next;//将结点S插入L当中
	p->next = s;
}
//删除--删除第i个结点
//找到第i-1个结点，保存要删除的第i个结点的值，令指针指向第（i+1）个结点
//释放删除结点的空间
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
	q = p->next;//临时保存被删结点的地址
	p->next = q->next;//改变删除结点前驱结点的地址以备释放
	e = q->data;//保存删除结点的控制域
	delete p;
	return OK;
}
//单链表的建立：头插法--元素插在链表头部，也叫前插法
//生成一个链表，将新结点依次插入链表前端
void CreatListHead(LinkList& L, int n)
{
	Lnode* p;
	L = new Lnode;
	p = new Lnode;
	L->next = NULL;
		
	for (int i = n; i > 0; i--)
	{
		scanf_s("%d",&( p->data));
		p->next = L->next;//插入到表头
		L->next = p;
	}
}
//尾插法
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
//循环链表：是一种头尾相接的链表（表中最后一个结点的指针域指向头结点）
//整个链表形成一个环
//由于循环链表中没有NULL指针，故涉及遍历操作时，其终止条件为判断它是否等于头指针
//带尾指针的循环链表合并
//Tb表头链接到Ta表尾，释放Tb头结点
LinkList Connect(LinkList Ta, LinkList Tb)
{
	Lnode* p;
	p = Ta->next;
	Ta->next = Tb->next->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}
 //双链表（double link list）
//双链表的定义
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode,*DuLinkList;
//双向链表的插入
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
//双向链表的删除
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
//线性表的合并
