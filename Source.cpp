#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main()

{
	int N;
	double max;
	double  min;
	printf("N= \t");
	scanf_s("%d", &N);
	printf("max= \t");
	scanf_s("%lf", &max);
	printf("min= \t");
	scanf_s("%lf", &min);

	int i = 0;
	int j = 0;
	double* massic;
	int* mazic;
	massic = (double*)malloc(N * sizeof(double));
	mazic = (int*)malloc(N * sizeof(int));
	double sum = 0.0;

	if (N <= 0)
	{
		printf("ERROR N<=0!:(\n");
		return 0;
	}

	if (max < min)
	{
		printf("ERROR max<min!:(\n");
		return 0;
	}
	if (massic == 0)
	{
		printf("ERROR massic==0!:(\n");
		return 0;
	}
	if (mazic == 0)
	{
		printf("ERROR mazic==0!:(\n");
		return 0;
	}
	for (i = 0; i < N; i++)
	{
		massic[i] = rand();
		massic[i] = ((double)rand() / RAND_MAX * (max - min) + min);
		printf("%lf \n", massic[i]);
		mazic[i] = ((massic[i] - (int)massic[i]) * 1000000);
		while (mazic[i] % 10 == 0)
			mazic[i] = mazic[i] / 10;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == mazic[j])
			{
				sum = sum - massic[i];
				mazic[j] = 0.0;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		sum = sum + massic[i];

	}

	printf("sum=%lf", sum);
	free(massic);
	free(mazic);
	return 0;

}