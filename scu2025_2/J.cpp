#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        int mon[n + 10] = {0};
        for(int i = 0; i < n; i++) {
            scanf("%d", &mon[i]);
        }
        sort(mon, mon + n);
        long long ret = 0;
        if(mon[0] > 1) {
            while(mon[0] != 1) {
                ret++;
                mon[0]--;
            }
        }
        int last = mon[0];
        for(int i = 1; i < n; i++) {
            if(mon[i] > last + 1) {
                while(mon[i] > last + 1) {
                    mon[i]--;
                    ret++;
                }
            }
            last = mon[i];
        }
        printf("%lld\n", ret);
    }

    return 0;
}