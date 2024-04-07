#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>


struct A
{
	constexpr A() : h(), w(), total() {}

	A(int h, int w) :
		total(h * h + w * w),
		h(h),
		w(w)
	{}

	constexpr A(const A& _other) :
		total(_other.total),
		h(_other.h),
		w(_other.w)
	{}

	constexpr A(A&& _other) noexcept :
		total(_other.total),
		h(_other.h),
		w(_other.w)
	{}

	constexpr A& operator=(const A& _other)
	{
		if (this != &_other)
		{
			total = _other.total;
			h = _other.h;
			w = _other.w;
		}

		return *this;
	}

	constexpr A& operator=(A&& _other) noexcept
	{
		if (this != &_other)
		{
			total = _other.total;
			h = _other.h;
			w = _other.w;
		}

		return *this;
	}

	int total = 0;
	int h = 0;
	int w = 0;

	bool operator<(const A& _other) const
	{
		if (this->total != _other.total)
		{
			return total < _other.total;
		}
		else
		{
			return this->h < _other.h;
		}
	}
};

std::set<A> map;

constexpr void Get()
{
	for (int h = 1; h < 151; h++)
	{
		for (int w = h + 1; w < 152; w++)
		{
			map.insert( std::move(A( h,  w )) );
		}
	}
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);

	Get();

	int h = 0;
	int w = 1;

	int H = 0;
	int W = 0;

	while (true)
	{
		std::cin >> h >> w;

		if (h == 0 && w == 0)
			break;

		auto itr = map.find(A(h, w));

		if (itr != map.end())
		{
			itr++;

			H = (*itr).h;
			W = (*itr).w;
			std::cout << H << " " << W << std::endl;;
		}
	}


	return 0;
}
