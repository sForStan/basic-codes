#include<stdio.h>
#include<stdbool.h>
typedef struct box{
	int x;
	int y;
	int di;
}Box;
typedef struct sta{
	Box data[100];
	int top;
}Stack;
int maze[6][6]={
	{0,0,0,0,0,0},
	{0,1,0,1,1,0},
	{0,1,0,0,1,0},
	{0,1,1,0,0,1},
	{0,1,1,0,0,1},
	{0,0,0,0,0,0},
};
void Init_Stack(Stack* s)
{
	s->top=-1;
}
bool isFull(Stack* s)
{
	if(s->top==100)
		return true;
	else
		return false;
}
bool isEmpty(Stack* s)
{
	if(s->top==-1)
		return true;
	else
		return false;
}
void push(Stack* s,Box dat)
{
	if(isFull(s))
		return;
	else
	s->data[++(s->top)]=dat;
}
void pop(Stack* s)
{
	s->top--;
}
void get_top(Stack* s,Box* dat)
{
	*dat=s->data[s->top];
}
int count=0;
void show_path(Stack* s)
{
	int i;
	printf("way %d:\t",++count);
	for(i=0;i<=s->top;i++)
		printf("(%d,%d)",s->data[i].x,s->data[i].y);
	printf("\n");
}
void get_path(Stack* s,int startX,int startY,int endX,int endY)
{
	Box temp;
	temp.x=startX;
	temp.y=startY;
	temp.di=-1;
	push(s,temp);
	maze[temp.x][temp.y]=-1;
	while(!isEmpty(s))
	{
		get_top(s,&temp);
		if(temp.x==endX&&temp.y==endY)
		{
			show_path(s);
			maze[temp.x][temp.y]=0;
			pop(s);
		}
		else
		{
			int direct,line,col;
			for(direct=temp.di+1;direct<4;direct++)
			{

				switch(direct)
				{	
				case 0:
					line=temp.x-1;
					col=temp.y;
					break;
				case 1:
					line=temp.x;
					col=temp.y+1;
					break;
				case 2:
					line=temp.x+1;
					col=temp.y;
					break;
				case 3:
					line=temp.x;
					col=temp.y-1;
					break;
				}
				Box next;
				if(maze[line][col]==0&&line<6&&line>=0&&col<6&&col>=0)
				{
			
					next.x=line;
					next.y=col;
					next.di=-1;
					s->data[s->top].di=direct;
					push(s,next);
					maze[line][col]=-1;
					break;
				}
			}
			if(direct==4)
			{
				pop(s);
				maze[temp.x][temp.y]=0;
			}
		}
	}

}
int main()
{
	system("clear");
	Stack stack;
	Init_Stack(&stack);
	get_path(&stack,0,0,5,5);
	return 0;
}
