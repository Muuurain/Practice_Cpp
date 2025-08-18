#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353, B = 233;
const int N = 1e6+100;
ll jc[N];
ll qpow(ll x, int y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % mod;
        x = x * x % mod; y >>= 1;
    }
    return ans;
}
ll solve(int n){
    return jc[n-1] * (qpow(B, n) % mod-1+mod) % mod * qpow(B-1, mod-2) % mod;
}
int main(){
    jc[0] = 1;
    for(int i = 1; i < N; i++) jc[i] = jc[i-1] * i % mod;
    int _; scanf("%d", &_);
    while(_--){
        int n; scanf("%d", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}
