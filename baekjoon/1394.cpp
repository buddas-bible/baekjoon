#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using ULL = unsigned long long;

std::string input;
std::string answer;
std::unordered_map<char, ULL> bindValue;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);

	std::cin >> input >> answer;

	for (ULL i = 0; i < input.size(); i++)
	{
		bindValue.insert({ input[i], i + 1 });
	}
}

ULL Calculation()
{
	const ULL N		= input.size();
	const ULL K		= answer.size() - 1;

	ULL R = 0;

	for (ULL i = 0; i < answer.size(); i++)
	{
		char raw = answer[i];					// 암호의 값을 가져옴
		ULL value = bindValue[raw];				// 값에 해당하는 숫자를 가져옴

		if (i == 0)
		{
			R = value;
		}
		else
		{
			R = (value + N * R);
		}

		R %= 900528;
	}

	return R % 900528;
}

void Output(ULL _output)
{
	std::cout << _output;
}

int main()
{
	Input();
	Output(Calculation());

	return 0;
}
