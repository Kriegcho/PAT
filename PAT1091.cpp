#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, L, T;
vector<vector<vector<int>>> ma;
vector<vector<vector<bool>>> v;
int oX[6] = { 0, 0, 1, 0, 0, -1 };
int oY[6] = { 0, 1, 0, 0, -1, 0 };
int oZ[6] = { 1, 0, 0, -1, 0, 0 };
struct node
{
	node(int px, int py, int pz) { x = px; y = py; z = pz; }
	int x, y, z;
};

int bfs(int x, int y, int z)
{
	int c = 0;
	queue<node*> q;
	node* n = new node(x, y, z);
	q.push(n);
	v[x][y][z] = true;
	while (!q.empty())
	{
		c++;
		for (int i = 0; i < 6; i++)
		{
			int nx = q.front()->x + oX[i];
			int ny = q.front()->y + oY[i];
			int nz = q.front()->z + oZ[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < L && ma[nx][ny][nz] && !v[nx][ny][nz])
			{
				node* nt = new node(nx, ny, nz);
				v[nx][ny][nz] = true;
				q.push(nt);
			}
		}
		q.pop();
	}
	if (c >= T) return c;
	else return 0;
}

int main()
{
	cin >> M >> N >> L >> T;
	ma.resize(M, vector<vector<int>>(N, vector<int>(L)));
	v.assign(M, vector<vector<bool>>(N, vector<bool>(L, false)));
	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++) cin >> ma[j][k][i];
	int ans = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < L; k++) if (ma[i][j][k] == 1 && !v[i][j][k]) ans += bfs(i, j, k);
	cout << ans;
	system("pause");
	return 0;
}