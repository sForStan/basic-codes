#include<stdio.h>
//二分法查找
int main()
{
	int array[] = { 0,5,13,19,22,41,55,68,72,81,98 };
	int targetNumber, result=0;//result：查找的结果
	int arrLength = sizeof(array) / sizeof(array[0]);//获得数组长度
	printf("请输入在以下数组中要查找的数字:\n");
	scanf("%d", &targetNumber);
	//查找代码
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
		printf("没有找到数字%d", targetNumber);
	else
		printf("找到了，是第%d个数字", mid+1);
	return 0;

}