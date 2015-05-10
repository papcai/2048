#include<iostream>
#include<string>
#include<time.h>
#include<conio.h>
#include<iomanip>

using namespace std;

const string score[] = { " ", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048", };

int FindValueScore(string Score)
{
	for (int i = 0; i < 12; i++)
		if (score[i] == Score)
			return i;

}

//hiển thị
void DisplayMatrix(string matrix[4][4])
{
	system("cls");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << setw(5) << matrix[i][j];
		cout << "\n\n";
	}
}

string Random()
{
	srand(time(0));
	int random = rand() % 20;
	if (!random)
		return score[2];
	else
		return score[1];
}

//khởi tạo ma trận ban đầu
void InitializationMatrix(string Matrix[4][4])
{
	srand(time(0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			Matrix[i][j] = score[0];

	for (int count = 1; count <= 2; count++)
	{
		int i, j;
		do
		{
			i = rand() % 4;
			j = rand() % 4;
		} while (Matrix[i][j] != score[0]);
		Matrix[i][j] = Random();
	}
}

void RandomMatrix(string Matrix[4][4], int Count)
{
	srand(time(0));

	for (int count = 1; count <= Count; count++)
	{
		int i, j;
		do
		{
			i = rand() % 4;
			j = rand() % 4;
		} while (Matrix[i][j] != score[0]);
		Matrix[i][j] = Random();
	}
}

//kiểm ta xem ma trận còn ô trống hay không
int CheckMatrix(string Matrix[4][4])
{
	int count = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (Matrix[i][j] == score[0] && count++ && count == 2)
				return count;
	return count;

}

//kiểm tra xem khi ma trận đầy thì có hai số cạnh nhau hay không
bool CheckContinue(string Matrix[4][4])
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 2; j++)
			if (Matrix[i][j] == Matrix[i][j + 1])
				return true;

	for (int j = 0; j <= 3; j++)
		for (int i = 0; i <= 2; i++)
			if (Matrix[i][j] == Matrix[i + 1][j])
				return true;

	return false;
}

void Up(string Matrix[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			int count = 0;
			int temp_i1 = i, temp_i2 = i - 1;
			bool ablCount = true;
			do
			{
				count++;
				if (Matrix[temp_i1][j] != score[0] && Matrix[temp_i2][j] == score[0])
				{
					Matrix[temp_i2][j] = Matrix[temp_i1][j];
					Matrix[temp_i1][j] = score[0];
					temp_i1--;
					temp_i2--;

				}
				else if (Matrix[temp_i1][j] == score[0] || Matrix[temp_i1][j] != Matrix[temp_i2][j])
				{
					break;
				}
				else if (Matrix[temp_i1][j] == Matrix[temp_i2][j])
				{
					if (ablCount)
					{
						ablCount = false;
						Matrix[temp_i2][j] = score[FindValueScore(Matrix[temp_i2][j]) + 1];
						Matrix[temp_i1][j] = score[0];
						temp_i1--;
						temp_i2--;
					}
					else
						break;
				}

			} while (count != i);

		}
	}
}

void Down(string Matrix[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			int count = 0;
			int temp_i1 = i, temp_i2 = i + 1;
			bool ablCount = true;
			do
			{
				count++;
				if (Matrix[temp_i1][j] != score[0] && Matrix[temp_i2][j] == score[0])
				{
					Matrix[temp_i2][j] = Matrix[temp_i1][j];
					Matrix[temp_i1][j] = score[0];
					temp_i1++;
					temp_i2++;
				}
				else if (Matrix[temp_i1][j] == score[0] || Matrix[temp_i1][j] != Matrix[temp_i2][j])
				{
					break;
				}
				else if (Matrix[temp_i1][j] == Matrix[temp_i2][j])
				{
					if (ablCount)
					{
						ablCount = false;
						Matrix[temp_i2][j] = score[FindValueScore(Matrix[temp_i2][j]) + 1];
						Matrix[temp_i1][j] = score[0];
						temp_i1++;
						temp_i2++;
					}
					else
						break;
				}

			} while (count != (3 - i));
		}
	}
}

void Right(string Matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			int count = 0;
			int temp_j1 = j, temp_j2 = j + 1;
			bool ablCount = true;
			do
			{
				count++;
				if (Matrix[i][temp_j1] != score[0] && Matrix[i][temp_j2] == score[0])
				{
					Matrix[i][temp_j2] = Matrix[i][temp_j1];
					Matrix[i][temp_j1] = score[0];
					temp_j1++;
					temp_j2++;
				}
				else if (Matrix[i][temp_j1] == score[0] || Matrix[i][temp_j1] != Matrix[i][temp_j2])
				{
					break;
				}
				else if (Matrix[i][temp_j1] == Matrix[i][temp_j2])
				{
					if (ablCount)
					{
						ablCount = false;
						Matrix[i][temp_j2] = score[FindValueScore(Matrix[i][temp_j2]) + 1];
						Matrix[i][temp_j1] = score[0];
						temp_j1++;
						temp_j2++;
					}
					else
						break;
				}

			} while (count != (3 - j));
		}
	}
}

void Left(string Matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			int count = 0;
			int temp_j1 = j, temp_j2 = j - 1;
			bool ablCount = true;
			do
			{
				count++;
				if (Matrix[i][temp_j1] != score[0] && Matrix[i][temp_j2] == score[0])
				{
					Matrix[i][temp_j2] = Matrix[i][temp_j1];
					Matrix[i][temp_j1] = score[0];
					temp_j1--;
					temp_j2--;
				}
				else if (Matrix[i][temp_j1] == score[0] || Matrix[i][temp_j1] != Matrix[i][temp_j2])
				{
					break;
				}
				else if (Matrix[i][temp_j1] == Matrix[i][temp_j2])
				{
					if (ablCount)
					{
						ablCount = false;
						Matrix[i][temp_j2] = score[FindValueScore(Matrix[i][temp_j2]) + 1];
						Matrix[i][temp_j1] = score[0];
						temp_j1--;
						temp_j2--;
					}
					else
						break;
				}

			} while (count != j);
		}
	}
}

int main()
{
	string matrix[4][4];

	InitializationMatrix(matrix);
	DisplayMatrix(matrix);

	do
	{
		fflush(stdin);
		char input = _getch();
		switch (input)
		{
		case 'a':
			Left(matrix);
			break;
		case 'w':
			Up(matrix);
			break;
		case 's':
			Down(matrix);
			break;
		case 'd':
			Right(matrix);
			break;
		default:
			return 0;
		}
		DisplayMatrix(matrix);
		if (CheckMatrix(matrix) == 2)
		{
			RandomMatrix(matrix, 2);
			DisplayMatrix(matrix);
		}
		else if (CheckMatrix(matrix) == 1)
		{
			RandomMatrix(matrix, 1);
			DisplayMatrix(matrix);
		}
		else
		{
			if (CheckContinue(matrix))
				continue;
			else
			{
				cout << "Lost";
				break;
			}
		}
//		RandomMatrix(matrix);
//		DisplayMatrix(matrix);
	} while (true);
	return 0;
}