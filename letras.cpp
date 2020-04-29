#include <bits/stdc++.h>

using namespace std;


int LIS(vector <char> &v)
{

	vector<char>pilha;
	for (int i = 0; i < v.size(); ++i)
	{
		vector<char> :: iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]);

		if(it == pilha.end())
		{
			pilha.push_back(v[i]);
		}
		else
		{

			*it = v[i];

			/*
			for (int i = (it - pilha.begin()); i < pilha.size(); ++i)
			{
				if(*it < pilha[i])
				{
					pilha[i] = *it;
				}
				else if(*it == pilha[pilha.size() - 1])
				{
					pilha.push_back(v[i]);
				}
			}*/
		}

	}

	return pilha.size();

}





int main()
{

	string a;
	vector<char> v;

	cin >> a;
		

	for (int i = 0; i < a.size(); ++i)
	{
		v.push_back(a[i]);
	}


	cout << LIS(v) << endl;




	return 0;
}
