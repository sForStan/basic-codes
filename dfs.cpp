#include<stdio.h>
//using namespace std;
int p, q, min = 9999999;
int a[100][100];//1��ʾ�յأ�2��ʾ�ϰ���
int v[100][100];//0��ʾδ����
int dy[4] = { 1,0,-1,0 };
int dx[4] = {0,1,0,-1};
void dfs(int x, int y, int step)
{
	if (x == p && y == q)
	{
		if (step < min)
			min = step;
		return;
	}
	//˳ʱ����̽
	for (int k = 0; k < 4; k++)
	{
		int tx, ty;
		tx = x + dx[k];
		ty = y + dy[k];
		if (a[tx][ty] == 1 && v[tx][ty] == 0)
		{
			v[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			v[tx][ty] = 0;
		}
	}
	/*
	//��
	if (a[x][y + 1] == 1 && v[x][y + 1] == 0)
	{
		v[x][y + 1] = 1;
		dfs(x, y + 1, step + 1);
		v[x][y + 1] = 0;
	}
	//��
	if (a[x + 1][y] == 1 && v[x + 1][y] == 0)
	{
		v[x + 1][y] = 1;
		dfs(x + 1, y, step + 1);
		v[x + 1][y] = 0;
	}
	//��
	if (a[x][y - 1] == 1 && v[x][y - 1] == 0)
	{
		v[x][y - 1] = 1;
		dfs(x, y - 1, step + 1);
		v[x][y - 1] = 0;
	}
	//��
	if (a[x - 1][y] == 1 && v[x - 1][y] == 0)
	{
		v[x - 1][y] = 1;
		dfs(x - 1, y, step + 1);
		v[x - 1][y] = 0;
	}
	*/
	return;
}
int main()
{
	int i, j;
	int m = 0, n = 0;
	int startx, starty;
	scanf("%d %d", &m, &n);
	for (i = 1; i <= m; i++)
	{
		//	printf("line %d\n",i);
		for (j = 1; j <= n; j++)
		{
			//		printf("col %d\t",j);
			scanf("%d", &a[i][j]);//1��ʾ�յأ�2��ʾ�ϰ���
		}
	}
	scanf("%d%d%d%d", &startx, &starty, &p, &q);
	v[startx][starty] = 1;
	dfs(startx, starty, 0);
	printf("min=%d\n", min);
}