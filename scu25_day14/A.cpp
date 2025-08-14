#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int MOD = 998244353;
typedef long long ll;
struct node{
    ll x;
    ll y;
}nodes[N];
double calk(int i, int j) {
    if(nodes[i].x == nodes[j].x) return INT_MAX;
    return (nodes[j].y - nodes[i].y) / (nodes[j].x - nodes[i].x);
}
bool cmp1(node a, node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(node a, node b) {
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
bool cmp3(node a, node b) {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
bool cmp4(node a, node b) {
    if(a.y == b.y) return a.x > b.x;
    return a.y < b.y;
}
ll dis2(int i, int j) {
    return (nodes[j].y - nodes[i].y) * (nodes[j].y - nodes[i].y) + (nodes[j].x - nodes[i].x) * (nodes[j].x - nodes[i].x);
}
ll mypow(ll a, ll b, ll p) {
    ll ans = 1;
    a %= p;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
int main() {
    ll n, v;
    cin >> n >> v;
    v = (v % MOD) * (v % MOD) % MOD;
    for(int i = 0; i <= n; i++) {
        cin >> nodes[i].x >> nodes[i].y;
    }
    double k1, k2;
    sort(nodes, nodes + n + 1, cmp1);
    k1 = calk(0, 1), k2 = calk(1, 2);
    int value = 1;
    for(int i = 2; i + 1 <= n; i++) {
        if(i & 1) {
            if(k2 != calk(i, i + 1)) {
                value = 0;
                break;
            }
        }
        else {
            if(k1 != calk(i, i + 1)) {
                value = 0;
                break;
            }
        }
    }
    ll sum = 0;
    if(value) {
        for(int i = 0; i < n; i++) {
            ll t = (dis2(i , i + 1) % MOD) * (mypow(v, MOD - 2, MOD)) % MOD;
            sum = (sum + t) % MOD;
        }
    }
    else {
        sort(nodes, nodes + n + 1, cmp2);
        k1 = calk(0, 1), k2 = calk(1, 2);
        int value = 1;
        for(int i = 2; i + 1 <= n; i++) {
            if(i & 1) {
                if(k2 != calk(i, i + 1)) {
                    value = 0;
                    break;
                }
            }
            else {
                if(k1 != calk(i, i + 1)) {
                    value = 0;
                    break;
                }
            }
        }
        if(value) {
            for(int i = 0; i < n; i++) {
                ll t = (dis2(i , i + 1) % MOD) * (mypow(v, MOD - 2, MOD)) % MOD;
                sum = (sum + t) % MOD;
            }
        }
        else {
            sort(nodes, nodes + n + 1, cmp3);
            k1 = calk(0, 1), k2 = calk(1, 2);
            int value = 1;
            for(int i = 2; i + 1 <= n; i++) {
                if(i & 1) {
                    if(k2 != calk(i, i + 1)) {
                        value = 0;
                        break;
                    }
                }
                else {
                    if(k1 != calk(i, i + 1)) {
                        value = 0;
                        break;
                    }
                }
            }
            if(value) {
                for(int i = 0; i < n; i++) {
                    ll t = (dis2(i , i + 1) % MOD) * (mypow(v, MOD - 2, MOD)) % MOD;
                    sum = (sum + t) % MOD;
                }
            }
            else {
                sort(nodes, nodes + n + 1, cmp4);
                for(int i = 0; i < n; i++) {
                    ll t = (dis2(i , i + 1) % MOD) * (mypow(v, MOD - 2, MOD)) % MOD;
                    sum = (sum + t) % MOD;
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}