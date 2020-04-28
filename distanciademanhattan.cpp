#include <bits/stdc++.h>


using namespace std;


int main()
{

	long int distancia;
	int x, y, x1, y1;

	cin >> x >> y >> x1 >> y1;

	distancia = abs(x1 - x) + abs(y1 - y);	

	cout << distancia << endl;




	return 0;
}