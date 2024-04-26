#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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