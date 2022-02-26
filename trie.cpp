/**
darkemeralddd
**/
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define l2 long long
#define st first
#define nd second
#define ll2 pair<l2,l2>
#define ii pair<int,int>
#define iii pair<int,ii>
#define il2 pair<int,l2>
#define l2i pair<l2,int>
#define emerald ""
#define memset(a,b) memset(a,b,sizeof(a))
#define ladd(a) a=" "+a
#define bit(x,y) (((y)>>(x))&1)
const l2 L = 100;
const l2 mod = 1000000007;
const l2 MAX = 100;
using namespace std;
struct tr {
    tr *br[26];
    bool fi;
    tr() {
        for(int i=0; i<26; i++) {
            br[i]=nullptr;
        }
        fi=0;
    }
};
tr *root=new tr;
void insert(string s) {
    tr *now=root;
    for(auto i:s) {
        int tp=i-97;
        if(now->br[tp]==nullptr) {
            now->br[tp]=new tr;
        }
        now=now->br[tp];
    }
    now->fi=1;
}
bool find(string s) {
    tr *now=root;
    for(auto i:s) {
        if(now->br[i-97]==nullptr) return 0;
        now=now->br[i-97];
    }
    return now->fi;
}
/*
Check a string exist or not?
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    int n,m;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>s;
        insert(s);
    }
    cin>>m;
    for(int i=1; i<=m; i++) {
        cin>>s;
        cout<<find(s)<<'\n';
    }
}
