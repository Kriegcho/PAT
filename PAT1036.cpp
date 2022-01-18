#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu
{
	string n, id;
	int g;
};

bool cmp(stu* s1, stu* s2)
{
	return s1->g < s2->g;
}

int main()
{
	int N;
	cin >> N;
	vector<stu*> f, m;
	for (int i = 0; i < N; i++)
	{
		char g;
		stu* p = new stu;
		cin >> p->n >> g >> p->id >> p->g;
		if (g == 'F') f.push_back(p);
		else m.push_back(p);
	}
	sort(f.begin(), f.end(), cmp);
	sort(m.begin(), m.end(), cmp);
	if (!f.empty() && !m.empty())
	{
		cout << f[f.size() - 1]->n << " " << f[f.size() - 1]->id << endl;
		cout << m[0]->n << " " << m[0]->id << endl;
		cout << f[f.size() - 1]->g - m[0]->g << endl;
	}
	else
	{
		if (f.empty()) cout << "Absent" << endl;
		else cout << f[f.size() - 1]->n << " " << f[f.size() - 1]->id << endl;
		if (m.empty()) cout << "Absent" << endl;
		else cout << m[0]->n << " " << m[0]->id << endl;
		cout << "NA" << endl;
	}
	system("pause");
	return 0;
}