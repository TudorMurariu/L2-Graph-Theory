#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

char mat[30001][30001];
int n , m;

struct {
    int x,y;
}start_,final_;

int lee(int x,int y)
{
    mat[x][y] = 'x';

    int aux = 0;
    if(final_.x == x && final_.y == y)
        return 1;

    /// jos
    if(x != n-1 && mat[x+1][y] == ' ')
        aux = lee(x+1,y);

    if(aux)
        return 1;


    /// dreapta
    if(y != m-1 && mat[x][y+1] == ' ')
        aux = lee(x,y+1);

    if(aux)
        return 1;

    /// stanga
    if(y != 0 && mat[x][y-1] == ' ')
        aux = lee(x,y-1);
    if(aux)
        return 1;

    if(aux)
        return 1;

    /// sus
    if(x != 0 && mat[x-1][y] == ' ')
        aux = lee(x-1,y);

    if(aux)
        return 1;

    //mat[x][y] = ' ';
    return 0;
}

int main()
{
    /// citim labirintul
    FILE *f;
    f = fopen("input.txt","r");
    char * buffer;
    int lsize;

    buffer = (char*) malloc (sizeof(char)*50001);
    fread (buffer,1,50001,f);

    int i , j , maxj = 0;
    i = j = 0;

    for(int k=0;buffer[k] != '\0';k++)
    {

        if(buffer[k] == '\n')
        {
            k++;
            if(buffer[k] == '\0')
                break;
            j = 0;
            i++;
        }
        mat[i][j] = buffer[k];
        j++;
        if(j > maxj)
            maxj = j;
    }
    i++;

    n = i;
    m = maxj;
    //cout << i << " " << j << endl;
    final_.x = -1;
    start_.x = -1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 'S' && start_.x == -1)
                {
                    start_.x = i;
                    start_.y = j;
                }

                if(mat[i][j] == 'F' && final_.x == -1)
                {
                    final_.x = i;
                    final_.y = j;
                }
                cout << mat[i][j];
            }
        cout << endl;
    }

    mat[final_.x][final_.y] = ' ';

    if(final_.x == -1 || start_.x == -1)
    {
        cout << "Labirintul nu poate fi rezolvat";
        return 0;
    }

    int rez = lee(start_.x,start_.y);
    mat[final_.x][final_.y] = 'F';

    if(rez)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    if(mat[i][j] == 'S')
                    {
                        start_.x = i;
                        start_.y = j;
                    }

                    if(mat[i][j] == 'F')
                    {
                        final_.x = i;
                        final_.y = j;
                    }
                    cout << mat[i][j];
                }
            cout << endl;
        }
    else
        cout << "Nu exitsa!";
    return 0;
}
