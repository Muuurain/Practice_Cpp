#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    ll ret = 0;
    unordered_map<int, int> uni;
    for(int i = 0; i <= l - 1 && i < n; i++) {
        if(uni.find(a[i]) == uni.end()) uni[a[i]] = 1;
        else uni[a[i]]++;
    }
    int cnt = uni.size();
    for(int pl = 0; pl + l - 1 < n; pl++) {
        int cntnow = cnt;
        if(cntnow == k) {
            ret++;
        }
        int mr = min(pl + r - 1, n - 1);
        for(int pr = pl + l; pr < pl + r && pr < n; pr++) {
            if(uni.find(a[pr]) == uni.end()) {
                uni[a[pr]] = 1;
                cntnow++;
                if(cntnow == k) {
                    ret++;
                }
                else if(cntnow > k) {
                    mr = pr;
                    break;
                }
            }
            else {
                uni[a[pr]]++;
                if(cntnow == k) {
                    ret++;
                }
            }
        }
        for(int pr = pl + l; pr < pl + r && pr < n && pr <= mr; pr++) {
            uni[a[pr]]--;
            if(uni[a[pr]] == 0) {
                uni.erase(a[pr]);
            }
        }
        if(uni[a[pl]] == 1) {
            uni.erase(a[pl]);
            cnt--;
        }
        else{
            uni[a[pl]]--;
        }
        if(pl + l == n) {
            break;
        }
        else if(uni.find(a[pl + l]) == uni.end()) {
            cnt++;
            uni[a[pl + l]] = 1;
        }
        else {
            uni[a[pl + l]]++;
        }
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