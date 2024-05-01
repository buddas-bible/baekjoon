#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N = 0;
int M = 0;

std::vector<int> HI;
std::vector<int> ARC;

int win = 0;
int lose = 0;
int draw = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> N >> M;
	HI.resize(N);
	ARC.resize(M);

	for (int i = 0; i < N; i++)
		std::cin >> HI[i];

	for (int i = 0; i < M; i++)
		std::cin >> ARC[i];
}

void BinarySearch()
{
	int min = 1;
	int mid = 0;
	int max = 100'000;

	while (min < max)
	{
		mid = (min + max) / 2;


	}
}

void Output()
{
	std::cout << win << " " << lose << " " << draw;
}

int main()
{
	Input();
	BinarySearch();
	Output();

	return 0;
}