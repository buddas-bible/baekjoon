#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

struct Data
{
	Data(int _x, int _y) : x(_x), y(_y){}
	int x;
	int y;
};

int n = 0;
int m = 0;
std::vector<std::vector<int>> art;
std::vector<std::vector<bool>> visit;
std::queue<Data> search;

int artCount = 0;
int maxSize = 0;

int dx[4] = { 0, -1, 0, +1 };
int dy[4] = { -1, 0, +1, 0 };

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;

	std::vector<int> temp(m);
	std::vector<std::vector<int>> tempM(n, temp);
	std::vector<bool> vtemp(m);
	std::vector<std::vector<bool>> vtempM(n, vtemp);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> tempM[i][j];

	art = std::move(tempM);
	visit = std::move(vtempM);
}

int BFS(int _x, int _y, int _count)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		// 인덱스 확인
		if (nextX < 0) continue;
		if (nextY < 0) continue;
		if (nextX > m - 1) continue;
		if (nextY > n - 1) continue;

		// 그림인지 확인
		if (art[nextY][nextX] == 0) continue;

		// 방문 했는지 확인
		if (visit[nextY][nextX]) continue;

		// 큐에 넣고 다시 서치
		search.push({nextX, nextY});
		visit[nextY][nextX] = true;

		_count++;
	}

	return _count;
}

void BFS()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (art[i][j] == 0) continue;
			if (visit[i][j]) continue;

			search.push({ j, i });
			visit[i][j] = true;
			int count = 1;

			while (!search.empty())
			{
				Data data = search.front();
				search.pop();
				count = BFS(data.x, data.y, count);

				if (maxSize < count)
					maxSize = count;
			}
			artCount++;
		}
}

void Output()
{
	std::cout << artCount << '\n' << maxSize;
}

int main()
{
	Input();
	BFS();
	Output();

	return 0;
}