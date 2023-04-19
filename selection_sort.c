#include<stdio.h>
void printArray(int* array,int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d", array[i]);
	}
	printf("\n");
}
int main()
{
	int array[] = {49,38,65,97,76,12,27,49};
	int i, j, tmp;
	int min;
	int length=sizeof(array)/sizeof(int);
	printf("待排序的数组是：");
	printArray(array, length);
	for (i = 0; i < length; i++)
	{
		min = i;
		for (j = i + 1; j < length; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
			if (min != i)
			{
				tmp = array[i];
				array[i] = array[min];
				array[min] = tmp;
			}
	}
	printf("排序后的数组是：");
	printArray(array, length);
	return 0;

}