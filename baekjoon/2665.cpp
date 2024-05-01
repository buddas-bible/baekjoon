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
std::vector<std::vector<int>> miro;				// �̷� ����
std::vector<std::vector<int>> distance;			// �ش� ��ǥ�� �����ϱ� ���� �μ� ���� �ּ� ����
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

		// �ε��� Ȯ��
		if (nx < 0) continue;
		if (ny < 0) continue;
		if (nx > n - 1) continue;
		if (ny > n - 1) continue;

		int newD = _data.d;

		// ���ΰ�?
		if (miro[ny][nx] == 0)
		{
			// ���� �ɾ���� �ִ� �� ���� �� ���� ���� �ν��°�
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
				// ���� �ƴϸ� ���� �ȴ°Ŷ� ����.
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