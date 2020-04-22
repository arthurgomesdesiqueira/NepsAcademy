#include <bits/stdc++.h>

using namespace std;



int main()
{

	string n;
	cin >> n;
	long long soma = 0;
	
	int a;
	if(n.size() == 1)
		a = n[n.size() - 1] - '0';
	else
		a = 10 * (n[n.size() - 2] - '0') + (n[n.size() - 1] - '0'); 	


	if(a % 4 == 0)
		cout << "S\n";
	else
		cout << "N\n";
	
	for (int i = 0; i < n.size(); ++i)
	{
		soma += n[i] - '0';
	}

	if(soma % 9 == 0)
		cout << "S\n";
	else
		cout << "N\n";
	

	if(a % 25 == 0)
		cout << "S\n";
	else
		cout << "N\n";








	return 0;
}