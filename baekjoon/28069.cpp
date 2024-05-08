#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int n = 0;
int k = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> k;
}

int DP()
{
	std::vector<int> container(n + 2, 0x7fffffff);

	// n���� ���� ���� ������ �� �ִ� ���
	container[0] = 0;
	container[1] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		const int plusOne = i + 1;
		const int plusHalf = i + (i / 2);

		if (plusOne <= n)
		{
			// plusOne ���� ���� ������ + 1 �� �ͺ��� �� ������ ������ �� �ִ°�?
			container[plusOne] = std::min(container[i] + 1, container[plusOne]);
		}
		if (plusHalf <= n)
		{
			// plusHalf ���� ���� ������ + 1 �� �ͺ��� �� ������ ������ �� �ִ°�?
			container[plusHalf] = std::min(container[i] + 1, container[plusHalf]);
		}
	}

	return container[n];
}

void Output(int _dp)
{
	// n�� k���� ���� Ƚ���� ������ �� �ִ� ���̶�� ������ ������.
	if (_dp <= k)
	{
		std::cout << "minigimbob";
	}
	else
	{
		std::cout << "water";
	}
}

int main()
{
	Input();
	Output(DP());

	return 0;
}