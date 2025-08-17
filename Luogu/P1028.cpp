#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> ans(N + 10);
    vector<ll> prefix(N + 10);

    ans[1] = 1;
    prefix[1] = 1;
    for(int i = 2; i < N; i++) {
        ans[i] = 1 + prefix[i / 2];
        prefix[i] = ans[i] + prefix[i - 1];
    }
    cout << ans[n] << endl;

    return 0;
}