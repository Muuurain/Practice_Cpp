#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
namespace poly{    
    const int mod = 998244353, g = 3;
    const int N = (1 << 18) + 1;
    ll qpow(ll x, int y){
        ll ans = 1;
        while(y){
            if(y&1) ans = ans * x % mod;
            x = x * x % mod; y >>= 1;
        }
        return ans;
    }
    const int invg = qpow(g, mod-2);
    int to[N];
    void init(int n, int lg){
        for(int i = 1; i <= n; i++) to[i] = ((to[i>>1]>>1) | (i&1) << (lg-1));
    }
    void ntt(vector<ll> &x, int op){
        int sz = x.size();
        for(int i = 0; i < sz; i++) if(to[i] > i) swap(x[i], x[to[i]]);
        for(int len = 2; len <= sz; len <<= 1){
            ll I = qpow(op == 1? g: invg, (mod-1)/len);
            for(int l = 0; l < sz; l += len){
                int r = l + len - 1, mid = (l + r) >> 1;
                ll Ipw = 1;
                for(int i = l; i <= mid; i++){
                    int opi = mid+i-l+1;
                    ll lw = x[i], rw = x[opi] * Ipw % mod;
                    x[i] = (lw + rw) % mod, x[opi] = (lw - rw + mod) % mod;
                    Ipw = Ipw * I % mod;
                }
            }
        }
    }
    vector<ll> mul(vector<ll> &x, vector<ll> &y){
        int lg = 1;
        while(x.size()+y.size() >= (1<<lg)) lg++;
        x.resize(1<<lg), y.resize(1<<lg);
        init(1<<lg, lg);
        vector<ll> ans(1<<lg);
        ntt(x, 1), ntt(y, 1);
        for(int i = 0; i < (1<<lg); i++) ans[i] = x[i] * y[i] % mod;
        ntt(ans, -1);
        ll inv = qpow(1<<lg, mod-2);
        for(int i = 0; i < (1<<lg); i++) ans[i] = ans[i] * inv % mod;
        return ans;
    }
};
char s[3][N];
int n;
int calc(vector<ll> *v){
    vector<ll> x, y;
    ll dlt = 0;
    for(int i = 0; i < n; i++){
        if(v[1][i]+v[2][i] == 2) x.push_back(0), dlt++;
        if(v[1][i]+v[2][i] == 1) x.push_back(1);
        if(v[1][i]+v[2][i] == 0) x.push_back(0);
    }
    reverse(x.begin(), x.end());
    y = v[0];
    auto f = poly::mul(x, y);
    ll ans = f[n-1];
    for(int i = n; i <= 2*(n-1); i++) ans = max(ans, f[i-n] + f[i]);
    return ans + dlt;
}
int solve(){
    int ans = 0;
    for(int i = 0; i < 3; i++){
        static vector<ll> v[3];
        for(int j = 0; j < 3; j++) v[j].clear(), v[j].shrink_to_fit();
        int c = 1;
        for(int j = 0; j < 3; j++){
            int id;
            if(i == j) id = 0;
            else id = c, c++;
            for(int k = 0; k < n; k++) v[id].push_back(s[j][k]-'0');
        }
        ans = max(ans, calc(v));
    }
    return ans;
}
int main(){
    int _; scanf("%d", &_);
    while(_--){
        scanf("%d", &n);
        for(int i = 0; i < 3; i++) scanf("%s", s[i]);
        printf("%d\n", solve());
    }
    return 0;
}
