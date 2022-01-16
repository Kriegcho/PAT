#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N1, N2;
	cin >> N1;
	queue<long int> q1;
	for (int i = 0; i < N1; i++)
	{
		long int t;
		cin >> t;
		q1.push(t);
	}
	cin >> N2;
	queue<long int> q2;
	for (int i = 0; i < N2; i++)
	{
		long int t;
		cin >> t;
		q2.push(t);
	}
	int cnt = 1;
	int mid = (N1 + N2 + 1) / 2;

	while (!q1.empty() || !q2.empty())
	{
		bool b = (cnt == mid);
		if (q1.empty())
		{
			if (b)
			{
				cout << q2.front();
				break;
			}
			q2.pop();
		}
		else if (q2.empty())
		{
			if (b)
			{
				cout << q1.front();
				break;
			}
			q1.pop();
		}
		else
		{
			bool f = (q1.front() < q2.front());
			if (b)
			{
				cout << (f ? q1.front() : q2.front());
				break;
			}
			f ? q1.pop() : q2.pop();
		}
		cnt++;
	}

	system("pause");
	return 0;
}