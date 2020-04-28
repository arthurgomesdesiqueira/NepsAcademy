#include <bits/stdc++.h>


using namespace std;

char eh_primo(long int n)
{
	if(n == 1)
		return 'N';

	for (int i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
			return 'N';
	}

	return 'S';

}




int main()
{

	long int n;
	cin >> n;

	cout << eh_primo(n) << endl;


	return 0;
}