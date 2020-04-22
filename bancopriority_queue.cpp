#include <bits/stdc++.h>

using namespace std;

struct blz
{
	int t, d;
};

typedef struct blz bora;

int main()
{

	int caixas, clientes, t, d, soma = 0;
	priority_queue <int, vector<int>, greater<int>> valor;


	cin >> caixas >> clientes;

	for (int i = 0; i < caixas; ++i)
	{
		valor.push(0);
	}

	for (int i = 0; i < clientes; ++i)
	{
		cin >> t >> d;
		
		int x = valor.top();
		valor.pop();
		if(x < t)
		{
			x = t;
			valor.push(x + d);
		}
		else
		{
			if(t + 20 < x)
			{
				soma++;
			}
			valor.push(x + d);

		}



	}
	
	cout << soma << endl;

















	

	return 0;
}