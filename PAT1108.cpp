#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int c = 0;
	double tol = 0;
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;
		bool f = false;
		int dc = 0;
		for (int i = 0; i < t.length(); i++)
			if (i == 0)
			{
				if (!isdigit(t[i]) && t[i] != '-')
				{
					f = true;
					break;
				}
			}
			else
			{
				if (t[i] == '.') dc++;
				if (!isdigit(t[i]) && t[i] != '.')
				{
					f = true;
					break;
				}
			}
		if (dc > 1) f = true;
		else if (dc == 1)
		{
			int pos = t.find('.');
			if (t.length() > 4 && pos < t.length() - 3) f = true;
		}
		if (!f)
		{
			double d = stod(t);
			if (d < -1000 || d > 1000) f = true;
		}
		if (f) cout << "ERROR: " << t << " is not a legal number" << endl;
		else
		{
			c++;
			tol += stod(t);
		}
	}
	double avg = tol / c;
	if (c)
	{
		if (c > 1) printf("The average of %d numbers is %.2f", c, avg);
		else printf("The average of %d number is %.2f", c, avg);
	}
	else cout << "The average of 0 numbers is Undefined";

	system("pause");
	return 0;
}