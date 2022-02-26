struct it {
    int val,len;
    void it() {
        val=len=0;
    }
} st[L+2<<2],ZERO;

it mix(it A,it B) {
    A.len+=B.len;
    A.val+=B.val;
    return A;
}

void build(int id,int l,int r) {
    if(l==r) {
        st[id].val=0;
        st[id].len=0;
        return;
    }
    int m=l+r>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    st[id]=mix(st[id<<1],st[id<<1|1]);
}

void update(int id,int l,int r,int u,int v,int x) {
    if(v<l||r<u) return;
    if(u<=l&&r<=v) {
        st[id].val+=x;
        return;
    }

    int m=l+r>>1;
    update(id<<1,l,m,u,v,x);
    update(id<<1|1,m+1,r,u,v,x);

    st[id]=mix(st[id<<1],st[id<<1|1]);
}

it getresult(int id,int l,int r,int u,int v) {
    if(v<l||r<u) return ZERO;
    if(u<=l&&r<=v) {
        return st[id];
    }

    int m=l+r>>1;
    return mix(getresult(id<<1,l,m,u,v),getresult(id<<1|1,m+1,r,u,v));
}
