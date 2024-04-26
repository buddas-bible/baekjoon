#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

struct Data
{
	Data(int _x, int _y) : x(_x), y(_y), days(0) {}
	Data(int _x, int _y, int _day) : x(_x), y(_y), days(_day) {}
	int x;
	int y;
	int days;
};

std::vector<std::vector<char>> miro;
std::queue<Data> search;

int dx[9] = {0, 0, -1, 0, +1, -1, +1, -1, +1 };
int dy[9] = {0, -1, 0, +1, 0, -1, -1, +1, +1 };

int result = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::vector<std::vector<char>> input(8, std::vector<char>(8));
	miro = std::move(input);

	freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			std::cin >> miro[i][j];
}

bool BFS(Data data)
{
	if (data.x == 7 && data.y == 0)
	{
		result = 1;
		return true;
	}

	// 내가 서있는 곳이 벽인가?
	const int currWall = data.y - data.days;
	char temp = 0;
	if (currWall < 0)
		temp = '.';
	else if (currWall > 7)
		temp = '.';
	else if (-1 < currWall && currWall < 8)
		temp = miro[currWall][data.x];

	// 벽이네?
	if (temp == '#')
		return false;

	for (int i = 0; i < 9; i++)
	{
		int nextX = data.x + dx[i];
		int nextY = data.y + dy[i];

		// 인덱스 체크
		if (nextX < 0) continue;
		if (nextY < 0) continue;
		if (nextX > 7) continue;
		if (nextY > 7) continue;

		char value = 0;

		// 내가 이동할 수 있는 곳이 있는가
		if (nextY - data.days < 0)
			value = '.';
		else if (nextY - data.days > 7)
			value = '.';
		else if (-1 < nextY - data.days && nextY - data.days < 8)
			value = miro[nextY - data.days][nextX];

		if (value == '.')
			search.push({ nextX, nextY, data.days + 1 });
		else
			continue;
	}

	return false;
}


void BFS()
{
	search.push({ 0, 7, 0 });

	while (!search.empty())
	{
		Data data = search.front();
		search.pop();
		if (BFS(data))
			break;
	}
}

void Output()
{
	std::cout << result;
}

int main()
{
	Input();
	BFS();
	Output();

	return 0;
}