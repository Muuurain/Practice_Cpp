#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+100;
bool vis[N];
ll ans[N], sum[N];
ll get_sum(ll r){
    if(r < 1) return 0;
    if(vis[r]) return ans[r];
    vis[r] = true;
    ll lg = log2(r);
    ll k = 1ll << lg;
    return ans[r] = (k + r) * (r - k + 1) / 2 + get_sum(k - (r - k) - 1);
}
int main(){
    for(int i = 1; i < N; i++) sum[i] = get_sum(i);
    for(int i = 1; i < N; i++) sum[i] += sum[i-1];
    int _;
    scanf("%d", &_);
    while(_--){
        int n; scanf("%d", &n);
        printf("%lld\n", sum[n]);
    }
    return 0;
}
