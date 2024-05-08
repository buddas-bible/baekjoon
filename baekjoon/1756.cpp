#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


void Input(int& _D, int& _N, std::vector<int>& _oven, std::vector<int>& _dough)
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	std::cin >> _D >> _N;

	_oven.resize(_D + 1, 0x7fffffff);
	_dough.resize(_N);

	int curr = 0;
	int prev = 0;

	for (int i = 1; i < _D + 1; i++)
	{
		if (i == 1)
		{
			std::cin >> curr;
			_oven[i] = curr;
		}
		else
		{
			prev = curr;
			std::cin >> curr;
			_oven[i] = std::min(_oven[i - 1], curr);
		}
	}

	for (int i = 0; i < _N; i++)
	{
		std::cin >> _dough[i];
	}
}

int BinarySearch(std::vector<int>& _oven, int _maxIndex, int _dough)
{
	int min = 1;
	int mid = 0;
	int max = _maxIndex;

	if (_maxIndex == 0)
	{
		return 0;
	}

	if (_oven[1] < _dough)
	{
		return 0;
	}

	// 들어갈 수 있는 구간 없는 구간 쉽게 뽑아내기 위해서.
	while (min < max)
	{
		mid = (min + max + 1) / 2;

		if (_oven[mid] >= _dough)
		{
			min = mid;
		}
		else
		{
			max = mid - 1;
		}
	}

	return min;
}

void Output(int _value)
{
	std::cout << _value;
}

int main()
{
	int D = 0;
	int N = 0;
	int result = 0;
	std::vector<int> oven;
	std::vector<int> doughs;

	Input(D, N, oven, doughs);

	int stackIndex = D;
	for (int i = 0; i < doughs.size(); i++)
	{
		int temp = BinarySearch(oven, stackIndex, doughs[i]);

		if (temp == 0)
		{
			result = 0;
			break;
		}
		else
		{
			result = temp;
			stackIndex = temp - 1;
		}
	}

	Output(result);

	return 0;
}