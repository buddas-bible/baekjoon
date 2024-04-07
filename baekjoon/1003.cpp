#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

int T = 0;
int N = 0;
std::vector<std::pair<int, int>> container;

//const std::pair<int, int>& operator+(const std::pair<int, int>& _lhs, const std::pair<int, int>& _rhs)
//{
//	return std::make_pair(_lhs.first + _rhs.first, _lhs.second + _rhs.second);
//}

//std::ostream& operator<< (std::ostream& _out, const std::pair<int, int>& _rhs)
//{
//	return _out << _rhs.first << " " << _rhs.second;
//}

std::pair<int, int> fibonacci(int n)
{
	if (n == 0) 
	{
		return container[n];
	}
	else if (n == 1) 
	{
		return container[n];
	}
	else 
	{
		std::pair<int, int>& n_1 = container[n - 1];
		std::pair<int, int>& n_2 = container[n - 2];

		// 값이 없다면 		
		if (n_1 == std::make_pair(0, 0))
		{	
			// 재귀를 돌아서 값을 찾아옴
			n_1 = fibonacci(n - 1);
		}

		if (n_2 == std::make_pair(0, 0))
		{
			n_2 = fibonacci(n - 2);
		}

		// n 에서의 호출 값은 (n - 1) + (n - 2) 값과 같음 
		container[n] = std::make_pair(n_1.first + n_2.first, n_1.second + n_2.second);
		return container[n];
	}
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	container.resize(41);
	container[0] = std::make_pair(1, 0);
	container[1] = std::make_pair(0, 1);

	fibonacci(40);

	std::cin >> T;

	while (T--)
	{
		std::cin >> N;

		// std::cout << container[N] << std::endl;
		std::cout << container[N].first << " " << container[N].second << std::endl;
	}

	return 0;
}