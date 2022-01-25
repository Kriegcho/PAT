#include <iostream>
#include <string>
using namespace std;

string num[10] = { "", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

string conv(int n, bool f = true) // 万以内的转换，f表征是否加前缀0
{
	string r = "";
	if (n == 0) return r;
	if (n < 1000)
	{
		if (f) r += "ling ";
		if (n < 100)
		{
			if (n < 10) r += num[n];
			else
			{
				if (n % 10 > 0) r += num[n / 10] + " Shi " + num[n % 10];
				else r += num[n / 10] + " Shi";
			}
		}
		else
		{
			r += num[n / 100] + " Bai";
			n = n % 100;
			if (n == 0) return r;
			else r += " ";
			if (n < 10) r += "ling " +  num[n];
			else
			{
				if (n % 10 > 0) r += num[n / 10] + " Shi " + num[n % 10];
				else r += num[n / 10] + " Shi";
			}
		}
	}
	else
	{
		r += num[n / 1000] + " Qian";
		n = n % 1000;
		if (n == 0) return r;
		else r += " ";
		if (n < 100)
		{
			r += "ling ";
			if (n < 10) r += num[n];
			else
			{
				if (n % 10 > 0) r += num[n / 10] + " Shi " + num[n % 10];
				else r += num[n / 10] + " Shi";
			}
		}
		else
		{
			r += num[n / 100] + " Bai";
			n = n % 100;
			if (n == 0) return r;
			else r += " ";
			if (n < 10) r += "ling " + num[n];
			else
			{
				if (n % 10 > 0) r += num[n / 10] + " Shi " + num[n % 10];
				else r += num[n / 10] + " Shi";
			}
		}
	}
	return r;
}

int main()
{
	int N;
	cin >> N;
	if (N < 0)
	{
		cout << "Fu ";
		N = -N;
	}
	string ans = "";
	if (N == 0) ans = "ling";
	else
	{
		bool f = false;
		if (N > 100000000)
		{
			ans += num[N / 100000000] + " Yi";
			N = N % 100000000;
			if (N > 0) ans += " ";
			f = true;
		}
		if (N > 10000)
		{
			ans += conv(N / 10000, f) + " Wan";
			N = N % 10000;
			if (N > 0) ans += " ";
			f = true;
		}
		ans += conv(N, f);
	}
	cout << ans;

	system("pause");
	return 0;
}