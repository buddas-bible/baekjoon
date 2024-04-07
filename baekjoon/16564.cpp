#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

int N = 0;
int K = 0;
std::vector<int> inputContainer{};

int minIndex = 0;
int midIndex = 0;
int maxIndex = 0;
int result = 0;

void Input()
{
	freopen("input.txt", "rt", stdin);
	std::cin >> N >> K;
	inputContainer.resize(N);

	// 입력값을 벡터에 넣음
	for (size_t i = 0; i < N; i++)
	{
		int a = 0;
		std::cin >> a;

		inputContainer[i] = a;
	}

	// 순서대로 정렬함
	std::sort(inputContainer.begin(), inputContainer.end());
}

void BinarySearch()
{
	minIndex = 0;
	midIndex = 0;
	maxIndex = N - 1;

	while (minIndex <= maxIndex)
	{
		midIndex = (minIndex + maxIndex) / 2;

		int need = 0;

		for (int i = 0; i < midIndex; i++)
		{


		}

		if (true)
		{

		}
		else
		{

		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	Input();
	BinarySearch();

	std::cout << result;

	return 0;
}
