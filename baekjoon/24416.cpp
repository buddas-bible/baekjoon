#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

int N = 0;
int count = 0;
std::vector<int> container;

int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1 || n == 2)
	{
		count++;
		return 1;
	}
	else
	{
		int n_1 = fib(n - 1);
		int n_2 = fib(n - 2);

		return n_1 + n_2;
	}
}

int fibonacci(int n)
{
	container[0] = 0;
	container[1] = container[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		count++;
		container[i] = container[i - 1] + container[i - 2];
	}

	return container[n];
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	container.resize(41);

	std::cin >> N;

	fib(N);
	std::cout << count << " ";
	count = 0;
	fibonacci(N);
	std::cout << count << " ";


	return 0;
}