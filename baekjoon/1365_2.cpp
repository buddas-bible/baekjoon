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
			// _data가 _vec의 mid보다 작다
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

		// 전에 넣은거랑 꼬이는지 체크
		if (line.back() < data)
		{
			// 꼬이면 새로 만들어서 넣어줌
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