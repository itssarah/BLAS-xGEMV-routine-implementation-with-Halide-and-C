#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* Initializing the data structures */
	int alpha, beta;
	alpha = 7;
	beta = 8;

	int vectX[6] = {2, 5, 5, 0, 7, 5};

	int vectY[2] = {1, 5};

	int A[2][6] = {
		{0, 1, 2, 3, 1, 1},
		{4, 5, 6, 7, 1, 1}};

	int result[2] = {0, 0};

	/* Doing the multiplication */
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			result[i] += A[i][j] * vectX[j];
		}
		result[i] = alpha * result[i] + beta * vectY[i];

	}
	printf("Youpiiii, multiplication terminado in C! \n");


	/* Saving the results into a file */
	FILE *fp;
	fp = fopen("../results/results_c.txt", "w+");

	
	for (int i = 0; i < 2; i++)
	{
		fprintf(fp, "%d ", result[i]);
	}

	fclose(fp);

	return 0;
}
