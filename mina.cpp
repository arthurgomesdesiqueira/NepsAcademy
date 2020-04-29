#include <bits/stdc++.h>

using namespace std;


typedef pair <int, pair<int, int>> pii;


int m[105][105];
int menor = 10000000;
int n;


int bfs(int a, int b)
{
	priority_queue <pii, vector<pii>, greater<pii> > fila;
	fila.push(make_pair(0 , make_pair(a, b)));
	pii var;

	while(!fila.empty())
	{
		var = fila.top();
		fila.pop();

		a = var.second.first;
		b = var.second.second;
		int valor = var.first;
		
		if(m[a][b] == -1) continue;

		//cout << a << " " << b << endl;

		if(a == n && b == n)
		{
			menor = valor;
			break;

		}
		else
		{
			m[a][b] = -1;	
			if(m[a+1][b] != -1)
			{
				fila.push(make_pair(valor + m[a+1][b], make_pair(a+1, b)));
			
			}
			if(m[a-1][b] != -1)
			{
				fila.push(make_pair(valor + m[a-1][b], make_pair(a-1, b)));
			
			}
			if(m[a][b+1] != -1)
			{
				fila.push(make_pair(valor + m[a][b+1], make_pair(a, b+1)));
			
			}
			if(m[a][b-1] != -1)
			{
				fila.push(make_pair(valor + m[a][b-1], make_pair(a, b-1)));
				
			}

		}




	}

	return menor;



}






int main()
{

	

	for (int i = 0; i <= 103; ++i)
	{
		for (int j = 0; j <= 103; ++j)
		{
			m[i][j] = -1;
		}
	}

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> m[i][j];
		}
	}




	cout << bfs(1, 1) << endl;







	return 0;
}