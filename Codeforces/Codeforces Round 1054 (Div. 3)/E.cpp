#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    vector<int> hs;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        hs.push_back(a[i]);
    }

    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end() ), hs.end() );
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(hs.begin(), hs.end(), a[i]) - hs.begin();
    }

    int px = 0, py = 0;
    int cntx = 0, cnty = 0;
    ll ret = 0;
    vector<int> extx(n), exty(n);
    for(int i = 0; i < n; i++) {
        while(cntx < k && px < n) {
            extx[a[px]]++;
            if(extx[a[px]] == 1) cntx++;
            px++;
        }
        
        while(cnty <= k && py < n) {
            if(exty[a[py]] == 0) {
                if(cnty == k) break;
                cnty++;
                exty[a[py]]++;
            }
            else {
                exty[a[py]]++;
            }
            py++;
        }

        if(cntx == k) {
            ret += max(0, min(py - 1, i + r - 1) - max(px - 1, i + l - 1) + 1);
        }

        extx[a[i]]--;
        exty[a[i]]--;
        if(extx[a[i]] == 0) cntx--;
        if(exty[a[i]] == 0) cnty--;
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}