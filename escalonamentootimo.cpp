#include <bits/stdc++.h>
#define MAX 50001
#define MAX_N 200002

using namespace std;


int grau[MAX];
vector<int> v[MAX_N];
vector<int> lista;
priority_queue <int, vector<int>, greater<int> > heap;


int main()
{

	int n, m, x, y;
	cin >> n >> m;


	for (int i = 0; i < n; i++) grau[i] = 0; 

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		grau[y]++;
		v[x].push_back(y);
	}

	for (int i = 0; i < n; ++i)
	{
		if(grau[i] == 0) heap.push(i);
	}

	int ini = 0;
	while(!heap.empty())
	{
		int atual = heap.top();
		heap.pop();
		
		for (int i = 0; i < (int)v[atual].size(); i++)
		{
			int outro = v[atual][i];
			grau[outro]--;
			if(grau[outro] == 0) heap.push(outro);

		}

		lista.push_back(atual);
		
		
	} 

	if(n != lista.size())
	{
		cout << "*" << endl;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cout << lista[i] << endl;
		}
	}







	return 0;
}