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

//    for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//                    cout << mat[i][j];
//            cout << endl;
//        }
//    cout << endl << endl << endl;

    //cout << x << " " << y << endl;

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

    /// dreapta
    if(y != m-1 && mat[x][y+1] == ' ')
        aux = lee(x,y+1);

    if(aux)
        return 1;

    /// jos
    if(x != 0 && mat[x-1][y] == ' ')
        aux = lee(x-1,y);

    if(aux)
        return 1;

    //mat[x][y] = ' ';
    return 0;
}

int main()
{
    FILE *f;
    f = fopen("input.txt","r");
    char * buffer;
    int lsize;

    buffer = (char*) malloc (sizeof(char)*50001);
    fread (buffer,1,50001,f);

    //cout << buffer;
    int i , j , maxj = 0;
    i = j = 0;

    for(int k=0;buffer[k] != '\0';k++)
    {

        if(buffer[k] == '\n')
        {
            //cout << "s\n";
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
                    //cout << "s" << endl;
                }

                if(mat[i][j] == 'F' && final_.x == -1)
                {
                    final_.x = i;
                    final_.y = j;
                    //cout << "f" << endl;
                }
                cout << mat[i][j];
            }
        cout << endl;
    }

    mat[final_.x][final_.y] = ' ';

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                    cout << mat[i][j];
            cout << endl;
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
