#include <bits/stdc++.h>
#define MAXN 100002

using namespace std;



int main()
{

	vector<int> v;
	int soma[MAXN];
	int best[MAXN];
	int n, a;

	cin >> n;


	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		v.push_back(a);
	}

	soma[0] = 0;
	best[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		soma[i+1] = soma[i] + v[i];
		best[i+1] = max(best[i], soma[i+1]);
	}
	int resp = 0;
	for (int i = 0; i <= n; ++i)
	{
		resp = max(resp, best[i] + (soma[n] - soma[i]));
	}
	int tmp = 0;
	for (int i = 0; i < n; ++i)
	{
		tmp = max(0, tmp + v[i]);
		resp = max(tmp, resp);	

	}
	


	cout << resp << endl;







 
	return 0;
}