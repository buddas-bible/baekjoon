#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

int n = 0;

void Eratosthenes(std::vector<bool>& _arr)
{
	_arr[0] = false;
	_arr[1] = false;
	for (int i = 2; i * i <= 1'000'000; i++)
	{
		if (!_arr[i])
			continue;

		for (int j = 2; i * j <= 1'000'000; j++)
			_arr[i * j] = false;
	}
}

bool PrimeDivide(int _x, int& _out0, int& _out1)
{
	
}

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;
}

void BinarySearch()
{
	
}

int main()
{
	std::vector<bool> eratosthenes(1'000'001, true);
	Eratosthenes(eratosthenes);

	std::vector<int> prime;
	for (int i = 2; i < eratosthenes.size(); i++)
	{
		if (eratosthenes[i])
			prime.emplace_back(i);
	}

	Input();

	std::vector<int> result(4, -1);

	std::sort(result.begin(), result.end());

	if (result[0] == -1)
	{
			std::cout << -1;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			std::cout << result[i] << " ";
	}
	return 0;
}