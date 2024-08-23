#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using ULL = unsigned long long;

ULL a = 0;
ULL b = 0;

std::vector<bool> number;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> a >> b;
}

void Eratosthenes()
{
	ULL start = std::sqrt(a);
	ULL end = std::sqrt(b);

	number.resize(end + 1, true);

	number[0] = false;
	number[1] = false;
	number[2] = true;

	// 소수를 찾음
	for (ULL i = 2; i < number.size(); i++)
	{
		if (number[i])
		{
			for (ULL j = 2; j < number.size(); j++)
			{
				if (i * j < number.size())
				{
					ULL next = i * j;
					number[next] = false;
				}
				else
				{
					break;
				}
			}
		}
	}

	ULL result = 0;
	for (ULL i = 0; i < end + 1; i++)
	{
		if (number[i])
		{
			int p = 2;
			while (true)
			{
				if (std::pow(i, p) <= b && std::pow(i, p) >= a)
				{
					p++;
					result++;
				}
				else if (std::pow(i, p) < a)
				{
					p++;
					continue;
				}
				else
				{
					break;
				}
			}
		}
	}

	std::cout << result;
}

int main()
{
	Input();
	Eratosthenes();

	return 0;
}