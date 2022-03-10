#include <iostream>
#include <fstream>
using namespace std;
ifstream f("input.txt");

int vizitati[101],mat[101][101],n;

void DFS(int nod)
{
    for(int i=1;i<=n;i++)
        if(!vizitati[i] && mat[nod][i])
            {
                cout << i << " ";
                vizitati[i] = 1;
                DFS(i);
            }
}

int main()
{
    /// Citire din fisier
    int x,y;
    f >> n;
    while(f >> x >> y)
    {
        mat[x][y] = 1;
    }

    int nod;
    cin >> nod;
    DFS(nod);

    return 0;
}
