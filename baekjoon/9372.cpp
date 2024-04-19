#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <stack>
#include <vector>

int T = 0;
int N = 0;
int M = 0;
int a = 0;
int b = 0;

std::vector<std::vector<int>> arr;
std::vector<bool> visit;

int result = 0;

void Input()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> T;
}

void Function()
{
	result = 0;

	std::cin >> N >> M;

	arr.clear();
	visit.clear();

	arr.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++)
	{
		arr[i].resize(N);
	}

	while (M--)
	{
		std::cin >> a >> b;

		arr[a - 1][b - 1] = 1;
		arr[b - 1][a - 1] = 1;
	}
}

void Trip(int index, int& count)
{
	visit[index] = true;

	for (int i = 0; i < arr[index].size(); i++)
	{
		// 경로가 열려있나?
		if (arr[index][i] == 1)
		{
			// 방문한 곳인가?
			if (visit[i])
			{
				continue;
			}
			// 방문하지 않았으면 방문함.
			else
			{
				count++;
				Trip(i, count);
			}
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

	while (T--)
	{
		Function();
		Trip(0, result);
		Output();
	}

	return 0;
}