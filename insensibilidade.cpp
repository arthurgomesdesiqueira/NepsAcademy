#include <bits/stdc++.h>


using namespace std;


int main()
{

	long int distancia = 0;
	int x, y, x1, y1, n;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> x1 >> y1;

		distancia += (x1 - x)*(x1 - x) + (y1 - y)*(y1 - y);
	}

	cout << distancia << endl;




	return 0;
}