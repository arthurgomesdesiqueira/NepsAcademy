#include <bits/stdc++.h>

using namespace std;


typedef pair<long int, int> ii;

int main()
{

	int vendedores, l, t;
	long long soma[1002];
	priority_queue <ii, vector<ii>, greater<ii>> valor;


	cin >> vendedores >> l;

	for (int i = 0; i < vendedores; ++i)
	{
		valor.push(make_pair(0, i));
		soma[i] = 0;
	}

	for (int i = 0; i < l; ++i)
	{
		cin >> t;
		
		auto x = valor.top();
		valor.pop();
		
		soma[x.second]++;
		x.first += t;

		valor.push(x);

	}
	
	for (int i = 0; i < vendedores; ++i)
	{
		cout << i + 1 << " " << soma[i] << endl;
	}
















	

	return 0;
}