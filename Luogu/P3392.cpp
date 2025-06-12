#include <bits/stdc++.h>
using namespace std;

int nw[60], nb[60], nr[60];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            switch(c) {
                case 'W': {
                    nw[i]++;
                    break;
                }
                case 'B': {
                    nb[i]++;
                    break;
                }
                case 'R': {
                    nr[i]++;
                    break;
                }
            }
        }
    }
    int ret = 1e9;
    for(int i = 1; i <= n - 2; i++) {
        for(int j = 1; j <= n - i - 1; j++) {
            int temp = 0;
            for(int k = 1; k <= i; k++) {
                temp += m - nw[k];
            }
            for(int k = i + 1; k <= i + j; k++) {
                temp += m - nb[k];
            }
            for(int k = i + j + 1; k <= n; k++) {
                temp += m - nr[k];
            }
            ret = min(temp, ret);
        }
    }
    cout << ret << endl;

    return 0;
}