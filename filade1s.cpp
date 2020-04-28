#include <bits/stdc++.h>


using namespace std;



int main()
{

	long int n;
	cin >> n;

	if(n == 0)
	{
		cout << "N\n";
		return 0;
	}


	while(n != 0)
	{
		if((n & 1) == 0)
		{
			cout << "N\n";
			return 0;
		}
		n = n >> 1;
	}

	cout << "S\n";






	return 0;
}