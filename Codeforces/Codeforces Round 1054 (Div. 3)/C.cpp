#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    vector<int> ext(n + 5);
    for(int& i : num) {
        cin >> i;
        ext[i]++;
    }
    int ret = 0;
    for(int i = 0; i < k; i++) {
        if(!ext[i]) ret++;
    }
    ret = ret < ext[k] ? ext[k] : ret;
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