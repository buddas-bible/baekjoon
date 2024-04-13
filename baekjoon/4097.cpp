#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>

int N = 0;	// 날짜 수
int P = 0;	// 각 날짜의 수익
std::vector<long long> DP{};

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	long unsigned int index = 0;

	freopen("input.txt", "rt", stdin);
	while (true)
	{
		std::cin >> N;
		if (N == 0)
		{
			break;
		}

		DP.resize(N);
		long long maxValue = -2500000000;

		for (long unsigned int i = 0; i < N; i++)
		{
			long long input = 0;
			std::cin >> input;

			if (i == 0)
			{
				DP[i] = input;
			}
			else
			{
				DP[i] = std::max(DP[i - 1] + input, input);
			}

			maxValue = std::max(DP[i], maxValue);
		}

		std::cout << maxValue << std::endl;
	}
}

int main()
{
	Input();

	return 0;
}