#include <bits/stdc++.h>

using namespace std;


typedef pair <int, int> pii;

int distancia(pii a, pii b)
{
	pii c;
	c.first = a.first - b.first;
	c.second = a.second - b.second;
	return c.first * c.first + c.second * c.second;
}

int sign(int x) { return (x < 0) ? -1 : 1; }

pii ponto_medio(pii a, pii b)
{
	pii c;
	c.first = a.first + b.first;
	c.second = a.second + b.second;
	return c;
}

int cross(pii a, pii b, pii c)
{
	//produto vetorial
	return (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);
}

int main()
{
	int x, y;
	vector<pii> v;

	v.push_back({0, 0});
	for (int i = 1; i <= 7; ++i)
	{
		cin >> x >> y;
		v.push_back({x, y});
	}

	//caso 1
	//OK
	if(distancia(v[1], v[2]) + distancia(v[1], v[3]) <= distancia(v[2], v[3]))
	{
		cout << "N\n";
		return 0;
	}

	//caso 2
	//OK-ctz
	if(distancia(v[1], v[2]) != distancia(v[1], v[3]))
	{
		cout << "N\n";
		return 0;
	}

	//caso 3
	//OK
	if(cross(v[2], v[3], v[4]) != 0 || cross(v[2], v[3], v[5]) != 0)
	{
		cout << "N\n";
		return 0;
	}

	//caso 4
	//OK
	if(ponto_medio(v[2], v[3]) != ponto_medio(v[4], v[5]))
	{
		cout << "N\n";
		return 0;
	}

	//caso 5
	//OK-ctz
	if(distancia(v[2], v[3]) <= distancia(v[4], v[5]))
	{
		cout << "N\n";
		return 0;
	}
	//caso6
	//OK
	if(distancia(v[2], v[6]) != distancia(v[2], v[4]) + distancia(v[4], v[6]) || distancia(v[3], v[7]) !=  distancia(v[3], v[5]) + distancia(v[5], v[7]))
	{
		cout << "N\n";
		return 0;
	}

	//caso 7
	//OK-ctz
	if(distancia(v[4], v[6]) != distancia(v[5], v[7]))
	{
		cout << "N\n";
		return 0;
	}
	//caso 8
	//OK
	if(sign(cross(v[2], v[3], v[1])) == sign(cross(v[2], v[3], v[6])))
	{
		cout << "N\n";
		return 0;
	}


	cout << "S\n";



	return 0;
}