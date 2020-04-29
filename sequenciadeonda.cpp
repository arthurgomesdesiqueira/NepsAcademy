#include <bits/stdc++.h>

using namespace std;

int pos2[100002];
int pos[100002];


void LIS(vector <int> &v)
{
	vector<int> pilha;

	for (int i = 0; i < v.size(); ++i)
	{
		vector<int> :: iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);		

		int p = it - pilha.begin();

		if(it == pilha.end()) 
		{
			pilha.push_back(v[i]);
			pos[i] = pos[i-1] + 1;
		}
		else
		{
			pos[i] = pos[i-1];
			*it = v[i]; 
		}
		
		
	}
	
	return; 

}
void LIS2(vector <int> &v)
{
	vector<int> pilha;

	for (int i = 0; i < v.size(); ++i)
	{
		vector<int> :: iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);		

		int p = it - pilha.begin();

		if(it == pilha.end()) 
		{
			pilha.push_back(v[i]);
			pos2[i] = pos2[i-1] + 1;
		}
		else
		{
			pos2[i] = pos2[i-1];
			*it = v[i]; 
		}
		
		
	}
	
	return; 

}

int main()
{

	int a, b;
	vector<int> v, x;
	cin >> a;
		
	for (int i = 0; i < a; ++i)
	{
		cin >> b;
		v.push_back(b);
		pos[i] = 0;
		pos2[i] = 0;
	}

	reverse(v.begin(), v.end());
	x = v;
	reverse(v.begin(), v.end());
	
	LIS(v);
	LIS2(x);

	int resp = 0;

/*
	for (int i = 0; i < a; ++i)
	{
		cout << pos[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < a; ++i)
	{
		cout << pos2[i] << " ";
	}
	cout << endl;
*/	for (int i = 0; i < a; ++i)
	{
		resp = max(resp, 2*min(pos[i], pos2[v.size()-1-i]) - 1);
	}

	cout << resp << endl;




	return 0;
}

