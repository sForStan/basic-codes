#include<stdio.h>
//���ַ�����
int main()
{
	int array[] = { 0,5,13,19,22,41,55,68,72,81,98 };
	int targetNumber, result=0;//result�����ҵĽ��
	int arrLength = sizeof(array) / sizeof(array[0]);//������鳤��
	printf("������������������Ҫ���ҵ�����:\n");
	scanf("%d", &targetNumber);
	//���Ҵ���
	int high = arrLength, low = 0;
	int mid;
	while (high >= low)
	{
		mid = (high + low) / 2;
		if (targetNumber > array[mid])
			low = mid + 1;
		else if (targetNumber <array[mid])
			high = mid - 1;
		else
		{
			result = 1;
			break;
		}
	}
	if (result==0)
		printf("û���ҵ�����%d", targetNumber);
	else
		printf("�ҵ��ˣ��ǵ�%d������", mid+1);
	return 0;

}