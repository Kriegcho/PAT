#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> h, path;
void DFS(int pos)
{
	path.push_back(pos);
	if (pos * 2 + 2 < N) DFS(pos * 2 + 2);
	if (pos * 2 + 1 < N) DFS(pos * 2 + 1);
	else
	{
		for (int i = 0; i < path.size(); i++)
		{
			if (i > 0) cout << " ";
			cout << h[path[i]];
		}
		cout << endl;
	}
	path.pop_back();
}

int main()
{
	cin >> N;
	h.resize(N);
	for (int i = 0; i < N; i++) cin >> h[i];
	DFS(0);
	int t = 0; // 0 no 1 max 2 min
	for (int i = 0; i < N / 2; i++)
	{
		if (h[i] >= h[i * 2 + 1] && (i * 2 + 2 < N ? h[i] >= h[i * 2 + 2] : true))
		{
			if (t == 0) t = 1;
			else if (t != 1)
			{
				t = 0;
				break;
			}
		}
		else if (h[i] <= h[i * 2 + 1] && (i * 2 + 2 < N ? h[i] <= h[i * 2 + 2] : true))
		{
			if (t == 0) t = 2;
			else if (t != 2)
			{
				t = 0;
				break;
			}
		}
		else
		{
			t = 0;
			break;
		}
	}
	if (t == 0) cout << "Not Heap";
	else if (t == 1) cout << "Max Heap";
	else if (t == 2) cout << "Min Heap";

	system("pause");
	return 0;
}