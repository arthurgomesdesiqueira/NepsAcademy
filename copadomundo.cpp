#include <bits/stdc++.h>
#define MAX 102

using namespace std;

struct s
{
	int x, y;
	int dist;
	int ferrovia;
};

typedef struct s bora;

int pai[MAX];
int peso[MAX];

bora v[20000];
bora res[20000];


bool comp(bora a, bora b)
{
	if(a.ferrovia == b.ferrovia) return a.dist < b.dist;

	return a.ferrovia > b.ferrovia;

}




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
		pai[x] = y;
		peso[x]++;
	}



}









int main()
{

	int n, f, r;
	cin >> n >> f >> r;

	for (int i = 1; i <= n; ++i)
	{
		pai[i] = i;
		peso[i] = 0;
	}


	for (int i = 1; i <= f; ++i)
	{
		cin >> v[i].x >> v[i].y >> v[i].dist;
		v[i].ferrovia = 1;
	}
	for (int i = f + 1; i <= f + r; ++i)
	{
		cin >> v[i].x >> v[i].y >> v[i].dist;
		v[i].ferrovia = 0;
	}
/*
	for (int i = 1; i <= f + r; ++i)
	{
		cout << v[i].x << " " << v[i].y << " " << v[i].dist << endl;
 	}
*/


	sort(v + 1, v + 1 + f + r, comp);


	int size = 0;
	for (int i = 1; i <= f + r; ++i)
	{
		if(find(v[i].x) != find(v[i].y))
		{
			join(v[i].x, v[i].y);
			res[++size] = v[i];
		}


	}

	long int soma = 0;
	for (int i = 1; i <= size; ++i)
	{
		soma = soma + res[i].dist;
	}


	cout << soma << endl;





















	return 0;
}