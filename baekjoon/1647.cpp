#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Street
{
	Street() : to(), value()
	{}
	Street(int _to, int _value) : to(_to), value(_value)
	{}
	Street(const Street& _st) : to(_st.to), value(_st.value)
	{}
	Street(Street&& _st) noexcept : to(_st.to), value(_st.value)
	{}
	Street& operator=(const Street& _st)
	{
		if (this != &_st)
		{
			to = _st.to;
			value = _st.value;
		}
		return *this;
	}
	Street& operator=(Street&& _st) noexcept
	{
		if (this != &_st)
		{
			*this = std::move(_st);
		}
		return *this;
	}
	bool operator==(const Street& _st)
	{
		return to == _st.to;
	}
	int to;
	int value;
};

int n = 0;
int m = 0;
std::vector<std::vector<Street>> input;
std::vector<std::vector<int>> graph;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;
	input.resize(n + 1);
	graph = std::vector(n + 1, std::vector<int>(n + 1, 0x7fffffff));

	for (size_t i = 0; i < m; i++)
	{
		int A = 0;
		int B = 0;
		int value = 0;
		std::cin >> A >> B >> value;
		input[A].emplace_back(B, value);
		input[B].emplace_back(A, value);
	}
}

void BFS(int _from, std::queue<std::pair<int, int>>& _search)
{
	while (!_search.empty())
	{
		auto [to, value] = _search.front();
		_search.pop();

		if (_from == to)
		{
			graph[_from][to] = 0;
			return;
		}

		if (graph[_from][to] < value)
		{
			return;
		}
		else
		{
			graph[_from][to] = value;
		}

		for (auto& streets : input[to])
		{
			int newValue = streets.value + graph[_from][to];
			if (newValue < graph[_from][streets.to])
			{
				if (_from == streets.to)
				{
					graph[_from][streets.to] = 0;
					continue;
				}

				// graph[streets.to][_from] = newValue;
				graph[_from][streets.to] = newValue;
				_search.push({ streets.to, newValue });
			}
		}
	}
}

void Search()
{
	for (size_t i = 1; i < n + 1; i++)
	{
		std::queue<std::pair<int, int>> search;

		for (auto street : input[i])
		{
			search.push({ street.to, street.value });
		}

		BFS(i, search);
	}
}

int main()
{
	Input();
	Search();
	

	return 0;
}