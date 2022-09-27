int pr[1562505];
bool check(int n) {
    return (!(pr[n>>6]&(1<<((n>>1)&31))));
}
void es() {
    memset(pr,0);
    int _SQRT=sqrt(100000000);
    for(int i=3; i<=_SQRT; i+=2) {
        if(check(i)) {
            int tmp=(i<<1);
            for(int j=i*i; j<=100000000; j+=tmp)
                pr[j>>6]|=(1<<((j>>1)&31));
        }
    }
}
