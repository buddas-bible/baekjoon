#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N = 0;
std::vector<int> container;
std::vector<int> counting;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> N;
	container.resize(N);
	counting.resize(N);
}

int BinaryCounting(int _value)
{
	int count = 0;
	while (_value)
	{
		if (_value & 0b1)
		{
			count++;
		}
		_value = _value >> 1;
	}

	return count;
}

int DP()
{
	for (int i = 0; i < N; i++)
	{
		std::cin >> container[i];
	}

	counting[0] = 0;

	if (N >= 2)
	{
		// 카드가 2장일 때 최선
		counting[1] = BinaryCounting(container[0] ^ container[1]);
		if (N >= 3)
		{
			// 카드가 3장일 때 최선
			counting[2] = BinaryCounting(container[0] ^ container[1] ^ container[2]);
			if (N >= 4)
			{
				// 카드가 4장일 때 최선
				counting[3] = counting[1] + BinaryCounting(container[2] ^ container[3]);
			}
		}
	}

	for (int i = 4; i < N; i++)
	{
		int twoCard = container[i] ^ container[i - 1];
		int threeCard = container[i] ^ container[i - 1] ^ container[i - 2];
		counting[i] = std::max(counting[i - 2] + BinaryCounting(twoCard), counting[i - 3] + BinaryCounting(threeCard));
	}

	return counting[N - 1];
}

void Output(int _value)
{
	std::cout << _value;
}

int main()
{
	Input();
	Output(DP());

	return 0;
}