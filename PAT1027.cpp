#include <iostream>
using namespace std;

char c[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void convert(int t)
{
	int t1 = t % 13;
	int t2 = t / 13;
	cout << c[t2] << c[t1];
}

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#";
	convert(r);
	convert(g);
	convert(b);

	system("pause");
	return 0;
}