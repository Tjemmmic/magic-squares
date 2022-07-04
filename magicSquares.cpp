#include <iostream>
#include <conio.h>

const int MATRIX_LIMIT = 100;

int main()
{
	int x, y = 0;
	int inputSize;
	int sumX;
	int sumDiag = 0;
	int sumY[MATRIX_LIMIT];
	int magicSquare[MATRIX_LIMIT][MATRIX_LIMIT];
	for (int i = 0; i < MATRIX_LIMIT; i++)
	{
		sumY[i] = 0;
		for (int j = 0; j < MATRIX_LIMIT; j++)
		{
			magicSquare[i][j] = 0;
		}
	}
	do
	{
		printf(" Please Enter the Magic Square Size You Would Like (Must Be Odd): ");
		std::cin >> inputSize;
		system("cls");
		if (inputSize % 2 == 0)
		{
			printf(" You Must Enter An Odd Number...");
			_getch();
			system("cls");
		}
		else if (inputSize > MATRIX_LIMIT)
		{
			printf(" Input Size Must Be Less than %d...", MATRIX_LIMIT);
			_getch();
			system("cls");
		}
	}while((inputSize % 2 == 0) || (inputSize > MATRIX_LIMIT));
	x = ((inputSize + 1) / 2) - 1;
	magicSquare[x][y] = 1;
	for (int i = 2; i < (inputSize * inputSize) + 1; i++)
	{
		if (x == (inputSize - 1))
		{
			if (magicSquare[0][y - 1] == 0)
			{
				x = 0;
				y--;
				magicSquare[x][y] = i;
			}
			else
			{
				if (y == inputSize - 1)
				{
					y = 0;
					magicSquare[x][y] = i;
				}
				else
				{
					y++;
					magicSquare[x][y] = i;
				}
			}
		}
		else if (y == 0)
		{
			if (magicSquare[x + 1][inputSize - 1] == 0)
			{
				x++;
				y = inputSize - 1;
				magicSquare[x][y] = i;
			}
			else
			{
				y++;
				magicSquare[x][y] = i;
			}
		}
		else if (magicSquare[x + 1][y - 1] == 0)
		{
			x++;
			y--;
			magicSquare[x][y] = i;

		}
		else
		{
			if (y == inputSize - 1)
			{
				y = 0;
				magicSquare[x][y] = i;
			}
			else
			{
				y++;
				magicSquare[x][y] = i;
			}
		}
	}
	for (int i = 0; i < inputSize; i++)
	{
		sumX = 0;
		for (int j = 0; j < inputSize; j++)
		{
			sumY[j] += magicSquare[j][i];
			printf(" %5i", magicSquare[j][i]);
			sumX += magicSquare[j][i];
		}
		printf(" %5i", sumX);
		printf("\n");
		
	}
	for (int i = 0; i < inputSize; i++)
	{
		printf(" %5i", sumY[i]);
		sumDiag += magicSquare[i][i];
	}
	printf(" %5i", sumDiag);
	_getch();
}