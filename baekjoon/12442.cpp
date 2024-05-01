#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

struct Data
{
	int now;
	int days;
};

struct Friend
{
	Friend() : from(), speed() {}
	Friend(int _from, int _v) : from(_from), speed(_v) {}
	int from;
	int speed;
};

struct Street
{
	Street() : to(), distance{} {}
	Street(int _to, int _d) : to(_to), distance{ _d } {}

	int to;
	int distance;
};

struct City
{
	bool visit = false;
	int days = -1;
	std::vector<Street> street;
};

int Case = 1;
int result = 0;
int T = 0;		// �׽�Ʈ ���̽�
int N = 0;		// ������ ��
int P = 0;		// ģ���� ��
int M = 0;		// ������ ��
std::vector<Friend> data;
std::vector<City> city;
std::queue<Data> search;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> T;
}

void Create()
{
	result = 2147483647;

	std::cin >> N >> P >> M;

	std::vector<Friend> friendTemp(P);
	std::vector<City> cityTemp(N + 1);

	data = std::move(friendTemp);
	city = std::move(cityTemp);

	// ģ������ ���� ���� ��ġ�� �ӵ�
	for (int i = 0; i < P; i++)
	{
		std::cin >> data[i].from >> data[i].speed;
	}

	// ���� ������ ����
	for (int i = 0; i < M; i++)
	{
		int D = 0;
		int L = 0;
		std::cin >> D >> L;

		std::vector<int> temp(L);

		for (int j = 0; j < L; j++)
		{
			// ���η� ����� ���õ�
			std::cin >> temp[j];
		}

		// ���θ� �������� �迭�� ����
		for (int a = 0; a < L - 1; a++)
		{
			int currCity = temp[a];
			int nextCity = temp[a + 1];
			int distance = D;

			city[currCity].street.push_back({ nextCity, D });
			city[nextCity].street.push_back({ currCity, D });
		}
	}
}

int Trip(int _index, int _from, int _speed, int _accumulate)
{
	city[_from].visit = true;									// �湮
	city[_from].days = std::max(city[_from].days, _accumulate);	// �湮�� ���ÿ��� ���� ��� �ɸ��� �ð�

	for (int i = 0; i < city[_from].street.size(); i++)
	{
		int to = city[_from].street[i].to;				// ���ο� ����� ���� ����
		int distance = city[_from].street[i].distance;	// ���� ���ÿ��� �Ÿ�

		if (city[to].visit) continue;					// �湮�� ���� �ѱ�

		search.push({ to, (_speed * distance) + _accumulate });
	}

	int can = 0;

	for (int j = 0; j < data.size(); j++)
	{
		bool same = _index == j;
		bool meet = _from == data[j].from;

		if ((!same) && meet)					// ���� ���� ���� ��� ������ ī����
			can++;
	}

	return can;
}

void Trip()
{
	for (int i = 0; i < P; i++)
	{
		int from = data[i].from;			// ģ���� ��ġ
		int speed = data[i].speed;			// ģ���� �ӵ�
		int accumulate = 0;					// ���� �ð�
		int count = 0;

		search.push({ from, accumulate });	// ��ġ�� ���� �ð��� ť�� �ְ� Ž��
		while (!search.empty())
		{
			Data d = search.front();
			search.pop();
			int meet = Trip(i, d.now, speed, d.days);
			count += meet;
		}

		if (count != P - 1)
		{
			result = -1;					// i�� ���ø� ���鼭 ���� ģ���� ���� ���� �ʴٸ�?
		}

		for (int a = 0; a < city.size(); a++)
		{
			city[a].visit = false;			// �湮 ��� �ʱ�ȭ
		}
	}

	for (int a = 1; a < city.size(); a++)
	{
		if (city[a].days == -1)	continue;				// ����� �� ������ �ѱ�

		result = std::min(city[a].days, result);		// ���� ���� �ϼ�
	}
}

void Output()
{
	std::cout << "Case #" << Case++ << ": " << result << '\n';
}

int main()
{
	Input();
	while (T--)
	{
		Create();
		Trip();
		Output();
	}

	return 0;
}