//dist[i]: Khoang cach tu goc den i

int lca(int x,int y) {
    if(dist[x]<dist[y]) swap(x,y);

    for(int k=16; k>=0; k--)
        if(dist[x]-(1<<k)>=dist[y])
            x=anc[k][x];

    if(x==y) return x;

    for(int k=16; k>=0; k--)
        if(anc[k][x]!=0&&anc[k][x]!=anc[k][y]) {
            x=anc[k][x];
            y=anc[k][y];
        }

    while(x!=y) {
        x=anc[0][x];
        y=anc[0][y];
    }

    return x;
}

for(int k=1; k<=16; k++)
    for(int i=1; i<=n; i++)
        anc[k][i]=anc[k-1][anc[k-1][i]];
