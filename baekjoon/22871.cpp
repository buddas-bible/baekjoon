#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

int N = 0;

std::vector<int> A;
std::stack<int> index;

// i에서 j까지 드는 힘
int GetK(int i, int j)
{
	return (j - i) * 1 + std::abs(A[i] - A[j]);
}

int DFS(int start, int depth, int end, int K)
{
	for (int i = start + 1; i < N; i++)
	{
		index.push(i);
		DFS(i, depth, end, K);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	freopen("input.txt", "rt", stdin);

	std::cin >> N;

	A.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> A[i];
		if (i != N - 1)
		{
			index.push(i);
		}
	}

	return 0;
}