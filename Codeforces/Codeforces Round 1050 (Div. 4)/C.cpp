#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n);
    for(auto& [x, y] : a) cin >> x >> y;
    int st = 0;
    int time = 0;
    int score = 0;
    for(auto [x, y] : a) {
        if((x - time) & 1) {
            if(y == st) {
                score += x - time - 1;
            }
            else {
                score += x - time;
            }
        }
        else {
            if(y == st) {
                score += x - time;
            }
            else {
                score += x - time - 1;
            }
        }
        st = y;
        time = x;
    }
    score += m - time;
    cout << score << '\n';
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