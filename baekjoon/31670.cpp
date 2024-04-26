#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using Ull = unsigned long long;

int N = 0;
std::vector<Ull> R;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);

	std::cin >> N;
	R.resize(N);

	for (int i = 0; i < N; i++)
		std::cin >> R[i];
}

void DP()
{
	
}

int main()
{
	Input();
	DP();

	return 0;
}