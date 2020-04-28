#include <bits/stdc++.h>


using namespace std;

/*
Determine if you can build a polygon from segments [closed]
https://mathoverflow.net/questions/96617/determine-if-you-can-build-a-polygon-from-segments
ri * 2 < (r1 + ... + rn)

*/




int main()
{
	int n, a;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	long int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if(2 * v[i] < sum)
		{
			cout << i + 1 << endl;
			return 0;
		}

		sum -= v[i];
	}	


	cout << "0\n";












	return 0;
}