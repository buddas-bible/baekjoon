#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// 영단어 암기는 괴로워

int N = 0;	// 단어 개수
int M = 0;	// 길이 기준 N

struct Data
{
	Data() : m_str{}, m_count{}
	{}
	Data(const std::string& _str) : 
		m_str{ _str }, 
		m_count{}
	{}
	Data(const Data& _data) : 
		m_str{ _data.m_str }, 
		m_count{ _data.m_count }
	{}
	Data(Data&& _data) noexcept : 
		m_str{ std::move(_data.m_str) }, 
		m_count{ std::move(_data.m_count) }
	{}

	void operator=(const Data& _data)
	{
		if (this != &_data)
		{
			m_str = _data.m_str;
			m_count = _data.m_count;
		}
	}
	void operator=(Data&& _data) noexcept
	{
		if (this != &_data)
		{
			m_str = std::move(_data.m_str);
			m_count = std::move(_data.m_count);
		}
	}

	std::string m_str{};
	int m_count{};

	bool operator<(const Data& _data) const
	{
		if (m_count != _data.m_count)
		{
			return m_count < _data.m_count;
		}
		else
		{
			int L = m_str.size();
			int R = _data.m_str.size();

			if (L != R)
			{
				return L < R;
			}
			else
			{
				return m_str > _data.m_str;
			}
		}
	}
	bool operator<=(const Data& _data) const
	{
		return (*this < _data) || (*this == _data);
	}
	bool operator>(const Data& _data) const
	{
		return !(*this <= _data);
	}
	bool operator>=(const Data& _data) const
	{
		return !(*this < _data);
	}
	bool operator==(const Data& _data) const
	{
		return m_str == _data.m_str;
	}
	bool operator==(const std::string& _str) const
	{
		return m_str == _str;
	}
};

std::vector<Data> container;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		std::string str{};
		std::cin >> str;

		if (M > str.size())
			continue;

		auto itr = std::ranges::find(container, str);		// 이 구간이 시간을 많이 먹는 이유인듯.
		if (itr == container.end())
		{
			container.push_back({ str });
		}
		else
		{
			itr->m_count++;
		}
	}
}

bool Sort(Data& a, Data& b)
{
	return a > b;
}

void Sorting()
{
	std::sort(container.begin(), container.end(), Sort);
}

void Output()
{
	for (auto& e : container)
	{
		std::cout << e.m_str << std::endl;
	}
}

int main()
{
	Input();
	Sorting();
	Output();

	return 0;
}