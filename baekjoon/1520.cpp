#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

int m = 0;
int n = 0;
std::vector<std::vector<std::pair<int, int>>> container;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> m >> n;
	container.resize(m, std::vector<std::pair<int, int>>(n, { 0, 0 }));

	for (size_t y = 0; y < m; y++)
	{
		for (size_t x = 0; x < n; x++)
		{
			std::cin >> container[y][x].first;
		}
	}
}

int DFS(int _x, int _y)
{
	auto& [height, count] = container[_y][_x];
	
	// 끝에 도달했는가?
	if (_x == n - 1 && _y == m - 1)
	{
		return 1;
	}

	// 이미 지나갔던 길인가?
	if (count > 0)
	{
		count++;
		return count - 1;
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		// 범위 내인가?
		if (nx < 0 || ny < 0) continue;
		if (nx >= n || ny >= m) continue;

		auto& [nh, nc] = container[ny][nx];

		if (nx == n - 1 && ny == m - 1)
			if (height <= nh) return -1;

		// 현재보다 낮은가?
		if (height <= nh) continue;

		// 더 들어가서 탐색
		int c = DFS(nx, ny);
		if (c >= 0)
		{
			count += c;
		}
	}

	return count;
}

int Search()
{
	DFS(0, 0);
	return container[0][0].second;
}

int main()
{
	Input();

	int result = Search();
	std::cout << ((result != -1) ? result : 0);

	return 0;
}