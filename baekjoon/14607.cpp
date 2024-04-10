#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using ULL = unsigned long long;

ULL N = 0;
std::vector<ULL> container;
std::map<ULL, ULL> container0;
bool NisOdd = true;

bool IsOddNumber(ULL value)
{
	return value % 2 == 1;
}

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> N;
}

//void DP()
//{
//	// 0�� ����� �� ���� 0
//	// 1�� ����� �� ���� 0 * 0					= 0
//	// 2�� '1 * 1' + 1�� ���					= 1
//	// 3�� '1 * 2' + 1�� ���(0) + 2�� ���(1) 	= 3
//	// 4�� '2 * 2' + 2�� ���(1) + 2�� ���(1)	= 6
//	// 5�� '2 * 3' + 2�� ���(1) + 3�� ���(3)	= 10
//	// 99�� 49�� 50
//	// 100�� 50�� 50
//
//	// N�� ���� Ȧ����� 
//	// N�� (N / 2) * ((N / 2) - 1) + (N / 2�� ����� �� ��) + (N / 2 + 1 ����� �� ��)
//	// N�� ���� ¦����� 
//	// N�� (N / 2) * (N / 2) + (N / 2�� ����� �� ��) + (N / 2 ����� �� ��)
//	NisOdd = IsOddNumber(N);
//	ULL invN = N / 2;
//	container.resize(invN + (NisOdd * 1) + 1);
//	// std::vector<ULL> container1[1000]{ container , container , container, };
//
//	container[0] = 0;
//	container[1] = 0;
//
//	for (ULL i = 2; i < container.size(); i++)
//	{
//		bool odd = IsOddNumber(i);
//
//		container[i] = (i / 2) * ((i / 2) + (odd * 1)) + container[i / 2] + container[(i / 2) + (odd * 1)];
//	}
//	
//	std::cout << invN * (invN + (NisOdd * 1)) + container[invN] + container[(invN + (NisOdd * 1))];
//}

ULL Func(ULL value)
{
	bool odd = IsOddNumber(value);
	
	if (value == 0 || value == 1)
	{
		return 0;
	}

	ULL value0 = value / 2;
	ULL value1 = odd ? (value / 2) + (odd * 1) : value0;

	ULL result = container0[value];
	if (result == 0)
	{
		ULL result0 = Func(value0);
		ULL result1 = odd ? Func(value1) : result0;

		result = value0 * value1 + result0 + result1;
	}

	return result;
}

void Func()
{
	NisOdd = IsOddNumber(N);
	ULL value0 = N / 2;
	ULL value1 = (N / 2) + (NisOdd * 1);

	container0[0] = 0;
	container0[1] = 0;
	// ULL result = value0 * value1 + Func(value0) + Func(value1);
	ULL result = N * (N - 1) / 2;

	std::cout << result;
}

int main()
{
	Input();
	//if (N < 1'000'000ll)
	//{
	//	DP();
	//}
	//else
	//{
		Func();
	//}

	return 0;
}