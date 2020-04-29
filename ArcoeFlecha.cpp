#include <bits/stdc++.h>

#define INF -1

using namespace std;


long long merge_sort(vector <long long> &v)
{

	long long inv = 0;
	
	if(v.size() == 1)
	{
		return 0;
	}


	vector <long long> u1, u2;

	for (int i = 0; i < v.size()/2; ++i)
	{
		u1.push_back(v[i]);
	}
	for (int i = v.size()/2; i < v.size(); ++i)
	{
		u2.push_back(v[i]);
	}

	inv = inv + merge_sort(u1);
	inv = inv + merge_sort(u2);

	long long ini1 = 0, ini2 = 0; 

	u1.push_back(INF);
	u2.push_back(INF);

	for(int i = 0; i < v.size(); i++)
	{

		if(u1[ini1] != -1 && u2[ini2] != -1)
		{
			if(u1[ini1] > u2[ini2])
			{
				v[i] = u1[ini1];
				ini1++;
			}
			else
			{

				v[i] = u2[ini2];
				ini2++;



				inv = inv + u1.size() - 1 - ini1;
				
				//cout << inv << " inv " << endl;

				

			
			}

		}
		else if(u1[ini1] == -1)
		{
			v[i] = u2[ini2];
			ini2++;
			
		}
		else if(u2[ini2] == -1)
		{
			v[i] = u1[ini1];
			ini1++;
			

		}	



	}

	return inv;





}





int main()
{

	long long n, x, y;
	vector <long long> v;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(x*x + y*y);
	}


	cout << merge_sort(v) << endl;





	return 0;
}

