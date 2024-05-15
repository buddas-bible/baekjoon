#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int t = 0;
std::vector<int> input;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> t;

	input.resize(t);

	for (int i = 0; i < t; i++)
	{
		std::cin >> input[t];
	}
}

int Func(int _n)
{
	// _n보다 작은 합성 소수?
	for ()
	{
	}

	return -1;
}

void Output(int _n)
{
	std::cout << _n << '\n';
}

int main()
{
	Input();
	for (int i = 0; i < t; i++)
	{
		Output(Func(input[i]));
	}

	return 0;
}