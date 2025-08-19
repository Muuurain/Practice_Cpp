#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e4;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> ans(n + 5), prefix(n + 5);
    ans[1] = ans[0] = 1;
    ans[2] = 2;
    prefix[0] = 1;
    prefix[1] = 2;
    prefix[2] = 4;
    for(int i = 3; i <= n; i++) {
        ans[i] = ans[i - 1] + ans[i - 2] + prefix[i - 3] * 2;
        ans[i] %= MOD;
        prefix[i] = prefix[i - 1] + ans[i];
        prefix[i] %= MOD;
    }
    cout << ans[n] << endl;

    return 0;
}