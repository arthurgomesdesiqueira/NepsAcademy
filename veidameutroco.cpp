#include <bits/stdc++.h>

using namespace std;

int dp[1002];

int troco(int m, vector<int> &v)
{
	if(m == 0) return 1;

	if(m < 0) return 0;

	if(dp[m] >= 0) return 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if(troco(m - v[i], v) == 1) return dp[m-v[i]] = 1;
	}
	return dp[m] = 0;


}





int main()
{
	int n, m, a;
	vector<int> v;

	cin >> n >> m;


	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		v.push_back(a);
	}

	long int soma = 0;
	for (int i = 1; i < m; ++i)
	{
		memset(dp, -1, sizeof(dp));	
		if(troco(i, v) == 0) soma++;

	}


	cout << soma << endl;

















	return 0;
}