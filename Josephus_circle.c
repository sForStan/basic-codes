#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
int main()
{
	int m, n;//�����nֻ���ӣ�����m��
	int i;//ÿֻ���ӵı��
	struct node* head, * tail, * q, * p;//ͷָ�룬βָ�룬��������ָ��p��ָ��pǰ������ָ��q
	int count=0;
	int answer[100] ;//count��answerһ�𱣴�ÿ�κ������
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;//����������ͷָ��head�ĳ�ʼ��
	while (1)
	{
		scanf("%d %d", &m,& n);//����m,n��ֵ
		if (m == 0 || n == 0)//����0��0ʱ�˳�ѭ��
		{
			free(head);
			break;
		}
		else
		{
			tail = head;
			for (i= 0; i< n; i++)//β�巨����n�����
			{
				p = (struct node*)malloc(sizeof(struct node));
				p->data = i + 1;
				tail->next = p;
				p->next = head->next;//β�����ָ��ͷ�����һ��������ѭ��
				tail = p;
			}
			p = head->next;
			q = tail;//q��ָ��β��㣬pָ��ͷ�����һ��
			i = 1;
			while (q!= p)
			{
				if (i == m)//ÿ������m��ɾ�����
				{
					q->next =p->next;
					free(p);
					p = q->next;
					i = 1;//���¼�����
				}
				else//û����n��ָ��ָ����һ���
				{
					i++;
					q = p;
					p = p->next;
					
				}
			}
			//ɾ����ֻʣһ�������˳�ѭ�����Ǹ�����data���Ǻ����ı��
			answer[count] = p->data;
			count++;
			free(p);
			head->next = NULL;//�ٴ����������ʼ��ͷ���
		}
	}
	for (i=0; i< count; i++)
	{
		printf("%d\n",answer[i]);
	}
	return 0;
}