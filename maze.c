#include<stdio.h>
#include<stdbool.h>
typedef struct Box
{
	int x;	//������
	int y;	//������
	int dir;	//����
}Box;

typedef struct {
	Box data[1024];
	int top;	//ջ��ָ�루-1Ϊ�գ�
}Stack;
int maze[6][6] = {
	{0,0,0,0,0,0},
	{0,1,0,1,1,0},
	{0,1,0,0,1,0},
	{0,1,1,0,0,1},
	{0,1,1,0,0,1},
	{0,0,0,0,0,0}
};
void InitStack(Stack* s)
{
	s->top = -1;
}
void push(Stack* s,Box b)
{
	if (s->top == 1023)
	{
		return;
	}
	s->data[++(s->top)] = b;
}
bool EmptyStack(Stack* s)
{
	return (s->top == -1)?true:false;
}
void GetTop(Stack* s, Box* b)
{
	*b = s->data[s->top];
}
void pop(Stack *s)
{
	s->top--;
}
void ShowPath(Stack* s)
{
	int i;
	for (i = 0; i <=s->top ; i++)
	{
		printf("(%d,%d)->",s->data[i].x,s->data[i].y);
	}
	printf("\n");
}
void Walk(Stack* s, int x1, int y1, int x2, int y2)
{
	Box now;
	now.x = x1;
	now.y = y1;
	now.dir = -1;
	push(s, now);	//����ջ
	maze[now.x][now.y] = -1;
	while (!EmptyStack(s))	//ջ����
	{
		GetTop(s, &now);
		if (now.x == x2 && now.y == y2)
		{
			ShowPath(s);
			maze[now.x][now.y] = 0;	//��û���߹�
			pop(s);
		}
		else
		{
			int k,i,j;
			for (k = now.dir+1; k < 4; k++)
			{
				switch (k)
				{
				case 0:
					i = now.x - 1;
					j = now.y;
					break;
				case 1:
					i = now.x;
					j = now.y + 1;
					break;
				case 2:
					i = now.x + 1;
					j = now.y;
					break;
				case 3:
					i = now.x;
					j = now.y-1;
					break;
				}
				Box t;
				if (i >= 0 && i <= 5 && j >= 0 && j <= 5 && maze[i][j] == 0)
				{
					t.x = i;
					t.y = j;
					t.dir = -1;
					s->data[s->top].dir = k;
					push(s, t);
					maze[i][j] = -1;
					break;
				}
			}
			if (4 == k)	//�ĸ����򶼲�����
			{
				pop(s);
				maze[now.x][now.y] = 0;
			}
		}
	}
}
int main()
{
	Stack stack;
	InitStack(&stack);
	Walk(&stack, 0, 0, 5, 5);
	return 0;
}