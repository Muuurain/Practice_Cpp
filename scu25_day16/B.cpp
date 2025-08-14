#include <bits/stdc++.h>
using namespace std;

typedef unsigned __int128 ui128;
typedef unsigned long long ull;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull n, k;
    cin >> n >> k;

    for(int i = n - 1; i >= 0;  i--) {
        ull t = k / ((ull)(1) << i);
        if (t % 4 == 0 || t % 4 == 3) cout << 0;
        else cout << 1;
    }    


    return 0;
}