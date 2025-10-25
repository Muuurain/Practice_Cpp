#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int num, int g) {
    if(num < g) return false;
    if(num % g == 0) return true;
    int q = num / g;
    if(q > 3) return true;
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    vector<int> ocr(n + 10);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        ocr[num[i]]++;
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    vector<int> prf(n + 5), suf(n + 5);
    for(int i = 2; i <= n; i++) {
        prf[i] = prf[i - 1] + ocr[i - 1];
    }
    for (int i = n; i >= 1; --i) suf[i] = suf[i+1] + ocr[i];

    int ans = 1;
    for(int g = n; g > 1; g--) {
        if(prf[g] > k) continue;
        if(g * 4 <= n && suf[g * 4] >= n - k) {
            ans = g;
            break;
        }
        int value = 0;
        for(int i = g; i <= 3 * g && i <= n; i += g) {
            value += ocr[i];
        }
        if(g * 4 <= n) {
            value += suf[g * 4];
        }
        if(n - value <= k) {
            ans = g;
            break;
        }
    }
    cout << ans << '\n';
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