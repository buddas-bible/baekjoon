#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);

	
}

int main()
{
	Input();

	std::vector<int> arr;
	arr.emplace_back(1);

	std::cout << sizeof(int*);
	std::cout << sizeof(int);
	std::cout << sizeof(&arr.front());

	return 0;
}