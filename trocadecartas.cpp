#include <bits/stdc++.h>

using namespace std;


int main()
{

	set<int> a, b;
	
	int n, m, tmp;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		a.insert(tmp);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		b.insert(tmp);
	}

	int soma01, soma02;
	soma01 = 0;
	soma02 = 0;
	for (set<int> :: iterator it = a.begin(); it != a.end(); ++it)
	{
		if(b.find(*it) == b.end())
		{
			soma01++;
		}
	}

	for (set<int> :: iterator it = b.begin(); it != b.end(); ++it)
	{
		if(a.find(*it) == a.end())
		{
			soma02++;
		}
	}

	if (soma01 > soma02) cout << soma02 << endl;
	else cout << soma01 << endl;















	return 0;
}