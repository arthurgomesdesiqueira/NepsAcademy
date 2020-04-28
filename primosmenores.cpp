#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<int> v(n+1, 1);
	
	for (int i = 2; i <= n; ++i)
	{

		if(v[i] == 1)
		{
			cout << i << " ";
			int j = 2;
			while(j*i <= n)
			{
				v[j*i] = 0;
				j++;
			}
		}

	}

	cout << endl;




	return 0;
}