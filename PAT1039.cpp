#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	map<string, vector<int>*> qm;
	vector<string> ns;

	for (int i = 0; i < K; i++)
	{
		int ci, Ni;
		cin >> ci >> Ni;
		for (int j = 0; j < Ni; j++)
		{
			string t;
			cin >> t;
			if (qm.find(t) == qm.end())
			{
				vector<int>* temp = new vector<int>;
				qm[t] = temp;
			}
			qm[t]->push_back(ci);
		}
	}
	ns.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ns[i];
	}

	map<string, vector<int>*>::iterator it = qm.begin();
	while (it != qm.end())
	{
		sort(it->second->begin(), it->second->end());
		it++;
	}
	for (int i = 0; i < N; i++)
	{
		if (qm[ns[i]])
		{
			cout << ns[i] << " " << qm[ns[i]]->size();
			for (int j = 0; j < qm[ns[i]]->size(); j++)
			{
				cout << " " << (*qm[ns[i]])[j];
			}
			cout << endl;
		}
		else cout << ns[i] << " 0" << endl;
	}
	
	system("pause");
	return 0;
}