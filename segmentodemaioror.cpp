#include <bits/stdc++.h>


using namespace std;


int main()
{
	long int res = 0;
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		res |= a;
	}


	cout << res << endl;



	return 0;
}