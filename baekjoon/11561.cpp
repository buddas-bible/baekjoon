#include <iostream>

bool CanJump(unsigned long long bridge, unsigned long long count)
{
	// count ��ŭ �ۼ� �ִ� ĭ
	unsigned long long d = count * (count + 1) / 2;

	// d���� ũ�� ����� �� �� ����
	return d <= bridge;
}

void Step()
{
	unsigned long long minCount = 1;
	unsigned long long midCount = 0;
	unsigned long long maxCount = 1'000'000'000;

	unsigned long long result = 0;
	unsigned long long bridge = 0;
	std::cin >> bridge;

	while (minCount <= maxCount)
	{
		midCount = (minCount + maxCount) / 2;

		// midCount Ƚ���� bridge�� �Ѿ �� �ֳ�?
		const bool can = CanJump(bridge, midCount);

		if (can)
		{
			// min ~ mid �κ��� ���� ����
			result = midCount;
			minCount = midCount + 1;
		}
		else
		{
			// mid ~ max �κ��� ���� �Ұ���
			result = midCount - 1;
			maxCount = midCount - 1;
		}
	}

	std::cout << result << std::endl;
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	long long testCase = 1;
	std::cin >> testCase;

	while (testCase--)
	{
		Step();
	}

	return  0;
}