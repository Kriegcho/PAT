#include <iostream>
#include <vector>
using namespace std;

struct node
{
	char c;
	int n;
	int np;
	bool f;
};

int main()
{
	int s1, s2, N;
	cin >> s1 >> s2 >> N;
	vector<node*> ns;
	ns.assign(100010, NULL);
	for (int i = 0; i < N; i++)
	{
		node* t = new node;
		t->f = false;
		cin >> t->n >> t->c >> t->np;
		ns[t->n] = t;
	}

	int ret = -1;
	if (s1 != -1 && s2 != -1)
	{
		int t = s1;
		while (t != -1 && ns[t])
		{
			ns[t]->f = true;
			t = ns[t]->np;
		}

		t = s2;
		while (t != -1 && ns[t])
		{
			if (ns[t]->f)
			{
				ret = ns[t]->n;
				break;
			}
			t = ns[t]->np;
		}
	}

	if (ret == -1) cout << ret;
	else printf("%05d", ret);

	system("pause");
	return 0;
}