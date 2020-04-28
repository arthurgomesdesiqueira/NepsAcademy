#include <bits/stdc++.h>


using namespace std;


int main()
{

	long int a, b, c, d;

	cin >> a >> b >> c >> d;

	long int divisor = b * d;

	a = (divisor/b) * a;
	c = (divisor/d) * c;

	a = a + c;
	c = __gcd(a, divisor);

	a = a/c;
	divisor = divisor/c;

	cout << a << " " << divisor << endl;

	

	return 0;
}