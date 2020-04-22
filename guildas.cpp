#include <bits/stdc++.h>

using namespace std;


int pai[100002];
int qtd[100002];


int find(int x)
{
	if(pai[x] == x) return x;

	return pai[x] = find(pai[x]);
}

void join(int x, int y)
{

	x = find(x);
	y = find(y);


	if(qtd[x] >= qtd[y])
	{
		pai[y] = x;
		qtd[x] += qtd[y];
	}
	else if(qtd[x] < qtd[y])
	{
		pai[x] = y;
		qtd[y] += qtd[x];
	}

}




int main()
{

	int n, m, num1, num2, letra;
	
	while(1)
	{
		cin >> n >> m;
		if(n == 0 && m == 0)
		{
			break;
		}

		int soma = 0;
		for (int i = 1; i <= n; ++i)
		{
			pai[i] = i;
			cin >> qtd[i];
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> letra >> num1 >> num2;

			if(letra == 1)
			{
				if(find(num1) != find(num2))
				{
					join(num1, num2);
				}
			}
			if(letra == 2)
			{
				if(find(num1) == find(1) && qtd[find(num1)] > qtd[find(num2)])
				{
					soma++;
				}
				else if(find(num2) == find(1) && qtd[find(num1)] < qtd[find(num2)])
				{
					soma++;
				}
			}
	
		}


		cout << soma << endl;


	}	



	return 0;
}