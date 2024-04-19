#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N = 1;
int coin2 = 0;
int coin5 = 0;
int result = 0;

int Devine5(int _N)
{
	return _N / 5;
}

int Remainder5(int _N)
{
	return _N % 5;
}

int Devine2(int _N)
{
	return _N / 2;
}

int Remainder2(int _N)
{
	return _N % 2;
}

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	auto file = freopen("input.txt", "rt", stdin);
	std::cin >> N;
}

void Function()
{
	int remainder5 = Remainder5(N);
	int devine5 = Devine5(N);

	if (remainder5 == 0)
	{
		std::cout << devine5;
	}
	else
	{
		// 남은 수가2로 나누어 떨어지나?
		int devine2_remainder5 = Devine2(remainder5);
		int remainder2_remainder5 = Remainder2(remainder5);

		if (remainder2_remainder5 == 0)
		{
			std::cout << devine5 + devine2_remainder5;
		}
		// 2로 안 나눠짐
		else
		{
			while (devine5)
			{
				devine5--;
				remainder5 += 5;
				// 2로 나누어 떨어지나?
				int remainder2_remainder5_5 = Remainder2(remainder5);
				if (remainder2_remainder5_5 == 0)
				{
					std::cout << Devine2(remainder5) + devine5;
					return;
				}
			}

			std::cout << "-1";
		}
	}
}

int main()
{
	Input();
	Function();

	return 0;
}