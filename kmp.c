#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void getNext(char* t, int* next,int lenT)
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < lenT)
	{
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
int kmp(char s[], char t[])
{
	int lenS = strlen(s);
	int lenT = strlen(t);
	int* next = (int*)malloc(lenT * sizeof(int));
	getNext(t, next,lenT);
	int i=0,j=0;
	while(i<lenS&&j<lenT)
	{
		if (s[i] == t[j]||-1==j)
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j==lenT)
		return (i - j);
	else
		return -1;

}
int main()
{
	char s[] = "ADABCDABD";
	char t[] = "DACDABD";
	printf("%d",kmp(s,t));
}