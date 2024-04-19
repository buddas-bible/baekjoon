#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N = 0;	// �ڸ��� Ƚ���� ��� ����� ����
int M = 0;	// �ڸ� �� �ִ� ������ ����
int L = 0;	// �� ����ũ�� ����

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
		// min ���̷δ� c��ŭ ���ڸ�
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

			// ���� ���� �ּ� ���̺��� ª�ٸ� ��������
			if (acc < min)
			{
				acc += diff[i];
			}
			// ������
			else if (acc == min)
			{
				
			}
			// ��� �ּҰ� �� �� ����
			else
			{
				acc
			}

		}
	}

	// min�� ���� �� �ִ� ����?
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