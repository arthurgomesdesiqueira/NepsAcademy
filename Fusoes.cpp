#include <bits/stdc++.h>

using namespace std;


int pai[100002];
int peso[100002];





int find(int x)
{
	if(pai[x] == x) return x;

	return pai[x] = find(pai[x]);
}

void join(int x, int y)
{

	x = find(x);
	y = find(y);


	if(peso[x] > peso[y])
	{
		pai[y] = x;
	}
	else if(peso[x] < peso[y])
	{
		pai[x] = y;
	}
	else
	{
		pai[y] = x;
		peso[x]++;
	}

}




int main()
{

	int n, k, num1, num2;
	cin >> n >> k;
	memset(peso, 0, sizeof(peso));

	char letra;

	for (int i = 1; i <= n; ++i)
	{
		pai[i] = i;
	}


	for (int i = 0; i < k; ++i)
	{
		cin >> letra >> num1 >> num2;
	
		if(letra == 'C')
		{
			if(find(num1) != find(num2))
			{
				cout << "N\n";
			}
			else
			{
				cout << "S\n";
			}

		}
		if(letra == 'F')
		{
			if(find(num1) != find(num2))
			{
				join(num1, num2);
			}
		}


	}






	return 0;
}