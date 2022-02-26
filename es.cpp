bool pr[100005];
void es() {
    memset(pr,1);
    pr[0]=pr[1]=0;
    int _SQRT=sqrt(100000);
    for(int i=2; i<=_SQRT; i++)
        if(pr[i])
            for(int j=i*i; j<=100000; j+=i)
                pr[j]=0;
}
