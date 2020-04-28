#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n, a;
	cin >> n;
	int max = 1300002;

	vector<int> v(max, 1);
	unordered_map<int, int> primos;

	int qtd = 0;
	for(int i = 2; i <= max; i++)
	{
		if(v[i] == 1)
		{	
			qtd++;
			primos[i] = qtd;
			int j = 2;
			while(j*i <= max)
			{
				v[j*i] = 0;
				j++;
			}
		}

	}
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cout << primos[a] << endl;
	}




	return 0;
}