#include <bits/stdc++.h>


using namespace std;


int main()
{

	int n, value;
	cin >> n;

	long int soma = 0;
	for (int i = 0; i < 7; ++i)
	{	
		cin >> value;
		if(i == 6 || i < 3)
		{
			soma += value;
		}
		else if(i >= 3)
		{	
			soma -= value;
		}

	}

	if(soma == n)
		cout << "N\n";
	else
		cout << "S\n";



	return 0;
}