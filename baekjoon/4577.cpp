#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

#define CANT 0
#define CAN_PLAYER_MOVE 1
#define CAN_ROCK_MOVE	2

// . 빈공간					0
// # 벽						-1
// + 비어있는 목표점			1
// b 박스					2
// B 목표점 위에 있는 박스	3
// w 캐릭터					4
// W 목표점 위에 있는 캐릭터	5

int R = 0;
int C = 0;
std::vector<std::vector<char>> map;

struct Vec2
{
	Vec2() : x(), y() {}
	Vec2(int _x, int _y) : x(_x), y(_y) {}
	Vec2(const Vec2& _right) : x(_right.x), y(_right.y) {}
	Vec2(Vec2&& _right) noexcept : x(std::move(_right.x)), y(std::move(_right.y)) {}
	
	int x;
	int y;

	Vec2& operator=(const Vec2& _vec)
	{
		if (this != &_vec)
		{
			x = _vec.x;
			y = _vec.y;
		}

		return *this;
	}
	Vec2& operator=(Vec2&& _vec) noexcept
	{
		if (this != &_vec)
		{
			x = std::move(_vec.x);
			y = std::move(_vec.y);
		}

		return *this;
	}

	Vec2& operator+=(const Vec2& _vec)
	{
		x += _vec.x;
		y += _vec.y;

		return *this;
	}
	Vec2 operator+(const Vec2& _vec) const
	{
		Vec2 temp(*this);

		return temp += _vec;
	}

	//Vec2& operator-=(const Vec2& _vec)
	//{
	//	x -= _vec.x;
	//	y -= _vec.y;

	//	return *this;
	//}
	//Vec2 operator-(const Vec2& _vec) const
	//{
	//	Vec2 temp(*this);

	//	return temp -= _vec;
	//}

	//bool operator==(const Vec2& _vec)
	//{
	//	if (x != _vec.x)
	//		return false;
	//	if (y != _vec.y)
	//		return false;

	//	return true;
	//}
	//bool operator!=(const Vec2& _vec)
	//{
	//	return !(*this == _vec);
	//}
};

Vec2 charactor;
std::vector<Vec2> target;
std::string commands;
int boxCount = 0;
int gameCount = 1;

bool Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	static bool first = true;
	if (first)
	{
		freopen("input.txt", "rt", stdin);
		first = false;
	}
	std::cin >> R >> C;

	if (R == 0 && C == 0)
		return false;

	target.clear();
	std::vector<char> temp(C);
	std::vector<std::vector<char>> tempC(R, temp);

	int count = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char input = 0;
			std::cin >> input;
			tempC[i][j] = input;

			switch (input)
			{
			case 'B':
				target.push_back({ j, i });
			case 'b':
				count++;
				break;
			
			case '+':
				target.push_back({ j, i });
				break;

			case 'W':
				target.push_back({ j, i });
			case 'w':
				charactor = { j, i };
				break;

			default:
				break;
			}
		}
	}

	map = std::move(tempC);
	boxCount = count;

	std::string input;
	std::cin >> commands;

	return true;
}

Vec2 Command(char _command)
{
	switch (_command)
	{
	case 'U':
		return Vec2{ 0 ,-1 };

	case 'L':
		return Vec2{ -1, 0 };
	
	case 'R':
		return Vec2{ +1, 0 };
	
	case 'D':
		return Vec2{ 0, +1 };

	default:
		return {};
	}
}

void Move(Vec2 _pos, Vec2 _dir)
{
	Vec2 newVec = _pos + _dir;

	char currData = map[_pos.y][_pos.x];
	char nextData = map[newVec.y][newVec.x];

	if (currData == 'w' || currData == 'b')
	{
		map[_pos.y][_pos.x] = '.';
	}
	else if (currData == 'W' || currData == 'B')
	{
		map[_pos.y][_pos.x] = '+';
	}

	if (currData == 'W' || currData == 'w')
	{
		if (nextData == '.')
		{
			charactor = { newVec.x , newVec.y };
			map[newVec.y][newVec.x] = 'w';
		}
		else if (nextData == '+')
		{
			charactor = { newVec.x , newVec.y };
			map[newVec.y][newVec.x] = 'W';
		}
	}
	else if (currData == 'b' || currData == 'B')
	{
		if (nextData == '.')
		{
			map[newVec.y][newVec.x] = 'b';
		}
		else if (nextData == '+')
		{
			map[newVec.y][newVec.x] = 'B';
		}
	}
}

int Rock_CanMove(Vec2 _pos, Vec2 _dir)
{
	Vec2 newVec = _pos + _dir;
	char nextTile = map[newVec.y][newVec.x];

	switch (nextTile)
	{
	case '.':
	case '+':
		return CAN_ROCK_MOVE;

	case 'b':
	case 'B':
	case '#':
		return CANT;

	default:
		break;
	}
}

int Player_CanMove(Vec2 _pos, Vec2 _dir)
{
	Vec2 newVec = _pos + _dir;
	char nextTile = map[newVec.y][newVec.x];

	switch (nextTile)
	{
	case '.':
	case '+':
		return CAN_PLAYER_MOVE;

	case 'b':
	case 'B':
		return Rock_CanMove(newVec, _dir);

	case '#':
		return CANT;

	default:
		break;
	}
}

int PlaySokoban()
{
	for (auto& command : commands)
	{
		Vec2 dir = Command(command);

		int result = Player_CanMove(charactor, dir);
		if (result == CAN_PLAYER_MOVE)
		{
			Move(charactor, dir);
		}
		else if (result == CAN_ROCK_MOVE)
		{
			Move(charactor + dir, dir);
			Move(charactor, dir);
		}

		int count = 0;
		for (auto& e : target)
		{
			if (map[e.y][e.x] == 'B')
				count++;
		}

		if (boxCount == count)
		{
			return 1;
		}
	}

	return 0;
}

void Output(int _result)
{
	std::string str;
	if (_result == 0)
		str = "incomplete";
	else
		str = "complete";

	std::cout << "Game " << gameCount++ << ": " << str << '\n';

	for (auto& r : map)
	{
		for (auto& c : r)
		{
			std::cout << c;
		}

		std::cout << "\n";
	}
}

int main()
{
	while (Input())
	{
		Output(PlaySokoban());
	}

	return 0;
}