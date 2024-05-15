#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int n = 0;
std::vector<std::vector<int>> lines;
int result = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;

	lines.emplace_back(std::vector<int>());
	lines[0].emplace_back(0);

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		std::cin >> input;

		// 전에 넣은거랑 꼬이는지 체크
		if (lines.back().back() > input)
		{
			// 꼬이면 새로 만들어서 넣어줌
			lines.emplace_back(std::vector<int>());
			lines.back().emplace_back(0);
		}
		
		lines.back().emplace_back(input);
	}
}

void Output()
{
	std::cout << result;
}

int main()
{
	Input();
	Output();

	return 0;
}