#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <string>
#include <iostream>

int A = 0;
int B = 0;
int C = 0;

std::map<std::string, long long> container;

int w(int a, int b, int c)
{
	std::string str_a = std::to_string(a) + ",";
	std::string str_b = std::to_string(b) + ",";
	std::string str_c = std::to_string(c) + ",";

	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}

	std::string str_a_1 = std::to_string(a - 1) + ",";
	std::string str_b_1 = std::to_string(b - 1) + ",";
	std::string str_c_1 = std::to_string(c - 1) + ",";

	if (a < b && b < c)
	{
		long long out0 = container[str_a + str_b + str_c_1];
		long long out1 = container[str_a + str_b_1 + str_c_1];
		long long out2 = container[str_a + str_b_1 + str_c];

		if (out0 == 0)
		{
			container[str_a + str_b + str_c_1] = out0 = w(a, b, c - 1);
		}
		if (out1 == 0)
		{
			container[str_a + str_b_1 + str_c_1] = out1 = w(a, b - 1, c - 1);
		}
		if (out2 == 0)
		{
			container[str_a + str_b_1 + str_c] = out2 = w(a, b - 1, c);
		}

		return out0 + out1 - out2;
	}

	long long result0 = container[str_a_1 + str_b + str_c];
	long long result1 = container[str_a_1 + str_b_1 + str_c];
	long long result2 = container[str_a_1 + str_b + str_c_1];
	long long result3 = container[str_a_1 + str_b_1 + str_c_1];

	if (result0 == 0)
	{
		container[str_a_1 + str_b + str_c] = result0 = w(a - 1, b, c);
	}
	if (result1 == 0)
	{
		container[str_a_1 + str_b_1 + str_c] =  result1 = w(a - 1, b - 1, c);
	}
	if (result2 == 0)
	{
		container[str_a_1 + str_b + str_c_1] = result2 = w(a - 1, b, c - 1);
	}
	if (result3 == 0)
	{
		container[str_a_1 + str_b_1 + str_c_1] = result3 = w(a - 1, b - 1, c - 1);
	}

	return result0 + result1 + result2 - result3;
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	while (true)
	{
		std::cin >> A >> B >> C;

		if (A == -1 && B == -1 && C == -1)
		{
			break;
		}

		std::string str_a = std::to_string(A) + ",";
		std::string str_b = std::to_string(B) + ",";
		std::string str_c = std::to_string(C) + ",";

		long long result = container[str_a + str_b + str_c];

		if (result == 0)
		{
			container[str_a + str_b + str_c] = result = w(A, B, C);
		}

		std::cout << "w(" + str_a + ", " + str_b + ", " + str_c + ") = " << result << std::endl;
	}

	return 0;
}