int par[10005];
int root(int n) {
    if(par[n]!=n) par[n]=root(par[n]);
    return par[n];
}

bool join(int x,int y) {
    x=root(x); y=root(y);
    if(x==y) return 0;
    par[x]=y;
    return 1;
}

for(int i=1; i<=n; i++) {
    p[i]=i;
}
