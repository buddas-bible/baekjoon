#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long n = 0;
long long m = 0;
long long h = 0;
long long maximun = -0x7f'ff'ff'ff;
std::vector<long long> tree;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;
	tree.resize(n);

	for (long long i = 0; i < n; i++)
	{
		std::cin >> tree[i];

		maximun = std::max(maximun, tree[i]);
	}
}

bool check(long long height)
{
	long long result = 0ll;

	for (long long i = 0ll; i < n; i++)
	{
		long long diff = tree[i] - height;
		if (diff <= 0)
		{
			continue;
		}
		else
		{
			result += diff;
		}
	}

	return result >= m;
}

long long binarySearch()
{
	long long min = 0ll;
	long long mid = 0ll;
	long long max = maximun;

	while (min < max)
	{
		mid = (min + max + 1ll) / 2ll;

		if (check(mid))
		{
			min = mid;
		}
		else
		{
			max = mid - 1ll;
		}
	}

	return min;
}

int main()
{
	Input();
	long long result = binarySearch();
	std::cout << result;

	return 0;
}