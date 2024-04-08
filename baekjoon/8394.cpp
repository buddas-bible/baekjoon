#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N = 0;

std::vector<unsigned long long> pibo;

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	std::cin >> N;

	unsigned long long answer = 0;

	pibo.resize(N + 1);

	pibo[0] = 1;
	pibo[1] = 1;
	pibo[2] = 2;

	if (3 <= N)
	{
		for (int i = 3; i <= N; i++)
		{
			pibo[i] = (pibo[i - 1]+ pibo[i - 2]) % 10;
		}
	}

	std::cout << pibo[N] % 10;


	return 0;
}