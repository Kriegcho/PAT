#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct node
{
	string add, nadd;
	int d;
};

int main()
{
	string h;
	int N, K;
	cin >> h >> N >> K;
	map<string, node*> m;
	for (int i = 0; i < N; i++)
	{
		node* p = new node;
		cin >> p->add >> p->d >> p->nadd;
		m[p->add] = p;
	}
	int n = 0;
	string t = h;
	while (t != "-1")
	{
		t = m[t]->nadd;
		n++;
	}
	vector<node*> ans(N, NULL);
	int r = n / K + 1;
	for (int j = 1; j <= r; j++)
	{
		for (int i = 0; i < K && h != "-1"; i++)
		{
			ans[(n - j * K > 0 ? n - j * K : 0) + i] = m[h]; // 计算下标填入
			//ans.insert(ans.begin() + i, m[h]); // 这一行导致测试点5超时。关于超时优化点还有很多，比如new、string改int、cin等，一开始往这些方向查却忽略了这个insert。。
			h = m[h]->nadd;
		}
		if (h == "-1") break;
	}
	for (int i = 0; i < n; i++) cout << ans[i]->add << " " << ans[i]->d << " " << (i < n - 1 ? ans[i + 1]->add : "-1") << endl;

	system("pause");
	return 0;
}