hdu

#include<bits/stdc++.h>
using namespace std;
const int mmax = 25;
char fl[mmax][mmax];
int cut;
int w,h;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x,int y)
{
    fl[x][y] = '@';
    cut++;
    for(int i=0; i<4; i++)
    {
        int dx = x+dir[i][0];
        int dy = y+dir[i][1];
        if(dx>=0 && dx<h && dy>=0 && dy<w && fl[dx][dy]!='@'&& fl[dx][dy]!='#')
        {
            fl[dx][dy] = '@';
            dfs(dx,dy);
        }
    }

}
int main()
{

    while(cin >> w >> h)
    {
        if(w==0 && h==0) break;
        int a,b;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin >>  fl[i][j];
                if(fl[i][j]=='@')
                {
                    a=i;
                    b=j;
                }
            }
        }
        cut = 0;
        dfs(a,b);
        cout << cut << endl;
    }
    return 0;
}
