#include <iostream>
#include <set>
using namespace std;

int calc(int n)
{
	int t = 0;
	while (n)
	{
		t += n % 10;
		n /= 10;
	}
	return t;
}

int main()
{
	int N;
	cin >> N;
	set<int> ans;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		ans.insert(calc(t));
	}
	cout << ans.size() << endl;
	set<int>::iterator it = ans.begin();
	while (it != ans.end())
	{
		if (it != ans.begin()) cout << " ";
		cout << *it;
		it++;
	}

	system("pause");
	return 0;
}