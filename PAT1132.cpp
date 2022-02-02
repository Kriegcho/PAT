#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int Z;
		cin >> Z;
		int d = 0, t = Z;
		while (t)
		{
			t /= 10;
			d++;
		}
		int z1 = Z / pow(10, d / 2);
		int z2 = Z - z1 * pow(10, d / 2);
		if (z1 && z2)
			if (Z % (z1 * z2)) cout << "No" << endl;
			else cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	system("pause");
	return 0;
}