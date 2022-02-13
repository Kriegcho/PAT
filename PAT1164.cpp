#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map<char, vector<string>> m;
	for (int i = 0; i < 26; i++)
	{
		vector<string> vs;
		for (int j = 0; j < 7; j++)
		{
			string s;
			getline(cin, s);
			vs.push_back(s);
		}
		m['A' + i] = vs;
	}
	string w, t;
	getline(cin, w);
	vector<string> ans;
	for (int i = 0; i < w.length(); i++)
	{
		if (w[i] >= 'A' && w[i] <= 'Z') t += w[i];
		else
		{
			if (!t.empty()) ans.push_back(t);
			t.clear();
		}
	}
	if (!t.empty()) ans.push_back(t);
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0) cout << endl;
		for (int k = 0; k < 7; k++)
		{
			for (int j = 0; j < ans[i].length(); j++)
			{
				if (j > 0) cout << " ";
				cout << m[ans[i][j]][k];
			}
			cout << endl;
		}
		// if (i < ans.size() - 1) cout << endl; 最后两个测试点查了很久居然是因为这个。。size返回无符号数，坏就坏在-1这里。
		// if (i + 1 < ans.size()) cout << endl;  这么写也可以AC
	}

	system("pause");
	return 0;
}