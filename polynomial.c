#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct polynomial
{
	int exp;
	int coefficient;
	struct polynomial* next;
}*Link,Node;
//测试用的输出函数
void print_List_tmp(Link head)
{
//	printf("1");
	Link p;
	p = head->next;
	//printf("%d", p->exp);
	while (p->next)
	{
//		printf("1");
		printf("%d %d", p->exp, p->coefficient);
		p = p->next;
	}
}
bool insert_node(Link head, int coefficient, int exp)
{
	Link node = (Link)malloc(sizeof(Node));
	node->next = NULL;
	node->exp = exp;
	node->coefficient = coefficient;//上边三句是node结点的初始化
	Link q, p;//操作指针
	q = head;
	p = head->next;
	if (head->next == NULL)//链表为空，直接插入到头结点后
		head->next = node;
	else//链表不为空则需要比较大小
	{
		while (p != NULL) { //循环访问链表中的所有节点

			if (node->exp > p->exp)//如果node节点的指数比p节点的指数大，则插在p的前面，完成插入后，提前退出
			{
				q->next = node;
				node->next = p;
				return true;
			}
			else if (node->exp == p->exp)//如果node节点的指数和p节点的指数相等，则合并这个多项式节点，提前退出
			{
				p->coefficient += node->coefficient;
				return true;
			}
			else//如果node节点的指数比p节点的指数小，继续向后移动指针（依然保持p，q一前一后）
			{
				q = p; 
				p = q->next;
			}
		}
		q->next = node;
		//如果退出循环是当前指针p移动到链表结尾，则说明之前没有插入，那么当前node节点的指数值是最大值，此时插在链表的最后面
	}
	return true;
}
void inputPoly(Link head)//只执行输入exp,coefficient和调用插入函数
{
	int exp, coefficient;
	printf("请输入系数与指数:\t");
	scanf("%d %d", &coefficient, &exp);
	while (coefficient || exp)
	{
		insert_node( head,coefficient,exp);//调用插入函数
		printf("请输入系数与指数:\t");
		scanf("%d %d", &coefficient, &exp);
	}
}
void print(Link head)
{
	Link p;
	p = head->next;
	if (!p)
	{
		printf("链表为空\n");
		return;
	}
	bool isFirstNum = true;
	do
	{
		if (isFirstNum)
		{
			isFirstNum = false;
			switch (p->coefficient)
			{
			case 1:
				printf("x^%d", p->exp);
				break;
			case -1:
				printf("-x^%d", p->exp);
				break;
			default:
				printf("%dx^%d", p->coefficient, p->exp);	
			}
		}
		else
		{
			switch (p->coefficient)
			{
			case 1:
				printf("+x^%d", p->exp);
				break;
			case -1:
				printf("-x^%d", p->exp);
				break;
			case 0:
				break;
			default:
			{
				if (p->coefficient > 0)
					printf("+%dx^%d", p->coefficient, p->exp);
				else
					printf("%dx^%d", p->coefficient, p->exp);
			}
			break;
			}
		}
		p = p->next;
	} while (NULL != p);
	printf("\n");
	return;
}
void combin2List(Link head_a, Link head_b, Link head_ab)
{
	Link pa, pb;
	pa = head_a->next;
	pb = head_b->next;
	while (pa || pb)
	{
		if (pa->exp > pb->exp)
		{
			insert_node(head_ab, pa->coefficient, pa->exp);
			pa = pa->next;
		}
		else if (pa->exp < pb->exp)
		{
			insert_node(head_ab, pb->coefficient, pb->exp);
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->exp == pb->exp)
		{
			pa->coefficient += pb->coefficient;
			insert_node(head_ab, pa->coefficient, pa->exp);
			pa = pa->next;
			pb = pb->next;
		}
	}
/*	while (pa != NULL)
	{
		insert_node(head_ab, pa->coefficient, pa->exp);
		pa = pa->next;
	}
	while (pb!= NULL)
	{
		insert_node(head_ab, pb->coefficient, pb->exp);
		pb = pb->next;
	}*/
	pa = pa ? pa:pb;
	return;
}
void clear_list(Link list)
{
	Link p, q;
	p = list;
	q = list->next;
	while (p)
	{
		free(p);
		p = q;
		q = p->next;
	}
	if (NULL == list)
		return;
}
int main()
{
	Link headA, headB;//两个多项式的头指针
	Link headAB;//合并后的多项式的头指针

	/*链表的初始化*/
	headA = (Link)malloc(sizeof(Node));
	headA->next = NULL;
	headB = (Link)malloc(sizeof(Node));
	headB->next = NULL;
	headAB = (Link)malloc(sizeof(Node));
	headAB->next = NULL;

	printf("请输入第一个多项式的系数和指数，以(0 0)结束：\n");
	inputPoly(headA);
	printf("第一个");
	print(headA);
	printf("请输入第二个多项式的系数和指数，以(0 0)结束：\n");
	inputPoly(headB);
	printf("第二个");
	print(headB);

	combin2List(headA, headB, headAB);
	printf("合并后");
	print(headAB);
	clear_list(headA);
	clear_list(headB);
	clear_list(headAB);
	return 0;
}