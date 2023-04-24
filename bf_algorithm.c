#include<stdio.h>

int BF(char S[],char T[])
{
	int i=0, j=0;
	while (S[i] && T[j])
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			i =i- j + 1;
			j = 0;
		}
	}
	if (T[j] == '\0')
		return (i - j);
	else
		return -1;
}
int main()
{
	char S[] = "ababcabcacbab";
	char T[] = "abcac";
	printf("%d",BF(S, T));
}