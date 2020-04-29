#include <bits/stdc++.h>

using namespace std;


int main()
{

	int n, tmp;
	long int d;
	vector<int> v;

	cin >> n >> d;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < n; ++i)
	{
		v.push_back(v[i]);
	}

	long int res = 0;
	int j = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		while(j < i + n && res < d)
		{
			res += v[j++];
		}
		if(res == d)
		{
			ans++;
		}
		res -= v[i];

			
	}
	
	cout << ans << endl;





 
	return 0;
}