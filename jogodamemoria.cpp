#include <bits/stdc++.h>
#define MAXN 50500

using namespace std;


int carta[MAXN];
int par[MAXN];



int nivel[MAXN];
int pai[MAXN];
int ancestral[MAXN][21];


//grafo
vector<int> lista[MAXN];


void dfs(int u)
{
	for (int i = 0; i < (int)lista[u].size(); ++i)
	{

		int v = lista[u][i];
		if(nivel[v] == -1)
		{
			pai[v] = u;
			nivel[v] = nivel[u] + 1;
			dfs(v);
		}
		


	}




}

int LCA(int u, int v)
{
	if(nivel[u] < nivel[v]) swap(u, v);

	for (int i = 20; i >= 0; i--)
	{
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	}

	if(u == v) return u;

	for (int i = 20; i >= 0; i--)
	{
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i])
		{
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}

	return pai[u];

}








int main()
{

	int n;
	int a, b, x;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> x;

		if(carta[x])
		{		
			par[i] = carta[x];
			par[carta[x]] = i;
		}
		carta[x] = i;

	}

	for (int i = 1; i <= n-1; ++i)
	{
		cin >> a >> b;

		lista[a].push_back(b);
		lista[b].push_back(a);

	}
	

	for (int i = 0; i < MAXN; ++i)
	{
		pai[i] = nivel[i] = -1;
	}
	for (int i = 0; i < MAXN; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			ancestral[i][j] = -1;
		}
	}

	nivel[1] = 0;
	//pai[1] = 1;
	dfs(1);

	for (int i = 1; i <= n; ++i) ancestral[i][0] = pai[i];

	for (int i = 1; i < 21; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ancestral[j][i] = ancestral[ancestral[j][i-1]][i-1];
		}
	}	


	long long resp = 0;
	for (int i = 1; i <= n; ++i)
	{
		resp = resp + (long long)(nivel[i] + nivel[par[i]] - 2 * nivel[LCA(i, par[i])]);
	}

	cout << resp/2 << endl;




	return 0;
}