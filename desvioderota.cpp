#include <bits/stdc++.h>
#define MAX 252
#define INFINITO 1000000

using namespace std;

typedef pair<int, int> pii;



int pedagio[MAX];
bool processado[MAX];
vector<pii> vizinhos[MAX];

void Dijkstra(int S, int ultimo)
{
	pedagio[S] = 0;
	priority_queue <pii, vector<pii>, greater<pii> > fila;
	fila.push(pii(pedagio[S], S));

	while(!fila.empty())
	{
		int atual = fila.top().second;
		fila.pop();

		if(atual == ultimo) break;

		if(!processado[atual])
		{
			processado[atual] = true;
			for (int i = 0; i < (int)vizinhos[atual].size(); i++)
			{
				int peda = vizinhos[atual][i].first;
				int adjacente = vizinhos[atual][i].second;
				if(pedagio[adjacente] > peda + pedagio[atual])
				{
					pedagio[adjacente] = peda + pedagio[atual];	
					fila.push(pii(pedagio[adjacente], adjacente));
				}


			}


		}


	}







}





int main()
{

	int n, m, c, k;
	int u, v, p;


	while(true)
	{
		cin >> n >> m >> c >> k;
		if(n == 0 && m == 0 && c == 0 && k == 0) break;

		for (int i = 0; i < n; i++)
		{	
			pedagio[i] = INFINITO;
			processado[i] = false;
		}

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> p;

			if(u > c - 1 && v > c - 1)
			{
				vizinhos[u].push_back(pii(p, v));
				vizinhos[v].push_back(pii(p, u));
			}
			else if(u > c - 1 && v <= c - 1)
			{
				vizinhos[u].push_back(pii(p, v));
			}
			else if(u <= c - 1 && v > c - 1)
			{
				vizinhos[v].push_back(pii(p, u));
			}
			else if(u <= c - 1 && v <= c - 1)
			{
				if(u == v + 1)
				{
					vizinhos[v].push_back(pii(p, u));		
				}
				else if(v == u + 1)
				{
					vizinhos[u].push_back(pii(p, v));
				}


			}


		}

		Dijkstra(k, c - 1);

		for (int i = 0; i < n; ++i)
		{
			vizinhos[i].clear();
		}

		cout << pedagio[c - 1] << endl;









	}












	return 0;
}