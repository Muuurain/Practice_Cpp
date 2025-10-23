#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cal(ll n) {
    ll ret = 1;
    ll cnt = 1;
    while(n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    ret *= cnt;
    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            cnt = 1;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            ret *= cnt;
        }
    }
    if(n != 1) ret *= 2;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n;
    cin >> n;
    int step = 0;
    while(n != 2) {
        step++;
        n = cal(n);
    }
    cout << step << '\n';
    
    return 0;
}