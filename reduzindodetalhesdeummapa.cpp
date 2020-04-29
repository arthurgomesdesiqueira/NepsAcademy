#include <bits/stdc++.h>
#define MAX 124752
#define valor_n 501
using namespace std;

struct vlw
{
    int x, y;
    int dist;

};

typedef struct vlw Kruscal;

Kruscal v[MAX];
int pai[valor_n];
int peso[valor_n];
vector <Kruscal> distancia;


bool comp(Kruscal a, Kruscal b)
{
    return a.dist < b.dist;
}


int find(int a)
{
    if(pai[a] == a) return a;
    return pai[a] = find(pai[a]);

}


void join(int a, int b)
{
    a = find(a);
    b = find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[a] < peso[b]) pai[a] = b;
    else
    {
        pai[b] = a;
        peso[b]++;
    }


}



int main()
{

    int n, m;

    cin >> n >> m;        

    for (int i = 0; i < m; ++i)
    {
        cin >> v[i].x >> v[i].y >> v[i].dist; 
    }

    for (int i = 0; i < n; ++i)
    {
        pai[i] = i; 
        peso[i] = 0;
    }



    sort(v, v + m, comp);


    for (int i = 0; i < m; ++i)
    {
        if(find(v[i].x-1) != find(v[i].y-1))
        {
            join(v[i].x-1, v[i].y-1);
            distancia.push_back(v[i]); 
        }

    }

    long int soma = 0;

    for (int i = 0; i < distancia.size(); ++i)
    {
        soma = soma + distancia[i].dist;
    }


    cout << soma << endl;


    return 0;

}