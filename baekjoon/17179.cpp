#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N = 0;	// 자르는 횟수가 담긴 목록의 길이
int M = 0;	// 자를 수 있는 지점의 개수
int L = 0;	// 롤 케이크의 길이

int minL = 1;
int midL = 0;
int maxL = 4'000'000;
int result = 0;

std::vector<int> input;
std::vector<int> diff;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> N >> M >> L;

	input.resize(M);
	diff.resize(M + 1);

	for (int i = 0; i < M; i++)
	{
		std::cin >> input[i];

		if (i == 0)
			diff[i] = input[i];
		else
			diff[i] = input[i] - input[i - 1];
	}

	diff[M] = L - input[M - 1];
}

bool check(int min, int c)
{
	int acc = 0;

	if (min * c > L)
	{
		// min 길이로는 c만큼 못자름
		return false;
	}
	else
	{
		for (int i = 0; i < diff.size(); i++)
		{
			if (i == 0)
			{
				acc += diff[i];
				continue;
			}

			// 누적 합이 최소 길이보다 짧다면 누적하자
			if (acc < min)
			{
				acc += diff[i];
			}
			// 같으면
			else if (acc == min)
			{
				
			}
			// 길면 최소가 될 수 없음
			else
			{
				acc
			}

		}
	}

	// min을 만들 수 있는 수임?
	if (acc == min)
		return true;

	return false;
}

void Function()
{
	int count = 0;
	std::cin >> count;

	minL = 1;
	maxL = 4'000'000;

	while (minL < maxL)
	{
		midL = (minL + maxL) / 2;

		if (check(midL, count))
		{
			result = midL;
			minL = midL + 1;
		}
		else
		{
			maxL = midL - 1;
		}
	}
}

void Output()
{
	std::cout << result << std::endl;
}

int main()
{
	Input();

	while (N--)
	{
		Function();
		Output();
	}

	return 0;
}