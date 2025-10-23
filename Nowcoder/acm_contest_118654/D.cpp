#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<char> s(n + 10);
    vector<vector<int> > pos(30);
    for(int i = 0; i < n; i++) {
        auto& c = s[i];
        cin >> c;
        pos[c - 'a'].push_back(i);
    }
    int ret = INT_MAX;
    for(char c = 'a'; c <= 'z'; c++) {
        if(pos[c - 'a'].size() < k) continue;
        for(int i = 0; i + k - 1 < pos[c - 'a'].size(); i++) {
            ret = min(ret, pos[c - 'a'][i + k - 1] - pos[c - 'a'][i] + 1);
        }
    }
    if(ret == INT_MAX) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}