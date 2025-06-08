#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        char c;
        long long ret = 0;
        for(int i = 0; i < n; i++) {
            scanf(" %c", &c);
            if(c == '1') {
                ret += n - 1;
            }
            else if(c == '0') {
                ret += 1;
            }
        }
        cout << ret << endl;

    }

    return 0;
}