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

	// n번에 가장 빨리 도착할 수 있는 경우
	container[0] = 0;
	container[1] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		const int plusOne = i + 1;
		const int plusHalf = i + (i / 2);

		if (plusOne <= n)
		{
			// plusOne 값이 이전 값에서 + 1 한 것보다 더 빠르게 도착할 수 있는가?
			container[plusOne] = std::min(container[i] + 1, container[plusOne]);
		}
		if (plusHalf <= n)
		{
			// plusHalf 값이 이전 값에서 + 1 한 것보다 더 빠르게 도착할 수 있는가?
			container[plusHalf] = std::min(container[i] + 1, container[plusHalf]);
		}
	}

	return container[n];
}

void Output(int _dp)
{
	// n이 k보다 적은 횟수로 도착할 수 있는 곳이라면 무조건 가능함.
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