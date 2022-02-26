l2 amb(l2 A,l2 N) {
    if(N==0) return 1;
    l2 temp=amb(A,N>>1);
    temp=(temp*temp)%mod;
    if(N&1) temp=(temp*A)%mod;
    return temp;
}

l2 amb(l2 A,l2 N) {
    if(N==0) return 1;
    l2 temp=1;
    for(; N>0; N>>=1) {
        if(N&1) temp=(temp*A)%mod;
        A=(A*A)%mod;
    }
    return temp;
}
