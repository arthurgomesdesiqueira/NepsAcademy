#include <bits/stdc++.h>


using namespace std;


int main()
{

	int a, b, n;

	cin >> n;
	cin >> a;
	for (int i = 1; i < n; i++)
	{
		cin >> b;
		a = __gcd(a, b);
	}


	cout << a << endl;


	return 0;
}