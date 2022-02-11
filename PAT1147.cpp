#include <iostream>
#include <vector>
using namespace std;

void Postorder(const vector<int>& ns, int r, bool& f)
{
	if (r * 2 + 1 < ns.size()) Postorder(ns, r * 2 + 1, f);
	if (r * 2 + 2 < ns.size()) Postorder(ns, r * 2 + 2, f);
	if (f) cout << " ";
	cout << ns[r];
	f = true;
}

int main()
{
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		vector<int> ns(N);
		for (int j = 0; j < N; j++) cin >> ns[j];
		int flag = -1;
		bool f = true;
		for (int j = 0; j < N / 2; j++)
		{
			if (ns[j] > ns[j * 2 + 1] && (j * 2 + 2 < N - 1 ? ns[j] > ns[j * 2 + 2] : true))
			{
				if (flag == -1) flag = 0;
				else if (flag != 0)
				{
					f = false;
					break;
				}
			}
			else if (ns[j] < ns[j * 2 + 1] && (j * 2 + 2 < N - 1 ? ns[j] < ns[j * 2 + 2] : true))
			{
				if (flag == -1) flag = 1;
				else if (flag != 1)
				{
					f = false;
					break;
				}
			}
			else
			{
				f = false;
				break;
			}
		}
		if (!f) cout << "Not Heap" << endl;
		else if (flag == 0) cout << "Max Heap" << endl;
		else if (flag == 1) cout << "Min Heap" << endl;
		f = false;
		Postorder(ns, 0, f);
		cout << endl;
	}

	system("pause");
	return 0;
}