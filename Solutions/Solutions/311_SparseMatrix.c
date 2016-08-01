/*Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |   
*/
#include "common.h"
void SparseMatrix(int **A, int row, int colA, int **B, int colB)
{
	int i, j, k;
	int C[3][3];
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < colB; j++)
		{
			if (A[i][j])
			{
				for (k = 0; k < colA; k++)
				{
					C[i][k] += A[i][k] * B[k][j];
				}
			}
		}
	}
}

