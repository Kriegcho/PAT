#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct book
{
	int id;
	string name;
	string au;
	string keys;
	string pub;
	string year;
};

bool cmp(book b1, book b2)
{
	return b1.id < b2.id;
}

int main()
{
	int N;
	cin >> N;
	vector<book> books;
	for (int i = 0; i < N; i++)
	{
		book b;
		string keys;
		scanf("%d", &b.id);
		cin.ignore();
		getline(cin, b.name);
		getline(cin, b.au);
		getline(cin, b.keys);
		getline(cin, b.pub);
		getline(cin, b.year);
		books.push_back(b);
	}
	sort(books.begin(), books.end(), cmp);

	int M;
	cin >> M;
	cin.ignore();
	for (int i = 0; i < M; i++)
	{
		string s;
		getline(cin, s);
		
		char ct = s[0];
		cout << s << endl;
		int cnt = 0;
		switch (ct)
		{
		case '1':
			for (int j = 0; j < books.size(); j++)
			{
				book b = books[j];
				if (b.name == s.substr(3, s.length()))
				{
					cnt++;
					printf("%07d\n", b.id);
				}
			}
			break;
		case '2':
			for (int j = 0; j < books.size(); j++)
			{
				book b = books[j];
				if (b.au == s.substr(3, s.length()))
				{
					cnt++;
					printf("%07d\n", b.id);
				}
			}
			break;
		case '3':
			for (int j = 0; j < books.size(); j++)
			{
				string key;
				int k = 0;
				while (k < books[j].keys.length()) {
					while (k < books[j].keys.length() && books[j].keys[k] != ' ') {
						key += books[j].keys[k];
						k++;
					}
					if (key == s.substr(3, s.length())) {
						printf("%07d\n", books[j].id);
						cnt++;
					}
					key.clear();
					k++;
				}

			}
			break;
		case '4':
			for (int j = 0; j < books.size(); j++)
			{
				book b = books[j];
				if (b.pub == s.substr(3, s.length()))
				{
					cnt++;
					printf("%07d\n", b.id);
				}
			}
			break;
		case '5':
			for (int j = 0; j < books.size(); j++)
			{
				book b = books[j];
				if (b.year == s.substr(3, s.length()))
				{
					cnt++;
					printf("%07d\n", b.id);
				}
			}
			break;
		}
		if (cnt == 0)
		{
			cout << "Not Found" << endl;
		}
	}

	system("pause");
	return 0;
}