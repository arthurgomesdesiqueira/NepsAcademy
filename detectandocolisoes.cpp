#include <bits/stdc++.h>


using namespace std;


int main()
{

	int x0, y0, x1, y1;
	int x2, y2, x3, y3; 


	cin >> x0 >> y0 >> x1 >> y1;
	cin >> x2 >> y2 >> x3 >> y3;


	if(x1 < x2 || x0 > x3 || y1 < y2 || y0 > y3)
	{
		cout << "0\n";
		return 0;
	}

	cout << "1\n";



	return 0;
}