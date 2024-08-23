#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int BFS(int _x, int _y, int _color, 
	vector<vector<int>> _picture, int _maxX, int _maxY, 
	queue<pair<int, int>>& _search, 
	vector<vector<bool>>& _visit)
{
	int result = 0;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if (nx < 0 || ny < 0 || nx >= _maxX || ny >= _maxY)
			continue;

		if (_visit[nx][ny])
			continue;

		if (_picture[nx][ny] != _color)
			continue;

		_search.push({ nx, ny });
		_visit[nx][ny] = true;
		result++;
	}

	return result;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	vector<int> container;

	vector<vector<bool>> visit(m, vector<bool>(n));

	for (int i = 0; i < m; i++) // x
	{
		for (int j = 0; j < n; j++) // y
		{
			if (picture[i][j] == 0)
				continue;
			if (visit[i][j] == true)
				continue;

			int findColor = picture[i][j];

			queue<pair<int, int>> search;
			search.push({ i, j });
			visit[i][j] = true;
			int count = 1;

			while (!search.empty())
			{
				auto [x, y] = search.front();
				search.pop();

				// 좌표, 찾는 색, 컨테이너, 컨테이너 크기, 
				count += BFS(x, y, findColor, picture, m, n, search, visit);
			}

			container.emplace_back(count);
		}
	}

	sort(container.begin(), container.end());

	vector<int> answer(2);
	answer[0] = container.size();
	answer[1] = container.back();

	return answer;
}

int main()
{

	solution(6, 4, { {1, 1, 1, 0} ,{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} });

	return 0;
}