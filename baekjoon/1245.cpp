#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

int main()
{
	struct Data
	{
		Data(int _x, int _y) : x(_x), y(_y) {}
		int x;
		int y;
	};

	int N = 0;
	int M = 0;
	std::vector<std::vector<int>> mountain;
	std::vector<std::vector<bool>> visit;
	std::vector<std::vector<bool>> isSearch;
	std::vector<std::vector<bool>> temp;

	int dx[8] = { 0, -1, 0, +1, -1, -1, +1, +1 };
	int dy[8] = { -1, 0, +1, 0, -1, +1, -1, +1 };

	// input
	{
		std::cin.tie();
		std::cout.tie();
		std::ios_base::sync_with_stdio(false);

		freopen("input.txt", "rt", stdin);
		std::cin >> N >> M;

		mountain.resize(N);
		temp.resize(N);

		for (int i = 0; i < N; i++)
		{
			mountain[i].resize(M);
			temp[i].resize(M);

			for (int j = 0; j < M; j++)
				std::cin >> mountain[i][j];
		}
	}

	int result = 0;

	{
		isSearch = temp;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visit = temp;

				std::queue<Data> bfs;
				std::queue<Data> temtemtem;
				bfs.push({ j, i });
				temtemtem = bfs;
				visit[i][j] = true;
				int height = mountain[i][j];
				int maxHeight = mountain[i][j];

				if (isSearch[i][j])
					continue;

				while (!bfs.empty())
				{
					Data data = bfs.front();
					bfs.pop();

					// 현재 

					for (int k = 0; k < 8; k++)
					{
						int nextX = data.x + dx[k];
						int nextY = data.y + dy[k];

						// 인덱스 확인
						if (nextX < 0) continue;
						if (nextY < 0) continue;
						if (nextX > M - 1) continue;
						if (nextY > N - 1) continue;
						if (visit[nextY][nextX]) continue;

						int nextHeight = mountain[nextY][nextX];

						if (height == nextHeight)
						{
							bfs.push({ nextX, nextY });				// 탐색을 위한 큐
							temtemtem.push({ nextX, nextY });		// 나중에 탐색했었다. 라고 표시하기 위한 큐
							visit[nextY][nextX] = true;
						}
						else if (height < nextHeight)
						{
							maxHeight = nextHeight;
							break;
						}
					}
				}

				if (height == maxHeight && !isSearch[i][j])
				{
					result++;

					while (!temtemtem.empty())
					{
						Data data = temtemtem.front();
						temtemtem.pop();
						isSearch[data.y][data.x] = true;
					}
				}
			}
		}
	}

	std::cout << result;

	return 0;
}
