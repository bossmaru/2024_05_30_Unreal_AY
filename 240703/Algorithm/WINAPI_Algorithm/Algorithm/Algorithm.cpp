#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>


using namespace std;

// stack : 팬케이크
// FILO : First Input Last Out


// int

template<typename T, typename Container = vector<int>>
class Stack
{
public:
	void push(const T& value)
	{
		_stack.push_back(value);
	}

	bool empty()
	{
		return _stack.size() == 0;	
	}

	const T& top()
	{
		return _stack.back();
	}

	void pop()
	{
		_stack.pop_back();
	}

private:
	Container _stack;
};


int main()
{
	Stack<int> s;

	s.push(1);
	s.push(3);
	s.push(5);
	s.push(7);
	s.push(9);

	while (true)
	{
		if (s.empty())
		{
			break;
		}

		cout << s.top() << endl;
		s.pop();
	}


	return 0;
}