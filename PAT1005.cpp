#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string En[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	char c;
	int nAns = 0;
	while ((c = getchar()) != '\n')
	{
		nAns += c - '0';
	}
	vector<int> v;
	while (nAns / 10 > 0)
	{
		v.push_back(nAns % 10);
		nAns /= 10;
	}
	v.push_back(nAns);
	int nSize = v.size();
	for (int i = 0; i < nSize; i++)
	{
		if (i == 0)
			cout << En[v[nSize - 1 - i]];
		else
		{
			cout << " " << En[v[nSize - 1 - i]];
		}
	}
	system("pause");
	return 0;
}