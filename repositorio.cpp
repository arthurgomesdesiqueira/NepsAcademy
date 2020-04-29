#include <bits/stdc++.h>

using namespace std;


int main()
{

	int n, c;
	map<long int, long int> arvore, arvore2;
	long int chave, value;
	cin >> c >> n;

	for (int i = 0; i < c; ++i)
	{
		cin >> chave >> value;
		arvore.insert(make_pair(chave, value));
	}	

	for (int i = 0; i < n; ++i)
	{
		cin >> chave >> value;

		if(arvore2.find(chave) != arvore2.end())
		{
			if(arvore2.find(chave)->second < value)
			{
				arvore2.find(chave)->second = value;	
			}
		}
		else
		{
			arvore2.insert(make_pair(chave, value));
		}

	}
	/*cout << "\n\n\n";
	for (map<long int, long int> :: iterator it = arvore.begin(); it != arvore.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	for (map<long int, long int> :: iterator it = arvore2.begin(); it != arvore2.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "\n\n";
	*/
	for (map<long int, long int> :: iterator it = arvore2.begin(); it != arvore2.end(); ++it)
	{
		if(arvore.find(it->first) == arvore.end())
		{
			cout << it->first << " " << it->second << endl; 
		}
		else if(it->second > arvore.find(it->first)->second)
		{
			cout << it->first << " " << it->second << endl;
		}
		
	}	





	return 0;
}