int getsum(int p) {
    int ans = 0;
    while(p>0) {
        ans+=bit[p];
        p-=(p&(-p));
    }
    return ans;
}

void update(int u,int v) {
    while(u<=n) {
        bit[p]+=v;
        p+=(p&(-p));
    }
}
