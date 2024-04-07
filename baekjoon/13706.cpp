#include <iostream>
#include <string>
#include <cmath>

#define BIGINTIGER_MAX 801

class BigIntiger
{
public:
	BigIntiger() = default;
	BigIntiger(int _rhs)
	{
		usingArr = 0;

		int quotient = _rhs / arrMax;
		int remainder = _rhs % arrMax;
		intiger00[0] = remainder;

		if (quotient)
		{
			intiger00[1] = quotient;
		}
	}
	BigIntiger(const BigIntiger& _rhs) : usingArr(_rhs.usingArr)
	{
		for (int i = _rhs.usingArr; i >= 0; i--)
		{
			intiger00[i] = _rhs.intiger00[i];
		}
	}
	BigIntiger(BigIntiger&& _rhs) noexcept : usingArr(_rhs.usingArr)
	{
		for (int i = _rhs.usingArr; i >= 0; i--)
		{
			intiger00[i] = std::move(_rhs.intiger00[i]);
		}
	}
	BigIntiger& operator=(const BigIntiger& _rhs)
	{
		if (this != &_rhs)
		{
			for (int i = _rhs.usingArr; i >= 0; i--)
			{
				intiger00[i] = _rhs.intiger00[i];
			}

			usingArr = _rhs.usingArr;
		}

		return *this;
	}
	BigIntiger& operator=(BigIntiger&& _rhs) noexcept
	{
		if (this != &_rhs)
		{
			for (int i = _rhs.usingArr; i >= 0; i--)
			{
				intiger00[i] = std::move(_rhs.intiger00[i]);
			}

			usingArr = std::move(_rhs.usingArr);
		}

		return *this;
	}

	BigIntiger& operator+=(const BigIntiger& _rhs)
	{
		int quotient = 0;
		int remainder = 0;
		int newLength = 0;

		for (int i = 0; i < BIGINTIGER_MAX; i++)
		{
			unsigned long long temp = this->intiger00[i] + _rhs.intiger00[i] + quotient;

			int quotient = temp / arrMax;
			int remainder = temp % arrMax;
			intiger00[i] = remainder;

			if (quotient == 0 && remainder == 0)
			{
				usingArr = newLength;
				break;
			}

			newLength++;
		}

		return *this;
	}

	BigIntiger operator+(const BigIntiger& _rhs)
	{
		BigIntiger temp(*this);

		return temp += _rhs;
	}

	BigIntiger& operator-=(const BigIntiger& _rhs)
	{
		//int quotient = 0;
		//int remainder = 0;

		//for (int i = 0; i < BIGINTIGER_MAX; i++)
		//{
		//	unsigned long long temp = this->intiger00[i] + _rhs.intiger00[i] + quotient;

		//	int quotient = temp / arrMax;
		//	int remainder = temp % arrMax;
		//	intiger00[i] = remainder;

		//	if (quotient == 0 && remainder == 0)
		//		break;
		//}

		//return *this;
	}

	BigIntiger operator-(const BigIntiger& _rhs)
	{
		BigIntiger temp(*this);

		return temp -= _rhs;
	}

	BigIntiger& operator*=(const BigIntiger& _rhs)
	{

	}

	BigIntiger operator*(const BigIntiger& _rhs)
	{
		BigIntiger temp(*this);

		return temp *= _rhs;
	}

	BigIntiger& operator/=(const BigIntiger& _rhs)
	{

	}

	BigIntiger operator/(const BigIntiger& _rhs)
	{
		BigIntiger temp(*this);

		return temp /= _rhs;
	}
	
	bool operator<(const BigIntiger& _rhs)
	{
		if (usingArr != _rhs.usingArr)
		{
			return usingArr < _rhs.usingArr;
		}
		else
		{
			return intiger00[usingArr] < _rhs.intiger00[_rhs.usingArr];
		}
	}

	friend std::ostream& operator<< (std::ostream& _out, const BigIntiger& _rhs);
	friend std::istream& operator>> (std::istream& _in, const BigIntiger& _rhs);

private:		
	static unsigned int arrMax;
	unsigned int intiger00[BIGINTIGER_MAX]{};
	unsigned int usingArr = 0;
};

unsigned int BigIntiger::arrMax = 1'000'000'000;

std::istream& operator>> (std::istream& _in, const BigIntiger& _rhs)
{
	std::string str{};

	_in >> str;

	for (int i = 0; i < str.size(); i++)
	{

	}

	return _in;
}

std::ostream& operator<< (std::ostream& _out, const BigIntiger& _rhs)
{
	std::string str{};

	for (int i = BIGINTIGER_MAX; i >= 0; i--)
	{
		str += std::to_string(_rhs.intiger00[i]);
	}

	return _out << str;
}

int main()
{
	std::cin.tie();
	std::cout.tie();
	std::ios_base::sync_with_stdio(false);

	unsigned long long N = 0;

	std::cin >> N;

	unsigned long long low = 1;
	unsigned long long mid = 0;
	unsigned long long high = N;

	while (low <= high)
	{
		mid = (low + high) / 2;

		unsigned long long check = mid * mid;

		if (check == N)
		{
			break;
		}
		else if (check > N)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	std::cout << low;

	return 0;
}