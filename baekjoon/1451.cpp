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
std::vector<std::vector<int>> rect;
std::stack<std::vector<Rect>> search;
int result = 0;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n >> m;

	rect = std::vector(n, std::vector<int>(m));

	for (size_t i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		for (size_t j = 0; j < m; j++)
		{
			char data = input[j];
			char zero = '0';
			rect[i][j] = data - zero;
		}
	}
}

void Divide()
{
	std::vector<Rect> arr;
	arr.emplace_back(0, 0);

	if (n > 2 && m > 2)
	{
		// case 1
		{
			// 1 2
			// 33
			int rect1 = 0;
			int rect2 = 0;
			int rect3 = 0;
			{
				// rect1
				// i x j

				// rect2
				// i x (m - j)

				// rect3
				// (n - i) x m
			}
		}

		// case 2
		{
			// 11
			// 2 3
			int rect1 = 0;
			int rect2 = 0;
			int rect3 = 0;
			for (int i = 0; i < n - 1; i++)
			{
				// rect1
				// i x m

				// rect2
				// (n - i) x j

				// rect3
				// (n - i) x (m - j)
			}
		}
	}


	// case 3
	if (n > 3)
	{

		// 11
		// 22
		// 33
		int rect1 = 0;
		int rect2 = 0;
		int rect3 = 0;
		for (int i = 0; i < m; i++)
		{
			// rect1
			// i x m

			// rect2
			// j x m

			// rect3
			// (n - i - j) x m
		}
	}

	// case 4
	if (m > 3)
	{
		// 1 2 3
		// 1 2 3
		int rect1 = 0;
		int rect2 = 0;
		int rect3 = 0;

		// rect1
		// n x i

		// rect2
		// n x j

		// rect3
		// n x (m - i - j)
		}
	}

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