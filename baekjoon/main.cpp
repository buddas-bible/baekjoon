#include <iostream>
#include <vector>

class Z_Type
{
	int a;
};

namespace Name
{

	class A_Type
	{
	public:
		int a;
	};

	class B_Type : public A_Type
	{
	public:
		int c;
	};

	struct C_Type
	{
	public:
		int a;
	};
}

void StringSplit(std::string& _origin, std::string _tar)
{
	auto itr = _origin.find(_tar);
	if (itr != std::string::npos)
	{
		_origin = _origin.substr(itr + _tar.size());
	}
}


int main()
{
	Z_Type z;
	Name::A_Type a;
	Name::B_Type b;
	Name::A_Type* a_p = new Name::B_Type;
	Name::C_Type c;

	std::string classString = "class ";
	std::string structString = "struct ";
	std::string temp = "::";

	std::string zName = typeid(z).name();
	{
		StringSplit(zName, classString);
		StringSplit(zName, structString);
		// StringSplit(zName, temp);
	}

	std::string aName = typeid(a).name();
	{
		StringSplit(aName, classString);
		StringSplit(aName, structString);
		// StringSplit(aName, temp);
	}
	
	std::string bName = typeid(b).name();
	{
		StringSplit(bName, classString);
		StringSplit(bName, structString);
		// StringSplit(bName, temp);
	}
	
	std::string a_pName = typeid(a_p).name();
	{
		StringSplit(a_pName, classString);
		StringSplit(a_pName, structString);
		// StringSplit(a_pName, temp);
	}
	
	std::string cName = typeid(c).name();
	{
		StringSplit(cName, classString);
		StringSplit(cName, structString);
		// StringSplit(cName, temp);
	}

	std::vector<std::shared_ptr<Name::A_Type>> aCon;

	std::vector<std::weak_ptr<Name::B_Type>> bCon;

	std::shared_ptr<Name::A_Type> aa = std::make_shared<Name::B_Type>();

	std::cout << aa->a << '\n';

	aa->a = 12;
	std::cout << aa->a << '\n';

	std::shared_ptr<Name::B_Type> bb = static_pointer_cast<Name::B_Type>(aa);


	aa->a = 10;
	std::cout << aa->a << '\n';
	bb->c = 2;
	std::cout << bb->c << '\n';


	std::cout
		<< typeid(z).name() << '\n'
		<< zName << '\n'
		<< typeid(a).name() << '\n'
		<< aName << '\n'
		<< typeid(b).name() << '\n'
		<< bName << '\n'
		<< typeid(a_p).name() << '\n'
		<< a_pName << '\n'
		<< typeid(c).name() << '\n'
		<< cName << '\n';


	return 0;
}