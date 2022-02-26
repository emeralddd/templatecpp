l2 nhan(l2 x,l2 y,l2 z) {
    x%=z;
    y%=z;
    l2 q=x+y/z;
    return (((x*y-q*z)%z+z)%z);
}
