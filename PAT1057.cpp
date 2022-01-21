#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void bin(vector<int>& v, int t, bool f)
{
	int l = 0, h = v.size() - 1;
	while (l <= h)
	{
		if (v[(l + h) / 2] > t)
		{
			h = (l + h) / 2 - 1;
		}
		else if (v[(l + h) / 2] < t)
		{
			l = (l + h) / 2 + 1;
		}
		else
		{
			if (f) v.insert(v.begin() + (l + h) / 2, t);
			else v.erase(v.begin() + (l + h) / 2);
			return;
		}
	}
	if (f) v.insert(v.begin() + l, t);
}

int main()
{
	int N;
	cin >> N;
	stack<int> st;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "Pop")
		{
			if (st.empty()) cout << "Invalid" << endl;
			else
			{
				cout << st.top() << endl;
				bin(v, st.top(), false);
				st.pop();
			}
		}
		else if (s == "PeekMedian")
		{
			if (st.empty()) cout << "Invalid" << endl;
			else cout << v[(v.size() - 1) / 2] << endl;
		}
		else if (s == "Push")
		{
			int t;
			cin >> t;
			st.push(t);
			if (v.empty()) v.push_back(t);
			else bin(v, t, true);
		}
	}

	system("pause");
	return 0;
}