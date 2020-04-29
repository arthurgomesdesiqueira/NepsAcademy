#include <bits/stdc++.h>

using namespace std;


int main()
{

	int n, m, t;
	map<string, string> arvore;
	string chave, value, res;

	cin >> t;

	int j = 0;
	while(j < t)
	{
		cin >> m >> n;

		getchar();
		for (int i = 0; i < m; ++i)
		{
			getline(cin, chave);
			getline(cin, value);
			arvore.insert(make_pair(chave, value));
		
		}
		/*for (map<string, string> :: iterator it = arvore.begin(); it != arvore.end(); ++it)
		{
			cout << "1: " << it->first << " - 2: " << it->second << endl;
		}*/	

		for (int i = 0; i < n; ++i)
		{
			getline(cin, chave);
			
			int w = 0;
			res = "";
			value = "";
			while(w < chave.size())
			{
				if(chave[w] != ' ' && chave[w] != '\n')
				{
					value = value + chave[w]; 
				}

				//cout << "value: " << value << endl;
				if(chave[w] == ' ')
				{
					if(arvore.find(value) != arvore.end())
					{
						//cout << "value1: " << value << endl;
						res = res + arvore[value] + " ";
					}
					else
					{
						//cout << "value2: " << value << endl;
						res = res + value + " ";
					}
					value = "";
				}
				else if(w == chave.size() - 1)
				{
					if(arvore.find(value) != arvore.end())
					{
						res = res + arvore[value] + "\n";
					}
					else
					{
						res = res + value + "\n";
					}
					value = "";
				}
				
				w++;
			}
			//cout << "res:" << res;
			cout << res;
		}



		cout << endl;
		arvore.clear();














		j++;
	}


	return 0;
}