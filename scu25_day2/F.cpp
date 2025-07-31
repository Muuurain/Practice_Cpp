#include <bits/stdc++.h>
using namespace std;

struct contain{
    int l;
    int r;
    int real;
};

bool cmp(contain a, contain b) {
    return (a.l < b.l);
}

void solve() {
    int n, k;
    cin >> n >> k;
    contain c[n + 10];
    for(int i = 0; i < n; i++) {
        cin >> c[i].l >> c[i].r >> c[i].real;
    }
    sort(c, c + n, cmp);
    for(int i = 0; i < n; i++) {
        if(k >= c[i].l) k = max(k, c[i].real);
        else break;
    }
    cout << k << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}