#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;
const int MAXN = 1 << 12;
int mp[13];
bool value[MAXN];
int ret[13][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            int t;
            cin >> t;
            mp[i] = (mp[i] << 1) + t;
        }
    }

    for(int i = 0; i < (1 << N); i++) {
        if(!(i & (i << 1))) value[i] = true;
    }

    for(int i = 0; i < (1 << N); i++) {
        if(((i & mp[1]) == i && value[i])) ret[1][i] = 1; 
    }

    for(int i = 2; i <= M; i++) {
        for(int j = 0; j < (1 << N); j++) {
            if(value[j] && (j & mp[i]) == j) {
                for(int l = 0; l < (1 << N); l++) {
                    if(value[l] && (l & mp[i - 1]) == l && !(j & l)) {
                        ret[i][j] = (ret[i][j] + ret[i - 1][l]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < (1 << N); i++) {
        ans = (ans + ret[M][i]) % MOD;
    }

    cout << ans << endl;


    return 0;
}