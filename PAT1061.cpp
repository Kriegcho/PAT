#include <iostream>
#include <string>
using namespace std;

string w[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int c = 0;
	for (int i = 0; i < s1.length() && i < s2.length(); i++)
	{
		if (c == 0)
		{
			if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
			{
				cout << w[s1[i] - 'A'] << " ";
				c++;
			}
		}
		else if (c == 1)
		{
			if (s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9')))
			{
				if (s1[i] >= 'A' && s1[i] <= 'N') cout << 10 + s1[i] - 'A' << ":";
				if (s1[i] >= '0' && s1[i] <= '9') cout << "0" << s1[i] << ":";
				break;
			}
		}
	}
	for (int i = 0; i < s3.length() && i < s4.length(); i++)
	{
		if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')))
		{
			printf("%02d", i);
			break;
		}
	}

	system("pause");
	return 0;
}