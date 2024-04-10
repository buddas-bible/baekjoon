#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

unsigned long long S = 0;	// �� ����
unsigned long long C = 0;	// �Ĵ��� ��
// �� <= �Ĵ�

std::vector<unsigned long long> container;
std::vector<unsigned long long> carry;

unsigned long long min = 1;
unsigned long long mid = 0;
unsigned long long goodS = 0;
unsigned long long max = 0;

int F(unsigned long long L, unsigned long long N)
{
	// ���� L�� �ĸ� N��ŭ �߶��� �� �� ���� �Ĵ��� ���� �� ���� ��
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

	// �ĵ��� value ����ŭ ������ �Ĵ��� ����ŭ ���� �� ������?
	return C <= acc;
}

void BinarySearch()
{
	// �󸶸�ŭ �߶��� �� C���� �Ĵ��� ����� �ִ� ������ �ȵǴ� ������ ���� ��.
	// �� ������ ���� Ž���� �ϸ� ���� �� ����.
	// �Ǵ� ������ �����뼱�� ���� ������ ��鿡 ���� �ĸ� ���ϸ� ��.

	while (min <= max)
	{
		mid = (min + max) / 2;

		// mid��ŭ �ڸ��� �Ĵ��� C��ŭ ���� �� �ִ°�?
		bool can = Can(mid);

		if (can)
		{
			// �� ũ�� �߶� ��.
			goodS = mid;
			min = mid + 1;
		}
		else
		{
			// �� �۰� �߶�� ��.
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