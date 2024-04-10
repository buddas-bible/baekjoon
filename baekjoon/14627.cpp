#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

unsigned long long S = 0;	// 파 개수
unsigned long long C = 0;	// 파닭의 수
// 파 <= 파닭

std::vector<unsigned long long> container;
std::vector<unsigned long long> carry;

unsigned long long min = 1;
unsigned long long mid = 0;
unsigned long long goodS = 0;
unsigned long long max = 0;

int F(unsigned long long L, unsigned long long N)
{
	// 길이 L의 파를 N만큼 잘랐을 때 몇 깨의 파닭을 만들 수 있을 까
	return L / N;
}

void Input()
{
	freopen("input.txt", "rt", stdin);
	std::cin >> S >> C;

	container.resize(S);

	for (unsigned long long i = 0; i < S; i++)
	{
		std::cin >> container[i];

		if (container[i] > max)
		{
			max = container[i];
		}
	}
}

bool Can(unsigned long long value)
{
	unsigned long long acc = 0;
	for (unsigned long long i = 0; i < S; i++)
	{
		unsigned long long A = F(container[i], value);
		acc += A;
	}

	// 파들을 value 값만큼 나누면 파닭의 수만큼 만들 수 있을까?
	return C <= acc;
}

void BinarySearch()
{
	// 얼마만큼 잘랐을 때 C개의 파닭을 만들수 있는 구간과 안되는 구간이 있을 것.
	// 그 구간을 이진 탐색을 하면 좋을 거 같음.
	// 되는 구간의 마지노선의 값을 가지고 라면에 넣을 파를 구하면 됨.

	while (min <= max)
	{
		mid = (min + max) / 2;

		// mid만큼 자르면 파닭을 C만큼 만들 수 있는가?
		bool can = Can(mid);

		if (can)
		{
			// 더 크게 잘라도 됨.
			goodS = mid;
			min = mid + 1;
		}
		else
		{
			// 더 작게 잘라야 함.
			max = mid - 1;
		}
	}
}

void Accumulate()
{
	unsigned long long result0 = 0;
	unsigned long long result1 = 0;

	for (int i = 0; i < S; i++)
	{
		result0 += container[i];
	}
	result1 = goodS * C;

	std::cout << result0 - result1;
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	Input();
	BinarySearch();
	Accumulate();

	return 0;
}