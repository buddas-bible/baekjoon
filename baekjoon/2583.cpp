#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

int m = 0;	// 가로
int n = 0;	// 세로
int k = 0;	// 직사각형 개수

std::vector<std::vector<bool>> visit;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> m >> n >> k;
	visit.resize(m, std::vector<bool>(n, false));

	for (int i = 0; i < k; i++)
	{
		int box0x = 0;
		int box0y = 0;
		int box1x = 0;
		int box1y = 0;
		std::cin >> box0x >> box0y >> box1x >> box1y;

		for (int y = box0y; y < box1y; y++)
		{
			for (int x = box0x; x < box1x; x++)
			{
				visit[y][x] = true;
			}
		}
	}
}

int Search(int _x, int _y)
{
	int result = 0;
	std::queue<std::pair<int, int>> search;
	search.push({ _x, _y });
	visit[_y][_x] = true;

	while (!search.empty())
	{
		auto [x, y] = search.front();
		search.pop();
		result++;

		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위 내
			if (nx < 0 || ny < 0) continue;
			if (nx >= n || ny >= m) continue;

			// 방문 여부
			if (visit[ny][nx]) continue;

			visit[ny][nx] = true;
			search.push({ nx, ny });
		}
	}

	return result;
}

int main()
{
	Input();

	std::vector<int> c;

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visit[y][x])
				c.emplace_back(Search(x, y));
		}
	}

	std::sort(c.begin(), c.end());

	std::cout << c.size() << '\n';

	for (auto& e : c)
	{
		std::cout << e << " ";
	}

	return 0;
}