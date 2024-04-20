#define _CRT_SECURE_NO_WARNINGS
#define INF 0x0f'ff'ff'ff;
#include <iostream>
#include <vector>
#include <queue>

struct Data
{
	Data(int _x, int _y) : x(_x), y(_y)
	{}
	int x;
	int y;
};

int dx[4] = { 0, -1, 0, +1 };
int dy[4] = { -1, 0, +1, 0 };

int N = 2;
std::vector<std::vector<int>> cave;		// 동굴에 퍼진 루피
std::vector<std::vector<int>> rupee;	// 해당 위치까지 최소한의 루피
std::queue<Data> bfs;					// 인덱스 큐
int count = 1;
int result = 0;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
}

void CreateCave()
{
	std::cin >> N;

	if (N == 0)
		return;

	result = INF;

	std::vector<int> temp(N);
	std::vector<int> tempR(N, result);
	std::vector<std::vector<int>> tempN(N, temp);
	std::vector<std::vector<int>> tempNR(N, tempR);

	while (!bfs.empty())
	{
		bfs.pop();
	};

	cave = std::move(tempN);
	rupee = std::move(tempNR);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> cave[i][j];
		}
	}
}

void Trip(int _X, int _Y, int _result)
{
	// 마지막 인덱스면 끝.
	if ((_X == N - 1) && (_Y == N - 1))
	{
		result = rupee[N - 1][N - 1];
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = _X + dx[i];
		int nextY = _Y + dy[i];

		// 인덱스 초과 체크
		if (nextY < 0) continue;
		if (nextX < 0) continue;
		if (nextX > N - 1) continue;
		if (nextY > N - 1) continue;

		// 지금 경로에서 다음 위치로 이동했을 때 얻을 수 있는 루피
		int value = _result + cave[nextY][nextX];

		// 지금 경로가 다른 경로보다 최적화된 경로인가?
		if (value < rupee[nextY][nextX])
		{
			// 해당 인덱스를 큐에 넣고 탐색
			bfs.push(Data{ nextX, nextY });
			rupee[nextY][nextX] = value;
		}
	}
}

void Trip()
{
	bfs.push(Data{ 0, 0 });
	rupee[0][0] = cave[0][0];

	while (!bfs.empty())
	{
		Data pos = bfs.front();
		bfs.pop();
		Trip(pos.x, pos.y, rupee[pos.y][pos.x]);
	};
}

void Output()
{
	std::cout << "Problem " << count++ << ": " << result << std::endl;
}

int main()
{
	Input();

	while (true)
	{
		CreateCave();
		if (N == 0)
			break;
		
		Trip();
		Output();
	}

	return 0;
}