#include <bits/stdc++.h>
#define MAX 1002
#define INFINITO 1000000


using namespace std;

typedef pair<int, int> pii;

int n, m;
bool processado[MAX];
vector <pii> vizinhos[MAX];
int distancia[MAX];


int Prim()
{
	distancia[0] = 0;
	priority_queue <pii, vector<pii>, greater<pii> > fila;
	fila.push(pii(distancia[0], 0));

	while(!fila.empty())
	{

		int davez = fila.top().second;
		fila.pop();

		if(!processado[davez])
		{

			processado[davez] = true;
			for (int i = 0; i < vizinhos[davez].size(); ++i)
			{
				int dist = vizinhos[davez][i].first;
				int outro = vizinhos[davez][i].second;
				if(distancia[outro] > dist && !processado[outro])
				{
					distancia[outro] = dist;
					fila.push(pii(distancia[outro], outro));
				}


			}


		}




	}

	int custo_arvore = 0;
    for(int i = 0;i < n;i++) custo_arvore += distancia[i];

    return custo_arvore;









}









int main()
{
	int p, q, u;

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> p >> q >> u;
		vizinhos[p].push_back(pii(u, q));
		vizinhos[q].push_back(pii(u, p));
	}
	for (int i = 0; i < n; ++i)
	{
		distancia[i] = INFINITO;
		processado[i] = false;
	}


	cout << Prim() << endl;




	return 0;
}