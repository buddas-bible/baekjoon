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
int T = 0;		// 테스트 케이스
int N = 0;		// 도시의 수
int P = 0;		// 친구의 수
int M = 0;		// 도로의 수
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

	// 친구들의 시작 도시 위치와 속도
	for (int i = 0; i < P; i++)
	{
		std::cin >> data[i].from >> data[i].speed;
	}

	// 도로 정보를 저장
	for (int i = 0; i < M; i++)
	{
		int D = 0;
		int L = 0;
		std::cin >> D >> L;

		std::vector<int> temp(L);

		for (int j = 0; j < L; j++)
		{
			// 도로로 연결된 도시들
			std::cin >> temp[j];
		}

		// 도로를 바탕으로 배열을 만듬
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
	city[_from].visit = true;									// 방문
	city[_from].days = std::max(city[_from].days, _accumulate);	// 방문한 도시에서 만날 경우 걸리는 시간

	for (int i = 0; i < city[_from].street.size(); i++)
	{
		int to = city[_from].street[i].to;				// 도로와 연결된 다음 도시
		int distance = city[_from].street[i].distance;	// 다음 도시와의 거리

		if (city[to].visit) continue;					// 방문한 곳은 넘김

		search.push({ to, (_speed * distance) + _accumulate });
	}

	int can = 0;

	for (int j = 0; j < data.size(); j++)
	{
		bool same = _index == j;
		bool meet = _from == data[j].from;

		if ((!same) && meet)					// 본인 말고 만난 사람 있으면 카운팅
			can++;
	}

	return can;
}

void Trip()
{
	for (int i = 0; i < P; i++)
	{
		int from = data[i].from;			// 친구의 위치
		int speed = data[i].speed;			// 친구의 속도
		int accumulate = 0;					// 누적 시간
		int count = 0;

		search.push({ from, accumulate });	// 위치와 누적 시간을 큐에 넣고 탐색
		while (!search.empty())
		{
			Data d = search.front();
			search.pop();
			int meet = Trip(i, d.now, speed, d.days);
			count += meet;
		}

		if (count != P - 1)
		{
			result = -1;					// i가 도시를 돌면서 만난 친구의 수가 맞지 않다면?
		}

		for (int a = 0; a < city.size(); a++)
		{
			city[a].visit = false;			// 방문 기록 초기화
		}
	}

	for (int a = 1; a < city.size(); a++)
	{
		if (city[a].days == -1)	continue;				// 계산한 적 없으면 넘김

		result = std::min(city[a].days, result);		// 가장 적은 일수
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