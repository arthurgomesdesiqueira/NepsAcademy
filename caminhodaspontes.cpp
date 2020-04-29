#include <bits/stdc++.h>
#define MAX 100000
#define INFINITO 1000000
using namespace std;


//	<valor_distancia, vertice>	
typedef pair <int, int> pii;



vector <pii> vizinhos[MAX];
bool visitado[MAX];
long int distancia[MAX];



void Dijkstra(int S, int ultimo)
{
	distancia[S] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > fila;
	fila.push(pii(distancia[S], S));

	while(!fila.empty())
	{
		int vertice = fila.top().second;
		fila.pop();
		
		if(vertice == ultimo) break; 

		if(!visitado[vertice])
		{

			visitado[vertice] = true;
			for (int i = 0; i < (int)vizinhos[vertice].size(); ++i)
			{
				int dist = vizinhos[vertice][i].first;
				int vertice_adjacente = vizinhos[vertice][i].second;
				if(distancia[vertice_adjacente] > dist + distancia[vertice])
				{
					distancia[vertice_adjacente] = dist + distancia[vertice];
					fila.push(pii(distancia[vertice_adjacente], vertice_adjacente));
				}

			}

		}


	}



}





int main()
{

	int n, m, s, t, b;
	cin >> n >> m;


	for (int i = 0; i <= n + 1; ++i)
	{
		visitado[i] = false;
		distancia[i] = INFINITO;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> s >> t >> b;

		vizinhos[s].push_back(make_pair(b, t));
		vizinhos[t].push_back(make_pair(b, s));
			
	}

	Dijkstra(0, n + 1);


	cout << distancia[n+1] << endl;





	return 0;
}