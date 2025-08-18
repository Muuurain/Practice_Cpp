#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<vector <long long> > mp(n), tep(k);
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < m; j++) {
            long long t;
            cin >> t;
            mp[i].push_back(t);
        }
    }
    for(long long i = 0; i < k; i++) {
        for(long long j = 0; j < k; j++) {
            long long t;
            cin >> t;
            tep[i].push_back(t);
        }
    }
    for(long long i = 0; i < n - k + 1; i++) {
        for(long long j = 0; j < m - k + 1; j++) {
            long long ret = 0;
            for(long long l = 0; l < k; l++) {
                for(long long o = 0; o < k; o++) {
                    ret += mp[i + l][j + o] * tep[l][o];
                }
            }
            cout << ret << " ";
        }
        cout << endl;
    }
    return 0;
}