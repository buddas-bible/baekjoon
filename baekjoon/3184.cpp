#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

int areaX = 0;
int areaY = 0;

struct Data
{
	int x = 0;
	int y = 0;
};

struct Area
{
	int index = 0;

	int v = 0;
	int o = 0;
};

using Visit = std::vector<std::vector<bool>>;
std::vector<std::vector<char>> container;
Visit visit;
std::vector<Area> area;
std::vector<std::queue<Data>> search;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> areaX >> areaY;
	container.resize(areaY, std::vector<char>(areaX));

	for (int i = 0; i < areaY; i++)
	{
		for (int j = 0; j < areaX; j++)
		{
			std::cin >> container[areaY][areaX];

			// ���̸� ��ŵ
			if (container[areaY][areaX] == '#')
			{
				visit[areaY][areaX] = true;
				continue;
			}

			Data data;
			data.x = areaX;
			data.y = areaY;

			std::queue<Data> temp;
			temp.push(data);

			search.push_back(temp);
		}
	}
}

bool BFS(Data _data, std::queue<Data>& _search, Area& _area)
{
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	for (int i = 0; i < 4; i++)
	{
		int nextX = _data.x + dx[i];
		int nextY = _data.y + dy[i];

		// ���� üũ
		if (nextX > 10 || nextY > 10)
			continue;

		// ���� üũ
		if (nextX < 0 || nextY < 0)
			continue;

		// �湮 ���� üũ
		if (visit[nextY][nextX])
			continue;

		// ���̸� Ž�� ����
		if (container[nextY][nextX] == '#')
			continue;

		Data nextData;
		nextData.x = nextX;
		nextData.y = nextY;

		if (container[nextY][nextX] == 'o')
			_area.o++;
		if (container[nextY][nextX] == 'v')
			_area.v++;

		// �� �����̸� Ž����
		_search.push(nextData);
	}
}

void BFS()
{
	for (int i = 0; i < search.size(); i++)
	{
		Area areaTemp;

		while (!search[i].empty())
		{
			Data data = search[i].front();
			search[i].pop();
			BFS(data, search[i], areaTemp);
		}
	}
}

int main()
{
	Input();

	for (int i = 0; i < )
	{
	}

	return 0;
}