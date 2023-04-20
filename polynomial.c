#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct polynomial
{
	int exp;
	int coefficient;
	struct polynomial* next;
}*Link,Node;
//�����õ��������
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
	node->coefficient = coefficient;//�ϱ�������node���ĳ�ʼ��
	Link q, p;//����ָ��
	q = head;
	p = head->next;
	if (head->next == NULL)//����Ϊ�գ�ֱ�Ӳ��뵽ͷ����
		head->next = node;
	else//����Ϊ������Ҫ�Ƚϴ�С
	{
		while (p != NULL) { //ѭ�����������е����нڵ�

			if (node->exp > p->exp)//���node�ڵ��ָ����p�ڵ��ָ���������p��ǰ�棬��ɲ������ǰ�˳�
			{
				q->next = node;
				node->next = p;
				return true;
			}
			else if (node->exp == p->exp)//���node�ڵ��ָ����p�ڵ��ָ����ȣ���ϲ��������ʽ�ڵ㣬��ǰ�˳�
			{
				p->coefficient += node->coefficient;
				return true;
			}
			else//���node�ڵ��ָ����p�ڵ��ָ��С����������ƶ�ָ�루��Ȼ����p��qһǰһ��
			{
				q = p; 
				p = q->next;
			}
		}
		q->next = node;
		//����˳�ѭ���ǵ�ǰָ��p�ƶ��������β����˵��֮ǰû�в��룬��ô��ǰnode�ڵ��ָ��ֵ�����ֵ����ʱ��������������
	}
	return true;
}
void inputPoly(Link head)//ִֻ������exp,coefficient�͵��ò��뺯��
{
	int exp, coefficient;
	printf("������ϵ����ָ��:\t");
	scanf("%d %d", &coefficient, &exp);
	while (coefficient || exp)
	{
		insert_node( head,coefficient,exp);//���ò��뺯��
		printf("������ϵ����ָ��:\t");
		scanf("%d %d", &coefficient, &exp);
	}
}
void print(Link head)
{
	Link p;
	p = head->next;
	if (!p)
	{
		printf("����Ϊ��\n");
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
	Link headA, headB;//��������ʽ��ͷָ��
	Link headAB;//�ϲ���Ķ���ʽ��ͷָ��

	/*����ĳ�ʼ��*/
	headA = (Link)malloc(sizeof(Node));
	headA->next = NULL;
	headB = (Link)malloc(sizeof(Node));
	headB->next = NULL;
	headAB = (Link)malloc(sizeof(Node));
	headAB->next = NULL;

	printf("�������һ������ʽ��ϵ����ָ������(0 0)������\n");
	inputPoly(headA);
	printf("��һ��");
	print(headA);
	printf("������ڶ�������ʽ��ϵ����ָ������(0 0)������\n");
	inputPoly(headB);
	printf("�ڶ���");
	print(headB);

	combin2List(headA, headB, headAB);
	printf("�ϲ���");
	print(headAB);
	clear_list(headA);
	clear_list(headB);
	clear_list(headAB);
	return 0;
}