#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int T = 0;
int M = 0;
int N = 0;
int K = 0;

int result = 0;

std::vector<std::vector<int>> container;
std::vector<std::vector<bool>> visit;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> T;
}

void Input2()
{
	result = 0;

	container.clear();
	visit.clear();

	std::cin >> M >> N >> K;
	container.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++)
	{
		container[i].resize(M);
		visit[i].resize(M);
	}

	int X = 0;
	int Y = 0;
	for (int i = 0; i < K; i++)
	{
		std::cin >> X >> Y;
		container[Y][X] = 1;
	}
}

bool Trip(int _X, int _Y)
{
	bool canX = _X > -1 && _X < M;
	bool canY = _Y > -1 && _Y < N;
	bool can = canX && canY;

	// 유효 인덱스가 아님
	if (!can)
		return false;

	// 배추가 없음
	if (!container[_Y][_X])
		return false;

	// 방문한 곳임
	if (visit[_Y][_X])
		return false;

	visit[_Y][_X] = true;

	// up이 가능함?
	if (_Y > 0)
	{
		// 방문이 가능함?
		bool canvisit = !visit[_Y - 1][_X] && container[_Y - 1][_X];
		if (canvisit)
			Trip(_X, _Y - 1);
	}

	// down이 가능함?
	if (_Y < N - 1)
	{
		// 방문이 가능함?
		bool canvisit = !visit[_Y + 1][_X] && container[_Y + 1][_X];
		if (canvisit)
			Trip(_X, _Y + 1);
	}

	// left가 가능함?
	if (_X > 0)
	{
		// 방문이 가능함?
		bool canvisit = !visit[_Y][_X - 1] && container[_Y][_X - 1];
		if (canvisit)
			Trip(_X - 1, _Y);
	}

	// right가 가능함?
	if (_X < M - 1)
	{
		// 방문이 가능함?
		bool canvisit = !visit[_Y][_X + 1] && container[_Y][_X + 1];
		if (canvisit)
			Trip(_X + 1, _Y);
	}

	return visit[_Y][_X];
}

void Output()
{
	std::cout << result << std::endl;
}

int main()
{
	Input();
	while (T--)
	{
		Input2();

		for (int x = 0; x < M; x++)
			for (int y = 0; y < N; y++)
				if (Trip(x, y))
				{
					result++;
				}
		Output();
	}

	return 0;
}