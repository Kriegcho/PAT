#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long N, b;
	cin >> N >> b;

	vector<long long> d;
	while (N)
	{
		d.push_back(N % b);
		N = N / b;
	}

	int s = d.size();
	int l = 0, h = s - 1;
	bool flag = true;
	while (l <= h)
	{
		if (d[l] != d[h])
		{
			flag = false;
			break;
		}
		l++;
		h--;
	}

	if (flag)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	for (int i = s - 1; i >= 0; i--)
	{
		cout << d[i];
		if (i > 0)
		{
			cout << " ";
		}
	}

	system("pause");

	return 0;
}