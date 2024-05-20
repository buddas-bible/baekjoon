#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

std::vector<std::vector<int>> arr;

std::vector<std::vector<bool>> row;		// 행
std::vector<std::vector<bool>> col;		// 열
std::vector<std::vector<bool>> rect;	// 사각형

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	
	arr = std::vector<std::vector<int>>(9, std::vector<int>(9));

	row = std::vector<std::vector<bool>>(10, std::vector<bool>(10));
	col = std::vector<std::vector<bool>>(10, std::vector<bool>(10));
	rect = std::vector<std::vector<bool>>(10, std::vector<bool>(10));

	for (int i = 0; i < 9; i++)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			arr[i][j] = str[j] - '0';
			int data = arr[i][j];

			if (data == 0)
				continue;

			col[j + 1][data] = true;
			row[i + 1][data] = true;

			int pos = 0;

			if (j + 1 < 4)
			{
				pos = 1;
			}
			else if (3 < (j + 1) && (j + 1) < 7)
			{
				pos = 2;
			}
			else if (6 < (j + 1) && (j + 1) < 10)
			{
				pos = 3;
			}

			if (i + 1 < 4)
			{
				pos += 0;
			}
			else if (3 < (i + 1) && (i + 1) < 7)
			{
				pos += 3;
			}
			else if (6 < (i + 1) && (i + 1) < 10)
			{
				pos += 6;
			}

			rect[pos][data] = true;
		}
	}
}

bool Search(int _x, int _y)
{
	if (_x > 8 || _y > 8)
		return true;

	int x = _x;
	int y = _y;
	int pos = 0;

	if (x + 1 < 4)
	{
		pos = 1;
	}
	else if (3 < (x + 1) && (x + 1) < 7)
	{
		pos = 2;
	}
	else if (6 < (x + 1) && (x + 1) < 10)
	{
		pos = 3;
	}

	if (y + 1 < 4)
	{
		pos += 0;
	}
	else if (3 < (y + 1) && (y + 1) < 7)
	{
		pos += 3;
	}
	else if (6 < (y + 1) && (y + 1) < 10)
	{
		pos += 6;
	}

	if (arr[y][x] == 0)
	{
		for (int i = 1; i < 10; i++)
		{
			if (!row[y + 1][i] && !col[x + 1][i] && !rect[pos][i])
			{
				row[y + 1][i] = true;
				col[x + 1][i] = true;
				rect[pos][i] = true;
				arr[y][x] = i;

				if (_x < 8)
				{
					if (Search(_x + 1, _y))
						return true;
				}
				else
				{
					if (Search(0, _y + 1))
						return true;
				}

				row[y + 1][i] = false;
				col[x + 1][i] = false;
				rect[pos][i] = false;
				arr[y][x] = 0;
			}
		}
	}
	else
	{
		if (x < 8)
		{
			if (Search(_x + 1, _y))
				return true;
		}
		else
		{
			if (Search(0, _y + 1))
				return true;
		}
	}

	return false;
}

int main()
{
	Input();
	Search(0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << '\n';
	}

	return 0;
}