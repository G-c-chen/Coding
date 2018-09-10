#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
char block[maxn][maxn];
int cut;

int dir[8][2]= {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void dfs(int x,int y)
{
    block[x][y] = '*';
    int dx;
    int dy;
    for(int i=0; i<8; i++)
    {
         dx = x+dir[i][0];
         dy = y+dir[i][1];
        if(block[dx][dy]=='@')
        {
            block[dx][dy] = '*';
            dfs(dx,dy);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin >> n >> m)
    {
        if(n==0 && m==0) break;

        cut = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> block[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(block[i][j]=='@')
                {
                    cut++;
                    dfs(i,j);
                }
            }
        }
        cout << cut << endl;
    }

    return 0;
}
