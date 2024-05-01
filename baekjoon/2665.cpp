#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

struct Data
{
	Data() : x(), y(), d(999999)
	{}
	Data(int _x, int _y) : x(_x), y(_y), d(999999)
	{}

	Data(int _x, int _y, int _d) : x(_x), y(_y), d(_d)
	{}

	int x;
	int y;
	int d;
};

int n = 0;
std::vector<std::vector<int>> miro;				// 미로 정보
std::vector<std::vector<int>> distance;			// 해당 좌표에 도달하기 위해 부순 벽의 최소 개수
std::queue<Data> search;

int dx[4] = { 0,-1,0,+1 };
int dy[4] = { -1,0,+1,0 };


void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;

	std::vector<int> temp(n, 9999999);
	std::vector<std::vector<int>> init(n, temp);

	std::vector<int> tempD(n);
	std::vector<std::vector<int>> input(n, tempD);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			input[i][j] = static_cast<int>(str[j] - '0');
		}
	}

	miro = std::move(input);
	distance = std::move(init);
}

void BFS(Data _data)
{
	if (_data.x == n - 1 && _data.y == n - 1)
		return;

	for (int i = 0; i < 4; i++)
	{
		int nx = _data.x + dx[i];
		int ny = _data.y + dy[i];

		// 인덱스 확인
		if (nx < 0) continue;
		if (ny < 0) continue;
		if (nx > n - 1) continue;
		if (ny > n - 1) continue;

		int newD = _data.d;

		// 벽인가?
		if (miro[ny][nx] == 0)
		{
			// 내가 걸어오고 있는 이 길이 더 적은 벽을 부쉈는가
			if (distance[ny][nx] > newD + 1)
			{
				newD++;
				distance[ny][nx] = newD;
				search.push({ nx, ny, newD });
			}
		}
		else
		{
			if (distance[ny][nx] > newD)
			{
				// 벽이 아니면 지금 걷는거랑 같음.
				distance[ny][nx] = newD;
				search.push({ nx, ny, newD });
			}
		}
	}
}

void BFS()
{
	int d = 0;
	if (miro[0][0] == 0)
	{
		d = 1;
		distance[0][0] = 1;
	}
	else
	{
		d = 0;
		distance[0][0] = 0;
	}

	search.push({ 0, 0, d });

	while (!search.empty())
	{
		const Data data = search.front();
		search.pop();
		BFS(data);
	}
}

void Output()
{
	std::cout << distance[n - 1][n - 1];
}

int main()
{
	Input();
	BFS();
	Output();

	return 0;
}