#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

#define DEFAULT 0 
#define CRASH 1
#define BLOCK 2

struct Data
{
	Data() : x(), y() {}
	Data(int _x, int _y) : x(_x), y(_y) {}
	Data(const Data& _right) : x(_right.x), y(_right.y) {}
	Data(Data&& _right) noexcept : x(std::move(_right.x)), y(std::move(_right.y)) {}

	int x;
	int y;

	Data& operator=(const Data& _vec)
	{
		if (this != &_vec)
		{
			x = _vec.x;
			y = _vec.y;
		}

		return *this;
	}
	Data& operator=(Data&& _vec) noexcept
	{
		if (this != &_vec)
		{
			x = std::move(_vec.x);
			y = std::move(_vec.y);
		}

		return *this;
	}

	Data& operator+=(const Data& _vec)
	{
		x += _vec.x;
		y += _vec.y;

		return *this;
	}
	Data operator+(const Data& _vec) const
	{
		Data temp(*this);

		return temp += _vec;
	}

	bool operator==(const Data& _vec) const
	{
		return (x == _vec.x) && (y == _vec.y);
	}
};

struct Command
{
	int robot;			// 로봇 인덱스
	char action;		// 명령
	int repeat;		// 명령 반복
};

struct Robot
{
	int id;
	Data data;
	int dir = 0;
};

struct Result
{
	int result;
	int base;
	int other;
};

int A = 0;
int B = 0;
int N = 0;
int M = 0;

std::vector<Robot> robots;
std::queue<Command> command;

int GetIntDir(char d)
{
	switch (d)
	{
	case 'N':
		return 0;
	case 'E':
		return 1;
	case 'S':
		return 2;
	case 'W':
		return 3;
	}
}

void Input()
{
	robots.clear();
	while (!command.empty())
		command.pop();

	std::cin >> A >> B >> N >> M;
	robots = std::vector(N, Robot());

	// 로봇 위치
	for (int n = 0; n < N; n++)
	{
		char dir = 'N';
		std::cin
			>> robots[n].data.x
			>> robots[n].data.y
			>> dir;

		robots[n].id = n + 1;
		robots[n].dir = GetIntDir(dir);
	}

	// 명령
	for (int m = 0; m < M; m++)
	{
		int rIndex = 0;
		char cCommand = 0;
		int tryNum = 0;

		std::cin >> rIndex >> cCommand >> tryNum;
		command.push({ rIndex , cCommand, tryNum });
	}
}

Data GetDir(int _dir)
{
	switch (_dir)
	{
	case 0:  // N
		return Data( 0, +1 );
	case 1:  // E
		return Data( +1, 0 );
	case 2:  // S
		return Data( 0, -1 );
	case 3:  // W
		return Data( -1, 0 );
	default:
		return Data();
	}
}

bool isCrash(Robot& _robot, int& _other)
{
	for (size_t i = 0; i < robots.size(); i++)
	{
		int _origin = _robot.id - 1;

		if (_origin == i)
			continue;

		// 같은 위치에 있는 애들은 부딪친거임
		if (robots[_origin].data == robots[i].data)
		{
			_other = i + 1;
			return true;
		}
	}

	_other = -1;
	return false;
}

bool isBlock(Robot& _robot)
{
	int minX = 1;
	int minY = 1;
	int maxX = A;
	int maxY = B;

	if (_robot.data.x < minX)
		return true;
	if (_robot.data.y < minY)
		return true;
	if (_robot.data.x > maxX)
		return true;
	if (_robot.data.y > maxY)
		return true;

	return false;
}

Result TryMove(Robot& _robot, int _tryNum)
{
	while (_tryNum--)
	{
		_robot.data += GetDir(_robot.dir);

		int other = -1;

		if (isBlock(_robot))
		{
			return { BLOCK, _robot.id, -1 };
		}

		if (isCrash(_robot, other))
		{
			return { CRASH, _robot.id, other };
		}
	}

	return { DEFAULT, -1, -1 };
}

int Rotate(char _r)
{
	if (_r == 'L')
	{
		return -1;
	}
	else if(_r == 'R')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Result TryRotate(Robot& _robot, char _r, int _case)
{
	_case %= 4;

	while (_case--)
	{
		_robot.dir += Rotate(_r);

		if (_robot.dir < 0)
			_robot.dir = 3;
		else if (_robot.dir > 3)
			_robot.dir %= 4;
	}

	return { DEFAULT, -1, -1 };
}

Result TryCommand(Robot& _robot, Command _command)
{
	// 로봇이 해당 명령을 수행
	switch (_command.action)
	{
	case 'L':
	case 'R':
		return TryRotate(_robot, _command.action, _command.repeat);

	case 'F':
		return TryMove(_robot, _command.repeat);

	default:
		return Result();
	}
}

Result Simulation(Command _command)
{
	// 명령 수행
	return TryCommand(robots[_command.robot - 1], _command);
}

void Output(int X, int Y, int _result)
{
	if (_result == CRASH)
	{
		std::cout << "Robot " << X << " crashes into robot " << Y << '\n';
	}
	else if (_result == BLOCK)
	{
		std::cout << "Robot " << X << " crashes into the wall" << '\n';
	}
}

void Solve()
{
	Input();

	while (!command.empty())
	{
		Command co = command.front();
		command.pop();

		Result result = Simulation(co);
		if (result.result)
		{
			Output(result.base, result.other, result.result);
			return;
		}
	}

	std::cout << "OK" << '\n';
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	Input();

	while (!command.empty())
	{
		Command co = command.front();
		command.pop();

		Result result = Simulation(co);
		if (result.result)
		{
			Output(result.base, result.other, result.result);
			return 0;
		}
	}

	std::cout << "OK" << '\n';

	return 0;
}