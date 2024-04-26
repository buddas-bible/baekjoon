#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N = 0;
int M = 0;
std::vector<int> input;

struct SegmentTree
{
	struct Range
	{
		int begin;			// 노드의 시작 인덱스
		int end;			// 노드의 끝 인덱스

		bool operator==(const Range& _range) const
		{
			return begin == _range.begin && end == _range.end;
		}
	};

	struct Node
	{
		Node* node[2] = {};
		Range range;
		int minValue;

		void Query(const Range& _range, int& _out)
		{
			if (_range.begin == _range.end)
			{
				
			}

			if (range == _range)
			{
				_out = minValue < _out ? minValue : _out;
				return;
			}

			for (const auto& i : node)
			{
				if (i->overlap(_range))
				{
					i->Query(_range, _out);
				}
				else
				{
					Range newRange;
					newRange.begin = _range.begin;
					newRange.end = i->range.end;
					i->Query(newRange, _out);
				}
			}
		}
		bool overlap(const Range& _range) const
		{
			// 범위가 여기에 포함 되는가?
			return range.begin <= _range.begin && _range.end <= range.end;
		}
		bool operator==(const Range& _range) const
		{
			return range == _range;
		}
		bool operator==(const Node& _node) const
		{
			return range == _node.range;
		}
	};

	Node* root = nullptr;

	void create(const std::vector<int>& _container)
	{
		for (int i = 0; i < _container.size(); i += 2)
		{
			int begin = i;
			int end = i + 1;

			if (end > _container.size())
			{
				end = begin;
			}

			Node* node = new Node;
			node->range.begin = begin;
			node->range.end = end;
			node->minValue = std::min(_container[begin], _container[end]);
		}
	}

	int Query(int _begin, int _end)
	{
		if (_begin == _end)
			return input[_begin];

		Range range;
		range.begin = _begin;
		range.end = _end;

		int minValue = INT_MAX;
		root->Query(range, minValue);

		return minValue;
	}
};

SegmentTree tree;

void Input()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt", "rt", stdin);
	std::cin >> N >> M;

	input.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> input[i];
	}
}

void CreateTree()
{
	tree.create(input);


}

void Output()
{
	int begin = 0;
	int end = 0;
	std::cin >> begin >> end;
	std::cout << tree.Query(begin, end) << '\n';
}

int main()
{
	Input();
	CreateTree();
	while (M--)
	{
		Output();
	}

	return 0;
}