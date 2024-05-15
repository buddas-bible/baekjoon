#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int n = 0;
std::vector<int> input;
std::vector<int> line;
int result = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;

	input.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i];
	}
}

int BinarySearch(std::vector<int> _vec, int _data)
{
	int min = 0;
	int mid = 0;
	int max = _vec.size() - 1;

	while (min < max)
	{
		mid = (min + max) / 2;

		if (_vec[mid] <= _data)
		{
			min = mid + 1;
		}
		else
		{
			// _data�� _vec�� mid���� �۴�
			// 
			max = mid;
		}
	}

	return min;
}

void LIS()
{
	line.emplace_back(0);

	for (int i = 0; i < n; i++)
	{
		int data = input[i];

		// ���� �����Ŷ� ���̴��� üũ
		if (line.back() < data)
		{
			// ���̸� ���� ���� �־���
			line.emplace_back(data);
		}
		else
		{
			int index = BinarySearch(line, data);
			line[index] = data;
		}
	}

	result = n - (line.size() - 1);
}

void Output()
{
	std::cout << result;
}

int main()
{
	Input();
	LIS();
	Output();

	return 0;
}