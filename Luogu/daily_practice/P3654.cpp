#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, k;
    cin >> r >> c >> k;
    char mp[110][110] = {'\0'};
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> mp[i][j];
        }
    }
    long long ret = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(j >= k) {
                bool value = true;
                for(int x = 0; x < k; x++) {
                    if(mp[i][j - x] != '.') {
                        value = false;
                        break;
                    }
                }
                if(value) ret++;
            }
            if(i >= k) {
                bool value = true;
                for(int x = 0; x < k; x++) {
                    if(mp[i - x][j] != '.') {
                        value = false;
                        break;
                    }
                }
                if(value) ret++;
            }
        }
    }
    if(k == 1) ret /= 2;
    cout << ret << endl;

    return 0;
}