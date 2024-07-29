#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define CHANGE_ROW -1
#define CHANGE_COL -2

int n = 0;
int m = 0;

using p_arr = std::vector<std::vector<int>>;
using command = std::vector<std::pair<int, int>>;	// 위치, 바뀐 행 또는 열

p_arr arr;
std::vector<command, p_arr> data;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;

	arr = std::vector<std::vector<int>>(m, std::vector<int>(n));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			std::cin >> arr[i][j];
}

void GetCol(int _x, std::vector<int>& _out)
{
	for (int i = 0; i < m; i++)
		_out.emplace_back(arr[i][_x]);
}

void GetRow(int _y, std::vector<int>& _out)
{
	for (int i = 0; i < m; i++)
		_out.emplace_back(arr[_y][i]);
}

void ReverseCol(int _c)
{
	for (int i = 0; i < m; i++)
		arr[i][_c] *= -1;
}

void ReverseRow(int _r)
{
	for (int i = 0; i < n; i++)
		arr[_r][i] *= -1;
}

bool CheckCol(int& _x)
{
	// 열 체크
	for (int i = 0; i < n; i++)
	{
		int temp0 = 0;
		for (int j = 0; j < m; j++)
		{
			temp0 += arr[j][i];
		}

		if (temp0 <= 0)
		{
			_x = i;
			return false;
		}
	}

	return true;
}

bool CheckRow(int& _y)
{
	// 행 체크
	for (int i = 0; i < m; i++)
	{
		int temp0 = 0;
		for (int j = 0; j < n; j++)
		{
			temp0 += arr[i][j];
		}

		if (temp0 <= 0)
		{
			_y = i;
			return false;
		}
	}

	return true;
}

int main()
{
	Input();
	int x = 0;
	int y = 0;

	while (true)
	{
		bool column = CheckCol(x);
		bool row = CheckRow(y);

		if (column && row)
		{
			break;
		}

		std::vector<int> col;

		if (!column)
		{
			ReverseCol(x);
		}
		else if (!row)
		{
			ReverseRow(y);
		}
	}

	return 0;
}