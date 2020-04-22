#include <bits/stdc++.h>
#define ll long long

using namespace std;

int v[100000], tree[500000];


void build(int node, int l, int r)
{
	if(l == r)
	{
		tree[node] = v[l];
		return;
	}

	int meio = (l + r)/2;
	build(2*node + 1, l, meio);
	build(2*node + 2, meio+1, r);

	if(tree[2*node+1] * tree[2*node+2] < 0)
	{
		tree[node] = -1;	
	}
	else if(tree[2*node+1] * tree[2*node+2] > 0)
	{
		tree[node] = 1;	
	}
	if(tree[2*node+1] * tree[2*node+2] == 0)
	{
		tree[node] = 0;	
	}
}

void update(int node, int l, int r, int pos, int value)
{

	if(l == r)
	{
		//cout << "achei -> " << tree[node] << endl;
		tree[node] = value;
		//cout << "novo -> " << tree[node] << endl;
 		
 		return;
	}
	int meio = (l + r)/2;
	if(pos <= meio)
	{
		update(2*node + 1, l, meio, pos, value);
	}
	else if(pos > meio)
	{
		update(2*node + 2, meio+1, r, pos, value);
	}

	if(tree[2*node+1] * tree[2*node+2] < 0)
	{
		tree[node] = -1;	
	}
	else if(tree[2*node+1] * tree[2*node+2] > 0)
	{
		tree[node] = 1;	
	}
	if(tree[2*node+1] * tree[2*node+2] == 0)
	{
		tree[node] = 0;	
	}
}

ll query(int node, int l, int r, int x, int y)
{
	if(x > r || y < l)
	{
		return 1;
	}
	if(x <= l && r <= y)
	{
		return tree[node];
	}

	int meio = (l + r)/2;
	ll a = query(2*node + 1, l, meio, x, y);
	ll b = query(2*node + 2, meio+1, r, x, y);

	if(a * b > 0)
		return 1;
	if(a * b < 0)
		return -1;
	if(a * b == 0)
		return 0;


}


int main()
{

	int n, k, node;
	char letra;
	int ant, prox;
	
		
	while(cin >> n)
	{
		cin >> k;

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		build(0, 0, n-1);

		for (int i = 0; i < k; ++i)
		{
			cin >> letra >> ant >> prox;
			if(letra == 'C')
			{
				update(0, 0, n-1, ant-1, prox);
			}
			if(letra == 'P')
			{
				ll res = query(0, 0, n-1, ant-1, prox-1);
				if(res > 0)
					cout << '+';
				if(res < 0)
					cout << '-';
				if(res == 0)
					cout << '0';
			}

		}
		cout << endl;

	}	




	return 0;
}