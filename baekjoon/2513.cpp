#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int n = 0;	// 아파트 단지
int k = 0;	// 버스 정원
int s = 0;	// 학교 위치

std::vector<std::pair<int, int>> data;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> k >> s;
}

void Solve()
{
	for (int i = 0; i < n; i++)
	{
		int pos = 0;
		int count = 0;
		std::cin >> pos >> count;
		data.emplace_back( pos, count );
	}

	std::sort(data.begin(), data.end());
}

void Output()
{

}

int main()
{
	Input();
	Solve();
	Output();

	return 0;
}