#include <bits/stdc++.h>

using namespace std;



int main()
{

	string n;
	cin >> n;
	long long soma = 0;
	
	for (int i = 0; i < n.size(); ++i)
	{	
		if(i % 2 == 0)
			soma = soma + (n[i] - '0');
		else
			soma = soma - (n[i] - '0');
	}

	if(soma % 11 == 0)
		cout << "S\n";
	else
		cout << "N\n";






	return 0;
}