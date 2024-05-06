#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int n = 0;
int k = 0;
int h = 0;
std::vector<int> container;


void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> k;

	container.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> container[i];
	}
}

int main()
{
	Input();

	return 0;
}