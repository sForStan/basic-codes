#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
int main()
{
	int m, n;//输入的n只猴子，数到m；
	int i;//每只猴子的标号
	struct node* head, * tail, * q, * p;//头指针，尾指针，操作结点的指针p，指向p前驱结点的指针q
	int count=0;
	int answer[100] ;//count与answer一起保存每次猴王结果
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;//上面两句是头指针head的初始化
	while (1)
	{
		scanf("%d %d", &m,& n);//输入m,n的值
		if (m == 0 || n == 0)//输入0，0时退出循环
		{
			free(head);
			break;
		}
		else
		{
			tail = head;
			for (i= 0; i< n; i++)//尾插法插入n个结点
			{
				p = (struct node*)malloc(sizeof(struct node));
				p->data = i + 1;
				tail->next = p;
				p->next = head->next;//尾部结点指向头结点下一个。构成循环
				tail = p;
			}
			p = head->next;
			q = tail;//q是指向尾结点，p指向头结点下一个
			i = 1;
			while (q!= p)
			{
				if (i == m)//每次数到m，删除结点
				{
					q->next =p->next;
					free(p);
					p = q->next;
					i = 1;//重新计数；
				}
				else//没数到n，指针指向下一结点
				{
					i++;
					q = p;
					p = p->next;
					
				}
			}
			//删除到只剩一个结点后退出循环，那个结点的data就是猴王的编号
			answer[count] = p->data;
			count++;
			free(p);
			head->next = NULL;//再次清空链表，初始化头结点
		}
	}
	for (i=0; i< count; i++)
	{
		printf("%d\n",answer[i]);
	}
	return 0;
}