#include <bits/stdc++.h>
#define MAX 1001


using namespace std;



int n, valor[MAX], peso[MAX], tab[MAX][MAX];

int knapsack(int obj, int aguenta)
{

	if(tab[obj][aguenta] >= 0)
	{
		return tab[obj][aguenta];
	}

	if(obj == n || aguenta == 0)
	{
		return tab[obj][aguenta] = 0;
	}

	int nao_coloca = knapsack(obj + 1, aguenta);


	if(peso[obj] <= aguenta)
	{
		int coloca = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);

		return tab[obj][aguenta] = max(nao_coloca, coloca);

	}


	return tab[obj][aguenta] = nao_coloca;


}



int main()
{

	int p;
	int qtd = 0;
		
	while(1)
	{
		qtd++;
		memset(tab, -1, sizeof(tab));

		cin >> p >> n;
		if(p == 0 && n == 0)
		{
			break;
		}

		cout << "Teste " << qtd << endl;

		for(int i = 0; i < n; i++)
		{
			cin >> peso[i] >> valor[i];
		}

		cout << knapsack(0, p) << endl << endl;

	}






	return 0;
}