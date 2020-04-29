#include <bits/stdc++.h>

using namespace std;


int main()
{

	set<int> arvore;
	
	int n, tmp;

	cin >> n;

	long int soma = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;

		if(arvore.find(tmp) != arvore.end())
		{
			arvore.erase(tmp);
		}
		else
		{
			soma += 2;
			arvore.insert(tmp);
		}
	}
	

	cout << soma << endl;













	return 0;
}