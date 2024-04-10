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
//	// 0ÀÇ ±â»ÝÀÇ ÃÑ ÇÕÀº 0
//	// 1ÀÇ ±â»ÝÀÇ ÃÑ ÇÕÀº 0 * 0					= 0
//	// 2´Â '1 * 1' + 1ÀÇ ±â»Ý					= 1
//	// 3Àº '1 * 2' + 1ÀÇ ±â»Ý(0) + 2ÀÇ ±â»Ý(1) 	= 3
//	// 4´Â '2 * 2' + 2ÀÇ ±â»Ý(1) + 2ÀÇ ±â»Ý(1)	= 6
//	// 5´Â '2 * 3' + 2ÀÇ ±â»Ý(1) + 3ÀÇ ±â»Ý(3)	= 10
//	// 99´Â 49¿Í 50
//	// 100Àº 50°ú 50
//
//	// NÀÌ ¸¸¾à È¦¼ö¶ó¸é 
//	// NÀº (N / 2) * ((N / 2) - 1) + (N / 2ÀÇ ±â»ÝÀÇ ÃÑ ÇÕ) + (N / 2 + 1 ±â»ÝÀÇ ÃÑ ÇÕ)
//	// NÀÌ ¸¸¾à Â¦¼ö¶ó¸é 
//	// NÀº (N / 2) * (N / 2) + (N / 2ÀÇ ±â»ÝÀÇ ÃÑ ÇÕ) + (N / 2 ±â»ÝÀÇ ÃÑ ÇÕ)
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