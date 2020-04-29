#include <bits/stdc++.h>

using namespace std;


int main()
{

	int n, a;
	cin >> n;


	set <int> oi;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		oi.insert(a);
	}

	cout << oi.size() << endl;



	return 0;
}