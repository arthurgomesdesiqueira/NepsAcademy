#include <bits/stdc++.h>

using namespace std;

struct data{
	pair<int, int> sum, pref, suff, ans; 
};

int v[100100]; 
data t[400402];


data combine(data l, data r)
{
	if(l.ans.first == -11000)
		return r;
	if(r.ans.first == -11000)
		return l;

	data res;
	res.sum = {l.sum.first + r.sum.first, l.sum.second + r.sum.second};
	res.pref = max(l.pref, {l.sum.first + r.pref.first, l.sum.second + r.pref.second});
	res.suff = max(r.suff, {r.sum.first + l.suff.first, r.sum.second + l.suff.second});
	res.ans = max(max(r.ans, l.ans), {l.suff.first + r.pref.first, l.suff.second + r.pref.second});

	return res;
}

data make_data(int val)
{
	data res;
	res.sum = res.pref = res.suff = res.ans = {val, 1};

	return res;
}


void build(int node, int a[], int l, int r)
{
	if(l == r)
	{
		t[node] = make_data(a[r]);
		return;
	}
	int meio = (r + l)/2;
	build(node*2, a, l, meio);
	build(node*2+1, a, meio+1, r);
	t[node] = combine(t[node*2], t[node*2+1]);

}

data query(int node, int l, int r, int tl, int tr)
{

	if(tl > r || l > tr)
	{
		data neutro;
		neutro.sum = neutro.pref = neutro.ans = neutro.suff = {-11000, 0};
		return neutro;
	}
	if(tl <= l && r <= tr)
	{
		return t[node];
	}
	int meio = (r + l)/2;
	return combine(query(2*node, l, meio, tl, tr), 
		           query(2*node+1, meio+1, r, tl, tr));

}


	
int main()
{

	int tri, n, q, int01, int02;
	scanf("%d", &tri);


	for (int w = 0; w < tri; ++w)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &v[i]);
		}
		build(1, v, 1, n);

		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			scanf("%d%d", &int01, &int02);
			data v = query(1, 1, n, int01, int02);
			pair<int, int> a = max(max(v.ans, v.pref), max(v.suff, v.sum));
			printf("%d %d\n", a.first, a.second);

		}





	}






	return 0;
}