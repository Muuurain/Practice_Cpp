#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ret;
    cin >> n >> m;
    int maxn = 0;

    if(n <= 1000) {
        string ts[1010];
        int t[1010];
        for(int i = 0; i <= m; i++) {
            ret = i;
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    cin >> ts[j];
                    cin >> t[j];
                }
                if(ts[j] == "AND") {
                    ret &= t[j];
                }
                else if(ts[j] == "OR") {
                    ret |= t[j];
                }
                else if(ts[j] == "XOR") {
                    ret ^= t[j];
                }
            }
            maxn = max(maxn, ret);
        }
    }
    else{
        int a = 0, b = -1;
        for(int j = 0; j < n; j++) {
            string ts;
            int tt;
            cin >> ts >> tt;
            if(ts == "AND") {
                a &= tt;
                b &= tt;
            }
            else if(ts == "OR") {
                a |= tt;
                b |= tt;
            }
            else if(ts == "XOR") {
                a ^= tt;
                b ^= tt;
            }
        }
        for(int i = 30; i >= 0; i--) {
            if((a >> i) & 1) maxn += (1 << i);
            else if((b >> i) & 1) {
                if((1 << i) <= m) {
                    maxn += (1 << i);
                    m -= (1 << i);
                }
            }
        }
    }

    cout << maxn << endl;

    return 0;
}