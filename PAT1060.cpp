#include <iostream>
#include <string>
using namespace std;

void GetF(string s, string& e, int& p, int N)
{
	while (s[0] == '0') s = s.substr(1, s.length()); // 去前缀0
	if (s[0] == '.') s = "0" + s; // 补小数点前0
	int pos = s.find('.');
	if (pos == -1)
	{
		p = s.length();
		e = "0." + s.substr(0, N);
	}
	else
	{
		if (pos == 1 && s[0] == '0') // 特殊处理一下整数为0的情况
		{
			string t = s.substr(2, s.length());
			p = 0;
			while (t[0] == '0')
			{
				t = t.substr(1, t.length());
				p--;
			}
			if (t.empty()) p = 0; // 0.00的情况
			e = "0." + t.substr(0, N);
		}
		else
		{
			p = pos;
			string t = s.substr(0, pos) + s.substr(pos + 1, s.length());
			e = "0." + t.substr(0, N);
		}
	}
	// 补0
	while (e.length() < N + 2) e += "0";
}

int main()
{
	int N;
	string A, B;
	cin >> N >> A >> B;
	int pos1 = A.find('.');
	int pos2 = B.find('.');
	string sA, sB;
	int pA, pB;
	GetF(A, sA, pA, N);
	GetF(B, sB, pB, N);
	if (sA == sB && pA == pB)
	{
		cout << "YES " << sA << "*10^" << pA;
	}
	else
	{
		cout << "NO " << sA << "*10^" << pA << " " << sB << "*10^" << pB;
	}

	system("pause");
	return 0;
}