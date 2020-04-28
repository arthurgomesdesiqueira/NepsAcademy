#include <bits/stdc++.h>


using namespace std;



int main()
{

	long int n;
	cin >> n;


	cout << ~(n) << endl;


	int qtd = 0;
	while(n != 0)
	{
		qtd++;
		n -= n&-n;
	}

	cout << qtd << endl;






	return 0;
}