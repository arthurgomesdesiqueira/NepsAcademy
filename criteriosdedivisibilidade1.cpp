#include <bits/stdc++.h>

using namespace std;



int main()
{

	string n;
	cin >> n;
	long long soma = 0;
	int a = n[n.size() - 1] - '0';
	if(a % 2 == 0)
		cout << "S\n";
	else
		cout << "N\n";
	
	for (int i = 0; i < n.size(); ++i)
	{
		soma += n[i] - '0';
	}

	if(soma % 3 == 0)
		cout << "S\n";
	else
		cout << "N\n";
	if(a % 5 == 0)
		cout << "S\n";
	else
		cout << "N\n";








	return 0;
}