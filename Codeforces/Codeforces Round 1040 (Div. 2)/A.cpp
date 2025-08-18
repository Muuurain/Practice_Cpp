#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> S(n);

    for(int &i : S) cin >> i;
    int sum = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i]) sum += S[i];
        else sum += 1;
    }
    cout << sum << endl;
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