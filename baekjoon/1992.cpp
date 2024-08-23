#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

int n = 0;
std::vector<std::vector<int>> container;

struct vec2
{
	vec2() : x(), y() {}
	vec2(int _x, int _y) : x(_x), y(_y) {}
	vec2(const vec2& _vec) : x(_vec.x), y(_vec.y) {}
	vec2(vec2&& _vec) noexcept : x(_vec.x), y(_vec.y) {}
	vec2& operator= (const vec2& _vec)
	{
		if (this != &_vec)
		{
			x = _vec.x;
			y = _vec.y;
		}
		return *this;
	}
	vec2& operator= (vec2&& _vec) noexcept
	{
		if (this != &_vec)
		{
			_vec.x = _vec.x;
			_vec.y = _vec.y;
		}
		return *this;
	}
	vec2& operator+= (const vec2& _vec)
	{
		x += _vec.x;
		y += _vec.y;
		return *this;
	}
	vec2 operator+ (const vec2& _vec)
	{
		vec2 temp(*this);
		return temp += _vec;
	}
	vec2& operator-= (const vec2& _vec)
	{
		x -= _vec.x;
		y -= _vec.y;
		return *this;
	}
	vec2 operator- (const vec2& _vec)
	{
		vec2 temp(*this);
		return temp -= _vec;
	}
	vec2& operator/= (int _num)
	{
		x /= _num;
		y /= _num;

		return *this;
	}
	vec2 operator/ (int _num)
	{
		vec2 temp(*this);
		return temp /= _num;
	}
	vec2& operator*= (int _num)
	{
		x *= _num;
		y *= _num;

		return *this;
	}
	vec2 operator* (int _num)
	{
		vec2 temp(*this);
		return temp *= _num;
	}

	int x = 0;
	int y = 0;
};

struct Bound
{
	Bound() {}
	Bound(const vec2& _min, const vec2& _max) : minimum(_min), maximum(_max) {}
	Bound(const Bound& _bound) : minimum(_bound.minimum), maximum(_bound.maximum) {}
	Bound(Bound&& _bound) noexcept : minimum(_bound.minimum), maximum(_bound.maximum) {}
	Bound& operator= (const Bound& _bound)
	{
		if (this != &_bound)
		{
			minimum = _bound.minimum;
			maximum = _bound.maximum;
		}
		return *this;
	}
	Bound& operator= (Bound&& _bound) noexcept
	{
		if (this != &_bound)
		{
			minimum = _bound.minimum;
			maximum = _bound.maximum;
		}
		return *this;
	}

	vec2 minimum;
	vec2 maximum;
};

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> n;
	container.resize(n);

	for (int i = 0; i < n; i++)
	{
		container[i].resize(n);

		std::string str;
		std::cin >> str;

		for (int j = 0; j < str.size() - 1; j++)
		{
			container[i][j] = str[j] - '0';
		}
	}
}

std::string NodeSearch(Bound _bound)
{
	std::string result;

	if ((_bound.maximum.x - _bound.minimum.x + 1) > 2 || (_bound.maximum.y - _bound.minimum.y + 1) > 2)
	{
		vec2 mid = (_bound.minimum + _bound.maximum) / 2;
		vec2 diff = (_bound.maximum - _bound.minimum) / 2;
		int dx[4] = { -diff.x, diff.x, -diff.x, diff.x };
		int dy[4] = { -diff.y, -diff.y, diff.y, diff.y };
		int xOffset[4] = { 0, 1, 0, 1 };
		int yOffset[4] = { 0, 0, 1, 1 };

		Bound bound[4];
		std::string zero = "0";
		std::string one = "1";
		std::string boundStr[4];

		for (int i = 0; i < 4; i++)
		{
			vec2 newMid = mid + vec2(xOffset[i], yOffset[i]);
			vec2 dv = vec2(dx[i], dy[i]);
			vec2 temp = newMid + dv;

			vec2 minumum{ std::min(temp.x, newMid.x), std::min(temp.y, newMid.y) };
			vec2 maximum{ std::max(temp.x, newMid.x), std::max(temp.y, newMid.y) };

			bound[i] = Bound(minumum, maximum);
		}

		for (int i = 0; i < 4; i++)
		{
			boundStr[i] = NodeSearch(bound[i]);
		}

		bool sameZero = boundStr[0].compare(zero) == 0;
		bool sameOne = boundStr[0].compare(one) == 0;
		bool same0 = boundStr[0].compare(boundStr[1]) == 0;
		bool same1 = boundStr[1].compare(boundStr[2]) == 0;
		bool same2 = boundStr[2].compare(boundStr[3]) == 0;

		if ((sameZero || sameOne) && (same0 && same1 && same2))
		{
			result += boundStr[0];
		}
		else
		{
			result += ("(" + boundStr[0] + boundStr[1] + boundStr[2] + boundStr[3] + ")");
		}
	}
	else
	{
		int lu = container[_bound.minimum.y][_bound.minimum.x];
		int ru = container[_bound.minimum.y][_bound.maximum.x];
		int ld = container[_bound.maximum.y][_bound.minimum.x];
		int rd = container[_bound.maximum.y][_bound.maximum.x];

		bool same = (lu == ru) && (ru == ld) && (ld == rd);

		if (same)
		{
			result = std::to_string(lu);
		}
		else
		{
			result = ("(" + std::to_string(lu) + std::to_string(ru) + std::to_string(ld) + std::to_string(rd) + ")");
		}
	}

	return result;
}

int main()
{
	Input();
	std::cout << NodeSearch(Bound({ 0, 0 }, { n - 1, n - 1 }));

	return 0;
}


/*
1 1		1 1	 |	0 0		0 0
1 1		1 1	 |	0 0		0 0

0 0		0 1	 |	1 1		0 0
0 0		0 1	 |	1 1		0 0

---------------------------

1 1		1 1	 |	0 0		0 0
1 1		1 1	 |	0 0		0 0

1 1		1 1	 |	0 0		1 1
1 1		1 1	 |	0 0		1 1

(110 (0101)) (0 0 1 0)
1			 (0 0 0 1)


0 0		0 0	 |	0 0		0 0
0 0		0 0	 |	0 0		0 0

0 0		0 0	 |	1 1		1 1
0 0		0 0	 |	1 1		1 1

---------------------------

0 0		0 1	 |	1 1		1 1
0 0		1 1	 |	1 1		1 1

0 0		1 1	 |	1 1		1 1
0 0		1 1	 |	1 1		1 1

0				(0 0 1 1)
(0 (0111) 0 1)	1
*/