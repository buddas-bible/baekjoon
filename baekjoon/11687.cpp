#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cassert>

using ULL = unsigned long long;

ULL M = 0;
ULL N = 0;
ULL count = 0;
ULL minValue = 1;
ULL midValue = 0;
ULL maxValue = 500'000'000'001;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> M;
}

ULL GetCarry(ULL _N)
{
	int carry = 0;
	while (true)
	{
		ULL value = std::pow(5, carry);

		if (value == _N)
		{
			break;
		}
		if (value > _N)
		{
			carry--;
			break;
		}

		carry++;
	}

	return carry;
}

ULL GetCount(ULL _N)
{
	ULL result = 0;
	ULL carry = GetCarry(_N);
	if (carry > 0)
	{
		for (ULL i = 1; i <= carry; i++)
		{
			ULL value = std::pow(5, i);
			ULL c = _N / value;
			result += c;
		}
	}

	return result;
}

void BinarySearch()
{
	while (minValue < maxValue)
	{
		midValue = (minValue + maxValue) / 2;
		count = GetCount(midValue);

		if(M <= count)
		{
			maxValue = midValue;
		}
		else
		{
			minValue = midValue + 1;
		}
	}

	N = maxValue;
}

void Output()
{
	count = GetCount(N);

	if (count != M)
		std::cout << -1 << std::endl;
	else
		std::cout << N << std::endl;
}

int main()
{
	Input();
	BinarySearch();
	Output();

	return 0;
}