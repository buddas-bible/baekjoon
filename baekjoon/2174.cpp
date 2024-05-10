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
	int robot;
	char command;
	int commandTry;
};

struct Robot
{
	Data data;
	int dir = 0;
};

int A = 0;
int B = 0;
int N = 0;
int M = 0;

std::vector<std::vector<int>> ground;
std::vector<Robot> robots;
std::queue<Command> command;

char GetCharDir(int i)
{
	switch (i)
	{
	case 0:
		return 'N';
	case 1:
		return 'E';
	case 2:
		return 'S';
	case 3:
		return 'W';
	}
}

int GetIntDir(char d)
{
	d %= 4;

	switch (d)
	{
	case 'N':
		return 0;
	case 'E':
		return 1;
	case 'S':
		return 2;
	case 'W:
		return 3;
	}
}

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> A >> B >> N >> M;
	ground = std::move(std::vector(B, std::vector<int>(A)));
	robots = std::vector(N, Robot());

	// 로봇 위치
	for (int n = 0; n < N; n++)
	{
		char dir = 'N';
		std::cin
			>> robots[n].data.x
			>> robots[n].data.y
			>> dir;

		robots[n].dir = GetIntDir(dir);
	}

	// 명령
	for (int m = 0; m < M; m++)
	{
		int rIndex = 0;
		char cCommand = 0;
		int tryNum = 0;

		std::cin >> rIndex >> cCommand >> tryNum;

		tryNum = GetIntDir(tryNum);

		command.push({ rIndex , cCommand, tryNum });
	}
}

bool Crashed()
{
	for (int i = 0; i < robots.size() - 1; i++)
	{
		for (int j = i + 1; j < robots.size(); j++)
		{
			if (robots[i].data == robots[j].data)
			{
				return true;
			}
		}
	}

	return false;
}

int TryMove(Robot& _robot, int _case)
{
	
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
}

int TryRotate(Robot& _robot, char _r, int _case)
{
	while (_case--)
	{
		if (_r == 'L')
		{
			_robot.dir += -1;
		}
		else if (_r == 'R')
		{
			_robot.dir += 1;
		}

		if (_robot.dir < 0)
		{
			_robot.dir = 3;
		}
		else if (_robot.dir > 3)
		{
			_robot.dir %= 4;
		}
	}

	return DEFAULT;
}

int TryCommand(Robot _robot, Command _command)
{
	switch (_command.command)
	{
	case 'L':
	case 'R':
		return TryRotate(robots[_command.robot], _command.command, _command.commandTry);

	case 'F':
		return TryMove(robots[_command.robot], _command.commandTry);
	}
}

int Simulation(Command _command, int& _base, int& _other)
{
	return TryCommand(robots[_command.robot], _command);
}

void Output(int X, int Y, int _result)
{
	if (_result == DEFAULT)
	{

	}

	if (_result == CRASH)
	{
		std::cout << "Robot " << X << " crashes into robot " << Y;
	}

	if (_result == BLOCK)
	{
		std::cout << "Robot " << X << " crashes into the wall";
	}
}

int main()
{
	Input();

	while (!command.empty())
	{
		Command co = command.front();
		command.pop();

		int base = 0;
		int other = 0;

		int result = Simulation(co, base, other);

		Output(base, other, result);
	}

	return 0;
}