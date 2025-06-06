#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n + 10] = {0};
        int b[m + 10] = {0};
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + m);
        int t1 = n, t2 = m;
        int st1 = 0, st2 = 0;
        int swc = 1;
        while(n && m) {
            if(swc == 1) {
                if(a[st1] > b[t2 - 1]) {
                    a[st1] -= b[t2 - 1];
                    b[t2 - 1] = 0;
                    t2--;
                    m--;
                }
                else if(a[st1] == b[t2 - 1]) {
                    a[st1] = b[t2 - 1] = 0;
                    st1++;
                    t2--;
                    m--;
                    n--;
                }
                else {
                    b[t2 - 1] -= a[st1];
                    a[st1] = 0;
                    st1++;
                    n--;
                }
                swc = 2;
            }
            else {
                if(b[st2] > a[t1 - 1]) {
                    b[st2] -= a[t1 -1];
                    a[t1 - 1] = 0;
                    t1--;
                    n--;
                }
                else if(b[st2] == a[t1 - 1]) {
                    b[st2] = a[t1 - 1] = 0;
                    st2++;
                    t1--;
                    m--;
                    n--;
                }
                else {
                    a[t1 - 1] -= b[st2];
                    b[st2] = 0;
                    st2++;
                    m--;
                }
                swc = 1;
            }
            
        }
        if(n == 0 && m == 0) {
            printf("Draw\n");
        }
        else if(n == 0) {
            printf("Tenzing\n");
        }
        else if(m == 0) {
            printf("Tsondu\n");
        }
    }

    return 0;
}