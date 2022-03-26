//读取 排序 打印一列整型值。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int compare_integers(void const *a, void const *b)	//qsort函数的最后一个参数
{
	register int const *pa = a;
	register int const *pb = b;

	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main()
{
	int *array;
	int n_values;
	int i;

	printf("How many values are there?");
	scanf("%d", &n_values);

	array = malloc(n_values * sizeof(int));

	if (array == NULL)
	{
		printf("Can't get momery.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n_values; i += 1)
	{
		printf("? ");
		scanf("%d", (array + i));
	}
	qsort(array, n_values, sizeof(int), compare_integers);

	for (i = 0; i < n_values; i += 1)
		printf("%d\n", array[i]);
	system("pause");
	free(array);
	return EXIT_SUCCESS;
	
}