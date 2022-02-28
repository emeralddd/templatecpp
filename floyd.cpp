/**
darkemeralddd
**/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define l2 long long
#define st first
#define nd second
#define ll2 pair<l2,l2>
#define emerald ""
#define memset(a,b) memset(a,b,sizeof(a))
const l2 L = 100;
using namespace std;
int n,m,s,fr,u,v,t,w,q;
l2 d[L+5][L+5];
bool dir;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(d,1);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j) d[i][j]=0;
            else d[i][j]=1e9;
    while(m--)
    {
        cin>>u>>v>>w>>dir;
        d[u][v]=w;
        if(!dir) d[v][u]=w;
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
        {
            if(i!=k&&d[i][k]!=1e9)
            {
                for(int j=1; j<=n; j++)
                {
                    if(k!=j&&d[k][j]!=1e9)
                    {
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                    }
                }
            }
        }
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        if(d[u][v]==1e9) cout<<-1<<'\n';
        else cout<<d[u][v]<<'\n';
    }

}
/*
6 7
1 2 1 1
1 6 10 1
2 3 2 1
3 4 20 1
3 6 3 1
5 4 5 1
6 5 4 1
1
1 4
*/

