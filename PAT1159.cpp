#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct node
{
	node(int nd) { d = nd; lc = NULL; rc = NULL; par = NULL; }
	int d;
	node *lc, *rc, *par;
};
vector<int> post, ino;
map<int, node*> m;
node* gettree(node* par, int ol, int oh, int pl, int ph)
{
	node* p = m[post[ph]];
	p->par = par;
	int ind;
	for (int i = ol; i <= oh; i++)
		if (ino[i] == post[ph])
		{
			ind = i;
			break;
		}
	if (ind > ol) p->lc = gettree(p, ol, ind - 1, pl, pl + ind - 1 - ol);
	if (ind < oh) p->rc = gettree(p, ind + 1, oh, pl + ind - ol, ph - 1);
	return p;
}

int main()
{
	int N, M;
	cin >> N;
	post.resize(N);
	ino.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> post[i];
		node* p = new node(post[i]);
		m[post[i]] = p;
	}
	for (int i = 0; i < N; i++) cin >> ino[i];
	node* r = gettree(NULL, 0, N - 1, 0, N - 1);
	cin >> M;
	cin.ignore();
	for (int i = 0; i < M; i++)
	{
		string qs;
		getline(cin, qs);
		if (qs.find("root") != -1)
		{
			int pos = qs.find(' ');
			int rd = stoi(qs.substr(0, pos));
			if (rd == r->d) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (qs.find("siblings") != -1)
		{
			int pos = qs.find(' ');
			int ld = stoi(qs.substr(0, pos));
			int pos1 = pos + 1 + qs.substr(pos + 1).find(' ');
			int pos2 = pos1 + 1 + qs.substr(pos1 + 1).find(' ');
			int rd = stoi(qs.substr(pos1 + 1, pos2 - pos1 - 1));
			if (m[ld]->par == m[rd]->par) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (qs.find("parent") != -1)
		{
			int pos = qs.find(' ');
			int ld = stoi(qs.substr(0, pos));
			int rpos = qs.rfind(' ');
			int rd = stoi(qs.substr(rpos + 1));
			if (m[ld] == m[rd]->par) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (qs.find("left") != -1)
		{
			int pos = qs.find(' ');
			int ld = stoi(qs.substr(0, pos));
			int rpos = qs.rfind(' ');
			int rd = stoi(qs.substr(rpos + 1));
			if (m[ld] == m[rd]->lc) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (qs.find("right") != -1)
		{
			int pos = qs.find(' ');
			int ld = stoi(qs.substr(0, pos));
			int rpos = qs.rfind(' ');
			int rd = stoi(qs.substr(rpos + 1));
			if (m[ld] == m[rd]->rc) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (qs.find("same") != -1)
		{
			int pos = qs.find(' ');
			int ld = stoi(qs.substr(0, pos));
			int pos1 = pos + 1 + qs.substr(pos + 1).find(' ');
			int pos2 = pos1 + 1 + qs.substr(pos1 + 1).find(' ');
			int rd = stoi(qs.substr(pos1 + 1, pos2 - pos1 - 1));
			node* t = m[ld];
			int dep1 = 0, dep2 = 0;
			while (t)
			{
				dep1++;
				t = t->par;
			}
			t = m[rd];
			while (t)
			{
				dep2++;
				t = t->par;
			}
			if (dep1 == dep2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if (qs.find("full") != -1)
		{
			map<int, node*>::iterator it = m.begin();
			bool f = true;
			while (it != m.end())
			{
				if ((it->second->lc && it->second->rc == NULL) || (it->second->lc == NULL && it->second->rc))
				{
					f = false;
					break;
				}
				it++;
			}
			if (f) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	system("pause");
	return 0;
}