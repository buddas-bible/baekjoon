#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	int N = 0;
	int K = 0;
	std::cin >> N >> K;

	std::vector<int> X{};
	std::vector<int> X2{};

	// �Է°��� ���Ϳ� ����
	for (size_t i = 0; i < N; i++)
	{
		int a = 0;
		std::cin >> a;

		X.push_back(a);
	}

	// ������� ������
	std::sort(X.begin(), X.end());

	// ��źȭ �۾��� ���ؼ� �� ���� �ʿ����� �����.
	for (size_t i = 0; i < N; i++)
	{
		if (i == 0)
		{
			X2.push_back(0);
			continue;
		}

		// �տ� ������ ġ�� ���� �ʿ��� ����
		// + �ڱ⺸�� �տ� �ִ� ģ������ �����ϴٴ� ���� �Ͽ� �ʿ��� �ø�Ʈ ����
		// (���� * �ε��� ����)
		X2.push_back(X2[i - 1] + (X[i] - X[i - 1]) * i);
	}

	size_t min = 0;
	size_t mid = 0;
	size_t max = X2.size() - 1;

	while (min <= max)
	{
		mid = (min + max) / 2;

		// K���� mid��°���� ������ �����Ѱ�?
		if (X2[mid] == K)
		{
			break;
		}
		else if (X2[mid] < K)
		{
			// ����� ������
			min = mid + 1;
		}
		else
		{
			// �����ϸ� ������
			max = mid - 1;
		}
	}

	size_t result = X[min];

	while (K - X2[min] < min)
	{
		result++;
	}

	std::cout << result;

	return 0;
}
