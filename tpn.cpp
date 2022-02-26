void initALR() {
    l2 v=n,last=1;
    while(v!=1) {
        a[++z]=v;
        l[z]=last;
        r[z]=n/v;

        //L[z] -> Z[z]: A[z]

        mp[v]=z;

        last=r[z]+1;
        v=n/(r[z]+1);
    }

    a[++z]=1;
    l[z]=r[z-1]+1;
    r[z]=n;

    mp[1]=z;
}
