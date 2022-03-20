#include <iostream>
#include <map>
using namespace std;

int main()
{
	int K1, K2, c = 0;
	map<int, double> m;
	cin >> K1;
	for (int i = 0; i < K1; i++)
	{
		int n;
		double e;
		cin >> n >> e;
		m[n] = e;
	}
	cin >> K2;
	for (int i = 0; i < K2; i++)
	{
		int n;
		double e;
		cin >> n >> e;
		if (m.find(n) == m.end()) m[n] = e;
		else m[n] += e;
	}
	map<int, double>::iterator it = m.begin();
	while (it != m.end())
	{
		if (it->second) c++;
		it++;
	}
	cout << c;
	while (it != m.begin())
	{
		it--;
		if (it->second)
		{
			cout << " " << it->first << " ";
			printf("%.1f", it->second);
		}
	}
	system("pause");
}