#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

int n = 0;

void Eratosthenes(std::vector<bool>& _arr)
{
	_arr[0] = false;
	_arr[1] = false;

	for (int i = 2; i * i < _arr.size(); i++)
	{
		if (!_arr[i])
			continue;

		for (int j = 2; i * j < _arr.size(); j++)
			_arr[i * j] = false;
	}
}

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;
}

int main()
{
	Input();

	if (n < 8)
	{
		std::cout << -1 << '\n';
		return 0;
	}

	std::vector<bool> eratosthenes(n + 1, true);
	Eratosthenes(eratosthenes);

	std::vector<int> result(4, -1);

	if (n % 2 == 0)
	{
		n -= 4;

		result[0] = 2;
		result[1] = 2;
	}
	else
	{
		n -= 5;

		result[0] = 2;
		result[1] = 3;
	}

	for (int i = 2; i <= n; i++)
	{
		if (eratosthenes[i] && eratosthenes[n - i])
		{
			result[2] = i;
			result[3] = n - i;
			break;
		}
	}


	for (int i = 0; i < 4; i++)
		std::cout << result[i] << " ";

	std::cout << '\n';


	return 0;
}