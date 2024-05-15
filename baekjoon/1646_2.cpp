#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


int n = 0;
int m = 0;
std::vector< std::pair< int, std::pair<int, int > > > streets;
std::vector<int> parent;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;
	parent.resize(n + 1);

	for (size_t i = 0; i < m; i++)
	{
		int A = 0;
		int B = 0;
		int value = 0;
		std::cin >> A >> B >> value;

		auto fromTo = std::minmax(A, B);
		streets.emplace_back(value, fromTo);
	}

	std::sort(streets.begin(), streets.end());

	for (size_t i = 1; i < n + 1; i++)
		parent[i] = i;
}

int RootSearch(int _from)
{
	if (_from == parent[_from])
		return _from;

	return parent[_from] = RootSearch(parent[_from]);
}

void UnionRoot(int _A, int _B)
{
	_A = RootSearch(_A);
	_B = RootSearch(_B);

	if (_A != _B)
		parent[_B] = _A;
}

std::vector<std::pair< int, std::pair<int, int > >> Kruscal()
{
	std::vector<std::pair< int, std::pair<int, int > >> result;

	for (size_t i = 0; i < streets.size(); i++)
	{
		auto street = streets[i];

		auto& [from, to] = street.second;

		if (RootSearch(parent[from]) == RootSearch(parent[to]))
			continue;

		result.push_back(street);

		UnionRoot(from, to);

		if (result.size() == n - 1)
			break;
	}

	return result;
}

int main()
{
	Input();
	auto a = Kruscal();
	
	int result = 0;
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		result += a[i].first;
	}
	std::cout << result;

	return 0;
}