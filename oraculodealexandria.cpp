#include <bits/stdc++.h>


using namespace std;


long int fatorial(int n, int k)
{
	if(1 >= n)
	{
		return 1;
	}

	return n * fatorial(n-k, k); 

}




int main()
{

	int n, k, num;
	string nome;
	cin >> num;


	for (int i = 0; i < num; ++i)
	{
		cin >> nome;
		int j = 0;	
		string numero = "";
		while(nome[j] != '!')
		{
			numero += nome[j];
			j++;
		}
		n = stoi(numero);
		k = nome.size() - j;

		cout << fatorial(n, k) << endl;


	}







	return 0;
}