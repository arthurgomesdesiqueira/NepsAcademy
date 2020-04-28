#include <bits/stdc++.h>


using namespace std;


int main()
{

	int n, m;
	cin >> n >> m;

	long int resp = 0;
	for (int renato = 1; renato <= m; renato++)
	{
		int gustavo = min(m, n - renato - 1); //todos precisam ter pelo menos 1, esse '-1' é o valor do 1do bruno
		int bruno = max(1, n - renato - gustavo);

		resp += max(0, gustavo - bruno + 1); 

	}

	cout << resp << endl;



	return 0;
}