#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int k)
{
	if (k == 1)
	{
		st.pop();
		return;
	}
	int temp = st.top();
	st.pop();
	solve(st,k-1);
	st.push(temp);
}

stack<int> removemid(stack<int> st, int size)
{
	if (size == 0)
		return st;
	int k = (size / 2) + 1;
	solve(st, k);
	return st;
}

int main()
{
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	stack<int> ans = removemid(st, st.size());
	while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}
	cout<<endl;
	return 0;
}