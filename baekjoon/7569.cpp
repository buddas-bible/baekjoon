#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

struct Data
{
	Data(int _x, int _y, int _z) : x(_x), y(_y), z(_z), day()
	{}
	int x;
	int y;
	int z;
	int day;
};

int M = 0;
int N = 0;
int H = 0;

int dx[6] = { 0, -1, 0, +1, 0, 0 };
int dy[6] = { -1, 0, +1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, +1 };

std::vector<std::vector<std::vector<int>>> tomato;
std::vector<std::vector<std::vector<int>>> days;
std::queue<Data> bfs;

int result = 0;
int count = 0;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> M >> N >> H;

	std::vector<int> tempM(M);
	std::vector<std::vector<int>> tempN(N, tempM);
	std::vector<std::vector<std::vector<int>>> temp(H, tempN);
	days = temp;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				std::cin >> temp[i][j][k];

				if (temp[i][j][k] == 1)
					bfs.push({ k, j, i });
				else if(temp[i][j][k] == -1)
					days[i][j][k] = -1;
				else
					count++;
			}
		}
	}

	tomato = std::move(temp);
}

// ����
void Infection(int x, int y, int z, int day)
{
	for (int i = 0; i < 6; i++)
	{
		// ���� Ž���� ��
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		int nextZ = z + dz[i];

		// �ε��� �ʰ� ����
		if (nextX < 0) continue;
		if (nextY < 0) continue;
		if (nextZ < 0) continue;
		if (nextX > M - 1) continue;
		if (nextY > N - 1) continue;
		if (nextZ > H - 1) continue;

		// ����ִ� �������� üũ
		if (tomato[nextZ][nextY][nextX] == -1)
			continue;

		// �̹� ���� �丶������ üũ
		if (tomato[nextZ][nextY][nextX] == 1)
			continue;

		// �丶�並 ������ �ϼ��� �ø�.
		tomato[nextZ][nextY][nextX] = 1;
		days[nextZ][nextY][nextX] = day + 1;
		bfs.push({ nextX, nextY, nextZ });

		// �ִ� �ϼ��� ������.
		result = std::max(days[nextZ][nextY][nextX], result);
		
		// ���� ���� �丶���� ������ ����
		count--;
	}
}

void Infection()
{
	while (!bfs.empty())
	{
		Data data = bfs.front();
		bfs.pop();
		Infection(data.x, data.y, data.z, days[data.z][data.y][data.x]);
	}
}

void Output()
{
	if (count)
		std::cout << -1;
	else
		std::cout << result;
}

int main()
{
	Input();
	Infection();
	Output();

	return 0;
}