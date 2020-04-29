#include <bits/stdc++.h>
#define INFINITO 9999999

using namespace std;


int main()
{

	int n, m;
	int u, v, w;

	cin >> n >> m;

	int distancia[100][100];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			distancia[i][j] = INFINITO;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		distancia[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;

		if(distancia[u][v] != INFINITO)
		{
			if(distancia[u][v] > w)
			{
				distancia[u][v] = w;
				distancia[v][u] = w;		
			}
		}
		else
		{
			distancia[u][v] = w;
			distancia[v][u] = w;	
		}
		
	


	}
	
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);

			}
		}
	}


	int min = 0;
	int max = INFINITO;
	for (int i = 0; i < n; ++i)
	{
		min = 0;
		for (int j = 0; j < n; ++j)
		{
			if(distancia[i][j] > min)
			{
				min = distancia[i][j];
			}
		}
		if(min < max)
		{
			max = min;
		}
	}

	cout << max << endl;






	return 0;
}