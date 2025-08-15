#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int M = 5e3 + 10;
vector<vector<long long>> C(M);
vector<long long> tosum(M);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < M; i++) {
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    int n;
    cin >> n;
    vector<int> match(M);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        match[t]++;
    }

    for(int i = 1; i < M; i++) {
        if(!match[i]) continue;
        for(int j = i; j + i < M; j++) {
            if(i == j) {
                if(match[i] < 2) continue;
                tosum[i + j] = (tosum[i + j] + C[match[i]][2]) % MOD;
            }
            else if(match[j]) tosum[i + j] = (tosum[i + j] + C[match[i]][1] * C[match[j]][1]) % MOD;
        }
    }
    long long ans = 0;
    for(int i = 1; i < M; i++) {
        if(match[i] < 2 || !tosum[i]) continue;
        ans = ans + C[match[i]][2] * tosum[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}