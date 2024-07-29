#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using ULL = unsigned long long;

int n = 0;
std::vector<ULL> container;
std::vector<ULL> out;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;
}

void HexagonalWater()
{
	out = std::vector<ULL>(n + 2, 6);

	container.emplace_back(0);
	out[0] = 0;
	out[1] = 1;

	ULL count = 1;
	while (true)
	{
		container.emplace_back(container[count - 1] + 4 * (count - 1) + 1);
		if (container[count] <= n)
		{
			out[container[count]] = 1;
		}
		else
		{
			break;
		}

		count++;
	}
	
	for (ULL i = 1; i <= n; i++)
	{
		for (ULL j = 0; j < container.size(); j++)
		{
			if (i >= container[j])
			{
				out[i] = std::min(out[i], out[i - container[j]] + 1);
			}
		}
	}
}

int main()
{
	Input();
	HexagonalWater();

	std::cout << out[n];

	return 0;
}