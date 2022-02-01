#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int M, N, S;
	cin >> M >> N >> S;
	vector<string> ss(M);
	for (int i = 0; i < M; i++) cin >> ss[i];
	set<string> st;
	vector<string> ans;
	while (S <= M)
	{
		if (st.find(ss[S - 1]) == st.end())
		{
			st.insert(ss[S - 1]);
			ans.push_back(ss[S - 1]);
		}
		else
		{
			S++;
			while (S <= M)
			{
				if (st.find(ss[S - 1]) == st.end())
				{
					st.insert(ss[S - 1]);
					ans.push_back(ss[S - 1]);
					break;
				}
				S++;
			}
		}
		S += N;
	}
	if (ans.empty()) cout << "Keep going...";
	else for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

	system("pause");
	return 0;
}