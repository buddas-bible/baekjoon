#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stack>

struct Rect;

struct Rect
{
	Rect() : min(), max() 
	{}
	Rect(int _min, int _max) : min(_min), max(_max)
	{}
	Rect(const Rect& _rect) : min(_rect.min), max(_rect.max)
	{}
	Rect(Rect&& _rect) noexcept : min(_rect.min), max(_rect.max)
	{}
	Rect& operator=(const Rect& _rect)
	{
		if (this != &_rect)
		{
			min = _rect.min;
			max = _rect.max;
		}
		return *this;
	}
	Rect& operator=(Rect&& _rect) noexcept
	{
		if (this != &_rect)
		{
			*this = std::move(_rect);
		}
		return *this;
	}
	int min = 0;
	int max = 0;
};

int n = 0;
int m = 0;
std::vector < std::vector < std::pair<int, bool> > > rect;
std::stack<std::vector<Rect>> search;
int result = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;

	rect = std::vector(n, std::vector<std::pair<int, bool> >(m));

	for (size_t i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		for (size_t j = 0; j < m; j++)
		{
			char data = input[j];
			char zero = '0';
			rect[i][j].first = data - zero;
			rect[i][j].second = false;
		}
	}
}

void Divide()
{
	std::vector<Rect> arr;
	arr.emplace_back(0, 0);
}

void Output()
{
	std::cout << result;
}

int main()
{
	Input();
	Divide();
	Output();

	return 0;
}