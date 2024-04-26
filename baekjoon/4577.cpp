#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int R = 0;
int C = 0;
std::vector<std::vector<char>> map;

struct Vec2
{
	Vec2() : x(), y() {}
	Vec2(int _x, int _y) : x(_x), y(_y) {}
	int x;
	int y;

	Vec2& operator=(const Vec2& _vec)
	{
		if (this != &_vec)
		{
			x = _vec.x;
			y = _vec.y;
		}

		return *this;
	}
	Vec2& operator=(Vec2&& _vec) noexcept
	{
		if (this != &_vec)
		{
			x = std::move(_vec.x);
			y = std::move(_vec.y);
		}

		return *this;
	}

	Vec2& operator+=(const Vec2& _vec)
	{
		x += _vec.x;
		y += _vec.y;

		return *this;
	}
	Vec2 operator+(const Vec2& _vec) const
	{
		Vec2 temp(*this);

		return temp += _vec;
	}

	Vec2& operator-=(const Vec2& _vec)
	{
		x -= _vec.x;
		y -= _vec.y;

		return *this;
	}
	Vec2 operator-(const Vec2& _vec) const
	{
		Vec2 temp(*this);

		return temp -= _vec;
	}
};

Vec2 u{0 ,- 1 };
Vec2 d{0,+ 1 };
Vec2 l{-1, 0};
Vec2 r{+1, 0};

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);



}

int main()
{
	Input();

	return 0;
}