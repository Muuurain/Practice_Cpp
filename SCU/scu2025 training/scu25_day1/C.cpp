#include<bits/stdc++.h>
using namespace std;

// int mypow(int a, int b) {
//     int ret = 1;
//     while(b) {
//         if(b & 1) ret *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return ret;
// }
int f[13];
int main() {
    for(int i = 1; i <= 12; i++) {
        f[i] = 2 * f[i - 1] + 1;
    }
    int ans[13];
    ans[0] = 0;
    for(int i = 1; i <= 12; i++) {
        ans[i] = INT_MAX;
        int ret = 1;
        for(int j = 0; j < i; j++) {
            ret = 2 * ans[j] + f[i - j];
            ans[i] = min(ans[i], ret);
        }
        cout << ans[i] << endl;
    }

    return 0;
}